/********************************************************************************
** Form generated from reading UI file 'circonscriptiongui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCONSCRIPTIONGUI_H
#define UI_CIRCONSCRIPTIONGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CirconscriptionGUIClass
{
public:
    QAction *InscriptionCandidat;
    QAction *InscriptionElecteur;
    QAction *DesinscrirePersonne;
    QAction *Quitter;
    QWidget *centralwidget;
    QTextEdit *affichage;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CirconscriptionGUIClass)
    {
        if (CirconscriptionGUIClass->objectName().isEmpty())
            CirconscriptionGUIClass->setObjectName(QString::fromUtf8("CirconscriptionGUIClass"));
        CirconscriptionGUIClass->resize(800, 600);
        InscriptionCandidat = new QAction(CirconscriptionGUIClass);
        InscriptionCandidat->setObjectName(QString::fromUtf8("InscriptionCandidat"));
        InscriptionElecteur = new QAction(CirconscriptionGUIClass);
        InscriptionElecteur->setObjectName(QString::fromUtf8("InscriptionElecteur"));
        DesinscrirePersonne = new QAction(CirconscriptionGUIClass);
        DesinscrirePersonne->setObjectName(QString::fromUtf8("DesinscrirePersonne"));
        Quitter = new QAction(CirconscriptionGUIClass);
        Quitter->setObjectName(QString::fromUtf8("Quitter"));
        centralwidget = new QWidget(CirconscriptionGUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        affichage = new QTextEdit(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(10, 10, 781, 541));
        CirconscriptionGUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CirconscriptionGUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        CirconscriptionGUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(CirconscriptionGUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CirconscriptionGUIClass->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(InscriptionCandidat);
        menuMenu->addAction(InscriptionElecteur);
        menuMenu->addAction(DesinscrirePersonne);
        menuMenu->addAction(Quitter);

        retranslateUi(CirconscriptionGUIClass);
        QObject::connect(Quitter, SIGNAL(triggered()), CirconscriptionGUIClass, SLOT(close()));
        QObject::connect(InscriptionElecteur, SIGNAL(triggered()), CirconscriptionGUIClass, SLOT(dialogueInscriptionElecteur()));
        QObject::connect(InscriptionCandidat, SIGNAL(triggered()), CirconscriptionGUIClass, SLOT(dialogueInscriptionCandidat()));
        QObject::connect(DesinscrirePersonne, SIGNAL(triggered()), CirconscriptionGUIClass, SLOT(dialogueDesinscriptionPersonne()));

        QMetaObject::connectSlotsByName(CirconscriptionGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *CirconscriptionGUIClass)
    {
        CirconscriptionGUIClass->setWindowTitle(QApplication::translate("CirconscriptionGUIClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        InscriptionCandidat->setText(QApplication::translate("CirconscriptionGUIClass", "InscriptionCandidat", 0, QApplication::UnicodeUTF8));
        InscriptionElecteur->setText(QApplication::translate("CirconscriptionGUIClass", "InscriptionElecteur", 0, QApplication::UnicodeUTF8));
        DesinscrirePersonne->setText(QApplication::translate("CirconscriptionGUIClass", "DesinscrirePersonne", 0, QApplication::UnicodeUTF8));
        Quitter->setText(QApplication::translate("CirconscriptionGUIClass", "Quitter", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("CirconscriptionGUIClass", "Menu", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CirconscriptionGUIClass: public Ui_CirconscriptionGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCONSCRIPTIONGUI_H
