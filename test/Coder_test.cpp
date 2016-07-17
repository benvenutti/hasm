#define BOOST_TEST_MODULE Coder_test

#include <boost/test/included/unit_test.hpp>

#include "Coder.h"

BOOST_AUTO_TEST_SUITE(destination)

  BOOST_AUTO_TEST_CASE(singleDestination) {
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("M"), 0b001000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("D"), 0b010000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("A"), 0b100000);
  }

  BOOST_AUTO_TEST_CASE(combinedDestination) {
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("MD"), 0b011000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("DM"), 0b011000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("AD"), 0b110000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("DA"), 0b110000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("AM"), 0b101000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("MA"), 0b101000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("AMD"), 0b111000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("ADM"), 0b111000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("DAM"), 0b111000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("DMA"), 0b111000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("MAD"), 0b111000);
    BOOST_CHECK_EQUAL(Hasm::Coder::dest("MDA"), 0b111000);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(jumps)

  BOOST_AUTO_TEST_CASE(jump) {
    BOOST_CHECK_EQUAL(Hasm::Coder::jump("JGT"), 0b001);
    BOOST_CHECK_EQUAL(Hasm::Coder::jump("JEQ"), 0b010);
    BOOST_CHECK_EQUAL(Hasm::Coder::jump("JGE"), 0b011);
    BOOST_CHECK_EQUAL(Hasm::Coder::jump("JLT"), 0b100);
    BOOST_CHECK_EQUAL(Hasm::Coder::jump("JNE"), 0b101);
    BOOST_CHECK_EQUAL(Hasm::Coder::jump("JLE"), 0b110);
    BOOST_CHECK_EQUAL(Hasm::Coder::jump("JMP"), 0b111);
  }

BOOST_AUTO_TEST_SUITE_END()