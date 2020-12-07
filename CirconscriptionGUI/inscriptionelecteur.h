#ifndef INSCRIPTIONELECTEUR_H
#define INSCRIPTIONELECTEUR_H

#include <QtGui/QDialog>
#include "ui_inscriptionelecteur.h"
#include "Date.h"
#include "Adresse.h"

class InscriptionElecteur : public QDialog
{
    Q_OBJECT

public:
    InscriptionElecteur(QWidget *parent = 0);
    ~InscriptionElecteur();

    QString reqNas() const;

    QString reqPrenom()const;
    QString reqNom() const;

    util::Date reqDateNaissance() const;

    int reqNumeroCivic() const;
    QString reqNomRue() const;
    QString reqVille() const;
    QString reqCodePostal() const;
    QString reqProvince() const;

private slots:
    void validerInscriptionElecteur();

private:
    Ui::InscriptionElecteurClass ui;
    util::Date m_dateNaissance;
};

#endif // INSCRIPTIONELECTEUR_H
