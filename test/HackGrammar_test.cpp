#define BOOST_TEST_MODULE HackGrammar_test

#include <boost/regex.hpp>
#include <boost/test/unit_test.hpp>

#include "HackGrammar.h"

struct FixtureDestinations {
  const boost::regex dest{Hack::Grammar::DESTINATIONS};
};

BOOST_FIXTURE_TEST_SUITE(destinations, FixtureDestinations)

BOOST_AUTO_TEST_CASE(test_validDestinationA) {
  BOOST_CHECK(boost::regex_match("A", dest));
}

BOOST_AUTO_TEST_CASE(test_validDestinationD) {
  BOOST_CHECK(boost::regex_match("D", dest));
}

BOOST_AUTO_TEST_CASE(test_validDestinationM) {
  BOOST_CHECK(boost::regex_match("M", dest));
}

BOOST_AUTO_TEST_CASE(test_destinationAM) {
  BOOST_CHECK(boost::regex_match("AM", dest));
}

BOOST_AUTO_TEST_CASE(test_validDestinationAD) {
  BOOST_CHECK(boost::regex_match("AD", dest));
}

BOOST_AUTO_TEST_CASE(test_validDestinationMD) {
  BOOST_CHECK(boost::regex_match("MD", dest));
}

BOOST_AUTO_TEST_CASE(test_validDestinationAMD) {
  BOOST_CHECK(boost::regex_match("AMD", dest));
}

BOOST_AUTO_TEST_CASE(test_invalidEmptyDestination) {
  BOOST_CHECK_EQUAL(boost::regex_match("", dest), false);
}

BOOST_AUTO_TEST_CASE(test_invalidDestination) {
  BOOST_CHECK_EQUAL(boost::regex_match("B", dest), false);
}

BOOST_AUTO_TEST_SUITE_END()

struct FixtureJumps {
  const boost::regex jump{Hack::Grammar::JUMPS};
};

BOOST_FIXTURE_TEST_SUITE(jumps, FixtureJumps)

BOOST_AUTO_TEST_CASE(test_validJGT) {
  BOOST_CHECK(boost::regex_match("JGT", jump));
}

BOOST_AUTO_TEST_CASE(test_validJGE) {
  BOOST_CHECK(boost::regex_match("JGE", jump));
}

BOOST_AUTO_TEST_CASE(test_validJLT) {
  BOOST_CHECK(boost::regex_match("JLT", jump));
}

BOOST_AUTO_TEST_CASE(test_validJLE) {
  BOOST_CHECK(boost::regex_match("JLE", jump));
}

BOOST_AUTO_TEST_CASE(test_validJEQ) {
  BOOST_CHECK(boost::regex_match("JEQ", jump));
}

BOOST_AUTO_TEST_CASE(test_validJNE) {
  BOOST_CHECK(boost::regex_match("JNE", jump));
}

BOOST_AUTO_TEST_CASE(test_validJMP) {
  BOOST_CHECK(boost::regex_match("JMP", jump));
}

BOOST_AUTO_TEST_CASE(test_invalidEmptyJump) {
  BOOST_CHECK_EQUAL(boost::regex_match("", jump), false);
}

BOOST_AUTO_TEST_CASE(test_invalidJump) {
  BOOST_CHECK_EQUAL(boost::regex_match("JP", jump), false);
}

BOOST_AUTO_TEST_SUITE_END()

struct FixtureComputations {
  const boost::regex comp{Hack::Grammar::COMPUTATIONS};
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