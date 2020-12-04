/**
 * \file Adresse.h
 * \brief Fichier qui contient l'interface de la classe Date qui sert au maintien et à la manipulation des adresses.
 * \author Maxime Imbeau
 * \version 0.1
 * \date 12/10/2020
 */
#ifndef ADRESSE_H_
#define ADRESSE_H_

#include "ContratException.h"

namespace util
{
/**
 * \class Adresse
 * \brief Cette classe sert au maintien et à la manipulation des adresses.
 *			La classe Adresse permet d'implanter des adresses.
 * \invariant de la classe: le numeroCivic doit être positif et les nomRue, ville, codePostal et province ne doivent pas être vides
 */
class Adresse
{
public:
	Adresse(int p_numeroCivic, const std::string& p_nomRue, const std::string& p_ville, const std::string& p_codePostal, const std::string& p_province);
	int reqNumeroCivic() const;
	const std::string& reqNomRue() const;
	const std::string& reqVille() const;
	const std::string& reqCodePostal() const;
	const std::string& reqProvince() const;
	void asgAdresse(int p_numeroCivic, const std::string& p_nomRue, const std::string& p_ville, const std::string& p_codePostal, const std::string& p_province);
	bool operator ==(const Adresse& p_adresse) const;
	std::string reqAdresseFormate() const;

private:
	int m_numeroCivic;
	std::string m_nomRue;
	std::string m_ville;
	std::string m_codePostal;
	std::string m_province;
	void verifieInvariant() const;
};
}// namespace util

#endif /* ADRESSE_H_ */
