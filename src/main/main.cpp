#include <QApplication>
#include "MainWindow.h"
#include "VectorTest.h"
#include "MatrixTest.h"
using namespace std;

int main(int argc, char *argv[])
{
    //VectorTestSuite vTest = VectorTestSuite();
    //vTest.main();
    //MatrixTestSuite mTest= MatrixTestSuite();
    //mTest.main();
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
	app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    return app.exec();
}
