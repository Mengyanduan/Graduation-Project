/********************************************************************************
** Form generated from reading UI file 'SimplifyWin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLIFYWIN_H
#define UI_SIMPLIFYWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_SimplifyWin
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLabel *label1;

    void setupUi(QDialog *SimplifyWin)
    {
        if (SimplifyWin->objectName().isEmpty())
            SimplifyWin->setObjectName(QStringLiteral("SimplifyWin"));
        SimplifyWin->resize(439, 334);
        buttonBox = new QDialogButtonBox(SimplifyWin);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(230, 280, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lineEdit = new QLineEdit(SimplifyWin);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(220, 100, 113, 20));
        label1 = new QLabel(SimplifyWin);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(160, 100, 54, 12));

        retranslateUi(SimplifyWin);
        QObject::connect(buttonBox, SIGNAL(accepted()), SimplifyWin, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SimplifyWin, SLOT(reject()));

        QMetaObject::connectSlotsByName(SimplifyWin);
    } // setupUi

    void retranslateUi(QDialog *SimplifyWin)
    {
        SimplifyWin->setWindowTitle(QApplication::translate("SimplifyWin", "Dialog", 0));
        label1->setText(QApplication::translate("SimplifyWin", "\347\256\200\345\214\226\347\216\207\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class SimplifyWin: public Ui_SimplifyWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLIFYWIN_H
