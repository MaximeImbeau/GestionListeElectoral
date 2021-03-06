/**
 * \file Electeur.cpp
 * \brief Implantation de la classe Electeur
 * \author Maxime Imbeau
 * \version 0.1
 * \date 14/1/2020
 */

#include "Electeur.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
namespace elections
{
/**
 * \brief Constructeur avec paramètres
 *        Création d'un objet Electeur à partir de valeurs passées en paramètres.
 * \param[in] p_nas nas de l'electeur
 * \param[in] p_prenom prenom de l'electeur
 * \param[in] p_nom nom de l'electeur
 * \param[in] p_dateNaissance date de naissance de l'electeur
 * \param[in] p_adresse adresse de l'electeur
 */
Electeur::Electeur(const string& p_nas, const string& p_prenom, const string& p_nom,
		           const util::Date& p_dateNaissance, const util::Adresse& p_adresse) :
				   Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse)
{
}
/**
 * \brief clone() permet de faire une copie allouée sur le monceau de l'objet courant
 * \return pointeur d’electeur
 */
Personne* Electeur::clone() const
{
	return new Electeur(*this);
}
/**
 * \brief Affiche les informations de l'electeur sous forme d'une chaîne de caractère formatée
 * \return les informations sur un electeur
 */
string Electeur::reqPersonneFormate() const
{
	ostringstream os;
	os << "Electeur" << endl;
	os << "----------------------------------------------" << endl;
	os << Personne::reqPersonneFormate();
	return os.str();
}
}// namespace elections




