#include "SalleControle.h"

// Constructeur

// Initialise une salle de contrôle avec des systèmes de gestion des badges (AccesBadge et StatutBadge).
SalleControle::SalleControle()
{
    accesBadges = new AccesBadge;
    statutBadges = new StatutBadge;
    journal = new Journal;
}

// Getters

// Retourne la liste des bâtiments sous forme de référence modifiable.
std::vector<std::unique_ptr<Batiment>> &SalleControle::getListeBatiment()
{
    return listeBatiment;
}
// Retourne la liste des bâtiments sous forme de référence constante.
const std::vector<std::unique_ptr<Batiment>> &SalleControle::getListeBatiment() const
{
    return listeBatiment;
}

// Retourne la liste des badges sous forme de référence modifiable.
std::vector<std::unique_ptr<Badge>> &SalleControle::getListeBadge()
{
    return listeBadge;
}
// Retourne la liste des badges sous forme de référence constante.
const std::vector<std::unique_ptr<Badge>> &SalleControle::getListeBadge() const
{
    return listeBadge;
}

// Retourne la liste des capteurs d'incendie sous forme de référence modifiable.
std::vector<std::unique_ptr<CapteurIncendie>> &SalleControle::getListeCapteursIncendie()
{
    return listeCapteursIncendie;
}
// Retourne la liste des capteurs d'incendie sous forme de référence constante.
const std::vector<std::unique_ptr<CapteurIncendie>> &SalleControle::getListeCapteursIncendie() const
{
    return listeCapteursIncendie;
}

// Retourne la liste des utilisateurs sous forme de référence modifiable.
std::vector<std::unique_ptr<Utilisateur>> &SalleControle::getListeUtilisateur()
{
    return listeUtilisateur;
}
// Retourne la liste des utilisateurs sous forme de référence constante.
const std::vector<std::unique_ptr<Utilisateur>> &SalleControle::getListeUtilisateur() const
{
    return listeUtilisateur;
}

// Retourne le gestionnaire des accès des badges.
AccesBadge *SalleControle::getAccesBadges() const
{
    return accesBadges;
}

// Retourne le gestionnaire des statuts des badges.
StatutBadge *SalleControle::getStatutBadges() const
{
    return statutBadges;
}

// Setters

// Met à jour la liste des bâtiments.
void SalleControle::setListeBatiment(std::vector<std::unique_ptr<Batiment>> newListeBatiment)
{
    listeBatiment = std::move(newListeBatiment);
}

// Met à jour la liste des badges.
void SalleControle::setListeBadge(std::vector<std::unique_ptr<Badge>> newListeBadge)
{
    listeBadge = std::move(newListeBadge);
}

// Met à jour la liste des capteurs d'incendie.
void SalleControle::setListeCapteursIncendie(std::vector<std::unique_ptr<CapteurIncendie>> newListeCapteursIncendie)
{
    listeCapteursIncendie = std::move(newListeCapteursIncendie);
}

// Met à jour la liste des utilisateurs.
void SalleControle::setListeUtilisateur(std::vector<std::unique_ptr<Utilisateur>> newListeUtilisateur)
{
    listeUtilisateur = std::move(newListeUtilisateur);
}

// Met à jour le gestionnaire des accès des badges.
void SalleControle::setAccesBadges(AccesBadge *newAccesBadges)
{
    accesBadges = newAccesBadges;
}

// Met à jour le gestionnaire des statuts des badges.
void SalleControle::setStatutBadges(StatutBadge *newStatutBadges)
{
    statutBadges = newStatutBadges;
}

// Methods
// Ajoute un bâtiment à la liste des bâtiments.
void SalleControle::ajouterBatiment(Batiment *b)
{
    listeBatiment.push_back(std::make_unique<Batiment>(*b));
}

// Retire un bâtiment de la liste des bâtiments.
void SalleControle::retirerBatiment(Batiment *b)
{
    auto it = std::remove_if(listeBatiment.begin(), listeBatiment.end(),
                             [b](const std::unique_ptr<Batiment> &batiment)
                             {
                                 return batiment.get() == b;
                             });
    listeBatiment.erase(it, listeBatiment.end());
}

// Retourne un bâtiment spécifique en fonction de son nom.
Batiment *SalleControle::getBatiment(const std::string &nomBatiment)
{
    for (const auto &batiment : listeBatiment)
    {
        if (batiment->getNom() == nomBatiment)
        {
            return batiment.get(); // Retourne le pointeur vers le Batiment trouvé
        }
    }
    return nullptr; // Retourne nullptr si le bâtiment n'est pas trouvé
}

// Ajoute un badge à la liste des badges.
void SalleControle::ajouterBadge(Badge *b)
{
    listeBadge.push_back(std::make_unique<Badge>(*b));
}

// Retire un badge de la liste des badges.
void SalleControle::retirerBadge(Badge *b)
{
    auto it = std::remove_if(listeBadge.begin(), listeBadge.end(),
                             [b](const std::unique_ptr<Badge> &badge)
                             {
                                 return badge.get() == b;
                             });
    listeBadge.erase(it, listeBadge.end());
}

// Retourne un badge spécifique en fonction de son ID.
Badge *SalleControle::getBadge(const int idBadge)
{
    for (const auto &badge : listeBadge)
    {
        if (badge->getId() == idBadge)
        {
            return badge.get(); // Retourne le pointeur vers le Badge trouvé
        }
    }
    return nullptr; // Retourne nullptr si le badge n'est pas trouvé
}

// Crée un badge avec un ID unique et le retourne.
// Le badge est placé dans la liste des badges, a le statut 'actif' par défaut
// mais n'a pas d'autorisation d'accès et n'est pas attribué à un utilisateur
Badge *SalleControle::creerBadgeUnique()
{
    // Trouver un ID unique
    int idUnique = 1;

    // Vérifier si l'ID existe déjà dans la liste des badges
    bool idTrouve = true;
    while (idTrouve)
    {
        idTrouve = false;
        for (const auto &badge : listeBadge)
        {
            if (badge->getId() == idUnique)
            {
                idTrouve = true;
                break; // Si l'ID existe déjà, on génère le suivant
            }
        }
        if (idTrouve)
        {
            idUnique++; // Si l'ID est déjà pris, essayer le suivant
        }
    }

    // Créer un badge avec cet ID unique
    Badge *nouveauBadge = new Badge(idUnique); // Crée un nouveau badge avec l'ID unique
    setStatutBadge(nouveauBadge, "actif");
    ajouterBadge(nouveauBadge);
    std::cout << "Nouveau badge créé et enregistré, id : " << idUnique << ", statut : actif" << std::endl;
    // Retourner le pointeur vers le badge créé
    return nouveauBadge;
}

// Ajoute un utilisateur à la liste des utilisateurs.e
void SalleControle::ajouterUtilisateur(Utilisateur *u)
{
    listeUtilisateur.push_back(std::make_unique<Utilisateur>(*u));
}

// Retire un utilisateur de la liste des utilisateurs.
void SalleControle::retirerUtilisateur(Utilisateur *u)
{
    auto it = std::remove_if(listeUtilisateur.begin(), listeUtilisateur.end(),
                             [u](const std::unique_ptr<Utilisateur> &utilisateur)
                             {
                                 return utilisateur.get() == u;
                             });
    listeUtilisateur.erase(it, listeUtilisateur.end());
}

// Retourne un utilisateur si trouvé dans la liste selon l'id du badge donné
Utilisateur *SalleControle::getUtilisateurAvecIdBadge(int id)
{
    for (const auto &utilisateur : listeUtilisateur)
    {
        // Vérifiez si l'utilisateur a un badge valide et si l'ID correspond
        if (utilisateur->getBadge() && utilisateur->getBadge()->getId() == id)
        {
            return utilisateur.get();
        }
    }
    std::cout << "Aucun utilisateur trouvé avec le badge ID " << id << "." << std::endl;
    return nullptr;
}

// Ajoute un capteur d'incendie à la liste des capteurs.
void SalleControle::ajouterCapteurIncendie(CapteurIncendie *c)
{
    listeCapteursIncendie.push_back(std::make_unique<CapteurIncendie>(*c));
}

// Retire un capteur d'incendie de la liste des capteurs.
void SalleControle::retirerCapteurIncendie(CapteurIncendie *c)
{
    auto it = std::remove_if(listeCapteursIncendie.begin(), listeCapteursIncendie.end(),
                             [c](const std::unique_ptr<CapteurIncendie> &capteur)
                             {
                                 return capteur.get() == c;
                             });
    listeCapteursIncendie.erase(it, listeCapteursIncendie.end());
}

// Vérifie et gère l'accès avec un badge à l'intérieur d'un bâtiment. Déverrouille la porte si autorisé.
void SalleControle::badgerInterieur(Batiment *batiment, Badge *badge)
{
    if (
        accesBadges->estAutorise(batiment, badge) &&
        statutBadges->estBadgeActif(badge))
    {
        batiment->ouvrirInterieur();
    }
    else
    {
        std::cout << "Vous n'êtes pas autorisé à accèder à ce bâtiment : " << batiment->getNom() << std::endl;
    }
}

// Vérifie et gère l'accès avec un badge à l'extérieur d'un bâtiment. Déverrouille la porte si autorisé.
void SalleControle::badgerExterieur(Batiment *batiment, Badge *badge)
{
    if (
        accesBadges->estAutorise(batiment, badge) &&
        statutBadges->estBadgeActif(badge))
    {
        batiment->ouvrirExterieur();
    }
    else
    {
        std::cout << "Vous n'êtes pas autorisé à accèder à ce bâtiment : " << batiment->getNom() << std::endl;
    }
}

// Ajoute une entrée dans le journal pour un badge et un bâtiment donnés.
void SalleControle::ajouterEntreeJournal(Batiment *batiment, Badge *badge)
{

    journal->ajouterEntree(batiment, badge);
}

// Ajoute une sortie dans le journal pour un badge et un bâtiment donnés.
void SalleControle::ajouterSortieJournal(Batiment *batiment, Badge *badge)
{
    journal->ajouterSortie(batiment, badge);
}

// Affiche l'historique des entrées et sorties pour un bâtiment spécifique ou pour tous les bâtiments si aucun nom n'est fourni.
void SalleControle::afficherJournalEntreesSorties(const std::string &nomBatiment)
{
    if ((nomBatiment != ""))
    {
        journal->afficherEntreesSorties(nomBatiment);
    }
    else
    {
        journal->afficherEntreesSorties();
    }
}

// Ajoute une autorisation d'accès pour un badge à un bâtiment.
void SalleControle::ajouterAccesBadge(Batiment *batiment, Badge *badge)
{
    accesBadges->ajouterAutorisation(batiment, badge);
}

// Retire une autorisation d'accès pour un badge d'un bâtiment.
void SalleControle::retirerAccessBadge(Batiment *batiment, Badge *badge)
{
    accesBadges->supprimerAutorisation(batiment, badge);
}

// Met à jour le statut d'un badge avec le statut spécifié.
void SalleControle::setStatutBadge(Badge *badge, const std::string &statut)
{
    statutBadges->setStatutBadge(badge, statut);
}

// Supprime le statut associé à un badge.
void SalleControle::supprimerStatutBadge(Badge *badge)
{
    statutBadges->supprimerStatutBadge(badge);
}

// Retourne la liste des utilisateurs présents dans le batiment donné
std::vector<Utilisateur *> SalleControle::getUtilisateursBatiment(Batiment *batiment)
{
    // On récupère tous les utilisateurs depuis entrées / sorties qui sont dans le bâtiment
    // et qui ne sont pas encore ressortis (dateSortie est null)
    std::string nomBatiment = batiment->getNom();
    std::vector<Utilisateur *> liste;

    for (auto &es : journal->getHistoriqueEntreeSortie())
    {
        if (
            es.getNomBatiment() == nomBatiment &&
            es.getDateSortie() == std::chrono::system_clock::time_point{})
        {
            Utilisateur *u = getUtilisateurAvecIdBadge(es.getIdBadge());
            if (u)
            {
                liste.push_back(u);
            }
        }
    }
    return liste;
}

// Affiche la liste des utilisateurs données
void SalleControle::afficherUtilisateurs(std::vector<Utilisateur *> liste)
{
    for (const auto &u : liste)
    {
        u->afficher();
    }
}

// Affiche la liste des utilisateurs données
void SalleControle::afficherUtilisateurs(std::vector<std::unique_ptr<Utilisateur>> liste)
{
    for (const auto &u : liste)
    {
        u->afficher();
    }
}