//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
using namespace std;

int main() {
    // Créer une photo et une vidéo
    Photo p("Eiffel Tower", "eiffeltower.jpg", 48.8584, 2.2945);
    Video v("Documentary", "CutePuppies.mp4", 105);

    // Afficher les objets
    std::cout << p << std::endl;
    std::cout << v << std::endl;

    // Jouer les objets
    p.jouer();
    v.jouer();

    return 0;
}

