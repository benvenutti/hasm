#!/bin/bash

set -x

if [ "$BUILD_TYPE" == "Coverage" ]; then
  cd ${TRAVIS_BUILD_DIR}
  pwd
  ls
  gcovtool="--gcov $(which ${GCOV})"
  excludes="-e tests -e libs -e build/include -e build/CMakeFiles"
  rootdirs="--root . --build-root build"
  coveralls ${gcovtool} ${excludes} ${rootdirs} --gcov-options '\-lp'
fi
