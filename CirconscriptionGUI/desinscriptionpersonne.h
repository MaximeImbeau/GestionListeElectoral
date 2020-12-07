#ifndef DESINSCRIPTIONPERSONNE_H
#define DESINSCRIPTIONPERSONNE_H

#include <QtGui/QDialog>
#include "ui_desinscriptionpersonne.h"

class DesinscriptionPersonne : public QDialog
{
    Q_OBJECT

public:
    DesinscriptionPersonne(QWidget *parent = 0);
    ~DesinscriptionPersonne();
    QString reqNas() const;

private slots:
    void validerDesinscriptionPersonne();

private:
    Ui::DesinscriptionPersonneClass ui;
};

#endif // DESINSCRIPTIONPERSONNE_H
