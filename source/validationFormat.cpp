/**
 * \file validationFormat.cpp
 * \brief Implantation de la fonctions de validation de format
 * \date 2020-10-11
 * \author Nicholas Rompré St-Yves
 */

#include <iostream>
#include <string>
#include <ctype.h>
#include <fstream>
#include "validationFormat.h"
#include <assert.h>
#include "Date.h"
#include "Adresse.h"
#include "ContratException.h"

using namespace std;


namespace util
{
/**
 * \brief Vérifie si le NAS est valide ou non
 * \param[in] p_nas Numéro d'assurance sociale (NAS) (string)
 * \return Si le NAS est valide ou non (bool).
 */
bool validerNas(const std::string& p_nas)
{
	int Arr[] = { 1, 2, 1, 2, 1, 2, 1, 2, 1 };
	int sommeChiffresNas = 0;
	int a;
	bool b;
	int c;
	int d;
	int e;
	int x;
	string y;
	int z;
	const int zeroASCII = 48;
	bool nasValid = false;
	bool separatorsValid = true;
	int digitCounter = 0;
	for (string::size_type i = 0; i < p_nas.size(); i++) {
		a = p_nas[i];
		b = isdigit(a);
		if (b) {
			c = a - zeroASCII;
			x = c * Arr[digitCounter];
			if (x >= 10) {
				y = to_string(x);
				z = 0;
				for (string::size_type j = 0; j < y.size(); j++) {
					z += y[j] - zeroASCII;
				}
				x = z;
			}
			sommeChiffresNas += x;
			digitCounter += 1;
		}
	}
	d = p_nas[3];
	e = p_nas[7];
	if ((d != 32) and (d != 45)) {
		separatorsValid = false;
	}
	if ((e != 32) and (e != 45)) {
		separatorsValid = false;
	}
	if (((sommeChiffresNas % 10) == 0) and (digitCounter == 9)
			and (separatorsValid)) {
		nasValid = true;
	}
	return nasValid;
}

/**
 * \brief Saisie et validation du NAS (string)
 * \return NAS (string)
 */
string entrerNas()
{
	try
	{
		cout << "Entrez le numero d'assurance sociale : ";
		string nas;
		char buffer[256];
		cin.getline(buffer, 256);
		nas = buffer;
		assert(validerNas(nas));
		return nas;
	}catch (PreconditionException &erreur)
	{
		cout << erreur.reqTexteException();
	}
}

/**
 * \brief Saisie et validation d'un paramètre string (string)
 * \return parametreString(string)
 */
string entrerParametreString()
{
	try
	{
		string parametreString;
		char buffer[256];
		cin.getline(buffer, 256);
		parametreString = buffer;
		return parametreString;
	}catch (PreconditionException &erreur)
	{
		cout << erreur.reqTexteException();
	}
}

/**
 * \brief Saisie et validation d'un prenom (string)
 * \return prenom (string)
 */
string entrerPrenom()
{
	try
	{
		string prenom;
		cout << "Entrez le prenom : ";
		prenom = entrerParametreString();
		return prenom;
	}catch (PreconditionException &erreur)
	{
		cout << erreur.reqTexteException();
	}
}

/**
 * \brief Saisie et validation d'un nom (string)
 * \return nom (string)
 */
string entrerNom()
{
	try
	{
		string nom;
		cout << "Entrez le nom : ";
		nom = entrerParametreString();
		return nom;
	}catch (PreconditionException &erreur)
	{
		cout << erreur.reqTexteException();
	}
}

/**
 * \brief Saisie et validation d'une date de naissance (Date)
 * \return date de naissance (Date)
 */
util::Date entrerDateNaissance()
{
	try
	{
		long jour;
		long mois;
		long annee;
		cout << "Veuillez entrer sa date de naissance." << endl;;
		cout << "Le jour [1..31]: ";
		cin >> jour;
		cout << "Le mois [1..12]: ";
		cin >> mois;
		cout << "L'annee [1970..2037]: ";
		cin >> annee;
		assert(util::Date::validerDate(jour, mois, annee));
		return util::Date (jour, mois, annee);
	}catch (PreconditionException &erreur)
	{
		cout << erreur.reqTexteException();
	}
}

/**
 * \brief Saisie et validation d'une adresse (Date)
 * \return adresse (Adresse)
 */
util::Adresse entrerAdresse()
{
	try
	{
		unsigned int numeroCivic;
		string nomRue;
		string ville;
		string codePostal;
		string province;

		cout << "No de rue: ";
		cin >> numeroCivic;
		assert(numeroCivic > 0);
		cin.ignore();
		cout << "Rue : ";
		nomRue = entrerParametreString();
		cout << "Ville : ";
		ville = entrerParametreString();
		cout << "Code postal : ";
		codePostal = entrerParametreString();
		cout << "Province : ";
		province = entrerParametreString();
		return util::Adresse (numeroCivic, nomRue, ville, codePostal, province);
	}catch (PreconditionException &erreur)
	{
		cout << erreur.reqTexteException();
	}
}

/**
 * \brief Saisie et validation d'un partiPolitique (int)
 * \return partiPolitique (int)
 */
int entrerPartiPolitique()
{
	try
	{
		int partiPolitique;
		cout << "Choisissez un parti:" << endl;
		cout << "0:BLOC_QUEBECOIS, 1:CONSERVATEUR,2:INDEPENDANT,3:LIBERAL,4:NOUVEAU_PARTI_DEMOCRATIQUE" << endl;
		cin >> partiPolitique;
		assert(partiPolitique <= 4);
		assert(partiPolitique >= 0);
		return partiPolitique;
	}catch (PreconditionException &erreur)
	{
		cout << erreur.reqTexteException();
	}
}
} //Fin namespace util
