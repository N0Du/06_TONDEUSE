// File     mower.h
// Author   Noam Dugerdil
// Date     22.11.2022
//
// Usage    Provide function to display a field, and create a mower to mow it.
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

// Field "objects" variables
const char X = 'X';     // Obstacle
const char H = '~';     // Uncutted grass
const char C = '.';     // Cutted grass
const char L = '#';     // Limit of the field

// Type definition
using Land = std::vector<std::vector<char>>;
using Mower = std::array<int, 2>;
using Position = std::array<int, 2>; // Same as mower but redeclared to make the code more understandable


// name        mow
// usage       update the mower and the field. Then display the field
// param       land        Reference to the 2D vector containing the data of the field
// param       mower       array of 2 int, contain the position of the mower in the field
// param       moveLimit   Number of steps the mower is going to do
// param       idk         I DONT KNOW
// return      void
// exception   n/a
void mow(Land& land, Mower& mower, int moveLimit, bool idk);

#endif //LABO_TONDEUSE_TONDEUSE_H
