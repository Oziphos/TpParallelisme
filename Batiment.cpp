#include "Batiment.h"
#include "SalleControle.h"

// Constructeur

// Initialise un object bâtiment avec un nom (porteVerouillee = true et lasers initialisés).
// La salle de controle n'est pas attribuée, il est nécessaire de la mettre à jour avec la
// fonction (setSalleControle)
Batiment::Batiment(const std::string &n) : nom(n)
{
    porteVerouillee = true;
    laserExterieur = new Laser();
    laserInterieur = new Laser();
}

// Getters

// Récupère le nom du batiment
std::string Batiment::getNom() const
{
    return nom;
}

// Récupère la salle de controle associée batiment
SalleControle *Batiment::getSalleControle() const
{
    return salleControle;
}

// Récupère l'état de la porte d'un batiment, true si vérouillée, false sinon
bool Batiment::isPorteVerouille() const
{
    return porteVerouillee;
}

// Setters

// Met à jour le nom d'un bâtiment
void Batiment::setNom(const std::string &n)
{
    nom = n;
}

// Met à jour la salle de contrôle associée à au bâtiment
void Batiment::setSalleControle(SalleControle *salle)
{
    salleControle = salle;
}

// Met à jour l'état de la porte du bâtiment (true pour verouillée, false pour deverouillée)
void Batiment::setPorteVerouille(const bool etat)
{
    porteVerouillee = etat;
    std::cout << "La porte du bâtiment " << nom << " est " << (etat ? "verouillée" : "deverouillée") << std::endl;
}

// Méthodes

// Permet à un badge d'interagir avec le système intérieur du bâtiment via la salle de contrôle.
void Batiment::badgerInterieur(Badge *badge)
{
    salleControle->badgerInterieur(this, badge);
}

// Permet à un badge d'interagir avec le système extérieur du bâtiment via la salle de contrôle.
void Batiment::badgerExterieur(Badge *badge)
{
    salleControle->badgerExterieur(this, badge);
}

// Déverrouille la porte pour l'entrée par l'intérieur, active un délai avec le laser extérieur.
// Si le délai échoue, déclenche une alarme.
// /!\ Cette méthode devrait être exécutée de manière parallèle pour éviter de bloquer le programme principal (et permettre à l'utilisateur d'entrer / sortir pendant que le laser est actif)
void Batiment::ouvrirInterieur()
{
    setPorteVerouille(false);
    // fermer();
    return;
    if (laserExterieur->startDelay(30, 1))
    {
        fermer();
    }
    else
    {
        std::cout << "Alarme entrée " << nom << std::endl;
    }
}

// Déverrouille la porte pour l'entrée par l'extérieur, active un délai avec le laser extérieur.
// Si le délai échoue, déclenche une alarme.
// /!\ Cette méthode devrait être exécutée de manière parallèle pour éviter de bloquer le programme principal (et permettre à l'utilisateur d'entrer / sortir pendant que le laser est actif)
void Batiment::ouvrirExterieur()
{
    setPorteVerouille(false);
    // fermer();
    return;
    if (laserExterieur->startDelay(30, 1))
    {
        fermer();
    }
    else
    {
        std::cout << "Alarme entrée " << nom << std::endl;
    }
}

// Enregistre l'entrée d'un utilisateur dans le bâtiment via le laser intérieur
// et met à jour le journal d'entrée dans la salle de contrôle.
void Batiment::entreeUtilisateur(Badge *badge)
{
    laserInterieur->compterPassage();
    salleControle->ajouterEntreeJournal(this, badge);
}

// Enregistre la sortie d'un utilisateur depuis le bâtiment via le laser extérieur
// et met à jour le journal de sortie dans la salle de contrôle.
void Batiment::sortieUtilisateur(Badge *badge)
{
    laserExterieur->compterPassage();
    salleControle->ajouterSortieJournal(this, badge);
}

// Verrouille la porte du bâtiment.
void Batiment::fermer()
{
    setPorteVerouille(true);
}
