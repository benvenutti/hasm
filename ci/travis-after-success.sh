#!/bin/bash

set -v

if [ "$BUILD_TYPE" == "Coverage" ]; then
  gcovtool="--gcov $(which ${GCOV})"
  excludes="--exclude tests --exclude libs"
  rootdirs="--root .. --build-root ."
  gcovopts="--gcov-options '\-lp'"
  coveralls ${gcovtool} ${excludes} ${rootdirs} ${gcovopts}
fi
