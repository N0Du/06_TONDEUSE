// File        mower.cpp
// Author      Noam Dugerdil
// Date        22.11.2022
//
// Usage       Functions to display a field, and simulate a mower to mow it.
//
// Remarks
//
// Modifications
//
// Compilator  Bundled MinGW - Version w64 9.0
#include "mower.h"
#include "utils.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//==============================
// Internal function declaration
//==============================

// name        displayLand
// usage       Display the given field
// param       land       Reference to the 2D vector containing the data of the field
// return      void
// exception   n/a
void displayLand(Land& land);

// name        nextPosition
// usage       randomly get the next position the mow should go.
// param       mower      Reference to the array containing the mower position
// return      Position   New position of the mower
// exception   n/a
Position nextPosition (const Mower& mower);

// name        canMove
// usage       Check if the mower is allowed to move to a given position
// param       land       Reference to the 2D vector containing the data of the field
// return      Position   Position the mower want to go
// exception   n/a
bool canMove(const Land& land, const array<int, 2>& newPosition);

// name        cut
// usage       If the mower is on uncutted grass, change the data in the field to cutted grass
// param       land       Reference to the 2D vector containing the data of the field
// return      mower      Reference to the array containing the position of the mower
// exception   n/a
void cut(Land& land, const Mower& mower);

// name        move
// usage       Move the mower to a given position
// param       mower      Reference to the array containing the position of the mower
// return      position   New position the mower will move to
// exception   n/a
void move(Mower& mower, const array<int, 2>& position);



//===============================
// Variables declaration
//===============================
const int NB_DIRECTION = 4; // Number of direction possible in the DIRECTION class
const int COL = 2;          // Widness of the collumns for the display


// Enum containing the direction the mower can go
enum class DIRECTION {
    UP,
    DOWN,
    RIGHT,
    LEFT
};


//============================
// Function definitions
//============================

void mow(Land& land, Mower& mower, int moveLimit, bool idk){
    // Main loop of the mow function
    for(size_t i = 0; i<moveLimit; ++i){
        Position newPos = {};

        bool willMove = false;
        // Loop until the mower as found a position to move
        while(!willMove){
             newPos = nextPosition(mower);

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
    for(auto & line : land){
        for(char row : line){
            cout << right << setw(COL) << row;
        }
        cout << endl;
    }
}

Position nextPosition (const Mower& mower){
    // Get a random int to define wich direction the mow should go
    auto dir = (DIRECTION) RandomInt(0, NB_DIRECTION-1); // Auto to avoid a warning

    Position newPosition = mower;

    // Calculate what will be the position of the mower based on the direction
    switch(dir){
        case DIRECTION::UP:    newPosition.front() = mower.front() - 1; break;
        case DIRECTION::DOWN:  newPosition.front() = mower.front() + 1; break;
        case DIRECTION::RIGHT: newPosition.back()  = mower.back()  + 1; break;
        case DIRECTION::LEFT:  newPosition.back()  = mower.back()  - 1; break;
    }

    return newPosition;
}

bool canMove(const Land& land, const Position& newPosition){
    char nextPositionObject = land.at(newPosition.front()).at(newPosition.back());

    // Return false if the "Object" at the position is either an obstacle or a limit.
    if(nextPositionObject == L || nextPositionObject == X)
        return false;

    return true;
}

void move(Mower& mower, const Position& position){
    // Update the mower "position" value to the new position
    mower.front() = position.front();
    mower.back()  = position.back();
}

void cut(Land& land, const Mower& mower) {
    //Check if the mower is on uncutted grass
    if (land.at(mower.front()).at(mower.back()) == H) {
        // Set the point the mower is on to cut grass
        land.at(mower.front()).at(mower.back()) = C;
    }
}