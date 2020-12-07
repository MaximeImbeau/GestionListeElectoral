/**
 * \file validationFormat.h
 * \brief Fichier qui contient l'interface de fonctions de validation de format
 * \date 2020-10-11
 * \author Nicholas Rompré St-Yves
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include "Adresse.h"
#include "Date.h"

namespace util
{
	bool validerNas(const std::string& p_nas);
	std::string entrerNas();
	std::string entrerParametreString();
	std::string entrerPrenom();
	std::string entrerNom();
	util::Date entrerDateNaissance();
	util::Adresse entrerAdresse();
	int entrerPartiPolitique();
} // namespace util

#endif /* VALIDATIONFORMAT_H_ */
