#ifndef BATIMENT_H
#define BATIMENT_H

class SalleControle;

#include <iostream>
#include "Badge.h"
#include "Laser.h"

class Batiment
{
private:
    // Attributs
    std::string nom;
    SalleControle *salleControle;
    Laser *laserInterieur;
    Laser *laserExterieur;
    bool porteVerouillee;

public:
    // Constructeur
    Batiment(const std::string &n);

    // Getters
    std::string getNom() const;
    SalleControle *getSalleControle() const;
    bool isPorteVerouille() const;
    // Setters
    void setNom(const std::string &nom);
    void setSalleControle(SalleControle *salle);
    void setPorteVerouille(const bool etat);
    // Méthodes
    void badgerInterieur(Badge *badge);
    void badgerExterieur(Badge *badge);
    void ouvrirInterieur();
    void ouvrirExterieur();
    void entreeUtilisateur(Badge *badge);
    void sortieUtilisateur(Badge *badge);
    void fermer();
};

#endif // BATIMENT_H
