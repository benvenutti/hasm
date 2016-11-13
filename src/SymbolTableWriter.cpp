#include "SymbolTableWriter.hpp"

#include <iomanip>

#include <boost/io/ios_state.hpp>

#include "SymbolTable.hpp"

namespace Hasm {

SymbolTableWriter::SymbolTableWriter(std::ostream& out, const SymbolTable& symbolTable)
    : out{out}, symbolTable{symbolTable} {}

void SymbolTableWriter::write() {
  boost::io::ios_flags_saver ifs{out};
  
  std::set<std::string> symbols{symbolTable.getSymbols()};
  for (const auto& s: symbols) {
    out << "0x" << std::setfill('0') << std::setw(4) << std::setbase(16)
        << s << " " << symbolTable.getAddress(s).get() << '\n';
  }

  out.flush();
  ifs.restore();
}

} // namespace Hasm