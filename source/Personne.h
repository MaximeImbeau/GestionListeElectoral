/**
 * \file Personne.h
 * \brief Fichier qui contient l'interface de la classe Personne qui sert au maintien
 * 		  et à la manipulation des informations sur une personne.
 * \author Maxime Imbeau
 * \version 0.1
 * \date 12/10/2020
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include "Adresse.h"
#include "Date.h"

namespace elections
{
/**
 * \class Personne
 * \brief Cette classe sert au maintien et à la manipulation des informations sur une personne.
 * 			La classe Personne permet d'implanter des personnes.
 * \invariant de la classe: le nas doit etre valide, le prenom et le nom non vide
 */
class Personne
{
public:
	Personne(const std::string& p_nas, const std::string& p_prenom, const std::string& p_nom, const util::Date& p_dateNaissance, const util::Adresse& p_adresse);
	virtual ~Personne(){};
	virtual Personne* clone() const = 0;
	const std::string& reqNas() const;
	const std::string& reqPrenom() const;
	const std::string& reqNom() const;
	const util::Date& reqDateNaissance() const;
	const util::Adresse& reqAdresse() const;
	void asgNouvelleAdresse(const util::Adresse& p_adresse);
	bool operator==(const Personne& p_personne) const;
	virtual std::string reqPersonneFormate() const = 0;

private:
	std::string m_nas;
	std::string m_prenom;
	std::string m_nom;
	util::Date m_dateNaissance;
	util::Adresse m_adresse;
	void verifieInvariant() const;
};
}// namespace elections

#endif /* PERSONNE_H_ */
