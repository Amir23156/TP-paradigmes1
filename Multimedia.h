#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

class Multimedia {
protected:
    std::string nom;      // Nom de l'objet multimédia
    std::string fichier;  // Chemin du fichier associé

public:
    // Constructeurs
    Multimedia() = default;
    Multimedia(const std::string& nom, const std::string& fichier);

    // Destructeur (virtuel pour support d'héritage)
    virtual ~Multimedia() = default;

    // Getters
    std::string getNom() const { return nom; }
    std::string getFichier() const { return fichier; }

    // Setters
    void setNom(const std::string& nom) { this->nom = nom; }
    void setFichier(const std::string& fichier) { this->fichier = fichier; }

    // Méthode d'affichage
    virtual void afficher(std::ostream& os) const;
    
    // Surcharge de l'opérateur << pour afficher l'objet directement
    friend std::ostream& operator<<(std::ostream& flux, const Multimedia& m);

};

#endif // MULTIMEDIA_H
