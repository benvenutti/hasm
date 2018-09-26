#!/bin/bash

if [ "$BUILD_TYPE" == "Coverage" ]; then
  cd ${TRAVIS_BUILD_DIR}
  tool="--gcov-tool $(which ${GCOV})"
  lcov ${tool} -d . -c -o coverage.info
  lcov ${tool} -r coverage.info '/usr/*' 'tests/*' 'libs/*' -o coverage.info
  lcov ${tool} -l coverage.info
  bash <(curl -s https://codecov.io/bash) -X gcov || echo "Codecov did not collect coverage reports"
fi
