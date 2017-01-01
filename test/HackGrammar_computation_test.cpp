#define BOOST_TEST_MODULE HackGrammar_computation_test

#include <boost/regex.hpp>
#include <boost/test/unit_test.hpp>

#include "HackGrammar.hpp"

struct FixtureComputations {
  const boost::regex compZero{Hasm::Hack::Grammar::COMP_ZERO};
  const boost::regex compOne{Hasm::Hack::Grammar::COMP_ONE};
  const boost::regex compMinusOne{Hasm::Hack::Grammar::COMP_MINUS_ONE};
  const boost::regex compD{Hasm::Hack::Grammar::COMP_D};
  const boost::regex compA{Hasm::Hack::Grammar::COMP_A};
  const boost::regex compNotD{Hasm::Hack::Grammar::COMP_NOT_D};
  const boost::regex compNotA{Hasm::Hack::Grammar::COMP_NOT_A};
  const boost::regex compMinusD{Hasm::Hack::Grammar::COMP_MINUS_D};
  const boost::regex compMinusA{Hasm::Hack::Grammar::COMP_MINUS_A};
  const boost::regex compDPlusOne{Hasm::Hack::Grammar::COMP_D_PLUS_ONE};
  const boost::regex compAPlusOne{Hasm::Hack::Grammar::COMP_A_PLUS_ONE};
  const boost::regex compDMinusOne{Hasm::Hack::Grammar::COMP_D_MINUS_ONE};
  const boost::regex compAMinusOne{Hasm::Hack::Grammar::COMP_A_MINUS_ONE};
  const boost::regex compDPlusA{Hasm::Hack::Grammar::COMP_D_PLUS_A};
  const boost::regex compDMinusA{Hasm::Hack::Grammar::COMP_D_MINUS_A};
  const boost::regex compAMinusD{Hasm::Hack::Grammar::COMP_A_MINUS_D};
  const boost::regex compDAndA{Hasm::Hack::Grammar::COMP_D_AND_A};
  const boost::regex compDOrA{Hasm::Hack::Grammar::COMP_D_OR_A};
  const boost::regex compM{Hasm::Hack::Grammar::COMP_M};
  const boost::regex compNotM{Hasm::Hack::Grammar::COMP_NOT_M};
  const boost::regex compMinusM{Hasm::Hack::Grammar::COMP_MINUS_M};
  const boost::regex compMPlusOne{Hasm::Hack::Grammar::COMP_M_PLUS_ONE};
  const boost::regex compMMinusOne{Hasm::Hack::Grammar::COMP_M_MINUS_ONE};
  const boost::regex compDPlusM{Hasm::Hack::Grammar::COMP_D_PLUS_M};
  const boost::regex compDMinusM{Hasm::Hack::Grammar::COMP_D_MINUS_M};
  const boost::regex compMMinusD{Hasm::Hack::Grammar::COMP_M_MINUS_D};
  const boost::regex compDAndM{Hasm::Hack::Grammar::COMP_D_AND_M};
  const boost::regex compDOrM{Hasm::Hack::Grammar::COMP_D_OR_M};
};

BOOST_FIXTURE_TEST_SUITE(computations, FixtureComputations)

BOOST_AUTO_TEST_CASE(test_validZero) {
  BOOST_CHECK(boost::regex_match("0", compZero));
}

BOOST_AUTO_TEST_CASE(test_invalidZero) {
  BOOST_CHECK_EQUAL(boost::regex_match("a", compZero), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-1", compZero), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", compZero), false);
}

BOOST_AUTO_TEST_CASE(test_validOne) {
  BOOST_CHECK(boost::regex_match("1", compOne));
}

BOOST_AUTO_TEST_CASE(test_invalidOne) {
  BOOST_CHECK_EQUAL(boost::regex_match("a", compOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-1", compOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("0", compOne), false);
}

BOOST_AUTO_TEST_CASE(test_validMinusOne) {
  BOOST_CHECK(boost::regex_match("-1", compMinusOne));
}

BOOST_AUTO_TEST_CASE(test_invalidMinusOne) {
  BOOST_CHECK_EQUAL(boost::regex_match("a", compMinusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("0", compMinusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("1", compMinusOne), false);
}

BOOST_AUTO_TEST_CASE(test_validD) {
  BOOST_CHECK(boost::regex_match("D", compD));
}

BOOST_AUTO_TEST_CASE(test_invalidD) {
  BOOST_CHECK_EQUAL(boost::regex_match("d", compD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("0", compD), false);
}

BOOST_AUTO_TEST_CASE(test_validA) {
  BOOST_CHECK(boost::regex_match("A", compA));
}

BOOST_AUTO_TEST_CASE(test_invalidA) {
  BOOST_CHECK_EQUAL(boost::regex_match("a", compA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("0", compA), false);
}

BOOST_AUTO_TEST_CASE(test_validNotD) {
  BOOST_CHECK(boost::regex_match("!D", compNotD));
}

BOOST_AUTO_TEST_CASE(test_invalidNotD) {
  BOOST_CHECK_EQUAL(boost::regex_match("!d", compNotD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("!", compNotD), false);
}

BOOST_AUTO_TEST_CASE(test_validNotA) {
  BOOST_CHECK(boost::regex_match("!A", compNotA));
}

BOOST_AUTO_TEST_CASE(test_invalidNotA) {
  BOOST_CHECK_EQUAL(boost::regex_match("!a", compNotA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("!", compNotA), false);
}

BOOST_AUTO_TEST_CASE(test_validMinusD) {
  BOOST_CHECK(boost::regex_match("-D", compMinusD));
}

BOOST_AUTO_TEST_CASE(test_invalidMinusD) {
  BOOST_CHECK_EQUAL(boost::regex_match("-d", compMinusD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-", compMinusD), false);
}

BOOST_AUTO_TEST_CASE(test_validMinusA) {
  BOOST_CHECK(boost::regex_match("-A", compMinusA));
}

BOOST_AUTO_TEST_CASE(test_invalidMinusA) {
  BOOST_CHECK_EQUAL(boost::regex_match("-a", compMinusA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-", compMinusA), false);
}

BOOST_AUTO_TEST_CASE(test_validDPLusOne) {
  BOOST_CHECK(boost::regex_match("D+1", compDPlusOne));
}

BOOST_AUTO_TEST_CASE(test_invalidDPlusOne) {
  BOOST_CHECK_EQUAL(boost::regex_match("d+1", compDPlusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D+", compDPlusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+1", compDPlusOne), false);
}

BOOST_AUTO_TEST_CASE(test_validAPlusOne) {
  BOOST_CHECK(boost::regex_match("A+1", compAPlusOne));
}

BOOST_AUTO_TEST_CASE(test_invalidAPlusOne) {
  BOOST_CHECK_EQUAL(boost::regex_match("a+1", compAPlusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("A+", compAPlusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+1", compAPlusOne), false);
}

BOOST_AUTO_TEST_CASE(test_validDMinusOne) {
  BOOST_CHECK(boost::regex_match("D-1", compDMinusOne));
}

BOOST_AUTO_TEST_CASE(test_invalidDMinusOne) {
  BOOST_CHECK_EQUAL(boost::regex_match("d-1", compDMinusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D-", compDMinusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-1", compDMinusOne), false);
}

BOOST_AUTO_TEST_CASE(test_validAMinusOne) {
  BOOST_CHECK(boost::regex_match("A-1", compAMinusOne));
}

BOOST_AUTO_TEST_CASE(test_invalidAMinusOne) {
  BOOST_CHECK_EQUAL(boost::regex_match("a-1", compAMinusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("A-", compAMinusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-1", compAMinusOne), false);
}

BOOST_AUTO_TEST_CASE(test_validDPlusA) {
  BOOST_CHECK(boost::regex_match("D+A", compDPlusA));
}

BOOST_AUTO_TEST_CASE(test_invalidDPlusA) {
  BOOST_CHECK_EQUAL(boost::regex_match("d+a", compDPlusA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D+a", compDPlusA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d+A", compDPlusA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D+", compDPlusA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+A", compDPlusA), false);
}
BOOST_AUTO_TEST_CASE(test_validDMinusA) {
  BOOST_CHECK(boost::regex_match("D-A", compDMinusA));
}

BOOST_AUTO_TEST_CASE(test_invalidDMinusA) {
  BOOST_CHECK_EQUAL(boost::regex_match("d-a", compDMinusA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D-a", compDMinusA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d-A", compDMinusA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D-", compDMinusA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-A", compDMinusA), false);
}

BOOST_AUTO_TEST_CASE(test_validAMinusD) {
  BOOST_CHECK(boost::regex_match("A-D", compAMinusD));
}

BOOST_AUTO_TEST_CASE(test_invalidAMinusD) {
  BOOST_CHECK_EQUAL(boost::regex_match("a-d", compAMinusD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("A-d", compAMinusD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("a-D", compAMinusD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("A-", compAMinusD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-D", compAMinusD), false);
}

BOOST_AUTO_TEST_CASE(test_validDAndA) {
  BOOST_CHECK(boost::regex_match("D&A", compDAndA));
}

BOOST_AUTO_TEST_CASE(test_invalidDAndA) {
  BOOST_CHECK_EQUAL(boost::regex_match("d&a", compDAndA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D&a", compDAndA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d&A", compDAndA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D&", compDAndA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("&A", compDAndA), false);
}

BOOST_AUTO_TEST_CASE(test_validDOrA) {
  BOOST_CHECK(boost::regex_match("D|A", compDOrA));
}

BOOST_AUTO_TEST_CASE(test_invalidDOrA) {
  BOOST_CHECK_EQUAL(boost::regex_match("d|a", compDOrA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D|a", compDOrA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d|A", compDOrA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D|", compDOrA), false);
  BOOST_CHECK_EQUAL(boost::regex_match("|A", compDOrA), false);
}

BOOST_AUTO_TEST_CASE(test_validM) {
  BOOST_CHECK(boost::regex_match("M", compM));
}

BOOST_AUTO_TEST_CASE(test_invalidM) {
  BOOST_CHECK_EQUAL(boost::regex_match("m", compM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("0", compM), false);
}

BOOST_AUTO_TEST_CASE(test_validNotM) {
  BOOST_CHECK(boost::regex_match("!M", compNotM));
}

BOOST_AUTO_TEST_CASE(test_invalidNotM) {
  BOOST_CHECK_EQUAL(boost::regex_match("!m", compNotM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("!", compNotM), false);
}

BOOST_AUTO_TEST_CASE(test_validMinusM) {
  BOOST_CHECK(boost::regex_match("-M", compMinusM));
}

BOOST_AUTO_TEST_CASE(test_invalidMinusM) {
  BOOST_CHECK_EQUAL(boost::regex_match("-m", compMinusM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-", compMinusM), false);
}

BOOST_AUTO_TEST_CASE(test_validMPlusOne) {
  BOOST_CHECK(boost::regex_match("M+1", compMPlusOne));
}

BOOST_AUTO_TEST_CASE(test_invalidMPlusOne) {
  BOOST_CHECK_EQUAL(boost::regex_match("m+1", compMPlusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("M+", compMPlusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+1", compMPlusOne), false);
}

BOOST_AUTO_TEST_CASE(test_validMMinusOne) {
  BOOST_CHECK(boost::regex_match("M-1", compMMinusOne));
}

BOOST_AUTO_TEST_CASE(test_invalidMMinusOne) {
  BOOST_CHECK_EQUAL(boost::regex_match("m-1", compMMinusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("M-", compMMinusOne), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-1", compMMinusOne), false);
}

BOOST_AUTO_TEST_CASE(test_validDPlusM) {
  BOOST_CHECK(boost::regex_match("D+M", compDPlusM));
}

BOOST_AUTO_TEST_CASE(test_invalidDPlusM) {
  BOOST_CHECK_EQUAL(boost::regex_match("d+m", compDPlusM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D+m", compDPlusM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d+M", compDPlusM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D+", compDPlusM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("+M", compDPlusM), false);
}

BOOST_AUTO_TEST_CASE(test_validDMinusM) {
  BOOST_CHECK(boost::regex_match("D-M", compDMinusM));
}

BOOST_AUTO_TEST_CASE(test_invalidDMinusM) {
  BOOST_CHECK_EQUAL(boost::regex_match("d-m", compDMinusM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D-m", compDMinusM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d-M", compDMinusM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D-", compDMinusM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-M", compDMinusM), false);
}

BOOST_AUTO_TEST_CASE(test_validMMinusD) {
  BOOST_CHECK(boost::regex_match("M-D", compMMinusD));
}

BOOST_AUTO_TEST_CASE(test_invalidMMinusD) {
  BOOST_CHECK_EQUAL(boost::regex_match("m-d", compMMinusD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("M-d", compMMinusD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("m-D", compMMinusD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("M-", compMMinusD), false);
  BOOST_CHECK_EQUAL(boost::regex_match("-D", compMMinusD), false);
}

BOOST_AUTO_TEST_CASE(test_validDAndM) {
  BOOST_CHECK(boost::regex_match("D&M", compDAndM));
}

BOOST_AUTO_TEST_CASE(test_invalidDAndM) {
  BOOST_CHECK_EQUAL(boost::regex_match("d&m", compDAndM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D&m", compDAndM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d&M", compDAndM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D&", compDAndM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("&M", compDAndM), false);
}

BOOST_AUTO_TEST_CASE(test_validDOrM) {
  BOOST_CHECK(boost::regex_match("D|M", compDOrM));
}

BOOST_AUTO_TEST_CASE(test_invalidDOrM) {
  BOOST_CHECK_EQUAL(boost::regex_match("d|m", compDOrM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D|m", compDOrM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("d|M", compDOrM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("D|", compDOrM), false);
  BOOST_CHECK_EQUAL(boost::regex_match("|M", compDOrM), false);
}

BOOST_AUTO_TEST_SUITE_END()
