#include "SimplifyWin.h"

SimplifyWin::SimplifyWin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//connect(ui.lineEdit, SIGNAL(textChange(QString)), this, SLOT(SendData(QString)));
}

SimplifyWin::~SimplifyWin()
{

}

//void SimplifyWin::sendData(QString)
//{
//	bool ok = true;
//	emit sendData2(ui.lineEdit->text());
//}

void SimplifyWin::on_buttonBox_accepted()
{
	emit SendData(ui.SimplifyRate->text());
	this->close();
}