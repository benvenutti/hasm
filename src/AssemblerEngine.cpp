#include "AssemblerEngine.h"

#include "Assembler.h"
#include "FileHandler.h"

#include <boost/program_options.hpp>

#include <fstream>
#include <iomanip>

using Hasm::Assembler;
using Hasm::AssemblerEngine;
using Hasm::FileHandler;

bool AssemblerEngine::run(int argc, char** argv) const {
  bool isVerbose;
  bool exportSymbolTable;

  namespace po = boost::program_options;

  po::options_description desc("usage");
  desc.add_options()
      (
          "verbose,v",
          po::value<bool>(&isVerbose)->default_value(false),
          "verbose mode"
      )
      (
          "symbol-table,s",
          po::value<bool>(&exportSymbolTable)->implicit_value(false),
          "export symbol table"
      );

  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv).options(desc).run(), vm);
  po::notify(vm);

  if (vm.count("help")) {
    std::cout << "Usage: options_description [options]\n";
    std::cout << desc;

    return false;
  }

  std::string inputName(argv[argc - 1]);

  if (!isAsmFile(inputName)) {
    return false;
  }

  std::ifstream inputFile(inputName);

  if (!inputFile.good()) {
    std::cerr << "error: unable to open input stream" << std::endl;

    return false;
  }

  std::string outputName = FileHandler::changeExtension(inputName, ".hack");
  std::ofstream outputFile(outputName);

  if (!outputFile.good()) {
    std::cerr << "error: unable to open " << outputName << std::endl;

    return false;
  }

  Assembler hasm(inputFile, outputFile);
  hasm.assemble();

  if (exportSymbolTable) {
    std::string symbolsOutName = FileHandler::changeExtension(inputName, "-symbols");
    std::ofstream symbolsOut(symbolsOutName);

    if (!symbolsOut.good()) {
      std::cerr << "error: unable to open output stream" << std::endl;

      return false;
    }

    outputSymbolTable(symbolsOut, hasm.symbols());
    symbolsOut.close();

    if (isVerbose) {
      std::cout << "symbol table output: " << symbolsOutName << std::endl;
    }
  }

  if (inputFile.is_open()) {
    inputFile.close();
  }

  if (outputFile.is_open()) {
    outputFile.close();
  }

  return true;
}

void AssemblerEngine::outputSymbolTable(std::ostream& out, const std::map<std::string, int>& table) const {
  for (auto it = table.cbegin(); it != table.cend(); ++it) {
    out << "0x" << std::setfill('0') << std::setw(4) << std::setbase(16)
        << it->second << " " << it->first << std::endl;
  }
}

bool AssemblerEngine::isAsmFile(const std::string& fileName) const {
  if (!FileHandler::isFile(fileName)) {
    std::cerr << "error: input \"" << fileName << "\"is not a file" << std::endl;

    return false;
  }

  if (!FileHandler::hasExtension(fileName, ".asm")) {
    std::cerr << "error: input file must have .asm extension" << std::endl;

    return false;
  }

  return true;
}
