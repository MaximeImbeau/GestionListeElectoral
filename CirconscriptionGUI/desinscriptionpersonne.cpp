#include "desinscriptionpersonne.h"
#include "validationFormat.h"
#include <QMessageBox>

DesinscriptionPersonne::DesinscriptionPersonne(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

DesinscriptionPersonne::~DesinscriptionPersonne()
{

}

QString DesinscriptionPersonne::reqNas() const
{
	return ui.lineEdit_DesinscriptionPersonne_Nas->text();
}

void DesinscriptionPersonne::validerDesinscriptionPersonne()
{
	std::string NAS = ui.lineEdit_DesinscriptionPersonne_Nas->text().toUtf8().constData();
	if (util::validerNas(NAS))
	{
		QString message("Le nas ne peut pas etre invalide.");
		QMessageBox::information(this, "Erreur: ", message);
	}
}
