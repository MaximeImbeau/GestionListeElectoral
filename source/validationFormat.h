/**
 * \file validationFormat.h
 * \brief Fichier qui contient l'interface du fichier de validation d'une NAS et du format d'un fichier.
 * \author Maxime Imbeau
 * \version 0.1
 * \date 12/10/2020
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

#include <string>

namespace util
{
const int MAX = 11;
const int nb_parti = 5;

bool validerNas(const std::string& p_nas);
bool validerFormatFichier(std::istream& p_is);
}// namespace util

#endif /* VALIDATIONFORMAT_H_ */
