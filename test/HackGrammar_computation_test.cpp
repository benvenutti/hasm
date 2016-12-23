#define BOOST_TEST_MODULE HackGrammar_computation_test

#include <boost/regex.hpp>
#include <boost/test/unit_test.hpp>

#include "HackGrammar.hpp"

struct FixtureComputations {
  const boost::regex comp{Hasm::Hack::Grammar::COMPUTATIONS};
};

BOOST_FIXTURE_TEST_SUITE(computations, FixtureComputations)

BOOST_AUTO_TEST_CASE(test_validZero) {
  BOOST_CHECK(boost::regex_match("0", comp));
}

BOOST_AUTO_TEST_CASE(test_validOne) {
  BOOST_CHECK(boost::regex_match("1", comp));
}

BOOST_AUTO_TEST_CASE(test_validMinusOne) {
  BOOST_CHECK(boost::regex_match("-1", comp));
}

BOOST_AUTO_TEST_CASE(test_validD) {
  BOOST_CHECK(boost::regex_match("D", comp));
}

BOOST_AUTO_TEST_CASE(test_validA) {
  BOOST_CHECK(boost::regex_match("A", comp));
}

BOOST_AUTO_TEST_CASE(test_validNotD) {
  BOOST_CHECK(boost::regex_match("!D", comp));
}

BOOST_AUTO_TEST_CASE(test_validNotA) {
  BOOST_CHECK(boost::regex_match("!A", comp));
}

BOOST_AUTO_TEST_CASE(test_validMinusD) {
  BOOST_CHECK(boost::regex_match("-D", comp));
}

BOOST_AUTO_TEST_CASE(test_validMinusA) {
  BOOST_CHECK(boost::regex_match("-A", comp));
}

BOOST_AUTO_TEST_CASE(test_validDPlusOne) {
  BOOST_CHECK(boost::regex_match("D+1", comp));
}

BOOST_AUTO_TEST_CASE(test_validAPlusOne) {
  BOOST_CHECK(boost::regex_match("A+1", comp));
}

BOOST_AUTO_TEST_CASE(test_validDMinusOne) {
  BOOST_CHECK(boost::regex_match("D-1", comp));
}

BOOST_AUTO_TEST_CASE(test_validAMinusOne) {
  BOOST_CHECK(boost::regex_match("A-1", comp));
}

BOOST_AUTO_TEST_CASE(test_validDPlusA) {
  BOOST_CHECK(boost::regex_match("D+A", comp));
}

BOOST_AUTO_TEST_CASE(test_validDMinusA) {
  BOOST_CHECK(boost::regex_match("D-A", comp));
}

BOOST_AUTO_TEST_CASE(test_validAMinusD) {
  BOOST_CHECK(boost::regex_match("A-D", comp));
}

BOOST_AUTO_TEST_CASE(test_validDAndA) {
  BOOST_CHECK(boost::regex_match("D&A", comp));
}

BOOST_AUTO_TEST_CASE(test_validDOrA) {
  BOOST_CHECK(boost::regex_match("D|A", comp));
}

BOOST_AUTO_TEST_CASE(test_validM) {
  BOOST_CHECK(boost::regex_match("M", comp));
}

BOOST_AUTO_TEST_CASE(test_validNotM) {
  BOOST_CHECK(boost::regex_match("!M", comp));
}

BOOST_AUTO_TEST_CASE(test_validMinusM) {
  BOOST_CHECK(boost::regex_match("-M", comp));
}

BOOST_AUTO_TEST_CASE(test_validMPlusOne) {
  BOOST_CHECK(boost::regex_match("M+1", comp));
}

BOOST_AUTO_TEST_CASE(test_validMMinusOne) {
  BOOST_CHECK(boost::regex_match("M-1", comp));
}

BOOST_AUTO_TEST_CASE(test_validDPlusM) {
  BOOST_CHECK(boost::regex_match("D+M", comp));
}

BOOST_AUTO_TEST_CASE(test_validDMinusM) {
  BOOST_CHECK(boost::regex_match("D-M", comp));
}

BOOST_AUTO_TEST_CASE(test_validMMinusD) {
  BOOST_CHECK(boost::regex_match("M-D", comp));
}

BOOST_AUTO_TEST_CASE(test_validDAndM) {
  BOOST_CHECK(boost::regex_match("D&M", comp));
}

BOOST_AUTO_TEST_CASE(test_validDOrM) {
  BOOST_CHECK(boost::regex_match("D|M", comp));
}

BOOST_AUTO_TEST_SUITE_END()
