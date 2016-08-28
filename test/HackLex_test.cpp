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