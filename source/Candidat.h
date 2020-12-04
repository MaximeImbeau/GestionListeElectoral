/**
 * \file Candidat.h
 * \brief Fichier qui contient l'interface de la classe Candidat qui sert au maintien
 * 		  et à la manipulation des informations sur un candidat.
 * \author Maxime Imbeau
 * \version 0.1
 * \date 14/11/2020
 */

#ifndef CANDIDAT_H_
#define CANDIDAT_H_

#include "Personne.h"
#include <map>

using namespace std;
namespace elections
{
/**
 * \class Candidat
 * \brief Classe dérivée de la classe Personne
 * \invariant de la classe: le parti politique doit etre un chiffre de 0 a 4
 */
class Candidat : public Personne
{
	enum PartisPolitiques{BLOC_QUEBECOIS, CONSERVATEUR, INDEPENDANT, LIBERAL, NOUVEAU_PARTI_DEMOCRATIQUE};
	std::map<PartisPolitiques, string> mapPartisPolitiques =
	{
		{BLOC_QUEBECOIS, "BLOC_QUEBECOIS"},
		{CONSERVATEUR, "CONSERVATEUR"},
		{INDEPENDANT, "INDEPENDANT"},
		{LIBERAL, "LIBERAL"},
		{NOUVEAU_PARTI_DEMOCRATIQUE, "NOUVEAU_PARTI_DEMOCRATIQUE"},
	};
public:
	Candidat(const string& p_nas, const string& p_prenom, const string& p_nom, const util::Date& p_dateNaissance,
			 const util::Adresse& p_adresse, int p_partiPolitique);
	virtual Personne* clone() const;
	int reqPartiPolitique() const;
	virtual std::string reqPersonneFormate() const;

private:
	int m_partiPolitique;
	void verifieInvariant() const;
};
}// namespace elections

#endif /* CANDIDAT_H_ */
