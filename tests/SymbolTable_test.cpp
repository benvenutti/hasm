#include <algorithm>

#include <boost/test/unit_test.hpp>

#include "SymbolTable.hpp"

struct FixtureSymbolTable {
  FixtureSymbolTable() {
    symbolTable.addEntry("s1", 0x1010);
    symbolTable.addEntry("s2", 0x2020);
    symbolTable.addEntry("s3", 0x3030);
  }

  Hasm::SymbolTable symbolTable;
};

BOOST_FIXTURE_TEST_SUITE(entries, FixtureSymbolTable)

BOOST_AUTO_TEST_CASE(contains) {
  BOOST_CHECK_EQUAL(symbolTable.contains("s1"), true);
  BOOST_CHECK_EQUAL(symbolTable.contains("s2"), true);
  BOOST_CHECK_EQUAL(symbolTable.contains("s3"), true);
  BOOST_CHECK_EQUAL(symbolTable.contains("s4"), false);
}

BOOST_AUTO_TEST_CASE(addresses) {
  BOOST_CHECK_EQUAL(symbolTable.getAddress("s1").get(), 0x1010);
  BOOST_CHECK_EQUAL(symbolTable.getAddress("s2").get(), 0x2020);
  BOOST_CHECK_EQUAL(symbolTable.getAddress("s3").get(), 0x3030);
  BOOST_CHECK(boost::none == symbolTable.getAddress("s4"));
}

BOOST_AUTO_TEST_CASE(getSymbols) {
  const auto symbols = symbolTable.getSymbols();

  BOOST_CHECK_EQUAL(std::count(symbols.begin(), symbols.end(), "s1"), 1u);
  BOOST_CHECK_EQUAL(std::count(symbols.begin(), symbols.end(), "s2"), 1u);
  BOOST_CHECK_EQUAL(std::count(symbols.begin(), symbols.end(), "s3"), 1u);
  BOOST_CHECK_EQUAL(std::count(symbols.begin(), symbols.end(), "s4"), 0u);
}

BOOST_AUTO_TEST_SUITE_END()
