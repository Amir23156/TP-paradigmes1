#ifndef FILM_H
#define FILM_H

#include "Video.h"

class Film : public Video {
private:
    int* durees = nullptr;  // Tableau des durées des chapitres
    int nbChapitres = 0;    // Nombre de chapitres

public:
    // Constructeurs et destructeur
    Film() = default;
    Film(std::string nom, std::string fichier, int dureeTotale, const int* chapitres, int nbChapitres);
    ~Film(); // Déstructeur

    // Copie et assignation (Règle des 3)
    Film(const Film& other);  // Constructeur de copie
    Film& operator=(const Film& other); // Opérateur d'affectation

    // Modifieur
    void setChapitres(const int* chapitres, int nbChapitres);

    // Accesseur
    const int* getChapitres(int& outNbChapitres) const;

    // Affichage
    void afficher(std::ostream& os) const override;
};

#endif // FILM_H
