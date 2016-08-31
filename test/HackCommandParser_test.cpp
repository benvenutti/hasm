#define BOOST_TEST_MODULE HackCommandParser_test

#include <boost/regex.hpp>
#include <boost/test/unit_test.hpp>

#include "HackCommandParser.h"

using namespace Hasm;

BOOST_AUTO_TEST_SUITE(label)

BOOST_AUTO_TEST_CASE(test_isLabelCommand_valid) {
  BOOST_CHECK(HackCommandParser::isLabelCommand("(_id)"));
}

BOOST_AUTO_TEST_CASE(test_isLabelCommand_invalid) {
  BOOST_CHECK_EQUAL(HackCommandParser::isLabelCommand("(_id"), false);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(computation)

BOOST_AUTO_TEST_CASE(test_isComputationCommand_validComp) {
  BOOST_CHECK(HackCommandParser::isComputationCommand("D+1"));
}

BOOST_AUTO_TEST_CASE(test_isComputationCommand_invalidComp) {
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D+X"), false);
}

BOOST_AUTO_TEST_CASE(test_isComputationCommand_validDestComp) {
  BOOST_CHECK(HackCommandParser::isComputationCommand("D=D+A"));
}

BOOST_AUTO_TEST_CASE(test_isComputationCommand_invalidDestValidComp) {
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("X=D+A"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("1=D+A"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("=D+A"), false);
}

BOOST_AUTO_TEST_CASE(test_isComputationCommand_validDestInvalidComp) {
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D=X"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D=2"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D="), false);
}

BOOST_AUTO_TEST_CASE(test_isComputationCommand_validCompJump) {
  BOOST_CHECK(HackCommandParser::isComputationCommand("D+A;JMP"));
}

BOOST_AUTO_TEST_CASE(test_isComputationCommand_invalidCompValidJump) {
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("X;JMP"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("2;JGT"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand(";JGE"), false);
}

BOOST_AUTO_TEST_CASE(test_isComputationCommand_validCompInvalidJump) {
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D;JM"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D;JG"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D;"), false);
}

BOOST_AUTO_TEST_CASE(test_isComputationCommand_validDestCompJump) {
  BOOST_CHECK(HackCommandParser::isComputationCommand("D=D+1;JMP"));
}

BOOST_AUTO_TEST_CASE(test_isComputationCommand_invalidDestValidCompValidJump) {
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("d=D+1;JMP"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("0=D+1;JMP"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("=D+1;JMP"), false);
}

BOOST_AUTO_TEST_CASE(test_isComputationCommand_validDestInvalidCompValidJump) {
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D=d+1;JMP"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D=D+;JMP"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D=;JMP"), false);
}

BOOST_AUTO_TEST_CASE(test_isComputationCommand_validDestValidCompInvalidJump) {
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D=A+1;jmp"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D=D+1;JM"), false);
  BOOST_CHECK_EQUAL(HackCommandParser::isComputationCommand("D=M+1;"), false);
}

BOOST_AUTO_TEST_SUITE_END()