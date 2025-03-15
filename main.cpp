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
#include "Groupe.h"

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
    /*int chapitres1[] = {34, 50, 19}; // 3 chapitres de 2min, 2min30s, 3min

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
    f.afficher(std::cout);*/

    //*****7eme Etape*****/
    /*int chapitres1[] = {34, 50, 19}; 
    Film film1("CutePuppies", "CutePuppies.mp4", 103, chapitres1, 3);

    std::cout << "\n Film 1 (Original):\n";
    film1.afficher(std::cout);

    // Copie de l'objet
    Film film2 = film1;
    std::cout << "\n Film 2 (Copie de Film 1):\n";
    film2.afficher(std::cout);

    // Modification des chapitres de film1 (ne doit pas affecter film2)
    int chapitres2[] = {25, 25, 25, 28};
    film1.setChapitres(chapitres2, 4);

    std::cout << "\n Film 1 Après Modification:\n";
    film1.afficher(std::cout);

    std::cout << "\n Film 2 (Ne doit pas être modifié !):\n";
    film2.afficher(std::cout);*/

    //*****8eme Etape *****/
    /*auto photo1 = new Photo("Eiffel Tower", "eiffeltower.jpg", 48.8584, 2.2945);
    auto photo2 = new Photo("Sunset", "sunset.jpg", 37.7749, -122.4194);
    auto video1 = new Video("CuteKittens", "CuteKittens.mp4", 60);
    
    int chapitres[] = {34, 50, 19};
    auto film1 = new Film("CutePuppies", "CutePuppies.mp4", 103, chapitres, 3);

    // Création des groupes
    Groupe groupePhotos("Photos de Voyage");
    groupePhotos.push_back(photo1);
    groupePhotos.push_back(photo2);

    Groupe groupeVideos("Vidéos et Films");
    groupeVideos.push_back(video1);
    groupeVideos.push_back(film1);

    Groupe groupeMixtes("Souvenirs Divers");
    groupeMixtes.push_back(photo1);
    groupeMixtes.push_back(film1);

    // Affichage des groupes
    std::cout << "\n=== Affichage des Groupes ===\n";
    groupePhotos.afficher(std::cout);
    groupeVideos.afficher(std::cout);
    groupeMixtes.afficher(std::cout);

    // Nettoyage (les objets ne doivent pas être supprimés par le groupe)
    delete photo1;
    delete photo2;
    delete video1;
    delete film1;*/

    //*********9eme Partie ********/
    // Création d'objets avec std::shared_ptr
    auto photo1 = std::make_shared<Photo>("Eiffel Tower", "eiffeltower.jpg", 48.8584, 2.2945);
    auto photo2 = std::make_shared<Photo>("Sunset", "sunset.jpg", 37.7749, -122.4194);
    auto video1 = std::make_shared<Video>("Cutekittens", "Cutekittens.mp4", 60);

    int chapitres[] = {34, 50, 19};
    auto film1 = std::make_shared<Film>("CutePuppies", "CutePuppies.mp4", 103, chapitres, 3);

    // Création des groupes
    Groupe groupePhotos("Photos de Voyage");
    groupePhotos.ajouter(photo1);
    groupePhotos.ajouter(photo2);

    Groupe groupeVideos("Vidéos et Films");
    groupeVideos.ajouter(video1);
    groupeVideos.ajouter(film1);

    Groupe groupeMixtes("Souvenirs Divers");
    groupeMixtes.ajouter(photo1);
    groupeMixtes.ajouter(film1);

    // Affichage des groupes
    std::cout << "\n=== Affichage des Groupes ===\n";
    groupePhotos.afficher(std::cout);
    groupeVideos.afficher(std::cout);
    groupeMixtes.afficher(std::cout);

    // Suppression des groupes (mais pas encore des objets car ils sont partagés)
    std::cout << "\n Suppression du groupe Photos de Voyage...\n";
    groupePhotos.clear(); // Les objets existent encore car ils sont dans d'autres groupes

    std::cout << "\n Suppression du groupe Vidéos et Films...\n";
    groupeVideos.clear(); // `film1` existe toujours dans groupeMixtes

    std::cout << "\n Suppression du groupe Souvenirs Divers...\n";
    groupeMixtes.clear(); // `film1` et `photo1` ne sont plus référencés → doivent être détruits

    // Vérification : Si `film1` et `photo1` ne sont plus référencés, ils seront supprimés ici
    std::cout << "\n Fin du programme. Tous les objets inutilisés devraient être détruits !\n";
    return 0;
}
