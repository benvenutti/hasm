# Changelog

All notable changes to this project will be documented in this file.

## [Unreleased]

### Added

- GitHub pull request template

### Changed

### Removed

### Fixed

## [0.3.0] - Jul 20, 2026

### Added

- Added TODO list
- Project default target settings
- Group target properties calls in cmake
- Define hack hardware related target
- Warnings as errors
- Introduce Logger to the Assembler 
- Add BUILD_APP_COMMAND_LINE build option
- Add Coverity Scan
- Add code coverage
- CLI11 for parsing arguments
- Add CMake option to enable or disable building tests
- Add gitattributes
- Enable release builds in github workflow
- CI with GitHub workflows

### Changed

- Rename hack command parser class
- Use logger solely in the backend
- Refactor:
  - Parser class
  - Version config file
  - Command line parser tests
  - Command line parser
- Move command line parser out of hasm
- Update README
- Modernize parser class
- Modernize error message
- Drop all caps from constants
- Switch from C++17 to C++20
- Fetch catch2 only if building tests
- Modernize symbol table class
- Modernize Coder class
- Refactor file handler class
- Refactor assembler engine config class
- Update clang-format style to add spaces for angle brackets
- Split project into backend and application
- Drop boost::regex in favour of std::regex
- Switch from C++14 to C++17

### Removed

- Disabling warning for c4702
- cdash
- Scripts from AppVeyor and travis
- Catch2 submodule

### Fixed

- Failing macOS build: bump CLI11 to v2.6.2
- Coverity Scan issues
- CMake warnings
- Illegal memory access in assembler engine
- Coverity is triggered when a pr is opened
- Coverage flags are set for non coverage builds
- Wrong call to make Catch2 available

## [0.2.1] - Jul 23, 2018

### Added

- Log tests results on dashboard
- Add clang-format file
- Add c++14 support
- Add license badge to README
- Add clang 3.6 and 3.7 to Travis build

### Changed

- Use Catch2 for unit tests
- Refactor CMake scripts
- Sort exported symbol table by address
- Refactor Hack lexical expressions into smaller units
- Refactor using clang-tidy

### Fixed

- Wrong values for predefined Hack symbols

## [0.2.0] - Nov 19, 2016

### Added

- Add version flag to command line
- Error messages for invalid assembly code
- Introduce CMake lib target to enable unit testing

### Changed

- Refactor coding style
- Remove IDE folder
- Load instruction accepts integers bigger than 15 bits
- Decouple AssemblerEngine from command line arguments
- Load command accepts negative numbers

### Fixed

- Duplicated compiler flag
- The assembler accepts invalid symbols
- The assembler accepts invalid computations
- Program exits with wrong value
- Exported symbol table has wrong string format

## [0.1.0] - Aug 8, 2016

Log not available

[Unreleased]: https://github.com/benvenutti/hasm/compare/v0.3.0...HEAD
[0.3.0]: https://github.com/benvenutti/hasm/compare/v0.2.1...v0.3.0
[0.2.1]: https://github.com/benvenutti/hasm/compare/v0.2.0...v0.2.1
[0.2.0]: https://github.com/benvenutti/hasm/compare/v0.1.0...v0.2.0
[0.1.0]: https://github.com/benvenutti/hasm/compare/48222141a2ba7e2d7ae0a433914cf3459f9c4051...v0.1.0
