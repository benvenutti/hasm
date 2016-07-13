#include "CommandLineParser.h"

#include <iostream>

#include <boost/program_options.hpp>

using Hasm::AssemblerEngineConfig;

AssemblerEngineConfig Hasm::CommandLineParser::parse(int argc, char** argv) {
  bool isVerbose{false};
  bool exportSymbolTable{false};
  bool isValid{true};
  std::string inputName{""};

  try {
    namespace po = boost::program_options;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("verbose,v", "verbose mode")
        ("symbol-table,s", "export symbol table (to <input file>.sym)")
        ("input-file,i", po::value<std::string>(&inputName), "input .asm file")
        ("help,h", "print this help message");

    po::positional_options_description positionalDescription;
    const int maxNumberOfInputFiles{1};
    positionalDescription.add("input-file", maxNumberOfInputFiles);

    po::variables_map vm;
    po::command_line_parser cmdParser(argc, argv);
    po::store(cmdParser.options(desc).positional(positionalDescription).run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
      std::cout << "Usage: hasm [options] <input file>.asm" << std::endl;
      std::cout << desc;
      isValid = false;
    }

    if (vm.count("input-file") == 0) {
      std::cerr << "hasm: no input file" << std::endl;
      isValid = false;
    }

    isVerbose = vm.count("verbose") > 0;
    exportSymbolTable = vm.count("symbol-table") > 0;

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
    isValid = false;
  }

  return AssemblerEngineConfig{isValid, isVerbose, exportSymbolTable, inputName};
}
