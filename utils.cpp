// Fichier     utils.cpp
// Auteur      Noam Dugerdil
// Date        22.11.2022
//
// But         description détaillée du projet
//
// Remarque
//
// Modifs      Date / Auteur / Raison
//
// Compilateur Bundled MinGW - Version w64 9.0

#include "utils.h"
#include <cmath>

int RandomInt(int min, int max){
    return min + (rand() % static_cast<int>(max - min + 1));
}
