// Fichier     utils.cpp
// Auteur      Noam Dugerdil - Hasan Ilingi
// Date        22.11.2022
//
// But         Met a disposition des fonctions utilitaires
//
// Remarque
//
// Modifs      Date / Auteur / Raison
//
// Compilateur Bundled MinGW - Version w64 9.0
#include "annexe.h"
#include <random>
using namespace std;

int intAleatoire(int min, int max){
    // Déclaration librairie random
    random_device                  device;
    default_random_engine          generateur(device());
    uniform_int_distribution<int>  distribution(min, max);

    // Retourne une valeur aléatoire
    return distribution(generateur);
}