#include <sstream>
#include <vector>

#include <boost/test/unit_test.hpp>

#include "Parser.hpp"

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
  BOOST_CHECK(parser.getCommandType() == Hasm::CommandType::ADDRESSING);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::CommandType::COMPUTATION);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::CommandType::ADDRESSING);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::CommandType::COMPUTATION);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::CommandType::COMPUTATION);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::CommandType::LABEL);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::CommandType::ADDRESSING);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getCommandType() == Hasm::CommandType::COMPUTATION);
}

BOOST_AUTO_TEST_CASE(lineNumber) {
  std::stringstream ss{asmProgram};
  Hasm::Parser parser{ss};

  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCurrentLineNumber(), 1);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCurrentLineNumber(), 2);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCurrentLineNumber(), 3);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCurrentLineNumber(), 4);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCurrentLineNumber(), 5);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCurrentLineNumber(), 6);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCurrentLineNumber(), 8);
  BOOST_CHECK(parser.advance());
  BOOST_CHECK_EQUAL(parser.getCurrentLineNumber(), 9);
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

BOOST_AUTO_TEST_SUITE(status)

BOOST_AUTO_TEST_CASE(getStatus_startOfFile) {
  const std::string cmd{""};
  std::stringstream ss{cmd};
  Hasm::Parser parser{ss};

  BOOST_CHECK(parser.getStatus() == Hasm::Parser::Status::START_OF_FILE);
}

BOOST_AUTO_TEST_CASE(getStatus_valid) {
  const std::string cmd{"@1"};
  std::stringstream ss{cmd};
  Hasm::Parser parser{ss};

  BOOST_CHECK(parser.advance());
  BOOST_CHECK(parser.getStatus() == Hasm::Parser::Status::VALID_COMMAND);
}

BOOST_AUTO_TEST_CASE(getStatus_invalid) {
  const std::string cmd{"+a"};
  std::stringstream ss{cmd};
  Hasm::Parser parser{ss};

  BOOST_CHECK_EQUAL(parser.advance(), false);
  BOOST_CHECK(parser.getStatus() == Hasm::Parser::Status::INVALID_COMMAND);
}

BOOST_AUTO_TEST_CASE(getStatus_endOfFile) {
  const std::string cmd{""};
  std::stringstream ss{cmd};
  Hasm::Parser parser{ss};

  BOOST_CHECK_EQUAL(parser.advance(), false);
  BOOST_CHECK(parser.getStatus() == Hasm::Parser::Status::END_OF_FILE);
}

BOOST_AUTO_TEST_SUITE_END()
