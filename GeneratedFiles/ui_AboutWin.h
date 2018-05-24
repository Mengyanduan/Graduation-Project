/********************************************************************************
** Form generated from reading UI file 'AboutWin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWIN_H
#define UI_ABOUTWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_AboutWin
{
public:
    QGraphicsView *Image;

    void setupUi(QDialog *AboutWin)
    {
        if (AboutWin->objectName().isEmpty())
            AboutWin->setObjectName(QStringLiteral("AboutWin"));
        AboutWin->setWindowModality(Qt::WindowModal);
        AboutWin->resize(692, 467);
        AboutWin->setModal(false);
        Image = new QGraphicsView(AboutWin);
        Image->setObjectName(QStringLiteral("Image"));
        Image->setGeometry(QRect(40, 130, 256, 192));

        retranslateUi(AboutWin);

        QMetaObject::connectSlotsByName(AboutWin);
    } // setupUi

    void retranslateUi(QDialog *AboutWin)
    {
        AboutWin->setWindowTitle(QApplication::translate("AboutWin", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutWin: public Ui_AboutWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWIN_H
