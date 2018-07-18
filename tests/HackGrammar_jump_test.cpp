#include <boost/test/unit_test.hpp>

#include "HackGrammar.hpp"

#include <regex>

struct FixtureJumps {
  const std::regex jump{Hasm::Hack::Grammar::JUMPS};
};

BOOST_FIXTURE_TEST_SUITE(jumps, FixtureJumps)

BOOST_AUTO_TEST_CASE(jump_test_validJGT) {
  BOOST_CHECK(std::regex_match("JGT", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_validJGE) {
  BOOST_CHECK(std::regex_match("JGE", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_validJLT) {
  BOOST_CHECK(std::regex_match("JLT", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_validJLE) {
  BOOST_CHECK(std::regex_match("JLE", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_validJEQ) {
  BOOST_CHECK(std::regex_match("JEQ", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_validJNE) {
  BOOST_CHECK(std::regex_match("JNE", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_validJMP) {
  BOOST_CHECK(std::regex_match("JMP", jump));
}

BOOST_AUTO_TEST_CASE(jump_test_invalidEmptyJump) {
  BOOST_CHECK_EQUAL(std::regex_match("", jump), false);
}

BOOST_AUTO_TEST_CASE(jump_test_invalidJump) {
  BOOST_CHECK_EQUAL(std::regex_match("JP", jump), false);
}

BOOST_AUTO_TEST_SUITE_END()
