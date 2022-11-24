// File     mower.h
// Author   Noam Dugerdil
// Date     22.11.2022
//
// Objective  Mower library
//
// Remarks
//
// Modifications
//
// Compilator Bundled MinGW - Version w64 9.0

#ifndef LABO_TONDEUSE_TONDEUSE_H
#define LABO_TONDEUSE_TONDEUSE_H

#include <vector>
#include <array>

const char X = 'X';
const char H = '~';
const char C = '.';
const char L = '#';

using Land = std::vector<std::vector<char>>;
using Mower = std::vector<int>;


void mow(Land& land, Mower& mower, int moveLimit, bool idk);

#endif //LABO_TONDEUSE_TONDEUSE_H
