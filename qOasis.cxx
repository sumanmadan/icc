#include <QApplication>

#include "Apps/qOasis/qOasisMainWindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	qOasisMainWindow * mainWin = new qOasisMainWindow;

	mainWin->show();
	return app.exec();
}