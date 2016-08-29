#define BOOST_TEST_MODULE HackLex_test

#include <regex>

#include <boost/test/unit_test.hpp>

#include "HackLex.h"

BOOST_AUTO_TEST_SUITE(destinations)

BOOST_AUTO_TEST_CASE(test_destinationA) {
  std::regex destA{Hack::Lex::DEST_A};
  BOOST_CHECK(std::regex_match("A", destA));
}

BOOST_AUTO_TEST_CASE(test_destinationD) {
  std::regex destD{Hack::Lex::DEST_D};
  BOOST_CHECK(std::regex_match("D", destD));
}

BOOST_AUTO_TEST_CASE(test_destinationM) {
  std::regex destM{Hack::Lex::DEST_M};
  BOOST_CHECK(std::regex_match("M", destM));
}

BOOST_AUTO_TEST_CASE(test_invalidDestinationA) {
  std::regex destA{Hack::Lex::DEST_A};
  BOOST_CHECK_EQUAL(std::regex_match("a", destA), false);
  BOOST_CHECK_EQUAL(std::regex_match("A_", destA), false);
  BOOST_CHECK_EQUAL(std::regex_match("_A", destA), false);
}

BOOST_AUTO_TEST_CASE(test_invalidDestinationD) {
  std::regex destD{Hack::Lex::DEST_D};
  BOOST_CHECK_EQUAL(std::regex_match("d", destD), false);
  BOOST_CHECK_EQUAL(std::regex_match("D_", destD), false);
  BOOST_CHECK_EQUAL(std::regex_match("_D", destD), false);
}

BOOST_AUTO_TEST_CASE(test_invalidDestinationM) {
  std::regex destM{Hack::Lex::DEST_M};
  BOOST_CHECK_EQUAL(std::regex_match("m", destM), false);
  BOOST_CHECK_EQUAL(std::regex_match("_M", destM), false);
  BOOST_CHECK_EQUAL(std::regex_match("M_", destM), false);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(jumps)

BOOST_AUTO_TEST_CASE(test_validJGT) {
  std::regex jumpJGT{Hack::Lex::JUMP_JGT};
  BOOST_CHECK(std::regex_match("JGT", jumpJGT));
}

BOOST_AUTO_TEST_CASE(test_invalidJGT) {
  std::regex jumpJGT{Hack::Lex::JUMP_JGT};
  BOOST_CHECK_EQUAL(std::regex_match("jgt", jumpJGT), false);
  BOOST_CHECK_EQUAL(std::regex_match("_JGT", jumpJGT), false);
  BOOST_CHECK_EQUAL(std::regex_match("JGT_", jumpJGT), false);
}

BOOST_AUTO_TEST_CASE(test_validJGE) {
  std::regex jumpJGE{Hack::Lex::JUMP_JGE};
  BOOST_CHECK(std::regex_match("JGE", jumpJGE));
}

BOOST_AUTO_TEST_CASE(test_invalidJGE) {
  std::regex jumpJGE{Hack::Lex::JUMP_JGE};
  BOOST_CHECK_EQUAL(std::regex_match("jge", jumpJGE), false);
  BOOST_CHECK_EQUAL(std::regex_match("_JGE", jumpJGE), false);
  BOOST_CHECK_EQUAL(std::regex_match("JGE_", jumpJGE), false);
}

BOOST_AUTO_TEST_CASE(test_validJLT) {
  std::regex jumpJLT{Hack::Lex::JUMP_JLT};
  BOOST_CHECK(std::regex_match("JLT", jumpJLT));
}

BOOST_AUTO_TEST_CASE(test_invalidJLT) {
  std::regex jumpJLT{Hack::Lex::JUMP_JLT};
  BOOST_CHECK_EQUAL(std::regex_match("jlt", jumpJLT), false);
  BOOST_CHECK_EQUAL(std::regex_match("_JLT", jumpJLT), false);
  BOOST_CHECK_EQUAL(std::regex_match("JLT_", jumpJLT), false);
}

BOOST_AUTO_TEST_CASE(test_validJLE) {
  std::regex jumpJLE{Hack::Lex::JUMP_JLE};
  BOOST_CHECK(std::regex_match("JLE", jumpJLE));
}

BOOST_AUTO_TEST_CASE(test_invalidJLE) {
  std::regex jumpJLE{Hack::Lex::JUMP_JLE};
  BOOST_CHECK_EQUAL(std::regex_match("jle", jumpJLE), false);
  BOOST_CHECK_EQUAL(std::regex_match("_JLE", jumpJLE), false);
  BOOST_CHECK_EQUAL(std::regex_match("JLE_", jumpJLE), false);
}

BOOST_AUTO_TEST_CASE(test_validJEQ) {
  std::regex jumpJEQ{Hack::Lex::JUMP_JEQ};
  BOOST_CHECK(std::regex_match("JEQ", jumpJEQ));
}

BOOST_AUTO_TEST_CASE(test_invalidJEQ) {
  std::regex jumpJEQ{Hack::Lex::JUMP_JEQ};
  BOOST_CHECK_EQUAL(std::regex_match("jeq", jumpJEQ), false);
  BOOST_CHECK_EQUAL(std::regex_match("_JEQ", jumpJEQ), false);
  BOOST_CHECK_EQUAL(std::regex_match("JEQ_", jumpJEQ), false);
}

BOOST_AUTO_TEST_CASE(test_validJNE) {
  std::regex jumpJNE{Hack::Lex::JUMP_JNE};
  BOOST_CHECK(std::regex_match("JNE", jumpJNE));
}

BOOST_AUTO_TEST_CASE(test_invalidJNE) {
  std::regex jumpJNE{Hack::Lex::JUMP_JNE};
  BOOST_CHECK_EQUAL(std::regex_match("jne", jumpJNE), false);
  BOOST_CHECK_EQUAL(std::regex_match("_JNE", jumpJNE), false);
  BOOST_CHECK_EQUAL(std::regex_match("JNE_", jumpJNE), false);
}

BOOST_AUTO_TEST_CASE(test_validJMP) {
  std::regex jumpJMP{Hack::Lex::JUMP_JMP};
  BOOST_CHECK(std::regex_match("JMP", jumpJMP));
}

BOOST_AUTO_TEST_CASE(test_invalidJMP) {
  std::regex jumpJMP{Hack::Lex::JUMP_JMP};
  BOOST_CHECK_EQUAL(std::regex_match("jmp", jumpJMP), false);
  BOOST_CHECK_EQUAL(std::regex_match("_JMP", jumpJMP), false);
  BOOST_CHECK_EQUAL(std::regex_match("JMP_", jumpJMP), false);
}

BOOST_AUTO_TEST_SUITE_END()