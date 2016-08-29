#define BOOST_TEST_MODULE HackLex_test

#include <boost/regex.hpp>
#include <boost/test/unit_test.hpp>

#include "HackLex.h"

BOOST_AUTO_TEST_SUITE(destinations)

BOOST_AUTO_TEST_CASE(test_destinationA) {
  boost::regex destA{Hack::Lex::DEST_A};
  BOOST_CHECK(boost::regex_match("A", destA));
}

BOOST_AUTO_TEST_CASE(test_destinationD) {
  boost::regex destD{Hack::Lex::DEST_D};
  BOOST_CHECK(boost::regex_match("D", destD));
}

BOOST_AUTO_TEST_CASE(test_destinationM) {
  boost::regex destM{Hack::Lex::DEST_M};
  BOOST_CHECK(boost::regex_match("M", destM));
}

BOOST_AUTO_TEST_CASE(test_invalidDestinationA) {
  boost::regex destA{Hack::Lex::DEST_A};
  BOOST_CHECK_EQUAL(boost::regex_match("a", destA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("A_", destA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_A", destA), false);
}

BOOST_AUTO_TEST_CASE(test_invalidDestinationD) {
  boost::regex destD{Hack::Lex::DEST_D};
  BOOST_CHECK_EQUAL(boost::regex_match("d", destD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D_", destD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_D", destD), false);
}

BOOST_AUTO_TEST_CASE(test_invalidDestinationM) {
  boost::regex destM{Hack::Lex::DEST_M};
  BOOST_CHECK_EQUAL(boost::regex_match("m", destM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_M", destM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("M_", destM), false);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(jumps)

BOOST_AUTO_TEST_CASE(test_validJGT) {
  boost::regex jumpJGT{Hack::Lex::JUMP_JGT};
  BOOST_CHECK(boost::regex_match("JGT", jumpJGT));
}

BOOST_AUTO_TEST_CASE(test_invalidJGT) {
  boost::regex jumpJGT{Hack::Lex::JUMP_JGT};
  BOOST_CHECK_EQUAL(boost::regex_match("jgt", jumpJGT), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JGT", jumpJGT), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JGT_", jumpJGT), false);
}

BOOST_AUTO_TEST_CASE(test_validJGE) {
  boost::regex jumpJGE{Hack::Lex::JUMP_JGE};
  BOOST_CHECK(boost::regex_match("JGE", jumpJGE));
}

BOOST_AUTO_TEST_CASE(test_invalidJGE) {
  boost::regex jumpJGE{Hack::Lex::JUMP_JGE};
  BOOST_CHECK_EQUAL(boost::regex_match("jge", jumpJGE), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JGE", jumpJGE), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JGE_", jumpJGE), false);
}

BOOST_AUTO_TEST_CASE(test_validJLT) {
  boost::regex jumpJLT{Hack::Lex::JUMP_JLT};
  BOOST_CHECK(boost::regex_match("JLT", jumpJLT));
}

BOOST_AUTO_TEST_CASE(test_invalidJLT) {
  boost::regex jumpJLT{Hack::Lex::JUMP_JLT};
  BOOST_CHECK_EQUAL(boost::regex_match("jlt", jumpJLT), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JLT", jumpJLT), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JLT_", jumpJLT), false);
}

BOOST_AUTO_TEST_CASE(test_validJLE) {
  boost::regex jumpJLE{Hack::Lex::JUMP_JLE};
  BOOST_CHECK(boost::regex_match("JLE", jumpJLE));
}

BOOST_AUTO_TEST_CASE(test_invalidJLE) {
  boost::regex jumpJLE{Hack::Lex::JUMP_JLE};
  BOOST_CHECK_EQUAL(boost::regex_match("jle", jumpJLE), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JLE", jumpJLE), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JLE_", jumpJLE), false);
}

BOOST_AUTO_TEST_CASE(test_validJEQ) {
  boost::regex jumpJEQ{Hack::Lex::JUMP_JEQ};
  BOOST_CHECK(boost::regex_match("JEQ", jumpJEQ));
}

BOOST_AUTO_TEST_CASE(test_invalidJEQ) {
  boost::regex jumpJEQ{Hack::Lex::JUMP_JEQ};
  BOOST_CHECK_EQUAL(boost::regex_match("jeq", jumpJEQ), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JEQ", jumpJEQ), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JEQ_", jumpJEQ), false);
}

BOOST_AUTO_TEST_CASE(test_validJNE) {
  boost::regex jumpJNE{Hack::Lex::JUMP_JNE};
  BOOST_CHECK(boost::regex_match("JNE", jumpJNE));
}

BOOST_AUTO_TEST_CASE(test_invalidJNE) {
  boost::regex jumpJNE{Hack::Lex::JUMP_JNE};
  BOOST_CHECK_EQUAL(boost::regex_match("jne", jumpJNE), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JNE", jumpJNE), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JNE_", jumpJNE), false);
}

BOOST_AUTO_TEST_CASE(test_validJMP) {
  boost::regex jumpJMP{Hack::Lex::JUMP_JMP};
  BOOST_CHECK(boost::regex_match("JMP", jumpJMP));
}

BOOST_AUTO_TEST_CASE(test_invalidJMP) {
  boost::regex jumpJMP{Hack::Lex::JUMP_JMP};
  BOOST_CHECK_EQUAL(boost::regex_match("jmp", jumpJMP), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JMP", jumpJMP), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JMP_", jumpJMP), false);
}

BOOST_AUTO_TEST_SUITE_END()