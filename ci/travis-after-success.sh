#!/bin/bash -x

if [ "$IS_COVERAGE_BUILD" == 1 ]; then
  coveralls --exclude libs --gcov-options '\-lp'
fi
