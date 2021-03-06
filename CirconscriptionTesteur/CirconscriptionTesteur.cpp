/**
 * \file CirconscriptionTesteur.cpp
 * \test Test unitaire de la classe Circonscription
 * \author Maxime Imbeau
 * \version 0.1
 * \date 2020-11-19
 */
#include<gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "Circonscription.h"
#include "Electeur.h"
#include "Candidat.h"
#include "PersonneException.h"
using namespace elections;
using namespace std;
/**
 * \brief Test du constructeur
 * 		  Cas valides: Création d'un objet Circonscription et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		       Le nom de la circonscription ne doit pas etre vide
 */
TEST(Circonscription, ConstructeurParDefaut)
{
	Circonscription uneCirconscription("Election", elections::Candidat("295 057 723", "Max", "Imbeau", util::Date(20, 9, 1998),
			                           util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), 1));
	ASSERT_EQ("Election", uneCirconscription.reqNomCirconscription());
	ASSERT_EQ(elections::Candidat("295 057 723", "Max", "Imbeau", util::Date(20, 9, 1998),
			                      util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), 1), uneCirconscription.reqDeputeElu());
}
//cas invalide
TEST(Circonscription, ConstructeurNomCirconscriptionInvalide)
{
	ASSERT_THROW(Circonscription uneCirconscription("", elections::Candidat("295 057 723", "Max", "Imbeau",
			                                        util::Date(20, 9, 1998), util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), 1)),
			                                        PreconditionException);
}
/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class uneCirconscription: public ::testing::Test
{
public:
	uneCirconscription() : circonscription1("circonscription1", elections::Candidat("295 057 723", "Max", "Imbeau", util::Date(20, 9, 1998),
                                            util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), 1)),
		                   electeur1("295 057 723", "Max", "Imbeau", util::Date(20, 9, 1998),
		                		     util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec")),
						   electeur2("409 772 563", "Jo", "Blo", util::Date(21, 10, 1998),
								     util::Adresse(54, "Commodore", "Levis", "GTA 5T9", "Quebec")),
					       candidat1("046 454 286", "Marie", "Gosselin", util::Date(9, 10, 1997),
					    		     util::Adresse(60, "Notre-Dame", "Montreal", "H1A 5H7", "Quebec"), 1),
						   candidat2("046 454 286", "Marie", "Gosselin", util::Date(9, 10, 1997),
							         util::Adresse(60, "Notre-Dame", "Montreal", "H1A 5H7", "Quebec"), 1)
			{
				circonscription1.inscrire(electeur1);
				circonscription1.inscrire(candidat1);
			};
			Circonscription circonscription1;
			Electeur electeur1;
			Electeur electeur2;
			Candidat candidat1;
			Candidat candidat2;
			std::vector<Personne*> m_vInscrits;
};
/**
 * \brief Test de la méthode reqNomCirconscription()
 *     Cas valide: vérifier le retour du nom de la circonscription
 *     Cas invalide: aucun
 */
TEST_F(uneCirconscription, reqNomCirconscription)
{
	ASSERT_EQ("circonscription1", circonscription1.reqNomCirconscription());
}
/**
 * \brief Test de la méthode reqDeputeElu()
 *     Cas valide: vérifier le retour des informations du depute elu
 *     Cas invalide: aucun
 */
TEST_F(uneCirconscription, reqDeputeElu)
{
	ASSERT_EQ(Candidat("295 057 723", "Max", "Imbeau", util::Date(20, 9, 1998),
	          util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), 1), circonscription1.reqDeputeElu());
}
/**
 * \brief  Test de la méthode bool personneEstDejaPresente(const std::string& p_nas)
 *        cas valide:
 *   		On parcourt la liste electoral et on verifie que la methode nous retourne vrai si la personne est presente
 *        cas invalide:
 *          On parcourt la liste electoral et on verifie que la methode nous retourne faux si la personne est absente
 */
TEST_F(uneCirconscription, testPersonneEstDejaPresente)
{
	EXPECT_TRUE(circonscription1.personneEstDejaPresente("295 057 723"));
}
//cas invalide
TEST_F(uneCirconscription, testPersonneEstDejaPresenteInvalide)
{
	EXPECT_FALSE(circonscription1.personneEstDejaPresente("783 346 059"));
}
/**
 * \brief  Test de la méthode inscrire(const Personne& p_nouvelInscrit)
 *        cas valide:
 *   		Inscrire: un electeur a bien ete inscrit dans la liste electoral
 *        cas invalide:
 *          Impossible d'inscrire une personne qui est deja inscrite
 */
TEST_F(uneCirconscription, testInscrire)
{
	string circonscriptionTest = "circonscription : circonscription1\nDepute sortant :\nCandidat\n----------------------------------------------\nNAS               : 295 057 723\nPrenom            : Max\nNom               : Imbeau\nDate de naissance : Dimanche le 20 septembre 1998\nAdresse           : 54, Laurier, Quebec, G7A 5T9, Quebec\nParti politique   : CONSERVATEUR\n\n\nListe des inscrits :\n\nElecteur\n----------------------------------------------\nNAS               : 295 057 723\nPrenom            : Max\nNom               : Imbeau\nDate de naissance : Dimanche le 20 septembre 1998\nAdresse           : 54, Laurier, Quebec, G7A 5T9, Quebec\n\nCandidat\n----------------------------------------------\nNAS               : 046 454 286\nPrenom            : Marie\nNom               : Gosselin\nDate de naissance : Jeudi le 09 octobre 1997\nAdresse           : 60, Notre-Dame, Montreal, H1A 5H7, Quebec\nParti politique   : CONSERVATEUR\n\n";
    ASSERT_EQ(circonscriptionTest, circonscription1.reqCirconscriptionFormate());
}
//cas invalide
TEST_F(uneCirconscription, testInscrireInvalide)
{
	ASSERT_THROW(circonscription1.inscrire(candidat2), PersonneDejaPresentException);
}
/**
 * \brief  Test de la méthode desinscrire(const std::string& p_nas)
 *        cas valide:
 *   		desinscrire: un electeur a bien ete desinscrit de la liste electoral
 *        cas invalide:
 *          Impossible de desincrire la personne de la liste car elle n'est pas sur la liste
 */
TEST_F(uneCirconscription, testDesinscrire1)
{
	string circonscriptionTest = "circonscription : circonscription1\nDepute sortant :\nCandidat\n----------------------------------------------\nNAS               : 295 057 723\nPrenom            : Max\nNom               : Imbeau\nDate de naissance : Dimanche le 20 septembre 1998\nAdresse           : 54, Laurier, Quebec, G7A 5T9, Quebec\nParti politique   : CONSERVATEUR\n\n\nListe des inscrits :\n\nCandidat\n----------------------------------------------\nNAS               : 046 454 286\nPrenom            : Marie\nNom               : Gosselin\nDate de naissance : Jeudi le 09 octobre 1997\nAdresse           : 60, Notre-Dame, Montreal, H1A 5H7, Quebec\nParti politique   : CONSERVATEUR\n\n";
    circonscription1.desinscrire(electeur1.reqNas());
    ASSERT_EQ(circonscriptionTest, circonscription1.reqCirconscriptionFormate());
}
TEST_F(uneCirconscription, testDesinscrire2)
{
	string circonscriptionTest = "circonscription : circonscription1\nDepute sortant :\nCandidat\n----------------------------------------------\nNAS               : 295 057 723\nPrenom            : Max\nNom               : Imbeau\nDate de naissance : Dimanche le 20 septembre 1998\nAdresse           : 54, Laurier, Quebec, G7A 5T9, Quebec\nParti politique   : CONSERVATEUR\n\n\nListe des inscrits :\n\nElecteur\n----------------------------------------------\nNAS               : 295 057 723\nPrenom            : Max\nNom               : Imbeau\nDate de naissance : Dimanche le 20 septembre 1998\nAdresse           : 54, Laurier, Quebec, G7A 5T9, Quebec\n\n";
    circonscription1.desinscrire(candidat1.reqNas());
    ASSERT_EQ(circonscriptionTest, circonscription1.reqCirconscriptionFormate());
}
//cas invalide
TEST_F(uneCirconscription, testDesinscrireInvalide)
{
	ASSERT_THROW(circonscription1.desinscrire("995 114 675"), PersonneAbsenteException);
}
/**
 * \brief Test du constructeur copie
 * 		  Cas valides: Création d'un objet Circonscription et vérification de l'assignation de tous les attributs
 *		  Cas invalides:
 *		       Aucun
 */
TEST_F(uneCirconscription, ConstructeurCopie)
{
	Circonscription uneAutreCirconscription(circonscription1);
	ASSERT_EQ(circonscription1.reqCirconscriptionFormate(), uneAutreCirconscription.reqCirconscriptionFormate());
}
/**
 * \test Test de la méthode std::string reqCirconscriptionFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objet circonscription formatée
 *        Cas invalides: aucun
 */
TEST_F(uneCirconscription, reqCirconscriptionFormate)
{
	ostringstream os;
	os << "circonscription : " << circonscription1.reqNomCirconscription() << endl;
	os << "Depute sortant :" << endl;
	os << circonscription1.reqDeputeElu().reqPersonneFormate() << endl;
	os << endl;
	os << "Liste des inscrits :" << endl;
	os << endl;
	os << electeur1.reqPersonneFormate() << endl;
	os << candidat1.reqPersonneFormate() << endl;
	ASSERT_EQ(os.str(), circonscription1.reqCirconscriptionFormate());
}
/**
 * \class DeuxCirconscriptions
 * \brief Fixture pour les tests comparaisons de deux circonscriptions
 */
class DeuxCirconscriptions: public ::testing::Test
{
public:
	DeuxCirconscriptions() : circonscription1("circonscription1", elections::Candidat("295 057 723", "Max", "Imbeau", util::Date(20, 9, 1998),
                                             util::Adresse(54, "Laurier", "Quebec", "G7A 5T9", "Quebec"), 1)),
	                         circonscription2("circonscription2", elections::Candidat("046 454 286", "Marie", "Gosselin", util::Date(9, 10, 1997),
	                        		          util::Adresse(60, "Notre-Dame", "Montreal", "H1A 5H7", "Quebec"), 1))
	{
	};
	Circonscription circonscription1;
	Circonscription circonscription2;
};
/**
 * \brief  Test de la méthode const Circonscription& Circonscription::operator= (const Circonscription& p_circonscription)
 *        cas valide:
 *   		OperatorEgalVrai: 	Circonscription indentique à elle-même.
 *  		OperatorEgalFaux: 	Circonscriptions différentes
 *        cas invalide:
 *          Aucun d'identifié
 */
TEST_F(DeuxCirconscriptions, OperatorEgalVrai)
{
	ASSERT_EQ(circonscription1.reqCirconscriptionFormate(), circonscription1.reqCirconscriptionFormate());
}
TEST_F(DeuxCirconscriptions, OperatorEgalFaux)
{
	ASSERT_NE(circonscription1.reqCirconscriptionFormate(), circonscription2.reqCirconscriptionFormate());
}






