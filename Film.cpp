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

// Constructeur de copie (Copie profonde)
Film::Film(const Film& other) : Video(other) {  // Appelle le constructeur de copie de Video
    setChapitres(other.durees, other.nbChapitres);
}

// Opérateur d'affectation (=) (Copie profonde)
Film& Film::operator=(const Film& other) {
    if (this != &other) { // Éviter l'auto-affectation
        Video::operator=(other); // Copie des attributs de Video
        setChapitres(other.durees, other.nbChapitres);
    }
    return *this;
}

// Modifieur : Met à jour le tableau des chapitres
void Film::setChapitres(const int* chapitres, int nbChapitres) {
    delete[] durees; // Supprime l'ancien tableau

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
    return durees;
}

// Affichage des chapitres
void Film::afficher(std::ostream& os) const {
    Video::afficher(os);
    os << "Chapitres: ";
    for (int i = 0; i < nbChapitres; i++) {
        os << durees[i] << "s ";
    }
    os << std::endl;
}
