#ifndef ENTREE_SORTIE_H
#define ENTREE_SORTIE_H

#include <chrono>
#include <string>

class EntreeSortie
{
private:
    std::chrono::system_clock::time_point dateEntree;
    std::chrono::system_clock::time_point dateSortie;
    std::string nomBatiment;
    int idBadge;

public:
    EntreeSortie() = default;                                // Constructeur par défaut
    ~EntreeSortie() = default;                               // Destructeur par défaut
    EntreeSortie(const EntreeSortie &) = default;            // Constructeur de copie
    EntreeSortie &operator=(const EntreeSortie &) = default; // Assignation
    // Constructeur
    EntreeSortie(std::chrono::system_clock::time_point entree, std::chrono::system_clock::time_point sortie,
                 const std::string &batiment, int badge);

    // Getters
    std::chrono::system_clock::time_point getDateEntree() const;
    std::chrono::system_clock::time_point getDateSortie() const;
    std::string getNomBatiment() const;
    int getIdBadge() const;

    // Setters
    void setDateEntree(const std::chrono::system_clock::time_point &entree);
    void setDateSortie(const std::chrono::system_clock::time_point &sortie);
    void setNomBatiment(const std::string &batiment);
    void setIdBadge(int badge);

    // Methods
    void afficher() const;
};

#endif // ENTREE_SORTIE_H
