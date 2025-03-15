#ifndef VIDEO_H
#define VIDEO_H

#include "Multimedia.h"

class Video : public Multimedia {
private:
    int duree; // Durée en secondes

public:
    // Constructeur
    Video(const std::string& nom, const std::string& fichier, int duree)
        : Multimedia(nom, fichier), duree(duree) {}

    // Getter
    int getDuree() const { return duree; }

    // Setter
    void setDuree(int d) { duree = d; }

    // Méthode d'affichage
    void afficher(std::ostream& os) const override {
        os << "Vidéo - Nom: " << nom << "\n"
           << "Fichier: " << fichier << "\n"
           << "Durée: " << duree << " secondes" << std::endl;
    }

    // Méthode pour lire la vidéo avec un programme externe
    void jouer() const override {
        std::string command = "mpv --ao=pulse  " + fichier + " &";
        system(command.data());
    }
};

#endif // VIDEO_H
