package edu.cmu.typechef.busybox

import java.io.{File, FileWriter}

import scala.sys.process._


object Preparation {


  /**
    * returns the directory containing the checked out code
    */
  def checkoutRevision(workingDirectory: File, commitid: String): File = {
    val dir = new File(workingDirectory, commitid)
    val lockFile = new File(dir, ".lock")

    //no need to do anything if the directory exists and is not locked
    if (dir.exists() && !lockFile.exists())
      return dir

    // if it exists and locked, do nothing but wait until lock is released
    if (dir.exists() && lockFile.exists()) {
      println(s"working directory $dir locked, waiting for other process to finish preparation")
      while (lockFile.exists())
        Thread.sleep(1000)
      return dir
    }

    // if directory does not exists, start preparation
    println(s"preparing analysis for $commitid")

    dir.mkdirs()
    lockFile.createNewFile()


    val checkoutDir = new File(dir, "git")
    checkoutDir.mkdir()
    checkoutSource(workingDirectory, commitid, checkoutDir)


    val genDir = new File(dir, "gen")
    genDir.mkdir()

    prepareBusybox(checkoutDir, genDir)

    lockFile.delete()

    dir
  }

  def checkoutSource(workingDirectory: File, commitid: String, targetDir: File): Int = {
    val repoCloneDir = new File(workingDirectory, "git")
    if (repoCloneDir.exists()) {
      println("updating repository from " + Config.GITREPO)
      Process("git fetch " + Config.GITREPO, repoCloneDir).!
    } else {
      println("cloning repository from " + Config.GITREPO)
      Process(s"git clone -n ${Config.GITREPO} git", workingDirectory).!
    }

    println(s"checking out source code (commit $commitid) from Git repository")
    Process(s"git --work-tree=${targetDir.getAbsolutePath} checkout $commitid -- .", repoCloneDir).!
  }

  def prepareBusybox(checkoutDir: File, genDir: File): Unit = {
    Process("make allnoconfig", checkoutDir).!
    Process("make gen_build_files", checkoutDir).!
    Process("make include/config/MARKER", checkoutDir).!
    Process("make applets/applets.o", checkoutDir).!

    val w = new FileWriter(new File(checkoutDir, "applets/applets.o"))
    w.close()

    //run busybox's kconfigreader
    de.fosd.typechef.busybox.KConfigReader.main(List(
      checkoutDir.getAbsolutePath+"/",
      new File(genDir, "featureModel").getAbsolutePath,
      new File(genDir, "header.h").getAbsolutePath,
      new File(genDir, "features").getAbsolutePath
    ).toArray)


    //    # translate the feature model into a .dimacs file for faster processing
    de.fosd.typechef.busybox.CreateDimacs.main(List("--cnf", new File(genDir, "featureModel").getAbsolutePath, new File(genDir, "featureModel.dimacs").getAbsolutePath).toArray)

    runKBuildMiner(checkoutDir, genDir)

  }


  def runKBuildMiner(checkoutDir: File, genDir: File) = {
    println("analyzing kbuild conditions")

    val kbmPath = new File(Config.KBUILDMINER)
    val outPath = new File(genDir, "pc.txt").getAbsolutePath

    s"""${kbmPath.getAbsolutePath} -ea gsd.buildanalysis.linux.KBuildMinerMain --codebase ${checkoutDir.getAbsolutePath} --topFolders applets,archival,archival/libarchive,console-tools,coreutils,coreutils/libcoreutils,debianutils,e2fsprogs,editors,findutils,init,libbb,libpwdgrp,loginutils,mailutils,miscutils,modutils,networking,networking/libiproute,networking/udhcp,printutils,procps,runit,selinux,shell,sysklogd,util-linux,util-linux/volume_id --pcOutput $outPath""".!

    s"grep -v libunarchive $outPath" #| "grep -v Unknown" #> new File(genDir, "pc_clean.txt")

    s"./run.sh de.fosd.typechef.busybox.CleanFileList --openFeatureList ${genDir.getAbsolutePath}/features " +
      s"--featureModel ${genDir.getAbsolutePath}/featureModel.dimacs ${genDir.getAbsolutePath}/pc_clean.txt" #> new File(genDir, "pc_processed.txt")
    //    s"cat ${genDir.getAbsolutePath}/pc_processed.txt" #| """sed s/\\:.*//""" #| "grep -v libunarchive" #| """grep -v "/tc$"""" #> new File(gi/filelist
    //
    //    # generate .pc files from the presence condition list
    //      ./run.sh de.fosd.typechef.busybox.GeneratePCFiles --workingDir gitbusybox/ gitbusybox/pc_processed.txt
    //




  }


}
