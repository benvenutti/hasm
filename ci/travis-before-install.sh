#!/bin/bash

set -v

if [ "$BUILD_TYPE" == "Coverage" ]; then
  pip install cpp-coveralls --user $(whoami)
fi
