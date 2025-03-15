#include "Film.h"
#include <iostream>
#include <cstring> // Pour memcpy

// Constructeur avec paramètres
Film::Film(std::string nom, std::string fichier, int dureeTotale, const int* chapitres, int nbChapitres)
    : Video(nom, fichier, dureeTotale) {
    setChapitres(chapitres, nbChapitres);
}

// Destructeur : Libère la mémoire du tableau de chapitres
Film::~Film() {
    delete[] durees;
}

// Modifieur : Met à jour le tableau des chapitres
void Film::setChapitres(const int* chapitres, int nbChapitres) {
    // Supprime l'ancien tableau s'il existe
    delete[] durees;

    if (chapitres && nbChapitres > 0) {
        this->nbChapitres = nbChapitres;
        durees = new int[nbChapitres];
        memcpy(durees, chapitres, nbChapitres * sizeof(int)); // Copie les valeurs
    } else {
        durees = nullptr;
        this->nbChapitres = 0;
    }
}

// Accesseur : Retourne une copie sécurisée des chapitres
const int* Film::getChapitres(int& outNbChapitres) const {
    outNbChapitres = nbChapitres;
    return durees; // Retourne un pointeur constant pour empêcher les modifications
}

// Méthode d'affichage des chapitres
void Film::afficher(std::ostream& os) const {
    Video::afficher(os); // Appelle l'affichage de Video
    os << "Chapitres: ";
    for (int i = 0; i < nbChapitres; i++) {
        os << durees[i] << "s ";
    }
    os << std::endl;
}
