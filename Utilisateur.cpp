#include "Utilisateur.h"

// Constructeur

// Initialise un utilisateur avec un nom, un prénom et un badge associé.
Utilisateur::Utilisateur(const std::string &n, const std::string &p, Badge *b) : nom(n), prenom(p), badge(b) {}

// Méthodes

// Simule l'action de badger à l'intérieur d'un bâtiment avec le badge de l'utilisateur.
// Affiche un message d'erreur si aucun badge n'est associé à l'utilisateur.
void Utilisateur::badgerInterieur(Batiment *b)
{
    if (badge != nullptr)
    {
        std::cout << nom << " " << prenom << " badge à l'intérieur du bat " << b->getNom() << std::endl;
        b->badgerInterieur(badge);
    }
    else
    {
        std::cerr << "Aucun badge associé à l'utilisateur." << std::endl;
    }
}

// Simule l'action de badger à l'extérieur d'un bâtiment avec le badge de l'utilisateur.
// Affiche un message d'erreur si aucun badge n'est associé à l'utilisateur.
void Utilisateur::badgerExterieur(Batiment *b)
{
    if (badge != nullptr)
    {
        std::cout << nom << " " << prenom << " badge à l'exterieur du bat " << b->getNom() << std::endl;
        b->badgerExterieur(badge);
    }
    else
    {
        std::cerr << "Aucun badge associé à l'utilisateur." << std::endl;
    }
}

// Permet à l'utilisateur d'entrer dans un bâtiment si la porte est déverrouillée.
// Affiche un message d'erreur si la porte est verrouillée.
void Utilisateur::entrerBatiment(Batiment *batiment)
{
    if (!batiment->isPorteVerouille())
    {
        std::cout << nom << " " << prenom << " entre dans le batiment " << batiment->getNom() << std::endl;
        batiment->entreeUtilisateur(badge);
    }
    else
    {
        std::cout << nom << " " << prenom << " ne peut pas entrer. La porte du bâtiment " << batiment->getNom() << " est verouillée" << std::endl;
    }
}

// Permet à l'utilisateur de sortir d'un bâtiment si la porte est déverrouillée.
// Affiche un message d'erreur si la porte est verrouillée.
void Utilisateur::sortirBatiment(Batiment *batiment)
{
    if (!batiment->isPorteVerouille())
    {
        std::cout << nom << " " << prenom << " sort du batiment " << batiment->getNom() << std::endl;
        batiment->sortieUtilisateur(badge);
    }
    else
    {
        std::cout << nom << " " << prenom << " ne peut pas entrer. La porte du bâtiment " << batiment->getNom() << " est verouillée" << std::endl;
    }
}

// Affiche les informations d'un utilisateur
void Utilisateur::afficher() const
{
    std::cout << "Nom : " << nom << std::endl;
    std::cout << "Prénom : " << prenom << std::endl;
    if (badge)
    {
        std::cout << "Badge ID : " << badge->getId() << std::endl; // Suppose que Badge a une méthode getId()
    }
    else
    {
        std::cout << "Aucun badge assigné." << std::endl;
    }
}
