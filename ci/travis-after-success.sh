#!/bin/bash

set -x

if [ "$BUILD_TYPE" == "Coverage" ]; then
  cd ${TRAVIS_BUILD_DIR}
  pwd
  ls
  gcovtool="--gcov $(which ${GCOV})"
  excludes="--exclude tests --exclude libs"
  rootdirs="--root . --build-root build"
  gcovopts="--gcov-options '\-lp'"
  coveralls ${gcovtool} ${excludes} ${rootdirs} ${gcovopts}
fi
