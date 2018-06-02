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
	void SendData(QString simplify_rate);
private slots:
	void on_buttonBox_accepted();
    //void sendData(QString text);
};

#endif // SIMPLIFY_H
