#define BOOST_TEST_MODULE Assembler_test

#include <sstream>

#include <boost/test/unit_test.hpp>

#include "Assembler.h"

BOOST_AUTO_TEST_SUITE(assembling)

BOOST_AUTO_TEST_CASE(codeToBinary) {
  const std::string code{"@2 \n D=A \n @3 \n D=D+A \n @0"};

  const std::string bin{
    "0000000000000010\n1110110000010000\n0000000000000011\n1110000010010000\n0000000000000000\n"
  };

  std::istringstream iss{code};
  std::ostringstream oss;

  Hasm::Assembler assembler{iss, oss};
  assembler.assemble();

  BOOST_CHECK_EQUAL(std::string{oss.str()}, bin);
}

BOOST_AUTO_TEST_SUITE_END()