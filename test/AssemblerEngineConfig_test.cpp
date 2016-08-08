#define BOOST_TEST_MODULE AssemblerEngineConfig_test

#include <boost/test/unit_test.hpp>

#include "AssemblerEngineConfig.h"

BOOST_AUTO_TEST_SUITE(constructor)

BOOST_AUTO_TEST_CASE(invalidConstructor) {
  Hasm::AssemblerEngineConfig cfg(false, false, "input");

  BOOST_CHECK_EQUAL(cfg.isValid, false);
  BOOST_CHECK_EQUAL(cfg.exportSymbols, false);
  BOOST_CHECK_EQUAL(cfg.inputName, "input");
}

BOOST_AUTO_TEST_CASE(validConstructor) {
  Hasm::AssemblerEngineConfig cfg(true, true, "file");

  BOOST_CHECK_EQUAL(cfg.isValid, true);
  BOOST_CHECK_EQUAL(cfg.exportSymbols, true);
  BOOST_CHECK_EQUAL(cfg.inputName, "file");
}

BOOST_AUTO_TEST_SUITE_END()