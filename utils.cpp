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

#include "utils.h"
#include <cmath>

int RandomInt(int min, int max){

    //Return a random int between min (included) and max (included)
    return min + (rand() % static_cast<int>(max - min + 1));
}
