// Fichier     mower.cpp
// Auteur      Noam Dugerdil - Hasan Ilingi
// Date        22.11.2022
//
// But         Affiche un champ dans lequel une tondeuse tond le gazon
//
// Remarque
//
// Modifs      Date / Auteur / Raison
//
// Compilateur Bundled MinGW - Version w64 9.0
#include "tondeuse.h"
#include "annexe.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

//===================================
// Déclaration des fonctions internes
//===================================

// nom         afficherTerrain
// but         Fonction permettant d'afficher le terrain
// param       terrain      Données du terrain à afficher
// return      void
// exception   n/a
void afficherTerrain(const Terrain& terrain);

// nom         positionSuivante
// but         Calcul la potentielle prochaine position de la tondeuse
// param       tondeuse      Notre tondeuse (Sa position)
// return      Position      La potentielle future position de la tondeuse
// exception   n/a
Position positionSuivante(const Tondeuse& tondeuse);

// nom         peuxSeDeplacer
// but         Test si la tondeuse et autorisé à se déplacer sur la position voulue
// param       terrain             Données de notre terrain
// param       nouvellePosition    La position sur laquelle la tondeuse veut se déplacer
// return      bool                Est-ce qu'elle a droit de s'y déplacer
// exception   n/a
bool peuxSeDeplacer(const Terrain& terrain, const Position& nouvellePosition);

// nom         couper
// but         Coupe l'herbe sur laquelle la tondeuse se trouve
// param       terrain             Données de notre terrain
// param       tondeuse            Position de la tondeuse
// return      void
// exception   n/a
void couper(Terrain& terrain, const Tondeuse& tondeuse);

// nom         deplacer
// but         Déplace la tondeuse à la position donnée
// param       tondeuse            La position de notre tondeuse
// param       nouvellePosition    La position sur laquelle la tondeuse va se déplacer
// exception   n/a
void deplacer(Tondeuse& tondeuse, const Position& position);

//===============================
// Déclaration des variable
//===============================
const int NB_DIRECTION = 4; // Nombre de directions possible dans l'enum
const int COL = 2;          // Largeur des colonnes lors de l'affichage


// enum contenant les différents déplacements que la tondeuse peut effectuer
enum class DIRECTION {
    HAUT,
    BAS,
    DROITE,
    GAUCHE
};


//============================
// Définition des fonctions
//============================

void tondre(Terrain& terrain, Tondeuse& tondeuse, int nbDeplacement, bool affichage){
    // Boucle principale de la fonction permettant de déplacer la tondeuse le nombre de fois voulu
    for(int i = 0; i< nbDeplacement; ++i){
        Position nouvellePos;

        bool posValide = false; // Est-ce que la tondeuse peut se déplacer sur la case voulue

        // Calcul une nouvelle position jusqu'à que la tondeuse puisse s'y déplacer
        while(!posValide){
            nouvellePos = positionSuivante(tondeuse);             // Récupere une position aléatoire sur laquelle la tondeuse pourrait se déplacer
            posValide   = peuxSeDeplacer(terrain, nouvellePos);   // Vérifie si la tondeuse peut se déplacer a la position voulue
        }

        deplacer(tondeuse, nouvellePos);

        couper(terrain, tondeuse);

        if(affichage)
            afficherTerrain(terrain);
    }
}

void afficherTerrain(const Terrain& terrain){
    // Vide l'affichage de la console
    system("clear");

    // Affiche le terrain
    for(auto & line : terrain){
        for(char row : line){
            cout << right << setw(COL) << row;
        }
        cout << endl;
    }
}

Position positionSuivante (const Tondeuse& tondeuse){
    // Défini une direction aléatoire
    auto dir = (DIRECTION) intAleatoire(0, NB_DIRECTION-1); // Auto to avoid a warning

    Position nouvellePosition = tondeuse;

    // Calcule la nouvelle position de la tondeuse en fonction de la direction
    switch(dir){
        case DIRECTION::HAUT:    nouvellePosition.front() = tondeuse.front() - 1; break;
        case DIRECTION::BAS:     nouvellePosition.front() = tondeuse.front() + 1; break;
        case DIRECTION::DROITE:  nouvellePosition.back()  = tondeuse.back()  + 1; break;
        case DIRECTION::GAUCHE:  nouvellePosition.back()  = tondeuse.back()  - 1; break;
    }

    return nouvellePosition;
}

bool peuxSeDeplacer(const Terrain& terrain, const Position& nouvellePosition){
    // Récupere le type d'"objet" sur la position voulue
    char objetSurLaPositionVoulue = terrain.at(size_t(nouvellePosition.front())).at(size_t(nouvellePosition.back()));

    // Retourne false si la tondeuse ne peut pas se déplacer à la position voulue.
    if(objetSurLaPositionVoulue == L || objetSurLaPositionVoulue == X)
        return false;

    return true;
}

void deplacer(Tondeuse& tondeuse, const Position& position){
    // Met à jour l'array de la tondeuse pour changer sa position
    tondeuse.front() = position.front();
    tondeuse.back()  = position.back();
}

void couper(Terrain& terrain, const Tondeuse& tondeuse) {
    // Remplace la case sur laquelle la tondeuse se trouve par de l'herbe coupée.
    terrain.at(size_t(tondeuse.front())).at(size_t(tondeuse.back())) = C;
}