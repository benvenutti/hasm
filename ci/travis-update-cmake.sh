#!/bin/bash -x

if [ "$TRAVIS_OS_NAME" == "linux" ]; then
  sudo apt-get purge cmake -y
  mkdir $HOME/usr
  export PATH="$HOME/usr/bin:$PATH"
  wget https://cmake.org/files/v3.8/cmake-3.8.2-Linux-x86_64.sh
  chmod +x cmake-3.8.2-Linux-x86_64.sh
  ./cmake-3.8.2-Linux-x86_64.sh --prefix=$HOME/usr --exclude-subdir --skip-license
fi
