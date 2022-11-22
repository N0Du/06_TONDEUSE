// Fichier     nom du fichier (.h / .cpp)
// Auteur      Noam Dugerdil
// Date        ...
//
// But         description détaillée du projet
//
// Remarque
//
// Modifs      Date / Auteur / Raison
//
// Compilateur Bundled MinGW - Version w64 9.0

#ifndef LABO_TONDEUSE_TONDEUSE_H
#define LABO_TONDEUSE_TONDEUSE_H

#include <vector>
#include <array>

using Land = std::vector<std::vector<char>>;
using Mower = std::array<int, 3>;



void mow(Land land, Mower mower, int moveLimit, bool idk);


#endif //LABO_TONDEUSE_TONDEUSE_H
