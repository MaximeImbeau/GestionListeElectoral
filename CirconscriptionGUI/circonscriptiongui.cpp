#include "circonscriptiongui.h"
#include "inscriptioncandidat.h"
#include "inscriptionelecteur.h"
#include "desinscriptionpersonne.h"
#include "Candidat.h"
#include "Electeur.h"
#include "Adresse.h"
#include "Date.h"

CirconscriptionGUI::CirconscriptionGUI(QWidget *parent)
    : QMainWindow(parent)
{
	m_circonscription = new elections::Circonscription("Circonscription 1", elections::Candidat ("046 454 286", "inconnu", "inconnu", util::Date(12,05,1979), util::Adresse(1, "rue inconnue", "inconnue", "G1V 0A7", "QC"),2));
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
			elections::Candidat unCandidat(inscriptionCandidat.reqNas().toUtf8().constData(), inscriptionCandidat.reqPrenom().toUtf8().constData(), inscriptionCandidat.reqNom().toUtf8().constData(),
					inscriptionCandidat.reqDateNaissance(), util::Adresse (inscriptionCandidat.reqNumeroCivic(), inscriptionCandidat.reqNomRue().toUtf8().constData(),
					inscriptionCandidat.reqVille().toUtf8().constData(),inscriptionCandidat.reqCodePostal().toUtf8().constData(), inscriptionCandidat.reqProvince().toUtf8().constData()), inscriptionCandidat.reqPartiPolitique());
			m_circonscription->inscrire(unCandidat);
			//Affichage dans la console
			ui.affichage->setText(QString::fromStdString(m_circonscription->reqCirconscriptionFormate()));
		}
}
void CirconscriptionGUI::dialogueInscriptionElecteur()
{
	InscriptionElecteur inscriptionElecteur(this);
	if (inscriptionElecteur.exec())
		{
			//METTRE LA METHODE POUR AJOUTER UN CANDIDAT ICI:
			elections::Electeur unElecteur(inscriptionElecteur.reqNas().toUtf8().constData(), inscriptionElecteur.reqPrenom().toUtf8().constData(), inscriptionElecteur.reqNom().toUtf8().constData(),
					inscriptionElecteur.reqDateNaissance(), util::Adresse (inscriptionElecteur.reqNumeroCivic(), inscriptionElecteur.reqNomRue().toUtf8().constData(),
					inscriptionElecteur.reqVille().toUtf8().constData(),inscriptionElecteur.reqCodePostal().toUtf8().constData(), inscriptionElecteur.reqProvince().toUtf8().constData()));
			m_circonscription->inscrire(unElecteur);
			//Affichage dans la console
			ui.affichage->setText(QString::fromStdString(m_circonscription->reqCirconscriptionFormate()));
		}
}
void CirconscriptionGUI::dialogueDesinscriptionPersonne()
{
	DesinscriptionPersonne desinscriptionPersonne(this);
	if (desinscriptionPersonne.exec())
		{
			//METTRE LA METHODE POUR DESINSCRIRE ICI:

			//Affichage dans la console
			ui.affichage->setText(QString::fromStdString(m_circonscription->reqCirconscriptionFormate()));
		}
}
