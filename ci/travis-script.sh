#!/bin/bash -x

if [ "$COVERITY_SCAN_BRANCH" == 1 ]; then
  cat /home/travis/build/benvenutti/hasmTest/build/cov-int/scm_log.txt
  exit 0
fi

if [ "$IS_COVERAGE_BUILD" == 1 ]; then
  flags="-g -O0 --coverage"
  cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="$flags" -DCMAKE_CXX_COMPILER=$COMPILER .
elif [ "$TRAVIS_OS_NAME" == "linux" ]; then
  mkdir build && cd build

  if [ "$COMPILER" == "clang++" ]; then
    cmake -DCMAKE_CXX_COMPILER=$COMPILER -DCMAKE_CXX_FLAGS="-stdlib=libc++" ..
  else
    cmake -DCMAKE_CXX_COMPILER=$COMPILER ..
  fi

elif [ "$TRAVIS_OS_NAME" == "osx" ]; then
  mkdir build && cd build
  cmake ..
fi

make
make test CTEST_OUTPUT_ON_FAILURE=TRUE