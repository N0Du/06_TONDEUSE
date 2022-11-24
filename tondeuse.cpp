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
#include "tondeuse.h"
#include "annexe.h"

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
void displayLand(Terrain& terrain);

// name        nextPosition
// usage       randomly get the next position the mow should go.
// param       mower      Reference to the array containing the mower position
// return      Position   New position of the mower
// exception   n/a
Position nextPosition (const Tondeuse& tondeuse);

// name        canMove
// usage       Check if the mower is allowed to move to a given position
// param       land       Reference to the 2D vector containing the data of the field
// return      Position   Position the mower want to go
// exception   n/a
bool canMove(const Terrain& terrain, const Position& newPosition);

// name        cut
// usage       If the mower is on uncutted grass, change the data in the field to cutted grass
// param       land       Reference to the 2D vector containing the data of the field
// return      mower      Reference to the array containing the position of the mower
// exception   n/a
void cut(Terrain& terrain, const Tondeuse& tondeuse);

// name        move
// usage       Move the mower to a given position
// param       mower      Reference to the array containing the position of the mower
// return      position   New position the mower will move to
// exception   n/a
void move(Tondeuse& tondeuse, const Position& position);

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

void tondre(Terrain& terrain, Tondeuse& tondeuse, int moveLimit, bool display){
    // Main loop of the mow function
    for(size_t i = 0; i<moveLimit; ++i){
        Position newPos = {};

        bool willMove = false;
        // Loop until the mower as found a position to move
        while(!willMove){
             newPos = nextPosition(tondeuse);

            if(canMove(terrain, newPos)){
                willMove = true;
            }
        }
        move(tondeuse, newPos);
        cut(terrain, tondeuse);

        if(display)
            displayLand(terrain);
    }
}

void displayLand(Terrain& terrain){
    // Clear the display
    system("clear");

    //Display the field
    for(auto & line : terrain){
        for(char row : line){
            cout << right << setw(COL) << row;
        }
        cout << endl;
    }
}

Position nextPosition (const Tondeuse& tondeuse){
    // Get a random int to define wich direction the mow should go
    auto dir = (DIRECTION) RandomInt(0, NB_DIRECTION-1); // Auto to avoid a warning

    Position newPosition = tondeuse;

    // Calculate what will be the position of the mower based on the direction
    switch(dir){
        case DIRECTION::UP:    newPosition.front() = tondeuse.front() - 1; break;
        case DIRECTION::DOWN:  newPosition.front() = tondeuse.front() + 1; break;
        case DIRECTION::RIGHT: newPosition.back()  = tondeuse.back()  + 1; break;
        case DIRECTION::LEFT:  newPosition.back()  = tondeuse.back()  - 1; break;
    }

    return newPosition;
}

bool canMove(const Terrain& terrain, const Position& newPosition){
    char nextPositionObject = terrain.at(newPosition.front()).at(newPosition.back());

    // Return false if the "Object" at the position is either an obstacle or a limit.
    if(nextPositionObject == L || nextPositionObject == X)
        return false;

    return true;
}

void move(Tondeuse& tondeuse, const Position& position){
    // Update the mower "position" value to the new position
    tondeuse.front() = position.front();
    tondeuse.back()  = position.back();
}

void cut(Terrain& terrain, const Tondeuse& tondeuse) {
    //Check if the mower is on uncutted grass
    terrain.at(tondeuse.front()).at(tondeuse.back()) = C;
}