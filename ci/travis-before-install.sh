#!/bin/bash

if [ "$TRAVIS_OS_NAME" == "linux" ]; then
  apt-get update -qq
  apt-get install -y libboost-all-dev
fi

if [ "$IS_COVERAGE_BUILD" == 1 ]; then
  pip install --user cpp-coveralls
fi
