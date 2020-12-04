/**
 * \file Adresse.cpp
 * \brief Implantation de la classe Adresse
 * \author Maxime Imbeau
 * \version 0.1
 * \date 12/10/2020
 */
#include "Adresse.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
namespace util
{
/**
 * \brief Constructeur avec paramètres
 * 		  On construit un objet Adresse à partir de valeurs passées en paramètres.
 * \param[in] p_numeroCivic est un entier int qui représente le numero civic de l'adresse
 * \param[in] p_nomRue est une string qui représente le nom de la rue de l'adresse
 * \param[in] p_ville est une string qui représente le nom de la ville de l'adresse
 * \param[in] p_codePostal est une string qui représente le code postal de l'adresse
 * \param[in] p_province est une string qui représente le nom de la province de l'adresse
 * \pre p_numeroCivic doit être un nombre positif.
 * \pre p_nomRue doit être non vide.
 * \pre p_ville doit être non vide.
 * \pre p_codePostal doit être non vide.
 * \pre p_province doit être non vide.
 * \post m_numeroCivic prend la valeur du paramètre reçu en entrée.
 * \post m_nomRue prend la valeur du paramètre reçu en entrée.
 * \post m_ville prend la valeur du paramètre reçu en entrée.
 * \post m_codePostal prend la valeur du paramètre reçu en entrée.
 * \post m_province prend la valeur du paramètre reçu en entrée.
 */
Adresse::Adresse(int p_numeroCivic, const string& p_nomRue, const string& p_ville, const string& p_codePostal, const string& p_province) :
		m_numeroCivic(p_numeroCivic), m_nomRue(p_nomRue), m_ville(p_ville), m_codePostal(p_codePostal), m_province(p_province)
{
	PRECONDITION(p_numeroCivic >= 0);
	PRECONDITION(!p_nomRue.empty());
	PRECONDITION(!p_ville.empty());
	PRECONDITION(!p_codePostal.empty());
	PRECONDITION(!p_province.empty());

	POSTCONDITION(m_numeroCivic == p_numeroCivic);
	POSTCONDITION(m_nomRue == p_nomRue);
	POSTCONDITION(m_ville == p_ville);
	POSTCONDITION(m_codePostal == p_codePostal);
	POSTCONDITION(m_province == p_province);

	INVARIANTS();
}
/**
 * \brief retourne le numero civic de l'adresse
 * \return un entier int qui représente le numero civic de l'adresse
 */
int Adresse::reqNumeroCivic() const
{
	return m_numeroCivic;
}
/**
 * \brief retourne le nom de la rue de l'adresse
 * \return une string qui représente le nom de la rue de l'adresse
 */
const string& Adresse::reqNomRue() const
{
	return m_nomRue;
}
/**
 * \brief retourne le nom de la ville de l'adresse
 * \return une string qui représente le nom de la ville de l'adresse
 */
const string& Adresse::reqVille() const
{
	return m_ville;
}
/**
 * \brief retourne le code postal de l'adresse
 * \return une string qui représente le code postal de l'adresse
 */
const string& Adresse::reqCodePostal() const
{
	return m_codePostal;
}
/**
 * \brief retourne le nom de la province de l'adresse
 * \return une string qui représente le nom de la province de l'adresse
 */
const string& Adresse::reqProvince() const
{
	return m_province;
}
/**
 * \brief Assigne une adresse à l'objet courant
 * \param[in] p_numeroCivic est un entier int qui représente le numero civic de l'adresse
 * \param[in] p_nomRue est une string qui représente le nom de la rue de l'adresse
 * \param[in] p_ville est une string qui représente le nom de la ville de l'adresse
 * \param[in] p_codePostal est une string qui représente le code postal de l'adresse
 * \param[in] p_province est une string qui représente le nom de la province de l'adresse
 * \pre p_numeroCivic doit être un nombre positif.
 * \pre p_nomRue doit être un nombre positif.
 * \pre p_ville doit être un nombre positif.
 * \pre p_codePostal doit être un nombre positif.
 * \pre p_province doit être un nombre positif.
 * \post m_numeroCivic prend la valeur du paramètre reçu en entrée.
 * \post m_nomRue prend la valeur du paramètre reçu en entrée.
 * \post m_ville prend la valeur du paramètre reçu en entrée.
 * \post m_codePostal prend la valeur du paramètre reçu en entrée.
 * \post m_province prend la valeur du paramètre reçu en entrée.
 */
void Adresse::asgAdresse(int p_numeroCivic, const string& p_nomRue, const string& p_ville, const string& p_codePostal, const string& p_province)
{
	PRECONDITION(p_numeroCivic >= 0);
	PRECONDITION(!p_nomRue.empty());
	PRECONDITION(!p_ville.empty());
	PRECONDITION(!p_codePostal.empty());
	PRECONDITION(!p_province.empty());

	m_numeroCivic = p_numeroCivic;
	m_nomRue = p_nomRue;
	m_ville = p_ville;
	m_codePostal = p_codePostal;
	m_province = p_province;

	POSTCONDITION(m_numeroCivic == p_numeroCivic);
	POSTCONDITION(m_nomRue == p_nomRue);
	POSTCONDITION(m_ville == p_ville);
	POSTCONDITION(m_codePostal == p_codePostal);
	POSTCONDITION(m_province == p_province);

	INVARIANTS();
}
/**
 * \brief surcharge de l'opérateur ==
 * \param[in] p_adresse qui est une adresse valide
 * \return un booléen indiquant si deux attributs d'une adresse sont égales ou pas
 */
bool Adresse::operator==(const Adresse& p_adresse) const
{
	if (m_numeroCivic != p_adresse.m_numeroCivic) return false;
	if (m_nomRue.compare(p_adresse.m_nomRue) != 0) return false;
	if (m_ville.compare(p_adresse.m_ville) != 0) return false;
	if (m_codePostal.compare(p_adresse.m_codePostal) != 0) return false;
	if (m_province.compare(p_adresse.m_province) != 0) return false;
	return true;
}
/**
 * \brief retourne une adresse formatée dans une chaîne de caractères (string)
 * \return une adresse formatée dans une chaîne de caractères
 */
string Adresse::reqAdresseFormate() const
{
	ostringstream os;
	os << m_numeroCivic << ", " << m_nomRue << ", " << m_ville << ", " << m_codePostal << ", " << m_province;
	return os.str();
}
/**
 * \brief Teste l'invariant de la classe Adresse.
 * 	      L'invariant de cette classe s'assure que l'adresse est valide
 */
void Adresse::verifieInvariant() const
{
	INVARIANT(m_numeroCivic >= 0);
	INVARIANT(!m_nomRue.empty());
	INVARIANT(!m_ville.empty());
	INVARIANT(!m_codePostal.empty());
	INVARIANT(!m_province.empty());
}
}// namespace util
