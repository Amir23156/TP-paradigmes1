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
#include "Film.h"

using namespace std;

int main() {
    //****5eme Partie*****
    /*// Création d'un vecteur de pointeurs uniques vers des objets Multimedia
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

    // Pas besoin de delete car std::unique_ptr gère la mémoire automatiquement !*/
 
    //*****6eme Partie******
    // Définition des chapitres (durées en secondes)
    int chapitres1[] = {34, 50, 19}; // 3 chapitres de 2min, 2min30s, 3min

    // Création du Film
    Film f("CutePuppies", "CutePuppies.mp4", 103, chapitres1, 3);

    // Affichage du Film
    std::cout << " Film Initial:" << std::endl;
    f.afficher(std::cout);

    // Modification des chapitres
    int chapitres2[] = {25, 25, 25, 28}; // Nouveau découpage en 4 chapitres
    f.setChapitres(chapitres2, 4);

    // Affichage après modification
    std::cout << "\n Film Après Modification:" << std::endl;
    f.afficher(std::cout);

    
    return 0;
}
