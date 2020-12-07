#ifndef INSCRIPTIONCANDIDAT_H
#define INSCRIPTIONCANDIDAT_H

#include <QtGui/QDialog>
#include "ui_inscriptioncandidat.h"
#include "Date.h"

class InscriptionCandidat : public QDialog
{
    Q_OBJECT

public:
    InscriptionCandidat(QWidget *parent = 0);
    ~InscriptionCandidat();

	QString reqNas() const;

    QString reqPrenom()const;
    QString reqNom() const;

    util::Date reqDateNaissance() const;

    int reqNumeroCivic() const;
    QString reqNomRue() const;
    QString reqVille() const;
    QString reqCodePostal() const;
    QString reqProvince() const;

    int reqPartiPolitique() const;
private slots:
void validerInscriptionCandidat();

private:
    Ui::InscriptionCandidatClass ui;
    util::Date m_dateNaissance;
};

#endif // INSCRIPTIONCANDIDAT_H
