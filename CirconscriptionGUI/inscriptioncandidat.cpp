#include "inscriptioncandidat.h"
#include <QMessageBox>
#include <validationFormat.h>
#include "Date.h"

InscriptionCandidat::InscriptionCandidat(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

InscriptionCandidat::~InscriptionCandidat()
{
}

QString InscriptionCandidat::reqNas() const
{
	return ui.lineEdit_Candidat_Nas->text();
}

QString InscriptionCandidat::reqPrenom()const
{
	return ui.lineEdit_Candidat_Prenom->text();
}
QString InscriptionCandidat::reqNom() const
{
	return ui.lineEdit_Candidat_Nom->text();
}

util::Date InscriptionCandidat::reqDateNaissance() const
{
	return m_dateNaissance;
}

int InscriptionCandidat::reqNumeroCivic() const
{
	return ui.spinBox_Candidat_NumeroCivic->value();
}

QString InscriptionCandidat::reqNomRue() const
{
	return ui.lineEdit_Candidat_NomRue->text();
}

QString InscriptionCandidat::reqVille() const
{
	return ui.lineEdit_Candidat_Ville->text();
}

QString InscriptionCandidat::reqCodePostal() const
{
	return ui.lineEdit_Candidat_CodePostal->text();
}

QString InscriptionCandidat::reqProvince() const
{
	return ui.lineEdit_Candidat_Province->text();
}

int InscriptionCandidat::reqPartiPolitique() const
{
	return ui.spinBox_Candidat_PartiPolitique->value();
}

void InscriptionCandidat::validerInscriptionCandidat()
{
	std::string NAS = ui.lineEdit_Candidat_Nas->text().toUtf8().constData();
	if (util::validerNas(NAS) == false)
	{
		QString message("Le nas doit etre valide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.lineEdit_Candidat_Prenom->text().isEmpty())
	{
		QString message("Le prenom ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.lineEdit_Candidat_Nom->text().isEmpty())
	{
		QString message("Le nom ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.spinBox_Candidat_NumeroCivic->value() <= 0)
	{
		QString message("Le numero civic ne peut pas etre inferieur ou egal a 0.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.lineEdit_Candidat_NomRue->text().isEmpty())
	{
		QString message("Le nom de rue ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.lineEdit_Candidat_Ville->text().isEmpty())
	{
		QString message("Le nom de la ville ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.lineEdit_Candidat_CodePostal->text().isEmpty())
	{
		QString message("Le code postal ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.lineEdit_Candidat_Province->text().isEmpty())
	{
		QString message("Le nom de la province ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}

	if (ui.spinBox_Candidat_PartiPolitique->value() < 0 or ui.spinBox_Candidat_PartiPolitique->value() > 4)
	{
		QString message("Le nom de la province ne peut pas etre vide.");
		QMessageBox::information(this, "Erreur: ", message);
		return;
	}
	else
	{
		m_dateNaissance.asgDate(ui.dateEdit_Candidat->date().day(), ui.dateEdit_Candidat->date().month(),
						ui.dateEdit_Candidat->date().year());
		accept();
	}
	return;
}
