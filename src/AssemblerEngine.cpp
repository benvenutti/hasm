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
  namespace po = boost::program_options;

  bool isVerbose{false};
  bool exportSymbolTable{false};
  std::string inputName{""};

  try {
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

      return false;
    }

    if (vm.count("input-file") == 0) {
      std::cerr << "hasm: no input file" << std::endl;

      return false;
    }

    isVerbose = vm.count("verbose") ? true : false;
    exportSymbolTable = vm.count("symbol-table") ? true : false;

  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;

    return false;
  }

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
  bool isAsmFile = true;
  if (!FileHandler::isFile(fileName)) {
    std::cerr << "error: input \"" << fileName << "\"is not a file" << std::endl;
    isAsmFile = false;
  }

  if (isAsmFile && !FileHandler::hasExtension(fileName, ".asm")) {
    std::cerr << "error: input file must have .asm extension" << std::endl;
    isAsmFile = false;
  }

  return isAsmFile;
}
