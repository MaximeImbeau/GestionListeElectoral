/**
 * \file validationFormat.cpp
 * \brief Fonctions qui permettent de valider un NAS et de valider le format d'un fichier
 * \author Maxime Imbeau
 * \version 0.1
 * \date 12/10/2020
 */

#include "validationFormat.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stdlib.h>
#include <fstream>


using namespace std;
namespace util
{
/**
 * \brief Vérifie la validité d'un NAS
 * \param[in] p_nas qui represente un numero d'assurance social (NAS)
 * \return un booléen indiquant si le NAS est valide ou non
 */
bool validerNas(const string& p_nas)
{
	int tableau_verif[MAX] = {1,2,1,2,1,2,1,2,1};
	if (p_nas.length() == 11)
	{
		int number_index = 0;
		int somme = 0;
		for (int i = 0; i < 11; i++)
		{
			if (i == 3 || i == 7)
			{
				i++;
			}
			int value = stoi(p_nas.substr(i,1));
			if ((value * tableau_verif[number_index]) > 9)
			{
				int multi = value * tableau_verif[number_index];
				string str= to_string(multi);
				somme += stoi(str.substr(0,1)) + stoi(str.substr(1,1));
			}
			else
			{
				somme += value * tableau_verif[number_index];
			}
			number_index++;
		}
		return somme % 10 == 0;
	}
	return false;
}
/**
 * \brief Vérifie la validité du format d'un fichier
 * \param[in] p_is qui represente un fichier.txt
 * \return un booléen indiquant si le format du fichier est valide ou non
 */
bool validerFormatFichier(istream& p_is)
{
	if(!p_is)
	{
		return false;
	}
	string p_isLineIterator;
	string parti[nb_parti] = {"BLOC_QUEBECOIS", "CONSERVATEUR", "INDEPENDANT", "LIBERAL", "NOUVEAU_PARTI_DEMOCRATIQUE"};
	bool isParti = false;
	//circonscription
	getline(p_is, p_isLineIterator);
	if (p_isLineIterator.compare("") != 0)
	{
		//parti
		getline(p_is, p_isLineIterator);
		for (int i = 0; i < nb_parti; i++)
		{
			if (p_isLineIterator.compare(parti[i]) == true)
			{
				isParti = true;
				break;
			}
		}
		if (isParti == false)
			return false;
		//NAS
		getline(p_is, p_isLineIterator);
		if (!validerNas(p_isLineIterator))
			return false;
		//prenom
		getline(p_is, p_isLineIterator);
		if (p_isLineIterator.compare("") == 0)
			return false;
		//nom
		getline(p_is, p_isLineIterator);
		if (p_isLineIterator.compare("") == 0)
			return false;
		//date
		getline(p_is, p_isLineIterator);
		if (p_isLineIterator.compare("") == 0)
			return false;
		//address
		getline(p_is, p_isLineIterator);
		if (p_isLineIterator.compare("") == 0)
			return false;

		while(getline(p_is, p_isLineIterator))
		{
			isParti = false;
			for (int j = 0; j < nb_parti; j++)
			{
				if (p_isLineIterator.compare(parti[j]) == 0)
				{
					isParti = true;
				}
			}
			bool nas = false;
			if (!isParti)
			{
				nas = validerNas(p_isLineIterator);
			}
			if(isParti || nas)
			{
				if(!nas)
				{
					//NAS
					getline(p_is, p_isLineIterator);
					if(!validerNas(p_isLineIterator))
						return false;
				}
				//prenom
				getline(p_is, p_isLineIterator);
				if(p_isLineIterator.compare("") == 0)
					return false;
				//nom
				getline(p_is, p_isLineIterator);
				if(p_isLineIterator.compare("") == 0)
					return false;
				//date
				getline(p_is, p_isLineIterator);
				if(p_isLineIterator.compare("") == 0)
					return false;
				//address
				getline(p_is, p_isLineIterator);
				if(p_isLineIterator.compare("") == 0)
					return false;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}
}// namespace util
