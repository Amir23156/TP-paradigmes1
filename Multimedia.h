#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

class Multimedia {
protected:
    std::string nom;      // Nom du fichier
    std::string fichier;  // Chemin du fichier

public:
    // Constructeur
    Multimedia() = default;
    Multimedia(const std::string& nom, const std::string& fichier);

    // Destructeur virtuel
    virtual ~Multimedia() = default;

    // Getters
    std::string getNom() const { return nom; }
    std::string getFichier() const { return fichier; }

    // Setters
    void setNom(const std::string& nom) { this->nom = nom; }
    void setFichier(const std::string& fichier) { this->fichier = fichier; }

    // Méthode d'affichage (Polymorphe)
    virtual void afficher(std::ostream& os) const;

    // Méthode pure virtuelle pour jouer le média (rend la classe abstraite)
    virtual void jouer() const = 0;

    // Surcharge de l'opérateur <<
    friend std::ostream& operator<<(std::ostream& flux, const Multimedia& m);
};

#endif // MULTIMEDIA_H
