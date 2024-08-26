# hasm ![Build Status](https://github.com/benvenutti/hasm/actions/workflows/ci.yaml/badge.svg) <a href="https://scan.coverity.com/projects/benvenutti-hasm"><img alt="Coverity Scan Build Status" src="https://scan.coverity.com/projects/9220/badge.svg"/></a> [![Coverage Status](https://coveralls.io/repos/github/benvenutti/hasm/badge.svg?branch=master)](https://coveralls.io/github/benvenutti/hasm?branch=master) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

**hasm** stands for *Hack* Assembler, an assembler for the *Hack Platform*. This project is based on the sixth chapter of the book "The Elements of Computing System: Building a Modern Computer from First Principles", by Nisan and Schocken, where the platform is fully described. For more information, see [nand2tetris](http://www.nand2tetris.org/).

## Overview

The **hasm** assembler is a cross-platform command line tool. From a valid *.asm* file, **hasm** will generate a valid *.hack* textual binary file. This output file can then be executed in any implementation of the *Hack Platform*.

Staying true to the chapter's goal, the assembler is implemented without the help of parser generators nor tools like boost's [Spirit](https://github.com/boostorg/spirit). Some parts of the code follow the authors' suggested API. On the other hand, some parts aim for a broader implementation, leaving the original API aside.

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
$ ./hasm --input-file add.asm
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

If you feel the need to take a look at the symbol table generated during the assembling process, you can add the flag `--symbol-table` (or the shorthand `-s`) to the command line as so:

```sh
$ ./hasm --symbol-table --input-file pong.asm
```

This will generate (alongside with the assembled *pong.hack*) a text file called *pong.sym* that could look like this:

```
0x0001 LCL
0x0023 END_GT
0x0033 END_LT
0x028e LOOP_ball.setdestination
0x072d LOOP_ball.bounce
0x17f6 LOOP_keyboard.readline
0x6000 KBD
```

The *.sym* exported table will list the addresses of user defined symbols (like *END_GT* and *LOOP_ball.bounce* in the  example above), as well as *Hack* predefined symbols, like *KBD* and *LCL*, etc. for instance.

#### Example 3: getting help

Running **hasm** in the command line with the argument `--help` (or the shorthand `-h`) will print the usage message:

```
$ ./hasm --help
hasm: assembler for the nand2tetris hack platform
Usage: ./hasm [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -i,--input-file TEXT        input .asm file
  -s,--symbol-table Needs: --input-file
                              export symbol table (to <input file>.sym)
  -v,--version                Display program version information and exit
```

## Building **hasm** from source

The assembler is written in C++20 and uses [CMake](https://cmake.org/) to manage the building process. Aside from the C++ Standard Library, **hasm** uses [CLI11](https://github.com/CLIUtils/CLI11) and [Catch2](https://github.com/catchorg/Catch2).

The following list enumerates the tools and dependencies' minimum requirements:

* C++20 compiler
* CMake 3.25 or higher
* CLI11 (managed by the main CMake script)
* Catch2 (managed by the main CMake script)

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
