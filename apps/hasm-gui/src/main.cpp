#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <cstdlib>

int main( int argc, char* argv[] )
{
    QGuiApplication       app( argc, argv );
    QQmlApplicationEngine engine;

    engine.loadFromModule( "Hasm", "Main" );

    if ( engine.rootObjects().isEmpty() )
    {
        return EXIT_FAILURE;
    }

    return QGuiApplication::exec();
}
