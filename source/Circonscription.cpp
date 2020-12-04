/**
 * \file Circonscription.cpp
 * \brief Implantation de la classe Circonscription
 * \author Maxime Imbeau
 * \version 0.1
 * \date 14/1/2020
 */

#include "Circonscription.h"
#include "Electeur.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
namespace elections
{
/**
 * \brief Constructeur avec paramètre
 *        Création d'un objet Circonscription à partir de valeurs passées en paramètres.
 * \param[in] p_nomCirconscription nom de la circonscription
 * \param[in] p_deputeElu depute elu sortant
 */
Circonscription::Circonscription(const string& p_nomCirconscription, const elections::Candidat& p_deputeElu) :
								 m_nomCirconscription(p_nomCirconscription), m_deputeElu(p_deputeElu)
{
	PRECONDITION(!p_nomCirconscription.empty());

	POSTCONDITION(m_nomCirconscription == p_nomCirconscription);

	INVARIANTS();
}
/**
 * \brief Destructeur responsable de désallouer toutes les Personnes de la liste dans le vecteur
 */
Circonscription::~Circonscription()
{
	for(Personne* personne : m_vInscrits)
	{
		delete personne;
		personne = nullptr;
	}
	m_vInscrits.clear();
}
/**
 * \brief retourne le nom de la circonscription
 * \return le nom est une string qui représente le nom de la circonscription
 */
const string& Circonscription::reqNomCirconscription() const
{
	return m_nomCirconscription;
}
/**
 * \brief retourne le candidat sortant d'une circonscription
 * \return Depute elu est un objet candidat qui représente le candidat sortant
 */
const Candidat& Circonscription::reqDeputeElu() const
{
	return m_deputeElu;
}
/**
 * \brief Methode qui permet d’inscrire une personne sur la liste électorale de la circonscription
 * \param[in] p_nouvelInscrit nouvelle personne qui sera inscrite a la liste electorale
 */
void Circonscription::inscrire(const Personne& p_nouvelInscrit)
{
	m_vInscrits.push_back(p_nouvelInscrit.clone());

	INVARIANTS();
}
/**
 * \brief Constructeur copie
 *        Création d'un objet Circonscription copie a partie d’un autre objet Circonscription.
 * \param[in] p_circonscription une circonscription
 */
Circonscription::Circonscription(const Circonscription& p_circonscription) :
		                         m_nomCirconscription(p_circonscription.m_nomCirconscription), m_deputeElu(p_circonscription.m_deputeElu)
{
	for(Personne* personne : p_circonscription.m_vInscrits)
	{
		inscrire(*personne);
	}
	INVARIANTS();
}
/**
 * \brief surcharge de l'opérateur =
 * \param[in] p_circonscription une circonscription valide
 * \return l'objet courant
 */
const Circonscription& Circonscription::operator=(const Circonscription& p_circonscription)
{
	if(this != &p_circonscription)
	{
		m_nomCirconscription = p_circonscription.m_nomCirconscription;
		m_deputeElu = p_circonscription.m_deputeElu;
		for(Personne* personne : m_vInscrits)
		{
			delete personne;
			personne = nullptr;
		}
		m_vInscrits = p_circonscription.m_vInscrits;
    }
	return *this;
	INVARIANTS();
}
/**
 * \brief Affiche les informations de la circonscription sous forme d'une chaîne de caractère formatée
 * \return les informations sur une circonscription
 */
string Circonscription::reqCirconscriptionFormate() const
{
	ostringstream os;
	os << "circonscription : " << reqNomCirconscription() << endl;
	os << "Depute sortant :" << endl;
	os << reqDeputeElu().reqPersonneFormate() << endl;
	os << endl;
	os << "Liste des inscrits :" << endl;
	os << endl;
	for(Personne* personne : m_vInscrits)
	{
		if(dynamic_cast<Electeur*>(personne))
		{
			personne = dynamic_cast<Electeur*>(personne);
			os << personne->reqPersonneFormate() << endl;
		}
		if(dynamic_cast<Candidat*>(personne))
		{
			personne = dynamic_cast<Candidat*>(personne);
			os << personne->reqPersonneFormate() << endl;
		}
	}
	return os.str();
}
/**
 * \brief Vérifier les invariants de classe
 */
void Circonscription::verifieInvariant() const
{
	INVARIANT(!m_nomCirconscription.empty());
}
}// namespace elections



