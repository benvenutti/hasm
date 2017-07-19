#!/bin/bash -x

if [ "$TRAVIS_OS_NAME" == "linux" ]; then
  sudo -E apt-get update -qq
  sudo -E apt-get install -y libboost-all-dev

  mkdir $HOME/usr
  export PATH="$HOME/usr/bin:$PATH"
  wget https://cmake.org/files/v3.8/cmake-3.8.2-Linux-x86_64.sh
  chmod +x cmake-3.8.2-Linux-x86_64.sh
  ./cmake-3.8.2-Linux-x86_64.sh --prefix=$HOME/usr --exclude-subdir --skip-license
fi

if [ "$IS_COVERAGE_BUILD" == 1 ]; then
  pip install --user cpp-coveralls
fi
