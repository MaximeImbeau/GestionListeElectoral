/**
 * \file PersonneException.h
 * \brief Fichier qui contient l'interface des classes qui souleve des exceptions
 * 		  sur des objets personne
 * \author Nicholas Rompré St-Yves
 * \version 0.1
 * \date 08/12/2020
 */
#ifndef PERSONNEEXCEPTION_H_
#define PERSONNEEXCEPTION_H_

#include <stdexcept>

class PersonneException : public std::runtime_error{
public:
	PersonneException(const std::string& p_raison):
		std::runtime_error(p_raison){}
};

class PersonneDejaPresentException : public PersonneException{
public:
	PersonneDejaPresentException(const std::string& p_raison):
		PersonneException(p_raison){}
};

class PersonneAbsenteException : public PersonneException{
public:
	PersonneAbsenteException(const std::string& p_raison):
		PersonneException(p_raison){}
};

#endif /* PERSONNEEXCEPTION_H_ */
