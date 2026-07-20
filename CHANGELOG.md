# Changelog

All notable changes to this project will be documented in this file.

## [Unreleased]

### Added

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

- Coverity Scan issues
- CMake warnings
- Illegal memory access in assembler engine
- Coverity is triggered when a pr is opened
- Coverage flags are set for non coverage builds
- Wrong call to make Catch2 available

## [0.2.1] - Jul 23, 2018

Log not available

## [0.2.0] - Nov 19, 2016

Log not available

## [0.1.0] - Aug 8, 2016

Log not available

[Unreleased]: https://github.com/benvenutti/hasm/compare/v0.2.1...HEAD
[0.2.1]: https://github.com/benvenutti/hasm/compare/v0.2...v0.2.1
[0.2.0]: https://github.com/benvenutti/hasm/compare/v0.1...v0.2
[0.1.0]: https://github.com/benvenutti/hasm/compare/48222141a2ba7e2d7ae0a433914cf3459f9c4051...0.1
