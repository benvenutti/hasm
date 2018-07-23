# hasm [![Build Status](https://travis-ci.org/benvenutti/hasm.svg?branch=master)](https://travis-ci.org/benvenutti/hasm) [![Build status](https://ci.appveyor.com/api/projects/status/xvvgrlygu5hofm75?svg=true)](https://ci.appveyor.com/project/benvenutti/hasmtest) <a href="https://scan.coverity.com/projects/benvenutti-hasm"><img alt="Coverity Scan Build Status" src="https://scan.coverity.com/projects/9220/badge.svg"/></a> [![Coverage Status](https://coveralls.io/repos/github/benvenutti/hasm/badge.svg?branch=master)](https://coveralls.io/github/benvenutti/hasm?branch=master) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT) [![CDash](https://img.shields.io/badge/dashboard-cdash-blue.svg)](https://my.cdash.org/index.php?project=hasm)

**hasm** stands for *Hack* Assembler, an assembler for the *Hack Platform*. This project is based on the sixth chapter of the book "The Elements of Computing System: Building a Modern Computer from First Principles", by Nisan and Schocken, where the platform is fully described. For more information, see [nand2tetris](http://www.nand2tetris.org/).

## Overview

The **hasm** assembler is a command line executable. From a valid *.asm* file, **hasm** will generate a valid *.hack* textual binary file. This output file can then be executed in any implementation of the *Hack Platform*.

Staying true to the chapter's goal, the assembler is implemented without the help of parser generators nor tools like boost's [Spirit](http://www.boost.org/doc/libs/1_62_0/libs/spirit/doc/html/index.html). Some parts of the code follow the authors' suggested API. On the other hand, some parts aim for a broader implementation, leaving the original API aside.

**hasm** goes a bit further than the assembler described in the book, offering the extra functionalities:

1. code analysis (lexical, syntactic and *a tiny bit of semantic*) with error messages;
2. ability to export the symbol table to a file.

## Examples

#### Example 1: assembling a file

Let us take it that there is a file named *add.asm* with the following Hack assembly machine language program:

```sh
@2
D=A
@3
D=D+A
@0
M=D
```

We can run the assembler from the command line, passing the path for the source file as an argument:

```sh
$ ./hasm add.asm
```

This will generate an output file called *add.hack*, with the following content:

```sh
0000000000000010
1110110000010000
0000000000000011
1110000010010000
0000000000000000
1110001100001000
```

This file can then be loaded into any Hack-compliance machine and it will correctly reflect the logic of the program described in the source file.

#### Example 2: exporting the symbol table

If we feel the need to take a look at the symbol table generated during the assembling process, we can add the flag *&#8209;&#8209;symbol&#8209;table* (or the shorthand *&#8209;s*) to the command line as so:

```sh
$ ./hasm -s pong.asm
```

This will generate (alongside with the assembled *pong.hack*) a text file called *pong.sym* that might look like this:

```
0x0001 LCL
0x0023 END_GT
0x0033 END_LT
0x028e LOOP_ball.setdestination
0x072d LOOP_ball.bounce
0x17f6 LOOP_keyboard.readline
0x6000 KBD
```

The *.sym* exported table will list the addresses of user defined symbols (like *END_GT* and *LOOP_ball.bounce* in the  example above), as well as *Hack* predefined symbols, like *KBD* and *LCL*, for instance.

#### Example 3: getting help

Running **hasm** in the command line with the argument *&#8209;&#8209;help* (or the shorthand *&#8209;h*) will print the usage message:

```
$ ./hasm --help
Usage: hasm [options] <input file>.asm
Allowed options:
  -s [ --symbol-table ]   export symbol table (to <input file>.sym)
  -i [ --input-file ] arg input .asm file
  -h [ --help ]           print this help message
  -v [ --version]         print version number
```

## Building **hasm** from source

The assembler is written in C++14 and uses [CMake](https://cmake.org/) to manage the building process. Aside from the C++ Standard Library, **hasm** uses [Boost](http://www.boost.org/) and [Catch2](https://github.com/catchorg/Catch2).

The following list enumerates the tools and dependencies' minimum requirements:

* c++14 compiler
* cmake 3.6
* libboost 1.54.0 (components: *filesystem*, *program_options*, *regex*, *system*)
* Catch2 (this is a submodule of the project)

### Cloning

Make sure to clone the repository with its submodules. One way to do this is as follows:

```shh
git clone --recurse-submodules https://github.com/benvenutti/hasm.git
```

### Cross-platform

One of the goals of **hasm** is to be a cross-platform project. The following table presents the operating systems and the compilers used in continuous integration at [Travis](https://travis-ci.org/benvenutti/hasm/) and [AppVeyor](https://ci.appveyor.com/project/benvenutti/hasmtest):

| Compiler        | Operating System             | Version String |
|-----------------|------------------------------|----------------|
| GCC 4.8.5       | Ubuntu 14.04.5 LTS           | g++-4.8 (Ubuntu 4.8.5-2ubuntu1~14.04.1) 4.8.5 |
| GCC 4.9.3       | Ubuntu 14.04.5 LTS           | g++-4.9 (Ubuntu 4.9.3-8ubuntu2~14.04) 4.9.3 |
| GCC 5.3.0       | Ubuntu 14.04.5 LTS           | g++-5 (Ubuntu 5.3.0-3ubuntu1~14.04) 5.3.0 20151204 |
| GCC 6.1.1       | Ubuntu 14.04.5 LTS           | g++-6 (Ubuntu 6.1.1-3ubuntu11~14.04.1) 6.1.1 20160511 |
| Clang 3.7.1     | Ubuntu 14.04.5 LTS           | clang version 3.7.1-svn253571-1~exp1 (branches/release_37) |
| Clang 5.0.0     | Ubuntu 14.04.5 LTS           | clang version 5.0.0 (tags/RELEASE_500/final) |
| Clang Xcode 7.3.1 | Darwin Kernel Version 15.6.0 (OS X 10.11)           | Apple LLVM version 7.3.0 (clang-703.0.31) |
| Clang Xcode 8.0 beta 4 | Darwin Kernel Version 15.6.0 (OS X 10.11)           | Apple LLVM version 8.0.0 (clang-800.0.38) |
| Visual Studio 14 2015 | Windows Server 2012 R2 (x86)          | Microsoft (R) Build Engine version 14.0.25420.1 |
| Visual Studio 14 2015 Win64 | Windows Server 2012 R2 (x64)          | Microsoft (R) Build Engine version 14.0.25420.1 |

### Compiling

Run the classic **cmake + make** on the source directory. It is recommend to run **cmake** from out of source, that is, usually from a *build* directory inside the source directory. Here is an example on Linux:

```shh
hasm$ mkdir build
hasm$ cd build
hasm/build$ cmake ..
hasm/build$ cmake --build .
```

### Running tests

To run the available test suite, first make sure the configuration option *BUILD_TESTING* was properly set (its default value is *ON*) . After a successful build, you need to execute the *test* target using **ctest** from CMake, like this:

```shh
Running tests...
Test project /Users/diogo.benvenutti/draft/hasm/build
    Start 1: HasmTestSuite
1/1 Test #1: HasmTestSuite ....................   Passed    0.01 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.02 sec
```
