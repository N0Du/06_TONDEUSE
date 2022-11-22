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
using Mower = std::array<int, 2>;


void mow(Land land, Mower mower, int moveLimit, bool idk);

void displayLand(Land land);

#endif //LABO_TONDEUSE_TONDEUSE_H
