// Fichier     mower.cpp
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
#include "mower.h"
#include "utils.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Internal function declaration
void displayLand(Land& land);

// Enum containing the direction the mower can go
enum class DIRECTION {
    UP,
    DOWN,
    RIGHT,
    LEFT
};

const int NB_DIRECTION = 4; // Number of direction possible in the DIRECTION class

const int COL = 2;          // largeur des collones lors de l'affichage

bool canMove(const Land& land, const vector<int>& newPosition){
    char nextPositionObject = land.at(newPosition.front()).at(newPosition.back());

    if(nextPositionObject == L || nextPositionObject == X)
        return false;

    return true;
}

vector<int> nextPosition (const Mower& mower){
    auto dir = (DIRECTION) RandomInt(0, NB_DIRECTION-1); // Auto pour warning

    vector<int> newPosition = mower;

    //REMPLACER PAR SWITCH ??
    if(dir == DIRECTION::UP){
        newPosition.front() = mower.front() - 1;
    }else if(dir == DIRECTION::DOWN){
        newPosition.front() = mower.front() + 1;
    }else if(dir == DIRECTION::RIGHT){
        newPosition.back() = mower.back() + 1;
    }else if(dir == DIRECTION::LEFT){
        newPosition.back() = mower.back() - 1;
    }

    return newPosition;
}

void move(Mower& mower, vector<int> position){
    mower.front() = position.front();
    mower.back()  = position.back();
}

void cut(Land& land, const Mower& mower){
    land.at(mower.front()).at(mower.back()) = C;
}

void mow(Land& land, Mower& mower, int moveLimit, bool idk){
    // Main loop of the mow function
    for(size_t i = 0; i<moveLimit; ++i){
        bool willMove = false;
        vector<int> newPos = {0, 0};

        while(!willMove){
             newPos = nextPosition(mower);;

            if(canMove(land, newPos)){
                willMove = true;
            }
        }
        move(mower, newPos);
        cut(land, mower);
        displayLand(land);
    }
}

void displayLand(Land& land){
    // Clear the display
    system("clear");

    //Display the field
    for(size_t line = 0; line < land.size(); ++line){
        for(size_t row = 0; row < land.at(line).size(); ++row){
            cout << right << setw(COL) << land.at(line).at(row);
        }
        cout << endl;
    }
}