#ifndef GROUPE_H
#define GROUPE_H

#include <list>
#include <string>
#include <iostream>
#include "Multimedia.h"

class Groupe : public std::list<Multimedia*> {
private:
    std::string nom;

public:
    // Constructeur
    Groupe(const std::string& nom) : nom(nom) {}

    // Accesseur du nom
    std::string getNom() const { return nom; }

    // Méthode d'affichage
    void afficher(std::ostream& os) const {
        os << "Groupe: " << nom << " (" << this->size() << " éléments)\n";
        for (const auto& media : *this) {
            media->afficher(os);
        }
    }
};

#endif // GROUPE_H
