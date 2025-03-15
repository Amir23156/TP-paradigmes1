#ifndef GROUPE_H
#define GROUPE_H

#include <list>
#include <string>
#include <iostream>
#include "Multimedia.h"
//********8eme Partie***********/
/*class Groupe : public std::list<Multimedia*> {
private:
    std::string nom;

public:
    // Constructeur
    Groupe(const std::string& nom) : nom(nom) {}

    // Accesseur du nom
    std::string getNom() const { return nom; }

    // Ajouter un objet au groupe
    void ajouter(const MultimediaPtr& media) {
        this->push_back(media);
    }

    // Méthode d'affichage
    void afficher(std::ostream& os) const {
        os << "Groupe: " << nom << " (" << this->size() << " éléments)\n";
        for (const auto& media : *this) {
            media->afficher(os);
        }
    }
};*/

//***********9eme Partie *********/
using MultimediaPtr = std::shared_ptr<Multimedia>;

class Groupe : public std::list<MultimediaPtr> {
private:
    std::string nom;

public:
    // Constructeur
    Groupe(const std::string& nom) : nom(nom) {}

    // Accesseur du nom
    std::string getNom() const { return nom; }

    // Ajouter un objet au groupe
    void ajouter(const MultimediaPtr& media) {
        this->push_back(media);
    }

    // Méthode d'affichage
    void afficher(std::ostream& os) const {
        os << "Groupe: " << nom << " (" << this->size() << " éléments)\n";
        if (this->empty()) {
            os << "(Vide)\n";
        }
        for (const auto& media : *this) {
            media->afficher(os);
        }
    }
};

#endif // GROUPE_H
