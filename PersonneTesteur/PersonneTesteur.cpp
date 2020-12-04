/**
 * \file PersonneTesteur.cpp
 * \test Test unitaire de la classe Personne
 * \author Maxime Imbeau
 * \version 0.1
 * \date 2020-11-19
 */
#include<gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Personne.h"
using namespace elections;
using namespace std;
/**
 * \class PersonneTest
 * \brief Classe de test permettant de tester la classe abstraite Personne
 */
class PersonneTest: public Personne
{
public:
	PersonneTest(const string& p_nas, const string& p_prenom, const string& p_nom,
	             const util::Date& p_dateNaissance, const util::Adresse& p_adresse) :
			     Personne(p_nas, p_prenom, p_nom, p_dateNaissance, p_adresse)
	{
	}
	; //instancie un objet Personne
	virtual Personne* clone() const
	{
		return new PersonneTest(*this);
	}
	; //doit être implantée car la classe est concrète
	virtual std::string reqPersonneFormate() const
	{
		return Personne::reqPersonneFormate();
	}
	;
};
/**
 * \test Test du constructeur
 *
 * 		Cas valides: Création d'un objet Personne et vérification de l'assignation de tous les attributs
 *		Cas invalides:
 *		    Nas non valide
 *		    Prenom non vide
 *		    Nom non vide
 */
TEST(Personne, Constructeur)
{
	PersonneTest UnePersonne("295 057 723", "Max", "Imbeau", util::Date(8, 11, 1975), util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"));

	ASSERT_EQ("295 057 723", UnePersonne.reqNas());
	ASSERT_EQ("Max", UnePersonne.reqPrenom());
	ASSERT_EQ("Imbeau", UnePersonne.reqNom());
	ASSERT_EQ(util::Date(8, 11, 1975), UnePersonne.reqDateNaissance());
	ASSERT_EQ(util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), UnePersonne.reqAdresse());
}
//cas invalide
TEST(Personne, ConstructeurInvalideNas)
{
	ASSERT_THROW(PersonneTest UnePersonne("111 111 111", "Max", "Imbeau", util::Date(8, 11, 1975), util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec")), ContratException);
}
TEST(Personne, ConstructeurInvalidePrenom)
{
	ASSERT_THROW(PersonneTest UnePersonne("295 057 723", "", "Imbeau", util::Date(8, 11, 1975), util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec")), ContratException);
}
TEST(Personne, ConstructeurInvalideNom)
{
	ASSERT_THROW(PersonneTest UnePersonne("295 057 723", "Max", "", util::Date(8, 11, 1975), util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec")), ContratException);
}
/**
 * \class UnePersonne
 * \brief Fixture  UnePersonne pour la création d'un objet PersonneTest pour les tests
 */
class UnePersonne: public ::testing::Test
{
public:
	UnePersonne() :
		personne("295 057 723", "Marie", "Gosselin", util::Date(9, 10, 1997), util::Adresse(60, "Notre-Dame", "Montreal", "H1A 5H7", "Quebec"))
	{}
	;
	PersonneTest personne;
};
/**
 * \test Test de la méthode reqNas()
 *
 *     Cas valide: vérifier le retour du NAS.
 *     Cas invalide: aucun.
 */
TEST_F(UnePersonne, reqNas)
{
	ASSERT_EQ("295 057 723", personne.reqNas());
}
/**
 * \test Test de la méthode reqPrenom()
 *
 *     Cas valide: vérifier le retour du prenom.
 *     Cas invalide: aucun.
 */
TEST_F(UnePersonne, reqPrenom)
{
	ASSERT_EQ("Marie", personne.reqPrenom());
}
/**
 * \test Test de la méthode reqNom()
 *
 *     Cas valide: vérifier le retour du nom.
 *     Cas invalide: aucun.
 */
TEST_F(UnePersonne, reqNom)
{
	ASSERT_EQ("Gosselin", personne.reqNom());
}
/**
 * \test Test de la méthode reqDateNaissance()
 *
 *     Cas valide: vérifier le retour de la date de naissance.
 *     Cas invalide: aucun.
 */
TEST_F(UnePersonne, reqDateNaissance)
{
	ASSERT_EQ(util::Date(9, 10, 1997), personne.reqDateNaissance());
}
/**
 * \test Test de la méthode reqAdresse()
 *
 *     Cas valide: vérifier le retour d'une adresse.
 *     Cas invalide: aucun.
 */
TEST_F(UnePersonne, reqAdresse)
{
	ASSERT_EQ(util::Adresse(60, "Notre-Dame", "Montreal", "H1A 5H7", "Quebec"), personne.reqAdresse());
}
/**
 * \brief Test de la méthode asgNouvelleAdresse()
 *     Cas valide: assigne des valeurs valides d´une adresse
 *     Cas invalide: assigne des valeurs invalides d´une adresse
 */
TEST_F(UnePersonne, assigneNouvelleAdresseValide)
{
	personne.asgNouvelleAdresse(util::Adresse(25, "Notre-Dame", "Montreal", "H1A 5H7", "Quebec"));
}
//cas invalide
TEST_F(UnePersonne, assigneNouvelleAdresseInvalide)
{
	ASSERT_THROW(personne.asgNouvelleAdresse(util::Adresse(-25, "", "Montreal", "H1A 5H7", "Quebec")), PreconditionException);
}
/**
 * \test Test de la méthode std::string reqPersonneFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objets Personne formaté
 *        Cas invalides: aucun
 */
TEST_F(UnePersonne, reqPersonneFormate)
{
	ostringstream os;
	os << "NAS               : " << personne.reqNas() << endl;
	os << "Prenom            : " << personne.reqPrenom() << endl;
	os << "Nom               : " << personne.reqNom() << endl;
	os << "Date de naissance : " << personne.reqDateNaissance().reqDateFormatee() << endl;
	os << "Adresse           : " << personne.reqAdresse().reqAdresseFormate() << endl;
	ASSERT_EQ(os.str(), personne.reqPersonneFormate());
}
/**
 * \class DeuxPersonnes
 * \brief Fixture pour les tests comparaisons de deux personnes
 */
class DeuxPersonnes: public ::testing::Test
{
public:
	DeuxPersonnes() : personne1("295 057 723", "Max", "Imbeau", util::Date(8, 11, 1975), util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec")),
	                  personne2("046 454 286", "Marie", "Gosselin", util::Date(9, 10, 1997), util::Adresse(60, "Notre-Dame", "Montreal", "H1A 5H7", "Quebec"))
	{
	};
	PersonneTest personne1;
	PersonneTest personne2;
};
/**
 * \brief  Test de la méthode bool Personne::operator== (const Personne& p_personne)
 *        cas valide:
 *   		OperatorEgalEgalVrai: 	Personne indentique à elle-même.
 *  		OperatorEgalEgalFaux: 	Personnes différentes
 *        cas invalide:
 *          Aucun d'identifié
 */
TEST_F(DeuxPersonnes, OperatorEgalEgalVrai)
{
	ASSERT_EQ(personne1, personne1);
}
TEST_F(DeuxPersonnes, OperatorEgalEgalFaux)
{
	ASSERT_FALSE(personne1 == personne2);
}

