#define BOOST_TEST_MODULE Coder_test

#include <boost/test/unit_test.hpp>

#include "Coder.h"

BOOST_AUTO_TEST_SUITE(destination)

BOOST_AUTO_TEST_CASE(singleDestination) {
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("M"), 0b001000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("D"), 0b010000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("A"), 0b100000u);
}

BOOST_AUTO_TEST_CASE(combinedDestination) {
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("MD"), 0b011000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("DM"), 0b011000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("AD"), 0b110000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("DA"), 0b110000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("AM"), 0b101000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("MA"), 0b101000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("AMD"), 0b111000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("ADM"), 0b111000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("DAM"), 0b111000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("DMA"), 0b111000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("MAD"), 0b111000u);
  BOOST_CHECK_EQUAL(Hasm::Coder::dest("MDA"), 0b111000u);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(jumps)

BOOST_AUTO_TEST_CASE(jump) {
  BOOST_CHECK_EQUAL(Hasm::Coder::jump("JGT"), 0b001u);
  BOOST_CHECK_EQUAL(Hasm::Coder::jump("JEQ"), 0b010u);
  BOOST_CHECK_EQUAL(Hasm::Coder::jump("JGE"), 0b011u);
  BOOST_CHECK_EQUAL(Hasm::Coder::jump("JLT"), 0b100u);
  BOOST_CHECK_EQUAL(Hasm::Coder::jump("JNE"), 0b101u);
  BOOST_CHECK_EQUAL(Hasm::Coder::jump("JLE"), 0b110u);
  BOOST_CHECK_EQUAL(Hasm::Coder::jump("JMP"), 0b111u);
}

BOOST_AUTO_TEST_SUITE_END()