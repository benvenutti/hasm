#include <boost/test/unit_test.hpp>

#include "AssemblerEngineConfig.hpp"
#include "CommandLineParser.hpp"

BOOST_AUTO_TEST_SUITE(parsingShorthands)

BOOST_AUTO_TEST_CASE(fileName) {
  int argc = 3;
  const char* argv[] = {"hasm", "-i", "input.asm"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), true);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), false);
  BOOST_CHECK_EQUAL(cfg.inputName(), "input.asm");
}

BOOST_AUTO_TEST_CASE(exportSymbolTable) {
  int argc = 3;
  const char* argv[] = {"hasm", "-s", "input.asm"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), true);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), true);
  BOOST_CHECK_EQUAL(cfg.inputName(), "input.asm");
}

BOOST_AUTO_TEST_CASE(help) {
  int argc = 2;
  const char* argv[] = {"hasm", "-h"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), false);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), false);
  BOOST_CHECK_EQUAL(cfg.inputName(), "");
}

BOOST_AUTO_TEST_CASE(version) {
  int argc = 2;
  const char* argv[] = {"hasm", "-v"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), false);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), false);
  BOOST_CHECK_EQUAL(cfg.inputName(), "");
}

BOOST_AUTO_TEST_CASE(missingInput1) {
  int argc = 2;
  const char* argv[] = {"hasm", "-i"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), false);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), false);
  BOOST_CHECK_EQUAL(cfg.inputName(), "");
}

BOOST_AUTO_TEST_CASE(missingInput2) {
  int argc = 1;
  const char* argv[] = {"hasm"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), false);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), false);
  BOOST_CHECK_EQUAL(cfg.inputName(), "");
}

BOOST_AUTO_TEST_CASE(invalidOption) {
  int argc = 3;
  const char* argv[] = {"hasm", "-x", "input.asm"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), false);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), false);
  BOOST_CHECK_EQUAL(cfg.inputName(), "");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(parsingNonShorthands)

BOOST_AUTO_TEST_CASE(fileName) {
  int argc = 3;
  const char* argv[] = {"hasm", "--input-file", "input.asm"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), true);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), false);
  BOOST_CHECK_EQUAL(cfg.inputName(), "input.asm");
}

BOOST_AUTO_TEST_CASE(exportSymbolTable) {
  int argc = 3;
  const char* argv[] = {"hasm", "--symbol-table", "input.asm"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), true);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), true);
  BOOST_CHECK_EQUAL(cfg.inputName(), "input.asm");
}

BOOST_AUTO_TEST_CASE(help) {
  int argc = 2;
  const char* argv[] = {"hasm", "--help"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), false);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), false);
  BOOST_CHECK_EQUAL(cfg.inputName(), "");
}

BOOST_AUTO_TEST_CASE(version) {
  int argc = 2;
  const char* argv[] = {"hasm", "--version"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), false);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), false);
  BOOST_CHECK_EQUAL(cfg.inputName(), "");
}

BOOST_AUTO_TEST_CASE(missingInput) {
  int argc = 2;
  const char* argv[] = {"hasm", "--input-file"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), false);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), false);
  BOOST_CHECK_EQUAL(cfg.inputName(), "");
}

BOOST_AUTO_TEST_CASE(invalidOption) {
  int argc = 3;
  const char* argv[] = {"hasm", "--invalidOption", "input.asm"};

  Hasm::AssemblerEngineConfig cfg = Hasm::CommandLineParser::parse(argc, argv);

  BOOST_CHECK_EQUAL(cfg.isValid(), false);
  BOOST_CHECK_EQUAL(cfg.exportSymbols(), false);
  BOOST_CHECK_EQUAL(cfg.inputName(), "");
}

BOOST_AUTO_TEST_SUITE_END()
