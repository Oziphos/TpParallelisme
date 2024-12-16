#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <iostream>
#include "Badge.h"
#include "Batiment.h"

class Utilisateur
{
private:
    // Attributs
    std::string nom;
    std::string prenom;
    Badge *badge;

public:
    // Constructeur
    Utilisateur(const std::string &n, const std::string &p, Badge *b = nullptr);

    // Getters
    std::string getNom() const { return nom; }
    std::string getPrenom() const { return prenom; }
    Badge *getBadge() const { return badge; }

    // Setters
    void setNom(const std::string &n) { nom = n; }
    void setPrenom(const std::string &p) { prenom = p; }
    void setBadge(Badge *b) { badge = b; }

    // Méthodes
    void badgerInterieur(Batiment *b);
    void badgerExterieur(Batiment *b);
    void entrerBatiment(Batiment *b);
    void sortirBatiment(Batiment *b);
    void afficher() const;
};

#endif // UTILISATEUR_H
