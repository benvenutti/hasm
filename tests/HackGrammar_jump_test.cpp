#include <boost/regex.hpp>
#include <boost/test/unit_test.hpp>

#include "HackGrammar.hpp"

struct FixtureJumps {
  const boost::regex jump{Hasm::Hack::Grammar::JUMPS};
};

BOOST_FIXTURE_TEST_SUITE(jumps, FixtureJumps)

BOOST_AUTO_TEST_CASE(jump_test_validJGT) {
  BOOST_CHECK(boost::regex_match("JGT", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_validJGE) {
  BOOST_CHECK(boost::regex_match("JGE", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_validJLT) {
  BOOST_CHECK(boost::regex_match("JLT", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_validJLE) {
  BOOST_CHECK(boost::regex_match("JLE", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_validJEQ) {
  BOOST_CHECK(boost::regex_match("JEQ", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_validJNE) {
  BOOST_CHECK(boost::regex_match("JNE", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_validJMP) {
  BOOST_CHECK(boost::regex_match("JMP", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_invalidEmptyJump) {
  BOOST_CHECK_EQUAL(boost::regex_match("", jump), false);
}

BOOST_AUTO_TEST_CASE(jump_test_invalidJump) {
  BOOST_CHECK_EQUAL(boost::regex_match("JP", jump), false);
}

BOOST_AUTO_TEST_SUITE_END()
