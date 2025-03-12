#include "Multimedia.h"

// Constructeur avec paramètres
Multimedia::Multimedia(const std::string& nom, const std::string& fichier) 
    : nom(nom), fichier(fichier) {}

// Méthode d'affichage des informations de l'objet
void Multimedia::afficher(std::ostream& os) const {
    os << "Nom: " << nom << "\n"
       << "Fichier: " << fichier << std::endl;
}


std::ostream& operator<< (std::ostream& flux, const Multimedia& m){
    m.afficher(flux);
    return flux;
}