package edu.cmu.typechef.busybox


object Config {

  private val configValues: Map[String, String] = io.Source.fromFile("config.txt").getLines().map(x => {
    if (x.startsWith("#")) ("" -> "")
    else if (x.split("=").length != 2) ("" -> "")
    else {
      val v = x.split("=")
      (v(0) -> v(1))
    }
  }).toMap

  val GITREPO = configValues("GITREPO")
  val TYPECHEF = configValues("TYPECHEF")
  val KCONFIGREADER = configValues("KCONFIGREADER")
  val KCONFIGREADER_DUMPCONFC = configValues("KCONFIGREADER_DUMPCONFC")
  val KBUILDMINER = configValues("KBUILDMINER")

}
