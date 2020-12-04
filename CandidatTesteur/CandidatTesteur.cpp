/**
 * \file CandidatTesteur.cpp
 * \test Test unitaire de la classe Candidat
 * \author Maxime Imbeau
 * \version 0.1
 * \date 2020-11-19
 */
#include<gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Candidat.h"
using namespace elections;
using namespace std;
/**
 * \brief Test du constructeur
 * 		  Cas valides: Création d'un objet Candidat et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		       Parti Politique n'est pas un chiffre de 0 a 4
 */
TEST(Candidat, ConstructeurParDefaut)
{
	Candidat unCandidat("295 057 723", "Max", "Imbeau", util::Date(20, 9, 1998), util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), 1);
	ASSERT_EQ("295 057 723", unCandidat.reqNas());
	ASSERT_EQ("Max", unCandidat.reqPrenom());
	ASSERT_EQ("Imbeau", unCandidat.reqNom());
	ASSERT_EQ(util::Date(20, 9, 1998), unCandidat.reqDateNaissance());
	ASSERT_EQ(util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), unCandidat.reqAdresse());
	ASSERT_EQ(1, unCandidat.reqPartiPolitique());
}
//cas invalide
TEST(Candidat,ConstructeurPartiPolitiqueInvalide)
{
	ASSERT_THROW(Candidat unCandidat("295 057 723", "Max", "Imbeau", util::Date(20, 9, 1998), util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), 0), PreconditionException);
}
/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class unCandidat: public ::testing::Test
{
public:
	unCandidat() :
		candidat("295 057 723", "Max", "Imbeau", util::Date(20, 9, 1998), util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), 1)
	{}
	;
	Candidat candidat;
};
/**
 * \brief Test de la méthode clone
 * 	   Cas valide: le methode reqPersonneFormate retourne la meme chose pour l'objet clone
 * 	   Cas invalide: aucun
 */
TEST_F(unCandidat, testClone)
{
	Personne* unePersonne = candidat.clone();
//	string personner2 = candidat.reqPersonneFormate();
//	string personner = unePersonne->reqPersonneFormate();
//	cout << personner2 << endl;
//	cout << personner << endl;
	ASSERT_EQ(unePersonne->reqPersonneFormate(), candidat.reqPersonneFormate());
}
/**
 * \brief Test de la méthode reqPartiPolitique()
 *     Cas valide: vérifier le retour du nom de parti politique du candidat
 *     Cas invalide: aucun
 */
TEST_F(unCandidat, reqPartiPolitique)
{
	ASSERT_EQ(1, candidat.reqPartiPolitique());
}
/**
 * \brief Test de la méthode std::string reqPersonneFormate()
 *        Cas valides: vérifier le retour des information sur l'objets candidat formaté
 *        Cas invalides: aucun
 */
TEST_F(unCandidat,reqPersonneFormate)
{
	ostringstream os;
	os << "Candidat" << endl;
	os << "----------------------------------------------" << endl;
	os << "NAS               : " << candidat.reqNas() << endl;
	os << "Prenom            : " << candidat.reqPrenom() << endl;
	os << "Nom               : " << candidat.reqNom() << endl;
	os << "Date de naissance : " << candidat.reqDateNaissance().reqDateFormatee() << endl;
	os << "Adresse           : " << candidat.reqAdresse().reqAdresseFormate() << endl;
	os << "Parti politique   : " << candidat.reqPartiPolitique() << endl;
	ASSERT_EQ(os.str(), candidat.reqPersonneFormate());
}

