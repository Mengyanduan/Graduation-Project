#include "PointSelected.h"
//#include "ui_SimplifyWin.h"

PointSelected::PointSelected(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.lineEdit_X->setText(" ");
	ui.lineEdit_Y->setText(" ");
	ui.lineEdit_Z->setText(" ");
}

PointSelected::~PointSelected()
{

}

void PointSelected::setLineEdit(float X, float Y, float Z)
{
	ui.lineEdit_X->setText(QString("%1").arg(X, 10));
	ui.lineEdit_Y->setText(QString("%1").arg(Y, 10));
	ui.lineEdit_Z->setText(QString("%1").arg(Z, 10));
}

void PointSelected::on_buttonBox_accepted()
{
	this->close();
}