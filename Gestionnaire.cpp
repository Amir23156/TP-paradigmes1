#include "Gestionnaire.h"
#include <iostream>

// Créer une Photo
std::shared_ptr<Photo> Gestionnaire::creerPhoto(const std::string& nom, const std::string& fichier, double latitude, double longitude) {
    auto photo = std::make_shared<Photo>(nom, fichier, latitude, longitude);
    objetsMultimedia[nom] = photo;
    return photo;
}

// Créer une Vidéo
std::shared_ptr<Video> Gestionnaire::creerVideo(const std::string& nom, const std::string& fichier, int duree) {
    auto video = std::make_shared<Video>(nom, fichier, duree);
    objetsMultimedia[nom] = video;
    return video;
}

// Créer un Film
std::shared_ptr<Film> Gestionnaire::creerFilm(const std::string& nom, const std::string& fichier, int duree, const int* chapitres, int nbChapitres) {
    auto film = std::make_shared<Film>(nom, fichier, duree, chapitres, nbChapitres);
    objetsMultimedia[nom] = film;
    return film;
}

// Créer un Groupe
std::shared_ptr<Groupe> Gestionnaire::creerGroupe(const std::string& nom) {
    auto groupe = std::make_shared<Groupe>(nom);
    groupes[nom] = groupe;
    return groupe;
}

// Afficher un Objet
void Gestionnaire::afficherObjet(const std::string& nom) const {
    auto it = objetsMultimedia.find(nom);
    if (it != objetsMultimedia.end()) {
        it->second->afficher(std::cout);
    } else {
        std::cout << " Objet " << nom << " non trouvé !\n";
    }
}

// Afficher un Groupe
void Gestionnaire::afficherGroupe(const std::string& nom) const {
    auto it = groupes.find(nom);
    if (it != groupes.end()) {
        it->second->afficher(std::cout);
    } else {
        std::cout << " Groupe " << nom << " non trouvé !\n";
    }
}

// Jouer un Objet
void Gestionnaire::jouerObjet(const std::string& nom) const {
    auto it = objetsMultimedia.find(nom);
    if (it != objetsMultimedia.end()) {
        it->second->jouer();
    } else {
        std::cout << " Impossible de jouer " << nom << ": objet non trouvé !\n";
    }
}

//  Supprimer un Objet
void Gestionnaire::supprimerObjet(const std::string& nom) {
    auto it = objetsMultimedia.find(nom);
    if (it != objetsMultimedia.end()) {
        // Supprimer des groupes
        for (auto& [_, groupe] : groupes) {
            groupe->remove(it->second);
        }
        objetsMultimedia.erase(it);
        std::cout << " Objet " << nom << " supprimé.\n";
    } else {
        std::cout << " Objet " << nom << " introuvable.\n";
    }
}

// Supprimer un Groupe
void Gestionnaire::supprimerGroupe(const std::string& nom) {
    if (groupes.erase(nom)) {
        std::cout << " Groupe " << nom << " supprimé.\n";
    } else {
        std::cout << " Groupe " << nom << " introuvable.\n";
    }
}
