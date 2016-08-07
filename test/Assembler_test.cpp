#define BOOST_TEST_MODULE Assembler_test

#include <sstream>

#include <boost/test/unit_test.hpp>

#include "Assembler.h"

BOOST_AUTO_TEST_SUITE(assembling)

BOOST_AUTO_TEST_CASE(addExample) {
  std::ostringstream asmCode;
  asmCode << "@2" << std::endl
          << "D=A" << std::endl
          << "@3" << std::endl
          << "D=D+A" << std::endl
          << "@0" << std::endl
          << "M=D" << std::endl;

  std::ostringstream binCode;
  binCode << "0000000000000010" << std::endl
          << "1110110000010000" << std::endl
          << "0000000000000011" << std::endl
          << "1110000010010000" << std::endl
          << "0000000000000000" << std::endl
          << "1110001100001000" << std::endl;

  std::istringstream iss{asmCode.str()};
  std::ostringstream oss;

  Hasm::Assembler assembler{iss, oss};
  assembler.assemble();

  BOOST_CHECK_EQUAL(std::string{oss.str()}, binCode.str());
}

BOOST_AUTO_TEST_CASE(rectExample) {
  std::ostringstream asmCode;
  asmCode << "@0" << std::endl
          << "D=M" << std::endl
          << "@INFINITE_LOOP" << std::endl
          << "D;JLE" << std::endl
          << "@counter" << std::endl
          << "M=D" << std::endl
          << "@SCREEN" << std::endl
          << "D=A" << std::endl
          << "@address" << std::endl
          << "M=D" << std::endl
          << "(LOOP)" << std::endl
          << "@address" << std::endl
          << "A=M" << std::endl
          << "M=-1" << std::endl
          << "@address" << std::endl
          << "D=M" << std::endl
          << "@32" << std::endl
          << "D=D+A" << std::endl
          << "@address" << std::endl
          << "M=D" << std::endl
          << "@counter" << std::endl
          << "MD=M-1" << std::endl
          << "@LOOP" << std::endl
          << "D;JGT" << std::endl
          << "(INFINITE_LOOP)" << std::endl
          << "@INFINITE_LOOP" << std::endl
          << "0;JMP" << std::endl;

  std::ostringstream binCode;
  binCode << "0000000000000000" << std::endl
          << "1111110000010000" << std::endl
          << "0000000000010111" << std::endl
          << "1110001100000110" << std::endl
          << "0000000000010000" << std::endl
          << "1110001100001000" << std::endl
          << "0100000000000000" << std::endl
          << "1110110000010000" << std::endl
          << "0000000000010001" << std::endl
          << "1110001100001000" << std::endl
          << "0000000000010001" << std::endl
          << "1111110000100000" << std::endl
          << "1110111010001000" << std::endl
          << "0000000000010001" << std::endl
          << "1111110000010000" << std::endl
          << "0000000000100000" << std::endl
          << "1110000010010000" << std::endl
          << "0000000000010001" << std::endl
          << "1110001100001000" << std::endl
          << "0000000000010000" << std::endl
          << "1111110010011000" << std::endl
          << "0000000000001010" << std::endl
          << "1110001100000001" << std::endl
          << "0000000000010111" << std::endl
          << "1110101010000111" << std::endl;

  std::istringstream iss{asmCode.str()};
  std::ostringstream oss;

  Hasm::Assembler assembler{iss, oss};
  assembler.assemble();

  BOOST_CHECK_EQUAL(std::string{oss.str()}, binCode.str());
}

BOOST_AUTO_TEST_SUITE_END()