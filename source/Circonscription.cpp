/**
 * \file Circonscription.cpp
 * \brief Implantation de la classe Circonscription
 * \author Maxime Imbeau
 * \version 0.1
 * \date 14/1/2020
 */
#include "Circonscription.h"
#include "Electeur.h"
#include "PersonneException.h"
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
	for(std::vector<Personne*>::iterator iter = m_vInscrits.begin(); iter != m_vInscrits.end(); iter++)
	{
		delete *iter;
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
 * \brief Verifie si une personne est deja inscrite dans la circonscription
 * \return True si la personne est sur la liste, False sinon
 */
bool Circonscription::personneEstDejaPresente(const std::string& p_nas) const
{
	for(vector<Personne*>::const_iterator iter = m_vInscrits.begin(); iter != m_vInscrits.end(); iter++)
	{
		if((*iter)->reqNas().compare(p_nas) == 0)
		{
			return true;
		}
	}
	return false;
}
/**
 * \brief Methode qui permet d’inscrire une personne sur la liste électorale de la circonscription
 * \param[in] p_nouvelInscrit nouvelle personne qui sera inscrite a la liste electorale
 */
void Circonscription::inscrire(const Personne& p_nouvelInscrit)
{
	if(!personneEstDejaPresente(p_nouvelInscrit.reqNas()))
	{
		m_vInscrits.push_back(p_nouvelInscrit.clone());
	}
	else
	{
		throw PersonneDejaPresentException(p_nouvelInscrit.reqPersonneFormate());
	}
	INVARIANTS();
}
/**
 * \brief Methode qui permet de desinscrire une personne sur la liste électorale de la circonscription
 * \param[in] p_nas d’une personne sur la liste electoral
 */
void Circonscription::desinscrire(const string& p_nas)
{
	for(vector<Personne*>::iterator iter = m_vInscrits.begin(); iter != m_vInscrits.end(); iter++)
	{
		if(personneEstDejaPresente(p_nas))
		{
			delete *iter;
			m_vInscrits.erase(iter);
		}
		else
		{
			throw PersonneAbsenteException("Ce NAS " + p_nas + " n’est pas inscrit a la liste electoral");
		}
	}
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
	for(std::vector<Personne*>::const_iterator iter = p_circonscription.m_vInscrits.begin(); iter != p_circonscription.m_vInscrits.end(); iter++)
	{
		inscrire(**iter);
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
		for(std::vector<Personne*>::const_iterator iter = p_circonscription.m_vInscrits.begin(); iter != p_circonscription.m_vInscrits.end(); iter++)
		{
			delete *iter;
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
	for(std::vector<Personne*>::const_iterator iter = m_vInscrits.begin(); iter != m_vInscrits.end(); iter++)
	{
		if(dynamic_cast<Electeur*>(*iter))
		{
			Electeur* personne = dynamic_cast<Electeur*>(*iter);
			os << personne->reqPersonneFormate() << endl;
		}
		if(dynamic_cast<Candidat*>(*iter))
		{
			Candidat* personne = dynamic_cast<Candidat*>(*iter);
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
} // namespace elections
