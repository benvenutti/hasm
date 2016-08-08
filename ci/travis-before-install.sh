#!/bin/bash -x

if [ "$TRAVIS_OS_NAME" == "linux" ]; then
  sudo -E apt-get update -qq
  sudo -E apt-get install -y libboost-all-dev
fi

if [ "$IS_COVERAGE_BUILD" == 1 ]; then
  pip install --user cpp-coveralls
fi
