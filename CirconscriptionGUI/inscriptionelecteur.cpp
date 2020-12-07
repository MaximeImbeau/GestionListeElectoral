#include "inscriptionelecteur.h"
#include "validationFormat.h"
#include <QMessageBox>

InscriptionElecteur::InscriptionElecteur(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

InscriptionElecteur::~InscriptionElecteur()
{
}

QString InscriptionElecteur::reqNas() const
{
	return ui.lineEdit_Electeur_Nas->text();
}

QString InscriptionElecteur::reqPrenom()const
{
	return ui.lineEdit_Electeur_Prenom->text();
}
QString InscriptionElecteur::reqNom() const
{
	return ui.lineEdit_Electeur_Nom->text();
}

util::Date InscriptionElecteur::reqDateNaissance() const
{
	return m_dateNaissance;
}

int InscriptionElecteur::reqNumeroCivic() const
{
	return ui.spinBox_Electeur_NumeroCivic->value();
}

QString InscriptionElecteur::reqNomRue() const
{
	return ui.lineEdit_Electeur_NomRue->text();
}

QString InscriptionElecteur::reqVille() const
{
	return ui.lineEdit_Electeur_Ville->text();
}

QString InscriptionElecteur::reqCodePostal() const
{
	return ui.lineEdit_Electeur_CodePostal->text();
}

QString InscriptionElecteur::reqProvince() const
{
	return ui.lineEdit_Electeur_Province->text();
}

void InscriptionElecteur::validerInscriptionElecteur()
{
	std::string NAS = ui.lineEdit_Electeur_Nas->text().toUtf8().constData();
	if (util::validerNas(NAS) == false)
	{
		QString message("Le nas doit etre valide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.lineEdit_Electeur_Prenom->text().isEmpty())
	{
		QString message("Le prenom ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.lineEdit_Electeur_Nom->text().isEmpty())
	{
		QString message("Le nom ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.spinBox_Electeur_NumeroCivic->value() <= 0)
	{
		QString message("Le numero civic ne peut pas etre inferieur ou egal a 0.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.lineEdit_Electeur_NomRue->text().isEmpty())
	{
		QString message("Le nom de rue ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.lineEdit_Electeur_Ville->text().isEmpty())
	{
		QString message("Le nom de la ville ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.lineEdit_Electeur_CodePostal->text().isEmpty())
	{
		QString message("Le code postal ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.lineEdit_Electeur_Province->text().isEmpty())
	{
		QString message("Le nom de la province ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}
	else
	{
		m_dateNaissance.asgDate(ui.dateEdit_Electeur->date().day(), ui.dateEdit_Electeur->date().month(),
						ui.dateEdit_Electeur->date().year());
		accept();
	}
}
