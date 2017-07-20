#include <boost/regex.hpp>
#include <boost/test/unit_test.hpp>

#include "HackGrammar.hpp"

struct FixtureDestinations {
  const boost::regex dest{Hasm::Hack::Grammar::DESTINATIONS};
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
