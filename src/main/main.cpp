#include <QApplication>
#include "MainWindow.h"
#include "VectorTest.h"
using namespace std;

int main(int argc, char *argv[])
{
    VectorTestSuite test = VectorTestSuite();
    test.main();
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
	app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    return app.exec();
}
