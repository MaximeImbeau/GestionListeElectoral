/********************************************************************************
** Form generated from reading UI file 'inscriptioncandidat.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSCRIPTIONCANDIDAT_H
#define UI_INSCRIPTIONCANDIDAT_H

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

class Ui_InscriptionCandidatClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_Candidat_Prenom;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_Candidat_Nom;
    QLineEdit *lineEdit_Candidat_Nas;
    QLineEdit *lineEdit_Candidat_CodePostal;
    QLineEdit *lineEdit_Candidat_Ville;
    QDateEdit *dateEdit_Candidat;
    QLabel *label_11;
    QLineEdit *lineEdit_Candidat_Province;
    QPushButton *pushButton_Candidat_OK;
    QSpinBox *spinBox_Candidat_NumeroCivic;
    QLabel *label_10;
    QLineEdit *lineEdit_Candidat_NomRue;
    QLabel *label_12;
    QSpinBox *spinBox_Candidat_PartiPolitique;
    QLabel *label_4;

    void setupUi(QDialog *InscriptionCandidatClass)
    {
        if (InscriptionCandidatClass->objectName().isEmpty())
            InscriptionCandidatClass->setObjectName(QString::fromUtf8("InscriptionCandidatClass"));
        InscriptionCandidatClass->resize(523, 576);
        label = new QLabel(InscriptionCandidatClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 130, 53, 17));
        label_2 = new QLabel(InscriptionCandidatClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 90, 53, 17));
        lineEdit_Candidat_Prenom = new QLineEdit(InscriptionCandidatClass);
        lineEdit_Candidat_Prenom->setObjectName(QString::fromUtf8("lineEdit_Candidat_Prenom"));
        lineEdit_Candidat_Prenom->setGeometry(QRect(180, 80, 261, 27));
        label_3 = new QLabel(InscriptionCandidatClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 50, 53, 17));
        label_5 = new QLabel(InscriptionCandidatClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 210, 91, 16));
        label_6 = new QLabel(InscriptionCandidatClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 360, 91, 16));
        label_7 = new QLabel(InscriptionCandidatClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 240, 91, 16));
        label_8 = new QLabel(InscriptionCandidatClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 320, 91, 16));
        label_9 = new QLabel(InscriptionCandidatClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 400, 91, 16));
        lineEdit_Candidat_Nom = new QLineEdit(InscriptionCandidatClass);
        lineEdit_Candidat_Nom->setObjectName(QString::fromUtf8("lineEdit_Candidat_Nom"));
        lineEdit_Candidat_Nom->setGeometry(QRect(180, 120, 261, 27));
        lineEdit_Candidat_Nas = new QLineEdit(InscriptionCandidatClass);
        lineEdit_Candidat_Nas->setObjectName(QString::fromUtf8("lineEdit_Candidat_Nas"));
        lineEdit_Candidat_Nas->setGeometry(QRect(180, 40, 261, 27));
        lineEdit_Candidat_CodePostal = new QLineEdit(InscriptionCandidatClass);
        lineEdit_Candidat_CodePostal->setObjectName(QString::fromUtf8("lineEdit_Candidat_CodePostal"));
        lineEdit_Candidat_CodePostal->setGeometry(QRect(180, 350, 261, 27));
        lineEdit_Candidat_Ville = new QLineEdit(InscriptionCandidatClass);
        lineEdit_Candidat_Ville->setObjectName(QString::fromUtf8("lineEdit_Candidat_Ville"));
        lineEdit_Candidat_Ville->setGeometry(QRect(180, 310, 261, 27));
        dateEdit_Candidat = new QDateEdit(InscriptionCandidatClass);
        dateEdit_Candidat->setObjectName(QString::fromUtf8("dateEdit_Candidat"));
        dateEdit_Candidat->setGeometry(QRect(180, 160, 261, 27));
        dateEdit_Candidat->setCalendarPopup(true);
        label_11 = new QLabel(InscriptionCandidatClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(40, 170, 111, 16));
        lineEdit_Candidat_Province = new QLineEdit(InscriptionCandidatClass);
        lineEdit_Candidat_Province->setObjectName(QString::fromUtf8("lineEdit_Candidat_Province"));
        lineEdit_Candidat_Province->setGeometry(QRect(180, 390, 261, 27));
        pushButton_Candidat_OK = new QPushButton(InscriptionCandidatClass);
        pushButton_Candidat_OK->setObjectName(QString::fromUtf8("pushButton_Candidat_OK"));
        pushButton_Candidat_OK->setGeometry(QRect(180, 490, 80, 28));
        spinBox_Candidat_NumeroCivic = new QSpinBox(InscriptionCandidatClass);
        spinBox_Candidat_NumeroCivic->setObjectName(QString::fromUtf8("spinBox_Candidat_NumeroCivic"));
        spinBox_Candidat_NumeroCivic->setGeometry(QRect(180, 230, 261, 27));
        label_10 = new QLabel(InscriptionCandidatClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 450, 91, 16));
        lineEdit_Candidat_NomRue = new QLineEdit(InscriptionCandidatClass);
        lineEdit_Candidat_NomRue->setObjectName(QString::fromUtf8("lineEdit_Candidat_NomRue"));
        lineEdit_Candidat_NomRue->setGeometry(QRect(180, 270, 261, 27));
        label_12 = new QLabel(InscriptionCandidatClass);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 280, 91, 16));
        spinBox_Candidat_PartiPolitique = new QSpinBox(InscriptionCandidatClass);
        spinBox_Candidat_PartiPolitique->setObjectName(QString::fromUtf8("spinBox_Candidat_PartiPolitique"));
        spinBox_Candidat_PartiPolitique->setGeometry(QRect(180, 440, 261, 27));
        label_4 = new QLabel(InscriptionCandidatClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 10, 261, 17));

        retranslateUi(InscriptionCandidatClass);
        QObject::connect(pushButton_Candidat_OK, SIGNAL(clicked()), InscriptionCandidatClass, SLOT(validerInscriptionCandidat()));

        QMetaObject::connectSlotsByName(InscriptionCandidatClass);
    } // setupUi

    void retranslateUi(QDialog *InscriptionCandidatClass)
    {
        InscriptionCandidatClass->setWindowTitle(QApplication::translate("InscriptionCandidatClass", "InscriptionCandidat", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InscriptionCandidatClass", "Nom:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("InscriptionCandidatClass", "Prenom:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("InscriptionCandidatClass", "NAS", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("InscriptionCandidatClass", "Adresse:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("InscriptionCandidatClass", "Code postal:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("InscriptionCandidatClass", "Numero civic:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("InscriptionCandidatClass", "Ville:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("InscriptionCandidatClass", "Province:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("InscriptionCandidatClass", "Date de naissance:", 0, QApplication::UnicodeUTF8));
        pushButton_Candidat_OK->setText(QApplication::translate("InscriptionCandidatClass", "OK", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("InscriptionCandidatClass", "Parti politique:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("InscriptionCandidatClass", "Nom rue:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("InscriptionCandidatClass", "Inscription dun candidat", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InscriptionCandidatClass: public Ui_InscriptionCandidatClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSCRIPTIONCANDIDAT_H
