/********************************************************************************
** Form generated from reading UI file 'sterowanie.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STEROWANIE_H
#define UI_STEROWANIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Sterowanie
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *Sterowanie)
    {
        if (Sterowanie->objectName().isEmpty())
            Sterowanie->setObjectName(QStringLiteral("Sterowanie"));
        Sterowanie->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/grafika/uasaha_ikonka.png"), QSize(), QIcon::Normal, QIcon::Off);
        Sterowanie->setWindowIcon(icon);
        textBrowser = new QTextBrowser(Sterowanie);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 400, 300));

        retranslateUi(Sterowanie);

        QMetaObject::connectSlotsByName(Sterowanie);
    } // setupUi

    void retranslateUi(QDialog *Sterowanie)
    {
        Sterowanie->setWindowTitle(QApplication::translate("Sterowanie", "Controls", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("Sterowanie", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Right arrow key - moves player to the right</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Left arrow key - moves player to the left</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Spacebar - shoots(holding spacebar will shoot continuously)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Esc - pause/unpause</p>\n"
""
                        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">M - when the game is paused - returns to main menu, when not does nothing </p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Sterowanie: public Ui_Sterowanie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STEROWANIE_H
