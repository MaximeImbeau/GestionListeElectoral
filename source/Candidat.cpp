/**
 * \file Candidat.cpp
 * \brief Implantation de la classe Candidat
 * \author Maxime Imbeau
 * \version 0.1
 * \date 14/1/2020
 */

#include "Candidat.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
namespace elections
{
/**
 * \brief Constructeur avec paramètre
 *        Création d'un objet Candidat à partir de valeurs passées en paramètres.
 * \param[in] p_nas nas du candidat
 * \param[in] p_prenom prenom du candidat
 * \param[in] p_nom nom du candidat
 * \param[in] p_dateNaissance date de naissance du candidat
 * \param[in] p_adresse adresse du candidat
 * \param[in] p_partiPolitique parti politique pour lequel le candidat se presente
 * \pre parti politique valide
 * \post m_partiPolitique prend la valeur de p_partiPolitique
 */
Candidat::Candidat(const string& p_nas, const string& p_prenom, const string& p_nom,
		           const util::Date& p_dateNaissance, const util::Adresse& p_adresse, int p_partiPolitique) :
				   Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse), m_partiPolitique(p_partiPolitique)
{
	    PRECONDITION(0 <= p_partiPolitique && p_partiPolitique <= 4);

		POSTCONDITION(m_partiPolitique == p_partiPolitique);

		INVARIANTS();
}
/**
 * \brief clone() permet de faire une copie allouée sur le monceau de l'objet courant
 * \return pointeur de candidat
 */
Personne* Candidat::clone() const
{
	return new Candidat(*this);
}
/**
 * \brief Accesseur sur le parti politique du candidat
 * \return le parti politique du candidat
 */
int Candidat::reqPartiPolitique() const
{
	return m_partiPolitique;
}
/**
 * \brief Affiche les informations du candidat sous forme d'une chaîne de caractère formatée
 * \return les informations sur un candidat
 */
string Candidat::reqPersonneFormate() const
{
	ostringstream os;
	os << "Candidat" << endl;
	os << "----------------------------------------------" << endl;
	os << Personne::reqPersonneFormate();
	os << "Parti politique   : " << mapPartisPolitiques.find((PartisPolitiques)m_partiPolitique)->second << endl;
	return os.str();
}
/**
 * \brief Vérifier les invariants de classe
 */
void Candidat::verifieInvariant() const
{
	INVARIANT(0 <= m_partiPolitique && m_partiPolitique <= 4);
}
}// namespace elections
