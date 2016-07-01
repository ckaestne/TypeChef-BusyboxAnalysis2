Minimal setup to analyze files in Busybox


call the script as `analyze.sh WORKINGDIR COMMITID FILE` in which the 
COMMITID refers to hash of the commit to be analyzed, 
FILE to the file (without the .c
extension), and WORKINGDIR is a directory in which the kernel will
be checked out and generated files are generated.

In `/data` the repository contains (mostly) static files that are manually created
and should not change much by commits in the data directory.
This includes system headers as well as a few workarounds and the
approximated feature model for the parser.

The script can be called multiple times on the same working directory.

The working directory will have the following structure:
  `/git` a bare git repository
  `/COMMITID/gen/<various generated files, such as feature model>`
  `/COMMITID/git/<checked out version of the kernel and working files and results>`



Compared to TypeChef-BusyboxAnalysis, the infrastructure is rewritten in Scala 
to avoid the mess of various shell scripts. Various debug functionality
has not been migrated yet.

To build this you need to publish TypeChef-BusyboxAnalysis locally (`sbt publish-local`)
first.