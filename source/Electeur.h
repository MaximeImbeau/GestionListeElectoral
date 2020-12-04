/**
 * \file Electeur.h
 * \brief Fichier qui contient l'interface de la classe Electeur qui sert au maintien
 * 		  et à la manipulation des informations sur un electeur.
 * \author Maxime Imbeau
 * \version 0.1
 * \date 14/11/2020
 */

#ifndef ELECTEUR_H_
#define ELECTEUR_H_

#include "Personne.h"

using namespace std;
namespace elections
{
/**
 * \class Electeur
 * \brief Classe dérivée de la classe Personne
 */
class Electeur : public Personne
{
public:
	Electeur(const string& p_nas, const string& p_prenom, const string& p_nom, const util::Date& p_dateNaissance,
			 const util::Adresse& p_adresse);
	~Electeur(){};
	virtual Personne* clone() const;
	virtual std::string reqPersonneFormate() const;

private:
	void verifieInvariant() const;
};
}// namespace elections

#endif /* ELECTEUR_H_ */
