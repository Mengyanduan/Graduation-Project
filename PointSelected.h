#ifndef POINTSELECTED_H
#define POINTSELECTED_H

#include <QWidget>
#include <QDialog>
#include "ui_PointSelected.h"


class PointSelected : public QDialog
{
	Q_OBJECT

public:
	PointSelected(QWidget *parent = 0);
	~PointSelected();
	void setLineEdit(float X, float Y, float Z);
private:
	Ui::PointSelected ui;

signals:
	private slots:
	void on_buttonBox_accepted();
};

#endif // POINTSELECTED_H
