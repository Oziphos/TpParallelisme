#include "Journal.h"

// Constructor

// Initialise un objet Journal
Journal::Journal()
{
    std::cout << historiqueEntreeSortie.size() << std::endl;
}

// Getters

std::vector<EntreeSortie> Journal::getHistoriqueEntreeSortie() const
{
    return historiqueEntreeSortie;
}

// Methods

// Enregistre une entrée dans un bâtiment avec un badge spécifique, incluant un timestamp.
void Journal::ajouterEntree(Batiment *batiment, Badge *badge)
{
    // Créer le timestamp pour l'entrée
    auto entree = std::chrono::system_clock::now();

    // Créer un objet EntreeSortie pour l'entrée
    EntreeSortie entreeSortie(entree, std::chrono::system_clock::time_point(), batiment->getNom(), badge->getId());

    // Ajouter cet objet à l'historique
    historiqueEntreeSortie.push_back(entreeSortie);

    std::cout << "Entrée enregistrée dans le bâtiment: " << batiment->getNom() << " avec le badge ID: " << badge->getId() << std::endl;
}

// Enregistre une sortie d'un bâtiment pour un badge spécifique.
// Si une entrée correspondante n'existe pas, affiche un message d'erreur.
void Journal::ajouterSortie(Batiment *batiment, Badge *badge)
{
    // Créer le timestamp pour la sortie
    auto sortie = std::chrono::system_clock::now();

    // Trouver l'entrée associée au badge et au bâtiment
    for (auto &es : historiqueEntreeSortie)
    {
        if (es.getNomBatiment() == batiment->getNom() && es.getIdBadge() == badge->getId() && es.getDateSortie() == std::chrono::system_clock::time_point())
        {
            // Si l'entrée est trouvée et qu'elle n'a pas encore de sortie, on met à jour la sortie
            es.setDateSortie(sortie);
            std::cout << "Sortie enregistrée du bâtiment: " << batiment->getNom() << " avec le badge ID: " << badge->getId() << std::endl;
            return;
        }
    }

    // Si l'entrée n'existe pas, afficher un message d'erreur
    std::cout << "Aucune entrée trouvée pour le badge ID: " << badge->getId() << " dans le bâtiment " << batiment->getNom() << std::endl;
}

// Afficher tout l'historique des entrées/sorties
// Affiche l'ensemble des entrées et sorties pour tous les bâtiments.
void Journal::afficherEntreesSorties() const
{
    for (const auto &es : historiqueEntreeSortie)
    {
        es.afficher();
    }
}

// Afficher l'historique des entrées/sorties pour un bâtiment donné
// Filtre et affiche les entrées/sorties liées à un bâtiment spécifique.
void Journal::afficherEntreesSorties(const std::string &nomBatiment) const
{
    for (const auto &es : historiqueEntreeSortie)
    {
        if (es.getNomBatiment() == nomBatiment)
        {
            es.afficher();
        }
    }
}
