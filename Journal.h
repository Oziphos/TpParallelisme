#ifndef JOURNAL_H
#define JOURNAL_H

#include <vector>
#include "EntreeSortie.h"
#include "Batiment.h"
#include "Badge.h"

class Journal
{
private:
    // Attributes
    std::vector<EntreeSortie> historiqueEntreeSortie;

public:
    // Constructor
    Journal();
    // Getters
    std::vector<EntreeSortie> getHistoriqueEntreeSortie() const;
    // Setters
    // Methods
    void ajouterEntree(Batiment *batiment, Badge *badge);
    void ajouterSortie(Batiment *batiment, Badge *badge);

    // Afficher l'historique
    void afficherEntreesSorties() const;
    void afficherEntreesSorties(const std::string &nomBatiment) const;
};

#endif // JOURNAL_H
