#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

${SCRIPT_DIR}/build.sh

rm -rf ${SCRIPT_DIR}/run
mkdir ${SCRIPT_DIR}/run
cp ${SCRIPT_DIR}/runtimeconfig.json ${SCRIPT_DIR}/run
cp ${SCRIPT_DIR}/build/Project2/Project2 ${SCRIPT_DIR}/run

if [ -d /usr/local/common/gcc-7.3.0/lib64 ]; then
  export LD_LIBRARY_PATH="/usr/local/common/gcc-7.3.0/lib64"
fi

echo "Executing Project 2. Output to run/out.txt"
${SCRIPT_DIR}/run/Project2 > ${SCRIPT_DIR}/run/out.txt
