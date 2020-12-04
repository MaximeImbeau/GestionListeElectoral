/**
 * \file programmePrincipal.cpp
 * \brief Programme interactif minimaliste qui permet simplement d’obtenir interactivement avec l’usager, les données nécessaires
 * 		  (que l’on valide à la saisie) pour créer une "Circonscription".
 * \author Maxime Imbeau
 * \version 0.1
 * \date 24/11/2020
 */
#include <string>
#include <iostream>
#include <sstream>
#include "validationFormat.h"
#include "Candidat.h"
#include "Electeur.h"
#include "Circonscription.h"

using namespace std;
/**
 * \fn int main(void)
 * \brief Programme minimaliste afin d'inscrire des candidats et des electeurs sur une liste electorale.
 *
 * \return La fin du programme
 */
int main(void)
{
	cout << "--------------------------------------------" << endl;
	cout << "Bienvenue a l'outil de gestion des listes électorales" << endl;
	cout << "--------------------------------------------" << endl;
	cout << endl;
	cout << "Inscription d'un candidat sortant" << endl;
	int partiPolitique = 0;
	do
	{
		cout << "Choisissez un parti:" << endl;
		cout << "0:BLOC_QUEBECOIS, 1:CONSERVATEUR,2:INDEPENDANT,3:LIBERAL,4:NOUVEAU_PARTI_DEMOCRATIQUE" << endl;
		cin >> partiPolitique;
	} while(partiPolitique < 0 or partiPolitique > 4);
//Set Date
	long int jour, mois, annee;
	while (util::Date::validerDate(jour, mois, annee) == false)
	{
		cout << "Veuillez entrer la date de naissance :" << endl;
		cout << "Le jour :" << endl;
		cin >> jour;
		cout << "Le mois :" << endl;
		cin >> mois;
		cout << "L'annee :" << endl;
		cin >> annee;
		if (util::Date::validerDate(jour, mois, annee) == false)
		{
			cout << "La date de naissance n'est pas valide." << endl;
		}
	}
	util::Date dateNaissance;
	dateNaissance.asgDate(jour, mois, annee);
//Set Adresse
	int numCivic = -1;
	string rue, ville, codePostal, province;
	cout << "Entrez l'adresse :" << endl;
	while (numCivic < 0)
	{
		cout << "Numéro de rue :" << endl;
		cin >> numCivic;
		cin.ignore();
	}
	while (rue.compare("") == 0)
	{
		cout << "Rue :" << endl;
		getline (cin, rue);
	}
	while (ville.compare("") == 0)
	{
		cout << "Ville :" << endl;
		getline (cin, ville);
	}
	while (codePostal.compare("") == 0)
	{
		cout << "Code Postal :" << endl;
		getline (cin, codePostal);
	}
	while (province.compare("") == 0)
	{
		cout << "Province :" << endl;
		getline (cin, province);
	}
	util::Adresse adresse(numCivic, rue, ville, codePostal, province);
//Set Nom
	string nom;
	while (nom.compare("") == 0)
	{
		cout << "Entrez le nom :" << endl;
		cin >> nom;
		if (nom.compare("") == 0)
		{
			cout << "Le nom est vide" << endl;
		}
	}
//Set Prenom
	string prenom;
	while (prenom.compare("") == 0)
	{
		cout << "Entrez le prenom :" << endl;
		cin >> prenom;
		cin.ignore();
		if (prenom.compare("") == 0)
		{
			cout << "Le nom est vide" << endl;
		}
	}
//Set NAS
	string nas;
	while (util::validerNas(nas) == false)
	{
		cout << "Entrez le numéro d’assurance sociale :" << endl;
		getline (cin, nas);
		if (util::validerNas(nas) == false)
		{
			cout << "NAS invalide" << endl;
		}
	}
//Set Nom Circonscription
	string nomCirconscription;
	while (nomCirconscription.compare("") == 0)
	{
		cout << "Entrez le nom de la circonscription :" << endl;
		cin >> nomCirconscription;
		if (nomCirconscription.compare("") == 0)
		{
			cout << "Le nom de la circonscription est vide" << endl;
		}
	}
	elections::Circonscription circonscriptionInscrit(nomCirconscription, elections::Candidat(nas, prenom, nom, dateNaissance, adresse, partiPolitique));
	int choixInscription;
	do
	{
		cout << "Pour inscrire un candidat entre 0 et pour inscrire un electeur entre 1" << endl << "Pour quitter, entre 2" << endl;
		cin >> choixInscription;
		if(choixInscription == 0)
		{
			cout << "Inscription d'un candidat" << endl;
			do
			{
				cout << "Choisissez un parti:" << endl;
				cout << "0:BLOC_QUEBECOIS, 1:CONSERVATEUR,2:INDEPENDANT,3:LIBERAL,4:NOUVEAU_PARTI_DEMOCRATIQUE" << endl;
				cin >> partiPolitique;
			} while(partiPolitique < 0 or partiPolitique > 4);
		}
		if(choixInscription == 1)
		{
			cout << "Inscription d'un electeur" << endl;
		}
		if(choixInscription == 2)
		{
			break;
		}
		//Set Date
		long int jour, mois, annee;
		while (util::Date::validerDate(jour, mois, annee) == false)
		{
			cout << "Veuillez entrer la date de naissance :" << endl;
			cout << "Le jour :" << endl;
			cin >> jour;
			cout << "Le mois :" << endl;
			cin >> mois;
			cout << "L'annee :" << endl;
			cin >> annee;
			if (util::Date::validerDate(jour, mois, annee) == false)
			{
				cout << "La date de naissance n'est pas valide." << endl;
			}
		}
		util::Date dateNaissance;
		dateNaissance.asgDate(jour, mois, annee);
		//Set Adresse
		int numCivic = -1;
		string rue, ville, codePostal, province;
		cout << "Entrez l'adresse :" << endl;
		while (numCivic < 0)
		{
			cout << "Numéro de rue :" << endl;
			cin >> numCivic;
			cin.ignore();
		}
		while (rue.compare("") == 0)
		{
			cout << "Rue :" << endl;
			getline (cin, rue);
		}
		while (ville.compare("") == 0)
		{
			cout << "Ville :" << endl;
			getline (cin, ville);
		}
		while (codePostal.compare("") == 0)
		{
			cout << "Code Postal :" << endl;
			getline (cin, codePostal);
		}
		while (province.compare("") == 0)
		{
			cout << "Province :" << endl;
			getline (cin, province);
		}
		util::Adresse adresse(numCivic, rue, ville, codePostal, province);
		//Set Nom
		string nom;
		while (nom.compare("") == 0)
		{
			cout << "Entrez le nom :" << endl;
			cin >> nom;
			if (nom.compare("") == 0)
			{
				cout << "Le nom est vide" << endl;
			}
		}
		//Set Prenom
		string prenom;
		while (prenom.compare("") == 0)
		{
			cout << "Entrez le prenom :" << endl;
			cin >> prenom;
			cin.ignore();
			if (prenom.compare("") == 0)
			{
				cout << "Le nom est vide" << endl;
			}
		}
		//Set NAS
		string nas;
		while (util::validerNas(nas) == false)
		{
			cout << "Entrez le numéro d’assurance sociale :" << endl;
			getline (cin, nas);
			if (util::validerNas(nas) == false)
			{
				cout << "NAS invalide" << endl;
			}
		}
		if(choixInscription == 0)
		{
			elections::Candidat candidat(nas, prenom, nom, dateNaissance, adresse, partiPolitique);
			circonscriptionInscrit.inscrire(candidat);
		}
		if(choixInscription == 1)
		{
			elections::Electeur electeur(nas, prenom, nom, dateNaissance, adresse);
			circonscriptionInscrit.inscrire(electeur);
		}
	} while(choixInscription == 1 or choixInscription == 0);
	cout << circonscriptionInscrit.reqCirconscriptionFormate() << endl;
	cout << "Fin du programme" << endl;
	return 0;
}




