/**
 * \file Circonscription.h
 * \brief Fichier qui contient l'interface de la classe Circonscription
 *        qui permet de faire la gestion des listes √©lectorales
 * \author Maxime Imbeau
 * \version 0.1
 * \date 14/11/2020
 */

#ifndef CIRCONSCRIPTION_H_
#define CIRCONSCRIPTION_H_

#include "Candidat.h"
#include <vector>

using namespace std;
namespace elections
{
/**
 * \class Circonscription
 * \brief La classe Circonscription permet de faire la gestion des listes √©lectorales
 * \invariant de la classe: le nom de la circonscription ne doit pas etre vide
 */
class Circonscription
{
public:
	Circonscription(const std::string& p_nomCirconscription, const elections::Candidat& p_deputeElu);
	~Circonscription();
	const std::string& reqNomCirconscription() const;
	const elections::Candidat& reqDeputeElu() const;
	bool personneEstDejaPresente(const std::string& p_nas) const;
	void inscrire(const Personne& p_nouvelInscrit);
	void desinscrire(const std::string& p_nas);
	Circonscription(const Circonscription& p_circonscription);
	const Circonscription& operator=(const Circonscription& p_circonscription);
	std::string reqCirconscriptionFormate() const;

private:
	std::string m_nomCirconscription;
	elections::Candidat m_deputeElu;
	std::vector<Personne*> m_vInscrits;
	void verifieInvariant() const;
};
}// namespace elections

#endif /* CIRCONSCRIPTION_H_ */
