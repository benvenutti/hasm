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