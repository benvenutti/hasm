#define BOOST_TEST_MODULE Parser_test

#include <sstream>
#include <vector>

#include <boost/test/unit_test.hpp>

#include "Parser.h"

struct Fixture {
  Fixture() {
    for (auto s: cmds) {
      asmProgram.append(s + "\n");
    }
  }

  std::string asmProgram{""};

  const std::vector<std::string> cmds{
    "@30",
    "D=A",
    "@1010",
    "M=D+1",
    "AMD=!A;JGT",
    "(LABEL_LOOP)",
    "// line comment",
    "@LABEL_LOOP",
    "0;JMP"
  };
};

BOOST_FIXTURE_TEST_SUITE(parsing, Fixture)

BOOST_AUTO_TEST_CASE(commands) {
  std::stringstream ss{asmProgram};
  Hasm::Parser parser{ss};

  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "@30");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "D=A");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "@1010");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "M=D+1");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "AMD=!A;JGT");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "(LABEL_LOOP)");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "@LABEL_LOOP");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "0;JMP");
}

BOOST_AUTO_TEST_CASE(commandTypes) {
  std::stringstream ss{asmProgram};
  Hasm::Parser parser{ss};

  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::HasmCommandType::A_COMMAND);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::HasmCommandType::C_COMMAND);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::HasmCommandType::A_COMMAND);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::HasmCommandType::C_COMMAND);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::HasmCommandType::C_COMMAND);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::HasmCommandType::L_COMMAND);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::HasmCommandType::A_COMMAND);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::HasmCommandType::C_COMMAND);
}

BOOST_AUTO_TEST_CASE(reset) {
  std::stringstream ss{asmProgram};
  Hasm::Parser parser{ss};

  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "@30");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "D=A");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "@1010");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "M=D+1");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "AMD=!A;JGT");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "(LABEL_LOOP)");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "@LABEL_LOOP");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "0;JMP");

  parser.reset();

  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "@30");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "D=A");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "@1010");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "M=D+1");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "AMD=!A;JGT");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "(LABEL_LOOP)");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "@LABEL_LOOP");
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "0;JMP");
}

BOOST_AUTO_TEST_CASE(commandInfo) {
  std::stringstream ss{asmProgram};
  Hasm::Parser parser{ss};

  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "@30");
  BOOST_CHECK_EQUAL(parser.symbol(), "30");

  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "D=A");
  BOOST_CHECK_EQUAL(parser.dest(), "D");
  BOOST_CHECK_EQUAL(parser.comp(), "A");
  BOOST_CHECK_EQUAL(parser.jump(), "");

  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "@1010");
  BOOST_CHECK_EQUAL(parser.symbol(), "1010");

  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "M=D+1");
  BOOST_CHECK_EQUAL(parser.dest(), "M");
  BOOST_CHECK_EQUAL(parser.comp(), "D+1");
  BOOST_CHECK_EQUAL(parser.jump(), "");

  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "AMD=!A;JGT");
  BOOST_CHECK_EQUAL(parser.dest(), "AMD");
  BOOST_CHECK_EQUAL(parser.comp(), "!A");
  BOOST_CHECK_EQUAL(parser.jump(), "JGT");

  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "(LABEL_LOOP)");
  BOOST_CHECK_EQUAL(parser.symbol(), "LABEL_LOOP");

  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "@LABEL_LOOP");
  BOOST_CHECK_EQUAL(parser.symbol(), "LABEL_LOOP");

  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCommand(), "0;JMP");
  BOOST_CHECK_EQUAL(parser.dest(), "");
  BOOST_CHECK_EQUAL(parser.comp(), "0");
  BOOST_CHECK_EQUAL(parser.jump(), "JMP");
}

BOOST_AUTO_TEST_SUITE_END()
