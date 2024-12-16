#include "AccesBadge.h"

// Constructeur

// Initialise un objet AccesBadge vide.
AccesBadge::AccesBadge() {}

// Getters

// Retourne une multimap contenant les autorisations associées aux badges.
std::multimap<std::string, int> AccesBadge::getAutorisations() const
{
    return autorisations;
}

// Setters

// Met à jour les autorisations avec la multimap fournie.
void AccesBadge::setAutorisations(std::multimap<std::string, int> a)
{
    autorisations = a;
}

// Methodes

// Permet d'ajouter une autorisation pour un badge dans un bâtiment spécifique.
// Si l'autorisation existe déjà, affiche un message d'erreur.
void AccesBadge::ajouterAutorisation(Batiment *batiment, Badge *badge)
{
    if (estAutorise(batiment, badge))
    {
        std::cout << "L'ajout de l'autorisation a échouée car elle existe déjà" << std::endl;
        return;
    }
    autorisations.insert(std::make_pair(batiment->getNom(), badge->getId()));
}

// Permet de retirer une autorisation existante pour un badge dans un bâtiment spécifique.
// Si l'autorisation n'existe pas, affiche un message d'erreur.
void AccesBadge::supprimerAutorisation(Batiment *batiment, Badge *badge)
{
    if (!estAutorise(batiment, badge))
    {
        std::cout << "La suppression de l'autorisation a échouée car elle n'existe pas" << std::endl;
        return;
    }

    auto range = autorisations.equal_range(batiment->getNom());
    std::vector<std::multimap<std::string, int>::iterator> toDelete;

    // Parcourir la plage pour collecter les éléments à supprimer
    for (auto it = range.first; it != range.second; ++it)
    {
        if (it->second == badge->getId())
        {
            toDelete.push_back(it);
        }
    }

    // Supprimer les éléments collectés
    for (auto it : toDelete)
    {
        autorisations.erase(it);
    }
}

// Vérifie si un badge a une autorisation pour un bâtiment donné.
// Retourne true si l'autorisation existe, false sinon.
bool AccesBadge::estAutorise(Batiment *batiment, Badge *badge) const
{
    for (const auto &pair : autorisations)
    {
        if (pair.first == batiment->getNom() && pair.second == badge->getId())
        {
            return true;
        }
    }
    return false;
}

// Retourne une liste des noms des bâtiments où le badge fourni est autorisé.
std::vector<std::string> AccesBadge::getBadgeAutorisations(Badge *badge) const
{
    std::vector<std::string> nomsBatiments;
    for (const auto &pair : autorisations)
    {
        if (pair.second == badge->getId())
        {
            nomsBatiments.push_back(pair.first);
        }
    }
    return nomsBatiments;
}
