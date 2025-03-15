#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video {
private:
    int* durees = nullptr;  // Tableau des durées des chapitres
    int nbChapitres = 0;    // Nombre de chapitres

public:
    // Constructeurs
    Film() = default;
    Film(std::string nom, std::string fichier, int dureeTotale, const int* chapitres, int nbChapitres);

    // Destructeur
    virtual ~Film();

    // Modifieur : Met à jour les chapitres
    void setChapitres(const int* chapitres, int nbChapitres);

    // Accesseur : Retourne une copie des chapitres
    const int* getChapitres(int& outNbChapitres) const;

    // Affichage des chapitres
    void afficher(std::ostream& os) const override;
};

#endif // FILM_H
