#!/bin/bash
#!/bin/bash -vxe

echo WORKDIR: $1
echo COMMIT: $2
echo FILE: $3

if [ ! -f run.sh ]; then
  echo first execution; compiling tool infrastructure (requires Java and SBT)
  sbt mkrun
fi

. run.sh  edu.cmu.typechef.busybox.AnalysisFrontend "$1" "$2" "$3"


