#ifndef SIMPLIFY_H
#define SIMPLIFY_H

#include <QWidget>
#include <QDialog>
#include "ui_SimplifyWin.h"


class SimplifyWin : public QDialog
{
	Q_OBJECT

public:
	SimplifyWin(QWidget *parent = 0);
	~SimplifyWin();

private:
	Ui::SimplifyWin ui;
signals:
	//void  sendData(QString);
	private slots:
	//void on_buttonBox_accepted();
};

#endif // SIMPLIFY_H
