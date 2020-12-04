/**
 * \file ElecteurTesteur.cpp
 * \test Test unitaire de la classe Electeur
 * \author Maxime Imbeau
 * \version 0.1
 * \date 2020-11-19
 */
#include<gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Electeur.h"
using namespace elections;
using namespace std;
/**
 * \brief Test du constructeur
 * 		  Cas valides: Création d'un objet Electeur et vérification de l'assignation de tous les attributs
 *		  Cas invalides: Aucun
 */
TEST(Electeur, ConstructeurParDefaut)
{
	Electeur unElecteur("295 057 723", "Max", "Imbeau", util::Date(20, 9, 1998), util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"));
	ASSERT_EQ("295 057 723", unElecteur.reqNas());
	ASSERT_EQ("Max", unElecteur.reqPrenom());
	ASSERT_EQ("Imbeau", unElecteur.reqNom());
	ASSERT_EQ(util::Date(20, 9, 1998), unElecteur.reqDateNaissance());
	ASSERT_EQ(util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), unElecteur.reqAdresse());
}
/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class unElecteur: public ::testing::Test
{
public:
	unElecteur() :
		electeur("295 057 723", "Max", "Imbeau", util::Date(20, 9, 1998), util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"))
	{}
	;
	Electeur electeur;
};
/**
 * \brief Test de la méthode clone
 * 	   Cas valide: le methode reqPersonneFormate retourne la meme chose pour l'objet clone
 * 	   Cas invalide: Aucun
 */
TEST_F(unElecteur, testClone)
{
	Personne* unePersonne = electeur.clone();
//	string personner2 = electeur.reqPersonneFormate();
//	string personner = unePersonne->reqPersonneFormate();
//	cout << personner2 << endl;
//	cout << personner << endl;
	ASSERT_EQ(unePersonne->reqPersonneFormate(), electeur.reqPersonneFormate());
}
/**
 * \brief Test de la méthode std::string reqPersonneFormate()
 *        Cas valides: vérifier le retour des information sur l'objets electeur formaté
 *        Cas invalides: aucun
 */
TEST_F(unElecteur, reqPersonneFormate)
{
	ostringstream os;
	os << "Electeur" << endl;
	os << "----------------------------------------------" << endl;
	os << "NAS               : " << electeur.reqNas() << endl;
	os << "Prenom            : " << electeur.reqPrenom() << endl;
	os << "Nom               : " << electeur.reqNom() << endl;
	os << "Date de naissance : " << electeur.reqDateNaissance().reqDateFormatee() << endl;
	os << "Adresse           : " << electeur.reqAdresse().reqAdresseFormate() << endl;
	ASSERT_EQ(os.str(), electeur.reqPersonneFormate());
}





