#ifndef PHOTO_H
#define PHOTO_H

#include "Multimedia.h"

class Photo : public Multimedia {
private:
    double latitude;
    double longitude;

public:
    // Constructeur
    Photo(const std::string& nom, const std::string& fichier, double latitude, double longitude)
        : Multimedia(nom, fichier), latitude(latitude), longitude(longitude) {}

    // Getters
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }

    // Setters
    void setLatitude(double lat) { latitude = lat; }
    void setLongitude(double lon) { longitude = lon; }

    // Méthode d'affichage
    void afficher(std::ostream& os) const override {
        os << "Photo - Nom: " << nom << "\n"
           << "Fichier: " << fichier << "\n"
           << "Latitude: " << latitude << ", Longitude: " << longitude << std::endl;
    }

    // Méthode pour afficher la photo avec un programme externe
    void jouer() const override {
        std::string command = "imagej " + fichier + " &";
        system(command.data());
    }
};

#endif // PHOTO_H
