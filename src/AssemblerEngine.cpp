#include "AssemblerEngine.h"

#include "Assembler.h"
#include "FileHandler.h"

#include <fstream>
#include <iomanip>
#include <unistd.h>

using Hasm::Assembler;
using Hasm::AssemblerEngine;
using Hasm::FileHandler;

AssemblerEngine::AssemblerEngine() {
}

int AssemblerEngine::run(int argc, char** argv) {
  if (argc == 1) {
    printUsageMessage();

    return EXIT_FAILURE;
  }

  bool isVerbose, exportSymbolTable;

  if (!getCmdFlags(argc, argv, isVerbose, exportSymbolTable)) {
    return EXIT_FAILURE;
  }

  std::string inputName(argv[argc - 1]);

  if (!isAsmFile(inputName)) {
    return EXIT_FAILURE;
  }

  std::ifstream inputFile(inputName);

  if (!inputFile.good()) {
    std::cerr << "error: unable to open input stream" << std::endl;

    return EXIT_FAILURE;
  }

  std::string outputName = FileHandler::changeExtension(inputName, ".hack");
  std::ofstream outputFile(outputName);

  if (!outputFile.good()) {
    std::cerr << "error: unable to open " << outputName << std::endl;

    return EXIT_FAILURE;
  }

  Assembler hasm(inputFile, outputFile);
  hasm.assemble();

  if (exportSymbolTable) {
    std::string symbolsOutName = FileHandler::changeExtension(inputName, "-symbols");
    std::ofstream symbolsOut(symbolsOutName);

    if (!symbolsOut.good()) {
      std::cerr << "error: unable to open output stream" << std::endl;

      return EXIT_FAILURE;
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

  return EXIT_SUCCESS;
}

void AssemblerEngine::printUsageMessage() const {
  std::cerr << "usage: " << "hasm" << " [-vs] file.asm" << std::endl;
  std::cerr << "       -v verbose" << std::endl;
  std::cerr << "       -s export symbol table" << std::endl;
}

void AssemblerEngine::outputSymbolTable(std::ostream& out, const std::map<std::string, int>& table) const {
  for (auto it = table.cbegin(); it != table.cend(); ++it) {
    out << "0x" << std::setfill('0') << std::setw(4) << std::setbase(16)
        << it->second << " " << it->first << std::endl;
  }
}

bool AssemblerEngine::getCmdFlags(
    int argc,
    char** argv,
    bool& isVerbose,
    bool& exportSymbolTable
) const {
  isVerbose = false;
  exportSymbolTable = false;

  char c;

  while ((c = getopt(argc, argv, "vs")) != -1) {
    switch (c) {
      case 'v':
        isVerbose = true;
        break;
      case 's':
        exportSymbolTable = true;
        break;
      case '?':
        return false;
    }
  }

  return true;
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
