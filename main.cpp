#include "qtapplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtApplication w;
	w.show();
	return a.exec();
}
