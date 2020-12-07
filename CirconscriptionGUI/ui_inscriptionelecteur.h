/********************************************************************************
** Form generated from reading UI file 'inscriptionelecteur.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSCRIPTIONELECTEUR_H
#define UI_INSCRIPTIONELECTEUR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_InscriptionElecteurClass
{
public:
    QLineEdit *lineEdit_Electeur_Prenom;
    QLineEdit *lineEdit_Electeur_Ville;
    QLabel *label_6;
    QLabel *label_11;
    QLineEdit *lineEdit_Electeur_Nom;
    QLabel *label_2;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_5;
    QLineEdit *lineEdit_Electeur_Nas;
    QLineEdit *lineEdit_Electeur_Province;
    QLabel *label_3;
    QLabel *label_8;
    QDateEdit *dateEdit_Electeur;
    QLineEdit *lineEdit_Electeur_CodePostal;
    QPushButton *pushButton_Electeur_Ok;
    QSpinBox *spinBox_Electeur_NumeroCivic;
    QLineEdit *lineEdit_Electeur_NomRue;
    QLabel *label_10;
    QLabel *label_4;

    void setupUi(QDialog *InscriptionElecteurClass)
    {
        if (InscriptionElecteurClass->objectName().isEmpty())
            InscriptionElecteurClass->setObjectName(QString::fromUtf8("InscriptionElecteurClass"));
        InscriptionElecteurClass->resize(667, 542);
        lineEdit_Electeur_Prenom = new QLineEdit(InscriptionElecteurClass);
        lineEdit_Electeur_Prenom->setObjectName(QString::fromUtf8("lineEdit_Electeur_Prenom"));
        lineEdit_Electeur_Prenom->setGeometry(QRect(170, 80, 261, 27));
        lineEdit_Electeur_Ville = new QLineEdit(InscriptionElecteurClass);
        lineEdit_Electeur_Ville->setObjectName(QString::fromUtf8("lineEdit_Electeur_Ville"));
        lineEdit_Electeur_Ville->setGeometry(QRect(170, 360, 261, 27));
        label_6 = new QLabel(InscriptionElecteurClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 330, 91, 16));
        label_11 = new QLabel(InscriptionElecteurClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 170, 111, 16));
        lineEdit_Electeur_Nom = new QLineEdit(InscriptionElecteurClass);
        lineEdit_Electeur_Nom->setObjectName(QString::fromUtf8("lineEdit_Electeur_Nom"));
        lineEdit_Electeur_Nom->setGeometry(QRect(170, 120, 261, 27));
        label_2 = new QLabel(InscriptionElecteurClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 53, 17));
        label_9 = new QLabel(InscriptionElecteurClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 410, 91, 16));
        label_7 = new QLabel(InscriptionElecteurClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 240, 91, 16));
        label = new QLabel(InscriptionElecteurClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 130, 53, 17));
        label_5 = new QLabel(InscriptionElecteurClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 210, 91, 16));
        lineEdit_Electeur_Nas = new QLineEdit(InscriptionElecteurClass);
        lineEdit_Electeur_Nas->setObjectName(QString::fromUtf8("lineEdit_Electeur_Nas"));
        lineEdit_Electeur_Nas->setGeometry(QRect(170, 40, 261, 27));
        lineEdit_Electeur_Province = new QLineEdit(InscriptionElecteurClass);
        lineEdit_Electeur_Province->setObjectName(QString::fromUtf8("lineEdit_Electeur_Province"));
        lineEdit_Electeur_Province->setGeometry(QRect(170, 400, 261, 27));
        label_3 = new QLabel(InscriptionElecteurClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 50, 53, 17));
        label_8 = new QLabel(InscriptionElecteurClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 370, 91, 16));
        dateEdit_Electeur = new QDateEdit(InscriptionElecteurClass);
        dateEdit_Electeur->setObjectName(QString::fromUtf8("dateEdit_Electeur"));
        dateEdit_Electeur->setGeometry(QRect(170, 160, 261, 27));
        dateEdit_Electeur->setCalendarPopup(true);
        lineEdit_Electeur_CodePostal = new QLineEdit(InscriptionElecteurClass);
        lineEdit_Electeur_CodePostal->setObjectName(QString::fromUtf8("lineEdit_Electeur_CodePostal"));
        lineEdit_Electeur_CodePostal->setGeometry(QRect(170, 320, 261, 27));
        pushButton_Electeur_Ok = new QPushButton(InscriptionElecteurClass);
        pushButton_Electeur_Ok->setObjectName(QString::fromUtf8("pushButton_Electeur_Ok"));
        pushButton_Electeur_Ok->setGeometry(QRect(170, 460, 80, 28));
        spinBox_Electeur_NumeroCivic = new QSpinBox(InscriptionElecteurClass);
        spinBox_Electeur_NumeroCivic->setObjectName(QString::fromUtf8("spinBox_Electeur_NumeroCivic"));
        spinBox_Electeur_NumeroCivic->setGeometry(QRect(170, 230, 261, 27));
        lineEdit_Electeur_NomRue = new QLineEdit(InscriptionElecteurClass);
        lineEdit_Electeur_NomRue->setObjectName(QString::fromUtf8("lineEdit_Electeur_NomRue"));
        lineEdit_Electeur_NomRue->setGeometry(QRect(170, 280, 261, 27));
        label_10 = new QLabel(InscriptionElecteurClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 290, 91, 16));
        label_4 = new QLabel(InscriptionElecteurClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 10, 261, 17));

        retranslateUi(InscriptionElecteurClass);
        QObject::connect(pushButton_Electeur_Ok, SIGNAL(clicked()), InscriptionElecteurClass, SLOT(validerInscriptionElecteur()));

        QMetaObject::connectSlotsByName(InscriptionElecteurClass);
    } // setupUi

    void retranslateUi(QDialog *InscriptionElecteurClass)
    {
        InscriptionElecteurClass->setWindowTitle(QApplication::translate("InscriptionElecteurClass", "InscriptionElecteur", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("InscriptionElecteurClass", "Code postal:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("InscriptionElecteurClass", "Date de naissance:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("InscriptionElecteurClass", "Prenom:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("InscriptionElecteurClass", "Province:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("InscriptionElecteurClass", "Numero civic:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InscriptionElecteurClass", "Nom:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("InscriptionElecteurClass", "Adresse:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("InscriptionElecteurClass", "NAS", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("InscriptionElecteurClass", "Ville:", 0, QApplication::UnicodeUTF8));
        pushButton_Electeur_Ok->setText(QApplication::translate("InscriptionElecteurClass", "OK", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("InscriptionElecteurClass", "Nom rue:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("InscriptionElecteurClass", "Inscription dun electeur", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InscriptionElecteurClass: public Ui_InscriptionElecteurClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSCRIPTIONELECTEUR_H
