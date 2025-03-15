#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include <map>
#include <memory>
#include "Multimedia.h"
#include "Photo.h"
#include "Video.h"
#include "Film.h"
#include "Groupe.h"

using MultimediaPtr = std::shared_ptr<Multimedia>;
using GroupePtr = std::shared_ptr<Groupe>;

class Gestionnaire {
private:
    std::map<std::string, MultimediaPtr> objetsMultimedia;
    std::map<std::string, GroupePtr> groupes;

public:
    // Création d'objets
    std::shared_ptr<Photo> creerPhoto(const std::string& nom, const std::string& fichier, double latitude, double longitude);
    std::shared_ptr<Video> creerVideo(const std::string& nom, const std::string& fichier, int duree);
    std::shared_ptr<Film> creerFilm(const std::string& nom, const std::string& fichier, int duree, const int* chapitres, int nbChapitres);
    std::shared_ptr<Groupe> creerGroupe(const std::string& nom);

    // Rechercher et afficher un objet ou un groupe
    void afficherObjet(const std::string& nom) const;
    void afficherGroupe(const std::string& nom) const;

    // Jouer un objet multimédia
    void jouerObjet(const std::string& nom) const;

    // Supprimer un objet ou un groupe
    void supprimerObjet(const std::string& nom);
    void supprimerGroupe(const std::string& nom);
};

#endif // GESTIONNAIRE_H
