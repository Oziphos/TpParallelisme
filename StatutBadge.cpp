#include "StatutBadge.h"

// Recherche le badge dans la map des statuts et retourne true s'il est trouvé, false sinon.
bool StatutBadge::estBadgePresent(Badge *b)
{
    return (statut.find(b->getId()) != statut.end());
}

// Associe le statut spécifié au badge donné en utilisant son ID.
void StatutBadge::setStatutBadge(Badge *b, const std::string &s)
{
    statut[b->getId()] = s;
}

// Retourne le statut associé au badge s'il est présent, ou une chaîne vide sinon.
std::string StatutBadge::getStatutBadge(Badge *b)
{
    auto it = statut.find(b->getId());
    if (it != statut.end())
    {
        return it->second;
    }
    return "";
}

// Retire le badge de la map des statuts.e
void StatutBadge::supprimerStatutBadge(Badge *b)
{
    statut.erase(b->getId());
}

// Retourne true si le badge est présent et a le statut "actif", false sinon.
bool StatutBadge::estBadgeActif(Badge *b)
{
    if (estBadgePresent(b))
    {
        return ("actif" == getStatutBadge(b));
    }
    return false; // Retourne false si le badge n'est pas présent
}
