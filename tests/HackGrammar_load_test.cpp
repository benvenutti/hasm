#include "HackGrammar.hpp"

#include <boost/regex.hpp>
#include <boost/test/unit_test.hpp>

struct FixtureLoad
{
    const boost::regex load{ Hasm::Hack::Grammar::LOAD };
};

BOOST_FIXTURE_TEST_SUITE( load, FixtureLoad )

BOOST_AUTO_TEST_CASE( test_validLoad_symbol )
{
    BOOST_CHECK( boost::regex_match( "@A", load ) );
    BOOST_CHECK( boost::regex_match( "@SYMBOL", load ) );
}

BOOST_AUTO_TEST_CASE( test_validLoad_integer )
{
    BOOST_CHECK( boost::regex_match( "@1010", load ) );
}

BOOST_AUTO_TEST_CASE( test_invalidLoad_invalidSymbol )
{
    BOOST_CHECK_EQUAL( boost::regex_match( "SYM+BOL", load ), false );
}

BOOST_AUTO_TEST_CASE( test_invalidLoad_invalidSignedInteger )
{
    BOOST_CHECK_EQUAL( boost::regex_match( "-1010", load ), false );
    BOOST_CHECK_EQUAL( boost::regex_match( "+1010", load ), false );
}

BOOST_AUTO_TEST_CASE( test_invalidLoad_symbolMissingAt )
{
    BOOST_CHECK_EQUAL( boost::regex_match( "SYMBOL", load ), false );
}

BOOST_AUTO_TEST_CASE( test_invalidLoad_integerMissingAt )
{
    BOOST_CHECK_EQUAL( boost::regex_match( "1010", load ), false );
}

BOOST_AUTO_TEST_CASE( test_invalidLoad_missingValue )
{
    BOOST_CHECK_EQUAL( boost::regex_match( "@", load ), false );
}

BOOST_AUTO_TEST_SUITE_END()
