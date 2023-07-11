#!/bin/bash
DIR=`pwd`
if [ -d build ]; then
  rm -rf build
fi
mkdir build
cp -r config/ build/conf/

# Support the arm compile, if the arm plaform need to be supported, please
# enable the CMAKE_COMMAND
# CMAKE_COMMAND=-DTEST_TOOLCHAIN_ROOT=/home/softwares

cd $DIR/build
cmake .. $CMAKE_COMMAND
make -j18
cd $DIR