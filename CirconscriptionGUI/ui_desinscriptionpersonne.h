/********************************************************************************
** Form generated from reading UI file 'desinscriptionpersonne.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESINSCRIPTIONPERSONNE_H
#define UI_DESINSCRIPTIONPERSONNE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DesinscriptionPersonneClass
{
public:
    QLineEdit *lineEdit_DesinscriptionPersonne_Nas;
    QLabel *label_3;
    QPushButton *pushButton_DesinscriptionPersonne_OK;
    QLabel *label_4;

    void setupUi(QDialog *DesinscriptionPersonneClass)
    {
        if (DesinscriptionPersonneClass->objectName().isEmpty())
            DesinscriptionPersonneClass->setObjectName(QString::fromUtf8("DesinscriptionPersonneClass"));
        DesinscriptionPersonneClass->resize(535, 447);
        lineEdit_DesinscriptionPersonne_Nas = new QLineEdit(DesinscriptionPersonneClass);
        lineEdit_DesinscriptionPersonne_Nas->setObjectName(QString::fromUtf8("lineEdit_DesinscriptionPersonne_Nas"));
        lineEdit_DesinscriptionPersonne_Nas->setGeometry(QRect(120, 60, 261, 27));
        label_3 = new QLabel(DesinscriptionPersonneClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 70, 53, 17));
        pushButton_DesinscriptionPersonne_OK = new QPushButton(DesinscriptionPersonneClass);
        pushButton_DesinscriptionPersonne_OK->setObjectName(QString::fromUtf8("pushButton_DesinscriptionPersonne_OK"));
        pushButton_DesinscriptionPersonne_OK->setGeometry(QRect(120, 110, 80, 28));
        label_4 = new QLabel(DesinscriptionPersonneClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(120, 20, 261, 17));

        retranslateUi(DesinscriptionPersonneClass);
        QObject::connect(pushButton_DesinscriptionPersonne_OK, SIGNAL(clicked()), DesinscriptionPersonneClass, SLOT(validerDesinscriptionPersonne()));

        QMetaObject::connectSlotsByName(DesinscriptionPersonneClass);
    } // setupUi

    void retranslateUi(QDialog *DesinscriptionPersonneClass)
    {
        DesinscriptionPersonneClass->setWindowTitle(QApplication::translate("DesinscriptionPersonneClass", "DesinscriptionPersonne", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DesinscriptionPersonneClass", "NAS", 0, QApplication::UnicodeUTF8));
        pushButton_DesinscriptionPersonne_OK->setText(QApplication::translate("DesinscriptionPersonneClass", "OK", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DesinscriptionPersonneClass", "Desinscription dune personne", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DesinscriptionPersonneClass: public Ui_DesinscriptionPersonneClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESINSCRIPTIONPERSONNE_H
