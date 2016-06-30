package edu.cmu.typechef.busybox

import java.io.File

import edu.cmu.typechef.linux.Preparation._

import scala.sys.process._


object AnalysisFrontend extends App {

  if (args.size != 3) {
    throw new RuntimeException("Incorrect parameters provided, expecting <working directory> <commit id> <file>")
  }

  val currentDir = new File(".")

  val workingDirectory = new File(args(0))
  if (!workingDirectory.exists()) workingDirectory.mkdirs()

  val commitid = args(1)

  val file = args(2)


  val dir = checkoutRevision(workingDirectory, commitid)
  val genDir = new File(dir, "gen").getAbsolutePath
  val srcDir = new File(dir, "git").getAbsolutePath
  assert(new File(dir, "gen").exists(), s"$genDir does not exist")
  assert(new File(dir, "git").exists(), s"$srcDir does not exist")
  val dataDir = new File(currentDir, "data").getAbsolutePath


  println("running TypeChef")

  val system = "ubuntu"


  var typechefFlags = List[String]("--bdd", s"--openFeat=$genDir/features",
//    s"--systemRoot=$dataDir/ubuntu",
//    s"--platfromHeader=$dataDir/platform-ubuntu.h",
    s"-c $dataDir/$system.properties",
    s"--openFeat=$genDir/features",
    s"--include $genDir/header.h",
    s"--include $dataDir/mheader.h",
    s"--featureModelDimacs $genDir/featureModel.dimacs",
    s"-I $srcDir/include",
    "--writePI", "--recordTiming", "--parserstatistics", //--lexdebug
    /*"--dumpcfg"*/ "-t", "--interface", /*"--debugInterface */ "--errorXML")

  typechefFlags = "-U HAVE_LIBDMALLOC -U ENABLE_NC_110_COMPAT -D_GNU_SOURCE" :: typechefFlags

  //TODO handle file presence conditions
  val command = Config.TYPECHEF + typechefFlags.mkString(" ", " ", " ") + srcDir + "/" + file + ".c"
  println(command)

  command.!


}
