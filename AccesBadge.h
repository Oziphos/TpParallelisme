#ifndef ACCESBADGE_H
#define ACCESBADGE_H

#include <map>
#include <vector>
#include <iostream>
#include "Badge.h"
#include "Batiment.h"

class AccesBadge
{
private:
    // Attributs
    std::multimap<std::string, int> autorisations;

public:
    // Constructeur
    AccesBadge();

    // Getters
    std::multimap<std::string, int> getAutorisations() const;

    // Setters
    void setAutorisations(std::multimap<std::string, int> a);

    // Methodes
    void ajouterAutorisation(Batiment *batiment, Badge *badge);
    void supprimerAutorisation(Batiment *batiment, Badge *badge);
    bool estAutorise(Batiment *batiment, Badge *badge) const;
    std::vector<std::string> getBadgeAutorisations(Badge *badge) const;
};

#endif // ACCESBADGE_H
