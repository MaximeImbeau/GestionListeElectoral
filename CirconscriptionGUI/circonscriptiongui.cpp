#include "circonscriptiongui.h"
#include "inscriptioncandidat.h"
#include "inscriptionelecteur.h"
#include "desinscriptionpersonne.h"
#include "Candidat.h"
#include "Electeur.h"
#include "Adresse.h"
#include "Date.h"
#include "Circonscription.h"
#include <QMessageBox>

CirconscriptionGUI::CirconscriptionGUI(QWidget *parent)
    : QMainWindow(parent), m_circonscription("Circonscription 1",
    		elections::Candidat("046 454 286", "inconnu", "inconnu", util::Date(12,05,1979),
			util::Adresse(1, "rue inconnue", "inconnue", "G1V 0A7", "QC"),2))
{
	ui.setupUi(this);
}

CirconscriptionGUI::~CirconscriptionGUI()
{
}

void CirconscriptionGUI::dialogueInscriptionCandidat()
{
	InscriptionCandidat inscriptionCandidat(this);
	if (inscriptionCandidat.exec())
		{
		//Utilisation de la methode inscrire pour un candidat
			elections::Candidat unCandidat(inscriptionCandidat.reqNas().toUtf8().constData(), inscriptionCandidat.reqPrenom().toUtf8().constData(), inscriptionCandidat.reqNom().toUtf8().constData(),
					inscriptionCandidat.reqDateNaissance(), util::Adresse (inscriptionCandidat.reqNumeroCivic(), inscriptionCandidat.reqNomRue().toUtf8().constData(),
					inscriptionCandidat.reqVille().toUtf8().constData(),inscriptionCandidat.reqCodePostal().toUtf8().constData(), inscriptionCandidat.reqProvince().toUtf8().constData()), inscriptionCandidat.reqPartiPolitique());
			if (!m_circonscription.personneEstDejaPresente(unCandidat.reqNas()))
			{
				m_circonscription.inscrire(unCandidat);
			}
			else
			{
				QString message("La personne est deja presente dans la liste electorale.");
				QMessageBox::information(this, "Erreur: ", message);
			}
			//Affichage dans la console
			ui.affichage->setText(QString::fromStdString(m_circonscription.reqCirconscriptionFormate()));
		}
	return;
}
void CirconscriptionGUI::dialogueInscriptionElecteur()
{
	InscriptionElecteur inscriptionElecteur(this);
	if (inscriptionElecteur.exec())
		{
			elections::Electeur unElecteur(inscriptionElecteur.reqNas().toUtf8().constData(), inscriptionElecteur.reqPrenom().toUtf8().constData(), inscriptionElecteur.reqNom().toUtf8().constData(),
					inscriptionElecteur.reqDateNaissance(), util::Adresse (inscriptionElecteur.reqNumeroCivic(), inscriptionElecteur.reqNomRue().toUtf8().constData(),
					inscriptionElecteur.reqVille().toUtf8().constData(),inscriptionElecteur.reqCodePostal().toUtf8().constData(), inscriptionElecteur.reqProvince().toUtf8().constData()));
			if (!m_circonscription.personneEstDejaPresente(unElecteur.reqNas()))
			{
				//Utilisation de la methode inscrire pour un electeur
				m_circonscription.inscrire(unElecteur);
			}
			else
			{
				QString message("La personne est deja presente dans la liste electorale.");
				QMessageBox::information(this, "Erreur: ", message);
			}
			//Affichage dans la console
			ui.affichage->setText(QString::fromStdString(m_circonscription.reqCirconscriptionFormate()));
			return;
		}
}
void CirconscriptionGUI::dialogueDesinscriptionPersonne()
{
	DesinscriptionPersonne desinscriptionPersonne(this);
	if (desinscriptionPersonne.exec())
		{
			if (m_circonscription.personneEstDejaPresente(desinscriptionPersonne.reqNas().toUtf8().constData()))
			{
				//Utilisation de la m??thode desinscrire
				m_circonscription.desinscrire(desinscriptionPersonne.reqNas().toUtf8().constData());
			}
			else
			{
				QString message("La personne nexiste pas dans la liste electorale.");
				QMessageBox::information(this, "Erreur: ", message);
			}
			//Affichage dans la console
			ui.affichage->setText(QString::fromStdString(m_circonscription.reqCirconscriptionFormate()));
		}
	return;
}
