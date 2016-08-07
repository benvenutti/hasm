# hasm [![Build Status](https://travis-ci.org/benvenutti/hasm.svg?branch=development)](https://travis-ci.org/benvenutti/hasm) [![Build status](https://ci.appveyor.com/api/projects/status/xvvgrlygu5hofm75?svg=true)](https://ci.appveyor.com/project/benvenutti/hasmtest) <a href="https://scan.coverity.com/projects/benvenutti-hasm"><img alt="Coverity Scan Build Status" src="https://scan.coverity.com/projects/9220/badge.svg"/></a> [![Coverage Status](https://coveralls.io/repos/github/benvenutti/hasm/badge.svg?branch=development)](https://coveralls.io/github/benvenutti/hasm?branch=development)

**hasm** stands for Hack Assembler, an assembler for the Hack platform. This project is based on the sixth chapter of the book "The Elements of Computing System: Building a Modern Computer from First Principles", by Nisan and Schocken, where the Hack platform is fully described. For more information, see [nand2tetris](http://www.nand2tetris.org/).

## Overview

The **hasm** assembler is a command line executable. From a valid *.asm* file, **hasm** will generate a valid *.hack* textual binary file. This output file can then be executed in any implementation of the Hack platform.

### Example 1: assembling a file

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

### Example 2: getting help

Running **hasm** in the command line with the argument *--help* (or the shorthand *-h*) will print the usage message:

```
$ ./hasm --help
Usage: hasm [options] <input file>.asm
Allowed options:
  -s [ --symbol-table ]   export symbol table (to <input file>.sym)
  -i [ --input-file ] arg input .asm file
  -h [ --help ]           print this help message
```
