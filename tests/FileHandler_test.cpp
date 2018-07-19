#include <fstream>

#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>

#include "FileHandler.hpp"

struct FixtureFileName
{
    FixtureFileName()
    {
    }

    const std::string fileDotAsm = "file.asm";
};

BOOST_FIXTURE_TEST_SUITE( handlingExtensions, FixtureFileName )

BOOST_AUTO_TEST_CASE( changeExtension )
{
    BOOST_CHECK_EQUAL( Hasm::FileHandler::changeExtension( fileDotAsm, ".hack" ), "file.hack" );
    BOOST_CHECK_EQUAL( Hasm::FileHandler::changeExtension( fileDotAsm, ".Hack" ), "file.Hack" );
    BOOST_CHECK_EQUAL( Hasm::FileHandler::changeExtension( fileDotAsm, ".HACK" ), "file.HACK" );
}

BOOST_AUTO_TEST_CASE( hasExtension )
{
    BOOST_CHECK_EQUAL( Hasm::FileHandler::hasExtension( fileDotAsm, ".asm" ), true );
    BOOST_CHECK_EQUAL( Hasm::FileHandler::hasExtension( fileDotAsm, ".aSm" ), true );
    BOOST_CHECK_EQUAL( Hasm::FileHandler::hasExtension( fileDotAsm, ".ASM" ), true );
    BOOST_CHECK_EQUAL( Hasm::FileHandler::hasExtension( fileDotAsm, "asm" ), false );
    BOOST_CHECK_EQUAL( Hasm::FileHandler::hasExtension( fileDotAsm, "aSm" ), false );
    BOOST_CHECK_EQUAL( Hasm::FileHandler::hasExtension( fileDotAsm, "ASM" ), false );
}

BOOST_AUTO_TEST_SUITE_END()

struct FixtureFiles
{
    FixtureFiles()
    {
        boost::filesystem::create_directories( directoryName );
    }

    ~FixtureFiles()
    {
        if ( file.is_open() )
        {
            file.close();
        }

        boost::filesystem::remove_all( fileName );
        boost::filesystem::remove_all( directoryName );
    }

    const std::string fileName{ "testfile.asm" };
    const std::string directoryName{ "testDir" };
    std::ofstream     file{ fileName };
};

BOOST_FIXTURE_TEST_SUITE( checkingFiles, FixtureFiles )

BOOST_AUTO_TEST_CASE( isFile )
{
    BOOST_CHECK_EQUAL( Hasm::FileHandler::isFile( fileName ), true );
    BOOST_CHECK_EQUAL( Hasm::FileHandler::isFile( directoryName ), false );
}

BOOST_AUTO_TEST_SUITE_END()
