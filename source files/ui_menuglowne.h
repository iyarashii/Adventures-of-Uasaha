/********************************************************************************
** Form generated from reading UI file 'menuglowne.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUGLOWNE_H
#define UI_MENUGLOWNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuGlowne
{
public:
    QWidget *centralwidget;
    QPushButton *opcje;
    QPushButton *wyjscie;
    QPushButton *start;

    void setupUi(QMainWindow *MenuGlowne)
    {
        if (MenuGlowne->objectName().isEmpty())
            MenuGlowne->setObjectName(QStringLiteral("MenuGlowne"));
        MenuGlowne->resize(800, 600);
        MenuGlowne->setMinimumSize(QSize(800, 600));
        MenuGlowne->setMaximumSize(QSize(800, 600));
        QIcon icon;
        icon.addFile(QStringLiteral(":/grafika/uasaha_ikonka.png"), QSize(), QIcon::Normal, QIcon::Off);
        MenuGlowne->setWindowIcon(icon);
        centralwidget = new QWidget(MenuGlowne);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        opcje = new QPushButton(centralwidget);
        opcje->setObjectName(QStringLiteral("opcje"));
        opcje->setGeometry(QRect(-10, 180, 421, 211));
        wyjscie = new QPushButton(centralwidget);
        wyjscie->setObjectName(QStringLiteral("wyjscie"));
        wyjscie->setGeometry(QRect(-10, 380, 421, 221));
        start = new QPushButton(centralwidget);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(-10, -10, 421, 201));
        start->setStyleSheet(QStringLiteral(""));
        MenuGlowne->setCentralWidget(centralwidget);

        retranslateUi(MenuGlowne);

        QMetaObject::connectSlotsByName(MenuGlowne);
    } // setupUi

    void retranslateUi(QMainWindow *MenuGlowne)
    {
        MenuGlowne->setWindowTitle(QApplication::translate("MenuGlowne", "Adventures of Uasaha", Q_NULLPTR));
        opcje->setText(QApplication::translate("MenuGlowne", "CONTROLS", Q_NULLPTR));
        wyjscie->setText(QApplication::translate("MenuGlowne", "EXIT", Q_NULLPTR));
        start->setText(QApplication::translate("MenuGlowne", "START", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MenuGlowne: public Ui_MenuGlowne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUGLOWNE_H
