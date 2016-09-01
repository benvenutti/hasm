#define BOOST_TEST_MODULE HackLex_test

#include <boost/regex.hpp>
#include <boost/test/unit_test.hpp>

#include "HackLex.h"

BOOST_AUTO_TEST_SUITE(identifiers)

BOOST_AUTO_TEST_CASE(test_validId_startsWithLetter) {
  boost::regex id{Hack::Lex::ID};
  BOOST_CHECK(boost::regex_match("id", id));
}

BOOST_AUTO_TEST_CASE(test_validId_startsWithUnderscore) {
  boost::regex id{Hack::Lex::ID};
  BOOST_CHECK(boost::regex_match("_id", id));
}

BOOST_AUTO_TEST_CASE(test_validId_startsWithDot) {
  boost::regex id{Hack::Lex::ID};
  BOOST_CHECK(boost::regex_match(".id", id));
}

BOOST_AUTO_TEST_CASE(test_validId_startsWithDollarSign) {
  boost::regex id{Hack::Lex::ID};
  BOOST_CHECK(boost::regex_match("$id", id));
}

BOOST_AUTO_TEST_CASE(test_validId_startsWithColon) {
  boost::regex id{Hack::Lex::ID};
  BOOST_CHECK(boost::regex_match(":id", id));
}

BOOST_AUTO_TEST_CASE(test_invalidId_startsWithDigit) {
  boost::regex id{Hack::Lex::ID};
  BOOST_CHECK_EQUAL(boost::regex_match("2id", id), false);
}

BOOST_AUTO_TEST_CASE(test_validId_withLettersAndDigits) {
  boost::regex id{Hack::Lex::ID};
  BOOST_CHECK(boost::regex_match("ab12cd34", id));
}

BOOST_AUTO_TEST_CASE(test_validId_withAllValidCharacters) {
  boost::regex id{Hack::Lex::ID};
  BOOST_CHECK(boost::regex_match("ab12_.$:cd34", id));
}

BOOST_AUTO_TEST_CASE(test_invalidId_withInvalidCharacter) {
  boost::regex id{Hack::Lex::ID};
  BOOST_CHECK_EQUAL(boost::regex_match("id@", id), false);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(integers)

BOOST_AUTO_TEST_CASE(test_validInteger) {
  boost::regex integer{Hack::Lex::INTEGER};
  BOOST_CHECK(boost::regex_match("0", integer));
  BOOST_CHECK(boost::regex_match("9", integer));
  BOOST_CHECK(boost::regex_match("10", integer));
  BOOST_CHECK(boost::regex_match("111", integer));
}

BOOST_AUTO_TEST_CASE(test_invalidInteger_invalidDigits) {
  boost::regex integer{Hack::Lex::INTEGER};
  BOOST_CHECK_EQUAL(boost::regex_match("10A20", integer));
}

BOOST_AUTO_TEST_CASE(test_invalidInteger_signedNegative) {
  boost::regex integer{Hack::Lex::INTEGER};
  BOOST_CHECK_EQUAL(boost::regex_match("-1", integer));
}

BOOST_AUTO_TEST_CASE(test_invalidInteger_signedNegative) {
  boost::regex integer{Hack::Lex::INTEGER};
  BOOST_CHECK_EQUAL(boost::regex_match("+1", integer));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(symbols)

BOOST_AUTO_TEST_CASE(test_validSemicolon) {
  boost::regex symbol{Hack::Lex::SEMICOLON};
  BOOST_CHECK(boost::regex_match(";", symbol));
}

BOOST_AUTO_TEST_CASE(test_invalidSemicolon) {
  boost::regex symbol{Hack::Lex::SEMICOLON};
  BOOST_CHECK_EQUAL(boost::regex_match("a", symbol), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", symbol), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+", symbol), false);
}

BOOST_AUTO_TEST_CASE(test_validEqual) {
  boost::regex symbol{Hack::Lex::EQUAL};
  BOOST_CHECK(boost::regex_match("=", symbol));
}

BOOST_AUTO_TEST_CASE(test_invalidEqual) {
  boost::regex symbol{Hack::Lex::EQUAL};
  BOOST_CHECK_EQUAL(boost::regex_match("a", symbol), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", symbol), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+", symbol), false);
}

BOOST_AUTO_TEST_CASE(test_validLeftParen) {
  boost::regex symbol{Hack::Lex::LEFT_PAREN};
  BOOST_CHECK(boost::regex_match("(", symbol));
}

BOOST_AUTO_TEST_CASE(test_invalidLeftParen) {
  boost::regex symbol{Hack::Lex::EQUAL};
  BOOST_CHECK_EQUAL(boost::regex_match(")", symbol), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a", symbol), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", symbol), false);
  BOOST_CHECK_EQUAL(boost::regex_match("", symbol), false);
}

BOOST_AUTO_TEST_CASE(test_validRightParen) {
  boost::regex symbol{Hack::Lex::RIGHT_PAREN};
  BOOST_CHECK(boost::regex_match(")", symbol));
}

BOOST_AUTO_TEST_CASE(test_invalidRightParen) {
  boost::regex symbol{Hack::Lex::RIGHT_PAREN};
  BOOST_CHECK_EQUAL(boost::regex_match("(", symbol), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a", symbol), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", symbol), false);
  BOOST_CHECK_EQUAL(boost::regex_match("", symbol), false);
}

BOOST_AUTO_TEST_SUITE_END()

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

BOOST_AUTO_TEST_SUITE(computations)

BOOST_AUTO_TEST_CASE(test_validZero) {
  boost::regex comp{Hack::Lex::COMP_ZERO};
  BOOST_CHECK(boost::regex_match("0", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidZero) {
  boost::regex comp{Hack::Lex::COMP_ZERO};
  BOOST_CHECK_EQUAL(boost::regex_match("a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("ab", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-1", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validOne) {
  boost::regex comp{Hack::Lex::COMP_ONE};
  BOOST_CHECK(boost::regex_match("1", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidOne) {
  boost::regex comp{Hack::Lex::COMP_ONE};
  BOOST_CHECK_EQUAL(boost::regex_match("a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("ab", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-1", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("0", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validMinusOne) {
  boost::regex comp{Hack::Lex::COMP_MINUS_ONE};
  BOOST_CHECK(boost::regex_match("-1", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidMinusOne) {
  boost::regex comp{Hack::Lex::COMP_MINUS_ONE};
  BOOST_CHECK_EQUAL(boost::regex_match("a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("ab", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("0", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validD) {
  boost::regex comp{Hack::Lex::COMP_D};
  BOOST_CHECK(boost::regex_match("D", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidD) {
  boost::regex comp{Hack::Lex::COMP_D};
  BOOST_CHECK_EQUAL(boost::regex_match("d", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("0", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validA) {
  boost::regex comp{Hack::Lex::COMP_A};
  BOOST_CHECK(boost::regex_match("A", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidA) {
  boost::regex comp{Hack::Lex::COMP_A};
  BOOST_CHECK_EQUAL(boost::regex_match("a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("0", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validNotD) {
  boost::regex comp{Hack::Lex::COMP_NOT_D};
  BOOST_CHECK(boost::regex_match("!D", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidNotD) {
  boost::regex comp{Hack::Lex::COMP_NOT_D};
  BOOST_CHECK_EQUAL(boost::regex_match("!d", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("!", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validNotA) {
  boost::regex comp{Hack::Lex::COMP_NOT_A};
  BOOST_CHECK(boost::regex_match("!A", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidNotA) {
  boost::regex comp{Hack::Lex::COMP_NOT_A};
  BOOST_CHECK_EQUAL(boost::regex_match("!a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("!", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validMinueD) {
  boost::regex comp{Hack::Lex::COMP_MINUS_D};
  BOOST_CHECK(boost::regex_match("-D", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidMinusD) {
  boost::regex comp{Hack::Lex::COMP_MINUS_D};
  BOOST_CHECK_EQUAL(boost::regex_match("-d", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validMinusA) {
  boost::regex comp{Hack::Lex::COMP_MINUS_A};
  BOOST_CHECK(boost::regex_match("-A", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidMinusA) {
  boost::regex comp{Hack::Lex::COMP_MINUS_A};
  BOOST_CHECK_EQUAL(boost::regex_match("-a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validDPLusOne) {
  boost::regex comp{Hack::Lex::COMP_D_PLUS_ONE};
  BOOST_CHECK(boost::regex_match("D+1", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidDPlusOne) {
  boost::regex comp{Hack::Lex::COMP_D_PLUS_ONE};
  BOOST_CHECK_EQUAL(boost::regex_match("d+1", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D+", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+1", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validAPlusOne) {
  boost::regex comp{Hack::Lex::COMP_A_PLUS_ONE};
  BOOST_CHECK(boost::regex_match("A+1", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidAPlusOne) {
  boost::regex comp{Hack::Lex::COMP_A_PLUS_ONE};
  BOOST_CHECK_EQUAL(boost::regex_match("a+1", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("A+", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+1", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validDMinusOne) {
  boost::regex comp{Hack::Lex::COMP_D_MINUS_ONE};
  BOOST_CHECK(boost::regex_match("D-1", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidDMinusOne) {
  boost::regex comp{Hack::Lex::COMP_D_MINUS_ONE};
  BOOST_CHECK_EQUAL(boost::regex_match("d-1", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D-", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-1", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validAMinusOne) {
  boost::regex comp{Hack::Lex::COMP_A_MINUS_ONE};
  BOOST_CHECK(boost::regex_match("A-1", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidAMinusOne) {
  boost::regex comp{Hack::Lex::COMP_A_MINUS_ONE};
  BOOST_CHECK_EQUAL(boost::regex_match("a-1", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("A-", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-1", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validDPlusA) {
  boost::regex comp{Hack::Lex::COMP_D_PLUS_A};
  BOOST_CHECK(boost::regex_match("D+A", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidDPlusA) {
  boost::regex comp{Hack::Lex::COMP_D_PLUS_A};
  BOOST_CHECK_EQUAL(boost::regex_match("d+a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D+a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d+A", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D+", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+A", comp), false);
}
BOOST_AUTO_TEST_CASE(test_validDMinusA) {
  boost::regex comp{Hack::Lex::COMP_D_MINUS_A};
  BOOST_CHECK(boost::regex_match("D-A", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidDMinusA) {
  boost::regex comp{Hack::Lex::COMP_D_MINUS_A};
  BOOST_CHECK_EQUAL(boost::regex_match("d-a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D-a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d-A", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D-", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-A", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validAMinusD) {
  boost::regex comp{Hack::Lex::COMP_A_MINUS_D};
  BOOST_CHECK(boost::regex_match("A-D", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidAMinusD) {
  boost::regex comp{Hack::Lex::COMP_A_MINUS_D};
  BOOST_CHECK_EQUAL(boost::regex_match("a-d", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("A-d", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a-D", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("A-", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-D", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validDAndA) {
  boost::regex comp{Hack::Lex::COMP_D_AND_A};
  BOOST_CHECK(boost::regex_match("D&A", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidDAndA) {
  boost::regex comp{Hack::Lex::COMP_D_AND_A};
  BOOST_CHECK_EQUAL(boost::regex_match("d&a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D&a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d&A", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D&", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("&A", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validDOrA) {
  boost::regex comp{Hack::Lex::COMP_D_OR_A};
  BOOST_CHECK(boost::regex_match("D|A", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidDOrA) {
  boost::regex comp{Hack::Lex::COMP_D_OR_A};
  BOOST_CHECK_EQUAL(boost::regex_match("d|a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D|a", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d|A", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D|", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("|A", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validM) {
  boost::regex comp{Hack::Lex::COMP_M};
  BOOST_CHECK(boost::regex_match("M", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidM) {
  boost::regex comp{Hack::Lex::COMP_M};
  BOOST_CHECK_EQUAL(boost::regex_match("m", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("0", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validNotM) {
  boost::regex comp{Hack::Lex::COMP_NOT_M};
  BOOST_CHECK(boost::regex_match("!M", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidNotM) {
  boost::regex comp{Hack::Lex::COMP_NOT_M};
  BOOST_CHECK_EQUAL(boost::regex_match("!m", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("!", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validMinusM) {
  boost::regex comp{Hack::Lex::COMP_MINUS_M};
  BOOST_CHECK(boost::regex_match("-M", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidMinusM) {
  boost::regex comp{Hack::Lex::COMP_MINUS_M};
  BOOST_CHECK_EQUAL(boost::regex_match("-m", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validMPlusOne) {
  boost::regex comp{Hack::Lex::COMP_M_PLUS_ONE};
  BOOST_CHECK(boost::regex_match("M+1", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidMPlusOne) {
  boost::regex comp{Hack::Lex::COMP_M_PLUS_ONE};
  BOOST_CHECK_EQUAL(boost::regex_match("m+1", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("M+", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+1", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validMMinusOne) {
  boost::regex comp{Hack::Lex::COMP_M_MINUS_ONE};
  BOOST_CHECK(boost::regex_match("M-1", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidMMinusOne) {
  boost::regex comp{Hack::Lex::COMP_M_MINUS_ONE};
  BOOST_CHECK_EQUAL(boost::regex_match("m-1", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("M-", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-1", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validDPlusM) {
  boost::regex comp{Hack::Lex::COMP_D_PLUS_M};
  BOOST_CHECK(boost::regex_match("D+M", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidDPlusM) {
  boost::regex comp{Hack::Lex::COMP_D_PLUS_M};
  BOOST_CHECK_EQUAL(boost::regex_match("d+m", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D+m", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d+M", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D+", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+M", comp), false);
}
BOOST_AUTO_TEST_CASE(test_validDMinusM) {
  boost::regex comp{Hack::Lex::COMP_D_MINUS_M};
  BOOST_CHECK(boost::regex_match("D-M", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidDMinusM) {
  boost::regex comp{Hack::Lex::COMP_D_MINUS_M};
  BOOST_CHECK_EQUAL(boost::regex_match("d-m", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D-m", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d-M", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D-", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-M", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validMMinusD) {
  boost::regex comp{Hack::Lex::COMP_M_MINUS_D};
  BOOST_CHECK(boost::regex_match("M-D", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidMMinusD) {
  boost::regex comp{Hack::Lex::COMP_M_MINUS_D};
  BOOST_CHECK_EQUAL(boost::regex_match("m-d", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("M-d", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("m-D", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("M-", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-D", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validDAndM) {
  boost::regex comp{Hack::Lex::COMP_D_AND_M};
  BOOST_CHECK(boost::regex_match("D&M", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidDAndM) {
  boost::regex comp{Hack::Lex::COMP_D_AND_M};
  BOOST_CHECK_EQUAL(boost::regex_match("d&m", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D&m", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d&M", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D&", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("&M", comp), false);
}

BOOST_AUTO_TEST_CASE(test_validDOrM) {
  boost::regex comp{Hack::Lex::COMP_D_OR_M};
  BOOST_CHECK(boost::regex_match("D|M", comp));
}

BOOST_AUTO_TEST_CASE(test_invalidDOrM) {
  boost::regex comp{Hack::Lex::COMP_D_OR_M};
  BOOST_CHECK_EQUAL(boost::regex_match("d|m", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D|m", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d|M", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D|", comp), false);
  BOOST_CHECK_EQUAL(boost::regex_match("|M", comp), false);
}

BOOST_AUTO_TEST_SUITE_END()