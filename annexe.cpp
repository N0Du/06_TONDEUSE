// File        utils.cpp
// Author      Noam Dugerdil
// Date        22.11.2022
//
// Purpose     Define basic utilitary function
//
// Remarks
//
// Modifications
//
// Compilator  Bundled MinGW - Version w64 9.0
#include "annexe.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int RandomInt(int min, int max){

    //Return a random int between min (included) and max (included)
    srand(time(NULL));
    //return min + (rand() % RAND_MAX static_cast<int>(max - min + 1));
    return rand() % 4;


    //return min + (rand() % RAND_MAX static_cast<int>(max - min + 1));
}