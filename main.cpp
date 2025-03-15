//
// main.cpp
// Created on 21/10/2018
//

#include <iostream>
#include <vector>
#include <memory> // Pour std::unique_ptr
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"

using namespace std;

int main() {
    // Création d'un vecteur de pointeurs uniques vers des objets Multimedia
    vector<unique_ptr<Multimedia>> multimediaList;

    // Ajout d'une photo et d'une vidéo
    multimediaList.push_back(make_unique<Photo>("EiffelTower", "eiffeltower.jpg", 48.8584, 2.2945));
    multimediaList.push_back(make_unique<Video>("Documentary", "CutePuppies.mp4", 105));

    // Parcours et affichage de tous les éléments
    cout << "Liste des fichiers multimédia :\n";
    for (const auto& media : multimediaList) {
        media->afficher(cout);
        cout << "-----------------------------\n";
    }

    // Lecture de tous les fichiers multimédias
    cout << "Lecture des fichiers multimédia :\n";
    for (const auto& media : multimediaList) {
        media->jouer();  // Polymorphisme : appelle la bonne version de jouer()
    }

    // Pas besoin de delete car std::unique_ptr gère la mémoire automatiquement !
    
    return 0;
}
