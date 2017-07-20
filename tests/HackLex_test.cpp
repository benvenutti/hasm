#include <boost/regex.hpp>
#include <boost/test/unit_test.hpp>

#include "HackLex.hpp"

namespace {

struct FixtureIdentifier {
  const boost::regex id{Hasm::Hack::Lex::ID};
};

BOOST_FIXTURE_TEST_SUITE(identifiers, FixtureIdentifier)

BOOST_AUTO_TEST_CASE(test_validId_startsWithLetter) {
  BOOST_CHECK(boost::regex_match("id", id));
}

BOOST_AUTO_TEST_CASE(test_validId_startsWithUnderscore) {
  BOOST_CHECK(boost::regex_match("_id", id));
}

BOOST_AUTO_TEST_CASE(test_validId_startsWithDot) {
  BOOST_CHECK(boost::regex_match(".id", id));
}

BOOST_AUTO_TEST_CASE(test_validId_startsWithDollarSign) {
  BOOST_CHECK(boost::regex_match("$id", id));
}

BOOST_AUTO_TEST_CASE(test_validId_startsWithColon) {
  BOOST_CHECK(boost::regex_match(":id", id));
}

BOOST_AUTO_TEST_CASE(test_invalidId_empty) {
  BOOST_CHECK_EQUAL(boost::regex_match("", id), false);
}

BOOST_AUTO_TEST_CASE(test_invalidId_startsWithDigit) {
  BOOST_CHECK_EQUAL(boost::regex_match("2id", id), false);
}

BOOST_AUTO_TEST_CASE(test_validId_withLettersAndDigits) {
  BOOST_CHECK(boost::regex_match("ab12cd34", id));
}

BOOST_AUTO_TEST_CASE(test_validId_withAllValidCharacters) {
  BOOST_CHECK(boost::regex_match("ab12_.$:cd34", id));
}

BOOST_AUTO_TEST_CASE(test_invalidId_withInvalidCharacter) {
  BOOST_CHECK_EQUAL(boost::regex_match("id@", id), false);
}

BOOST_AUTO_TEST_SUITE_END()

struct FixtureInteger {
  const boost::regex integer{Hasm::Hack::Lex::INTEGER};
};

BOOST_FIXTURE_TEST_SUITE(integers, FixtureInteger)

BOOST_AUTO_TEST_CASE(test_validInteger) {
  BOOST_CHECK(boost::regex_match("0", integer));
  BOOST_CHECK(boost::regex_match("9", integer));
  BOOST_CHECK(boost::regex_match("10", integer));
  BOOST_CHECK(boost::regex_match("111", integer));
}

BOOST_AUTO_TEST_CASE(test_invalidInteger_invalidDigits) {
  BOOST_CHECK_EQUAL(boost::regex_match("10A20", integer), false);
}

BOOST_AUTO_TEST_CASE(test_invalidInteger_signedNegative) {
  BOOST_CHECK_EQUAL(boost::regex_match("-1", integer), false);
}

BOOST_AUTO_TEST_CASE(test_invalidInteger_signedPositive) {
  BOOST_CHECK_EQUAL(boost::regex_match("+1", integer), false);
}

BOOST_AUTO_TEST_SUITE_END()

struct FixtureSymbol {
  const boost::regex at{Hasm::Hack::Lex::AT};
  const boost::regex semicolon{Hasm::Hack::Lex::SEMICOLON};
  const boost::regex equal{Hasm::Hack::Lex::EQUAL};
  const boost::regex leftParen{Hasm::Hack::Lex::LEFT_PAREN};
  const boost::regex rightParen{Hasm::Hack::Lex::RIGHT_PAREN};
  const boost::regex plus{Hasm::Hack::Lex::PLUS};
  const boost::regex minus{Hasm::Hack::Lex::MINUS};
  const boost::regex logicNot{Hasm::Hack::Lex::NOT};
  const boost::regex logicAnd{Hasm::Hack::Lex::AND};
  const boost::regex logicOr{Hasm::Hack::Lex::OR};
  const boost::regex zero{Hasm::Hack::Lex::ZERO};
  const boost::regex one{Hasm::Hack::Lex::ONE};
};

BOOST_FIXTURE_TEST_SUITE(symbols, FixtureSymbol)

BOOST_AUTO_TEST_CASE(test_validAt) {
  BOOST_CHECK(boost::regex_match("@", at));
}

BOOST_AUTO_TEST_CASE(test_invalidAt) {
  BOOST_CHECK_EQUAL(boost::regex_match("a", at), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", at), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+", at), false);
}

BOOST_AUTO_TEST_CASE(test_validSemicolon) {
  BOOST_CHECK(boost::regex_match(";", semicolon));
}

BOOST_AUTO_TEST_CASE(test_invalidSemicolon) {
  BOOST_CHECK_EQUAL(boost::regex_match("a", semicolon), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", semicolon), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+", semicolon), false);
}

BOOST_AUTO_TEST_CASE(test_validEqual) {
  BOOST_CHECK(boost::regex_match("=", equal));
}

BOOST_AUTO_TEST_CASE(test_invalidEqual) {
  BOOST_CHECK_EQUAL(boost::regex_match("a", equal), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", equal), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+", equal), false);
}

BOOST_AUTO_TEST_CASE(test_validLeftParen) {
  BOOST_CHECK(boost::regex_match("(", leftParen));
}

BOOST_AUTO_TEST_CASE(test_invalidLeftParen) {
  BOOST_CHECK_EQUAL(boost::regex_match(")", leftParen), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a", leftParen), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", leftParen), false);
  BOOST_CHECK_EQUAL(boost::regex_match("", leftParen), false);
}

BOOST_AUTO_TEST_CASE(test_validRightParen) {
  BOOST_CHECK(boost::regex_match(")", rightParen));
}

BOOST_AUTO_TEST_CASE(test_invalidRightParen) {
  BOOST_CHECK_EQUAL(boost::regex_match("(", rightParen), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a", rightParen), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", rightParen), false);
  BOOST_CHECK_EQUAL(boost::regex_match("", rightParen), false);
}

BOOST_AUTO_TEST_CASE(test_validPlus) {
  BOOST_CHECK(boost::regex_match("+", plus));
}

BOOST_AUTO_TEST_CASE(test_invalidPlus) {
  BOOST_CHECK_EQUAL(boost::regex_match("-", plus), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a", plus), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", plus), false);
  BOOST_CHECK_EQUAL(boost::regex_match("", plus), false);
}

BOOST_AUTO_TEST_CASE(test_validMinus) {
  BOOST_CHECK(boost::regex_match("-", minus));
}

BOOST_AUTO_TEST_CASE(test_invalidMinus) {
  BOOST_CHECK_EQUAL(boost::regex_match("+", minus), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a", minus), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", minus), false);
  BOOST_CHECK_EQUAL(boost::regex_match("", minus), false);
}

BOOST_AUTO_TEST_CASE(test_validNot) {
  BOOST_CHECK(boost::regex_match("!", logicNot));
}

BOOST_AUTO_TEST_CASE(test_invalidNot) {
  BOOST_CHECK_EQUAL(boost::regex_match("+", logicNot), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a", logicNot), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", logicNot), false);
  BOOST_CHECK_EQUAL(boost::regex_match("", logicNot), false);
}

BOOST_AUTO_TEST_CASE(test_validAnd) {
  BOOST_CHECK(boost::regex_match("&", logicAnd));
}

BOOST_AUTO_TEST_CASE(test_invalidAnd) {
  BOOST_CHECK_EQUAL(boost::regex_match("+", logicAnd), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a", logicAnd), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", logicAnd), false);
  BOOST_CHECK_EQUAL(boost::regex_match("", logicAnd), false);
}

BOOST_AUTO_TEST_CASE(test_validOr) {
  BOOST_CHECK(boost::regex_match("|", logicOr));
}

BOOST_AUTO_TEST_CASE(test_invalidOr) {
  BOOST_CHECK_EQUAL(boost::regex_match("+", logicOr), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a", logicOr), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", logicOr), false);
  BOOST_CHECK_EQUAL(boost::regex_match("", logicOr), false);
}

BOOST_AUTO_TEST_CASE(test_validZero) {
  BOOST_CHECK(boost::regex_match("0", zero));
}

BOOST_AUTO_TEST_CASE(test_invalidZero) {
  BOOST_CHECK_EQUAL(boost::regex_match("+", zero), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a", zero), false);
  BOOST_CHECK_EQUAL(boost::regex_match("2", zero), false);
  BOOST_CHECK_EQUAL(boost::regex_match("", zero), false);
}

BOOST_AUTO_TEST_CASE(test_validOne) {
  BOOST_CHECK(boost::regex_match("1", one));
}

BOOST_AUTO_TEST_CASE(test_invalidOne) {
  BOOST_CHECK_EQUAL(boost::regex_match("+", one), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a", one), false);
  BOOST_CHECK_EQUAL(boost::regex_match("2", one), false);
  BOOST_CHECK_EQUAL(boost::regex_match("", one), false);
}

BOOST_AUTO_TEST_SUITE_END()

struct FixtureDestination {
  const boost::regex destA{Hasm::Hack::Lex::DEST_A};
  const boost::regex destD{Hasm::Hack::Lex::DEST_D};
  const boost::regex destM{Hasm::Hack::Lex::DEST_M};
};

BOOST_FIXTURE_TEST_SUITE(destinations, FixtureDestination)

BOOST_AUTO_TEST_CASE(test_destinationA) {
  BOOST_CHECK(boost::regex_match("A", destA));
}

BOOST_AUTO_TEST_CASE(test_destinationD) {
  BOOST_CHECK(boost::regex_match("D", destD));
}

BOOST_AUTO_TEST_CASE(test_destinationM) {
  BOOST_CHECK(boost::regex_match("M", destM));
}

BOOST_AUTO_TEST_CASE(test_invalidDestinationA) {
  BOOST_CHECK_EQUAL(boost::regex_match("a", destA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("A_", destA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_A", destA), false);
}

BOOST_AUTO_TEST_CASE(test_invalidDestinationD) {
  BOOST_CHECK_EQUAL(boost::regex_match("d", destD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D_", destD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_D", destD), false);
}

BOOST_AUTO_TEST_CASE(test_invalidDestinationM) {
  BOOST_CHECK_EQUAL(boost::regex_match("m", destM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_M", destM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("M_", destM), false);
}

BOOST_AUTO_TEST_SUITE_END()

struct FixtureJump {
  const boost::regex jumpJGT{Hasm::Hack::Lex::JUMP_JGT};
  const boost::regex jumpJGE{Hasm::Hack::Lex::JUMP_JGE};
  const boost::regex jumpJLT{Hasm::Hack::Lex::JUMP_JLT};
  const boost::regex jumpJLE{Hasm::Hack::Lex::JUMP_JLE};
  const boost::regex jumpJEQ{Hasm::Hack::Lex::JUMP_JEQ};
  const boost::regex jumpJNE{Hasm::Hack::Lex::JUMP_JNE};
  const boost::regex jumpJMP{Hasm::Hack::Lex::JUMP_JMP};
};

BOOST_FIXTURE_TEST_SUITE(jumps, FixtureJump)

BOOST_AUTO_TEST_CASE(test_validJGT) {
  BOOST_CHECK(boost::regex_match("JGT", jumpJGT));
}

BOOST_AUTO_TEST_CASE(test_invalidJGT) {
  BOOST_CHECK_EQUAL(boost::regex_match("jgt", jumpJGT), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JGT", jumpJGT), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JGT_", jumpJGT), false);
}

BOOST_AUTO_TEST_CASE(test_validJGE) {
  BOOST_CHECK(boost::regex_match("JGE", jumpJGE));
}

BOOST_AUTO_TEST_CASE(test_invalidJGE) {
  BOOST_CHECK_EQUAL(boost::regex_match("jge", jumpJGE), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JGE", jumpJGE), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JGE_", jumpJGE), false);
}

BOOST_AUTO_TEST_CASE(test_validJLT) {
  BOOST_CHECK(boost::regex_match("JLT", jumpJLT));
}

BOOST_AUTO_TEST_CASE(test_invalidJLT) {
  BOOST_CHECK_EQUAL(boost::regex_match("jlt", jumpJLT), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JLT", jumpJLT), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JLT_", jumpJLT), false);
}

BOOST_AUTO_TEST_CASE(test_validJLE) {
  BOOST_CHECK(boost::regex_match("JLE", jumpJLE));
}

BOOST_AUTO_TEST_CASE(test_invalidJLE) {
  BOOST_CHECK_EQUAL(boost::regex_match("jle", jumpJLE), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JLE", jumpJLE), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JLE_", jumpJLE), false);
}

BOOST_AUTO_TEST_CASE(test_validJEQ) {
  BOOST_CHECK(boost::regex_match("JEQ", jumpJEQ));
}

BOOST_AUTO_TEST_CASE(test_invalidJEQ) {
  BOOST_CHECK_EQUAL(boost::regex_match("jeq", jumpJEQ), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JEQ", jumpJEQ), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JEQ_", jumpJEQ), false);
}

BOOST_AUTO_TEST_CASE(test_validJNE) {
  BOOST_CHECK(boost::regex_match("JNE", jumpJNE));
}

BOOST_AUTO_TEST_CASE(test_invalidJNE) {
  BOOST_CHECK_EQUAL(boost::regex_match("jne", jumpJNE), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JNE", jumpJNE), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JNE_", jumpJNE), false);
}

BOOST_AUTO_TEST_CASE(test_validJMP) {
  BOOST_CHECK(boost::regex_match("JMP", jumpJMP));
}

BOOST_AUTO_TEST_CASE(test_invalidJMP) {
  BOOST_CHECK_EQUAL(boost::regex_match("jmp", jumpJMP), false);
  BOOST_CHECK_EQUAL(boost::regex_match("_JMP", jumpJMP), false);
  BOOST_CHECK_EQUAL(boost::regex_match("JMP_", jumpJMP), false);
}

BOOST_AUTO_TEST_SUITE_END()

}
