// Fichier     tondeuse.h
// Auteur      Noam Dugerdil - Hasan Ilingi
// Date        22.11.2022
//
// But         Affiche un champ dans lequel une tondeuse tond l'herbe
//
// Remarque
//
// Modifs      Date / Auteur / Raison
//
// Compilateur Bundled MinGW - Version w64 9.0

#ifndef LABO_TONDEUSE_TONDEUSE_H
#define LABO_TONDEUSE_TONDEUSE_H

#include <vector>
#include <array>

// Variable definissant la "forme" des "objets" du terrain.
const char X = 'X';     // Obstacle
const char H = '~';     // Herbe non coupée
const char C = '.';     // Herbe coupée
const char L = '#';     // Limite du terrain

// Définition des types
using Terrain  = std::vector<std::vector<char>>;
using Tondeuse = std::array<int, 2>;
using Position = std::array<int, 2>;    // équivalent au type Tondeuse mais redéclaration pour améliorer la lisibilité
                                        //du code


// nom         tondre
// but         Gestion de la tondeuse et affichage (ou non) du terrain
// param       terrain             Les données du terrain
// param       tondeuse            La variable contenant la position de notre tondeuse
// param       nbDeplacement       Le nombre maximal de déplacement de la tondeuse
// param       affichage           Défini si le terrain doit être afficher ou non.
// exception   n/a
void tondre(Terrain& terrain, Tondeuse& tondeuse, int nbDeplacement, bool affichage);

#endif //LABO_TONDEUSE_TONDEUSE_H
