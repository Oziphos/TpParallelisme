#ifndef STATUT_BADGE_H
#define STATUT_BADGE_H

#include <map>
#include <iostream>
#include "Badge.h" // Assurez-vous que Badge.h est inclus pour utiliser Badge

class StatutBadge
{
private:
    // Attributs
    std::map<int, std::string> statut;

public:
    // Constructeur
    StatutBadge() = default;

    // Getters
    std::string getStatutBadge(Badge *b);

    // Setters
    void setStatutBadge(Badge *b, const std::string &s);

    // Méthodes
    bool estBadgePresent(Badge *b);
    void supprimerStatutBadge(Badge *b);
    bool estBadgeActif(Badge *b);
};

#endif // STATUT_BADGE_H
