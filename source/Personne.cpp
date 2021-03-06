/**
 * \file Personne.cpp
 * \brief Implantation de la classe Personne
 * \author Maxime Imbeau
 * \version 0.1
 * \date 12/10/2020
 */
#include "Personne.h"
#include "validationFormat.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
namespace elections
{
/**
 * \brief constructeur avec paramètres
 * 		  On construit un objet Personne à partir de valeurs passées en paramètres.
 * \param[in] p_nas est une string qui représente le nas d'une personne
 * \param[in] p_prenom est une string qui représente le prenom d'une personne
 * \param[in] p_nom est une string qui représente le nom d'une personne
 * \param[in] p_dateNaissance est un objet Date qui représente la date de naissance d'une personne
 * \param[in] p_adresse est un objet Adresse qui représente l'adresse d'une personne
 * \pre p_nas doit être un nas valide.
 * \pre p_prenom doit être non vide.
 * \pre p_nom doit être non vide.
 * \post m_nas prend la valeur du paramètre reçu en entrée.
 * \post m_prenom prend la valeur du paramètre reçu en entrée.
 * \post m_nom prend la valeur du paramètre reçu en entrée.
 * \post m_dateNaissance prend la valeur du paramètre reçu en entrée.
 * \post m_adresse prend la valeur du paramètre reçu en entrée.
 */
Personne::Personne(const string& p_nas, const string& p_prenom, const string& p_nom, const util::Date& p_dateNaissance, const util::Adresse& p_adresse) :
		m_nas(p_nas), m_prenom(p_prenom), m_nom(p_nom), m_dateNaissance(p_dateNaissance.reqJour(), p_dateNaissance.reqMois(),
				p_dateNaissance.reqAnnee()), m_adresse(p_adresse)
{
	PRECONDITION(util::validerNas(p_nas));
	PRECONDITION(!p_prenom.empty());
	PRECONDITION(!p_nom.empty());

	POSTCONDITION(m_nas == p_nas);
	POSTCONDITION(m_prenom == p_prenom);
	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_dateNaissance == p_dateNaissance);
	POSTCONDITION(m_adresse == p_adresse);

	INVARIANTS();
}
/**
 * \brief retourne le nas d'une personne
 * \return p_nas est une string qui représente le nas d'une personne
 */
const string& Personne::reqNas() const
{
	return m_nas;
}
/**
 * \brief retourne le prenom d'une personne
 * \return p_prenom est une string qui représente le prenom d'une personne
 */
const string& Personne::reqPrenom() const
{
	return m_prenom;
}
/**
 * \brief retourne le nom d'une personne
 * \return p_nom est une string qui représente le nom d'une personne
 */
const string& Personne::reqNom() const
{
	return m_nom;
}
/**
 * \brief retourne la date de naissance d'une personne
 * \return p_dateNaissance est un objet Date qui représente la date de naissance d'une personne
 */
const util::Date& Personne::reqDateNaissance() const
{
	return m_dateNaissance;
}
/**
 * \brief retourne l'adresse d'une personne
 * \return p_adresse est un objet Adresse qui représente l'adresse d'une personne
 */
const util::Adresse& Personne::reqAdresse() const
{
	return m_adresse;
}
/**
 * \brief Assigne une Personne à l'objet courant
 * \param[in] p_adresse est un objet Adresse qui représente l'adresse d'une personne
 * \post m_adresse prend la valeur du paramètre reçu en entrée.
 */
void Personne::asgNouvelleAdresse(const util::Adresse& p_adresse)
{
	m_adresse = p_adresse;

	POSTCONDITION(m_adresse == p_adresse);

	INVARIANTS();
}
/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_personne qui est une personne valide
 * \return un booléen indiquant si les attributs d'une personne sont égales ou pas
 */
bool Personne::operator==(const Personne& p_personne) const
{
	if (m_nas.compare(p_personne.m_nas) != 0) return false;
	if (m_prenom.compare(p_personne.m_prenom) != 0) return false;
	if (m_nom.compare(p_personne.m_nom) != 0) return false;
	if (!(m_dateNaissance == p_personne.m_dateNaissance)) return false;
	if (!(m_adresse == p_personne.m_adresse)) return false;
	return true;
}
/**
 * \brief retourne une personne formatée dans une chaîne de caractères (string)
 * \return une personne formatée dans une chaîne de caractères
 */
string Personne::reqPersonneFormate() const
{
	ostringstream os;
	os << "NAS               : " << m_nas << endl;
	os << "Prenom            : " << m_prenom << endl;
	os << "Nom               : " << m_nom << endl;
	os << "Date de naissance : " << m_dateNaissance.reqDateFormatee() << endl;
	os << "Adresse           : " << m_adresse.reqAdresseFormate() << endl;
	return os.str();
}
/**
 * \brief Teste l'invariant de la classe Personne.
 * 	      L'invariant de cette classe s'assure qu'une personne est valide.
 */
void Personne::verifieInvariant() const
{
	INVARIANT(util::validerNas(m_nas));
	INVARIANT(!m_prenom.empty());
	INVARIANT(!m_nom.empty());
}
}// namespace elections

