/********************************************************************************
** Form generated from reading UI file 'optiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONDIALOG_H
#define UI_OPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_OptionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QCheckBox *checkBox;

    void setupUi(QDialog *OptionDialog)
    {
        if (OptionDialog->objectName().isEmpty())
            OptionDialog->setObjectName("OptionDialog");
        OptionDialog->resize(575, 467);
        buttonBox = new QDialogButtonBox(OptionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(180, 410, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit = new QTextEdit(OptionDialog);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(60, 40, 104, 75));
        textEdit_2 = new QTextEdit(OptionDialog);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(60, 180, 104, 75));
        textEdit_3 = new QTextEdit(OptionDialog);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(60, 330, 104, 75));
        spinBox = new QSpinBox(OptionDialog);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(350, 60, 42, 25));
        spinBox_2 = new QSpinBox(OptionDialog);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(350, 190, 42, 25));
        spinBox_3 = new QSpinBox(OptionDialog);
        spinBox_3->setObjectName("spinBox_3");
        spinBox_3->setGeometry(QRect(350, 340, 42, 25));
        checkBox = new QCheckBox(OptionDialog);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(220, 410, 88, 24));

        retranslateUi(OptionDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, OptionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, OptionDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(OptionDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionDialog)
    {
        OptionDialog->setWindowTitle(QCoreApplication::translate("OptionDialog", "Dialog", nullptr));
        textEdit->setHtml(QCoreApplication::translate("OptionDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#f73008;\">RED</span></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("OptionDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00ff00;\">GREEN</span></p></body></html>", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("OptionDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#00aaff;\">BLUE</span></p></body></html>", nullptr));
        checkBox->setText(QCoreApplication::translate("OptionDialog", "IS VISIBLE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionDialog: public Ui_OptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDIALOG_H
