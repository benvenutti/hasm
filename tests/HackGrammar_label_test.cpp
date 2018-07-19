#include <boost/regex.hpp>
#include <boost/test/unit_test.hpp>

#include "HackGrammar.hpp"

struct FixtureLabel
{
    const boost::regex label{ Hasm::Hack::Grammar::LABEL };
};

BOOST_FIXTURE_TEST_SUITE( label, FixtureLabel )

BOOST_AUTO_TEST_CASE( test_validLabel )
{
    BOOST_CHECK( boost::regex_match( "(A)", label ) );
    BOOST_CHECK( boost::regex_match( "(AAAAAAA)", label ) );
}

BOOST_AUTO_TEST_CASE( test_invalidLabel_missingId )
{
    BOOST_CHECK_EQUAL( boost::regex_match( "()", label ), false );
}

BOOST_AUTO_TEST_CASE( test_invalidLabel_missingLeftParen )
{
    BOOST_CHECK_EQUAL( boost::regex_match( "A)", label ), false );
}

BOOST_AUTO_TEST_CASE( test_invalidLabel_missingRightParen )
{
    BOOST_CHECK_EQUAL( boost::regex_match( "(A", label ), false );
}

BOOST_AUTO_TEST_SUITE_END()
