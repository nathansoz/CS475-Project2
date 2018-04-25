#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

if [ -f /usr/local/common/gcc-7.3.0/bin/gcc ]; then
  export CC="/usr/local/common/gcc-7.3.0/bin/gcc"
  export CXX="/usr/local/common/gcc-7.3.0/bin/g++"
fi

rm -rf ${SCRIPT_DIR}/build
mkdir ${SCRIPT_DIR}/build
pushd ${SCRIPT_DIR}/build
cmake ${SCRIPT_DIR}/src
make
popd
