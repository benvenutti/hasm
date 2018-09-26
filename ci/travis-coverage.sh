#!/bin/bash

# To verify the collected data, first capture the data (the dollar
# symbol '$' here identifies a shell command):
#
# $ lcov --gcov-tool GCOV -d SOURCE_FOLDER -c -o coverage.info
#
# ...where GCOV is the absolute path to the gcov binary and SOURCE_FOLDER
# is the path to the root of the source code. Make sure the gcov version is
# a perfect match to the compiler used, z.B. gcov-6 to gcc-6, gcov-7 to
# gcc-7, etc.
#
# Once the coverage.info file is generated, remove unwanted paths from
# it by doing:
#
# $ lcov --gcov-tool GCOV -r coverage.info '/usr/*' 'tests/*' -o coverage.info
#
# In this example we remove the absolute path '/usr/' and the relative path
# 'tests' (relative to the SOURCE_FOLDER) recursively from the coverage
# data.
#
# Finally, every step on the way can be debugged by:
#
# $ lcov --gcov-tool GCOV -l coverage.info
#
# This will print all files that are part of the report, along with the
# coverage information.

if [ "$BUILD_TYPE" == "Coverage" ]; then
  lcov --gcov-tool $(which ${GCOV}) -d . -c -o coverage.info
  bash <(curl -s https://codecov.io/bash) -X gcov || echo "Codecov did not collect coverage reports"
fi
