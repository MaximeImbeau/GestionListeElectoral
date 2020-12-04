/**
 * \file AdresseTesteur.cpp
 * \test Test unitaire de la classe Adresse
 * \author Maxime Imbeau
 * \version 0.1
 * \date 2020-11-19
 */
#include<gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Adresse.h"
using namespace util;
using namespace std;
/**
 * \test Test du constructeur
 *
 * 		Cas valides: Création d'un objet Adresse et vérification de l'assignation de tous les attributs
 *		Cas invalides:
 *		    Numero Civic inferieur a 0
 *		    Nom de rue non vide
 *		    Ville non vide
 *		    Code Postal non vide
 *		    Province non vide
 */
TEST(Adresse, Constructeur)
{
	Adresse UneAdresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec");

	ASSERT_EQ(54, UneAdresse.reqNumeroCivic());
	ASSERT_EQ("Laurier", UneAdresse.reqNomRue());
	ASSERT_EQ("Quebec", UneAdresse.reqVille());
	ASSERT_EQ("G7A 5T9", UneAdresse.reqCodePostal());
	ASSERT_EQ("Quebec", UneAdresse.reqProvince());
}
//cas invalide
TEST(Adresse, ConstructeurInvalideNumeroCivic)
{
	ASSERT_THROW(Adresse UneAdresse(-54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), ContratException);
}
TEST(Adresse, ConstructeurInvalideNomRue)
{
	ASSERT_THROW(Adresse UneAdresse(54, "", "Quebec", "G7A 5T9", "Quebec"), ContratException);
}
TEST(Adresse, ConstructeurInvalideVille)
{
	ASSERT_THROW(Adresse UneAdresse(54, "Laurier", "", "G7A 5T9", "Quebec"), ContratException);
}
TEST(Adresse, ConstructeurInvalideCodePostal)
{
	ASSERT_THROW(Adresse UneAdresse(54, "Laurier", "Quebec", "", "Quebec"), ContratException);
}
TEST(Adresse, ConstructeurInvalideProvince)
{
	ASSERT_THROW(Adresse UneAdresse(54, "Laurier", "Quebec", "G7A 5T9", ""), ContratException);
}
/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UneAdresse: public ::testing::Test
{
public:
	UneAdresse() :
		adresse(60, "Notre-Dame", "Montreal", "H1A 5H7", "Quebec")
	{}
	;
	Adresse adresse;
};
/**
 * \test Test de la méthode reqNumeroCivic()
 *
 *     Cas valide: vérifier le retour du numero civic.
 *     Cas invalide: aucun.
 */
TEST_F(UneAdresse, reqNumeroCivic)
{
	ASSERT_EQ(60, adresse.reqNumeroCivic());
}
/**
 * \test Test de la méthode reqNomRue()
 *
 *     Cas valide: vérifier le retour du nom de rue.
 *     Cas invalide: aucun.
 */
TEST_F(UneAdresse, reqNomRue)
{
	ASSERT_EQ("Notre-Dame", adresse.reqNomRue());
}
/**
 * \test Test de la méthode reqVille()
 *
 *     Cas valide: vérifier le retour du nom de la ville.
 *     Cas invalide: aucun.
 */
TEST_F(UneAdresse, reqVille)
{
	ASSERT_EQ("Montreal", adresse.reqVille());
}
/**
 * \test Test de la méthode reqCodePostal()
 *
 *     Cas valide: vérifier le retour du code postal.
 *     Cas invalide: aucun.
 */
TEST_F(UneAdresse, reqCodePostal)
{
	ASSERT_EQ("H1A 5H7", adresse.reqCodePostal());
}
/**
 * \test Test de la méthode reqProvince()
 *
 *     Cas valide: vérifier le retour de la province.
 *     Cas invalide: aucun.
 */
TEST_F(UneAdresse, reqProvince)
{
	ASSERT_EQ("Quebec", adresse.reqProvince());
}
/**
 * \brief Test de la méthode asgAdresse()
 *     Cas valide: assigne des valeurs valides d´une adresse
 *     Cas invalide: assigne des valeurs invalides d´une adresse
 */
TEST_F(UneAdresse, assigneAdresseValide)
{
	adresse.asgAdresse(25, "Notre-Dame", "Montreal", "H1A 5H7", "Quebec");
}
//cas invalide
TEST_F(UneAdresse, assigneAdresseInvalide)
{
	ASSERT_THROW(adresse.asgAdresse(-25, "", "Montreal", "H1A 5H7", "Quebec"), PreconditionException);
}
/**
 * \test Test de la méthode std::string reqAdresseFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objets Adresse formaté
 *        Cas invalides: aucun
 */
TEST_F(UneAdresse, reqAdresseFormate)
{
	std::ostringstream os;
	os << adresse.reqNumeroCivic() << ", " << adresse.reqNomRue() << ", "
	   << adresse.reqVille() << ", " << adresse.reqCodePostal() << ", " << adresse.reqProvince();
	ASSERT_EQ(os.str(), adresse.reqAdresseFormate());
}
/**
 * \class DeuxAdresses
 * \brief Fixture pour les tests comparaisons de deux adresses
 */
class DeuxAdresses: public ::testing::Test
{
public:
	DeuxAdresses() : adresse1(25, "Notre-Dame", "Montreal", "H1A 5H7", "Quebec"), adresse2(25, "Laurier", "Quebec", "G7A 5T9", "Quebec")
	{
	};
	Adresse adresse1;
	Adresse adresse2;
};
/**
 * \brief  Test de la méthode bool Adresse::operator== (const Adresse& p_adresse)
 *        cas valide:
 *   		OperatorEgalEgalVrai: 	Adresse indentique à elle-même.
 *  		OperatorEgalEgalFaux: 	Adresses différentes
 *        cas invalide:
 *          Aucun d'identifié
 */
TEST_F(DeuxAdresses, OperatorEgalEgalVrai)
{
	ASSERT_EQ(adresse1, adresse1);
}
TEST_F(DeuxAdresses, OperatorEgalEgalFaux)
{
	ASSERT_FALSE(adresse1 == adresse2);
}


