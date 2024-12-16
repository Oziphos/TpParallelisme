#ifndef SALLE_CONTROLE_H
#define SALLE_CONTROLE_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Batiment.h"
#include "Badge.h"
#include "CapteurIncendie.h"
#include "Utilisateur.h"
#include "AccesBadge.h"
#include "StatutBadge.h"
#include "Journal.h"

class SalleControle
{
private:
    // Attributs
    std::vector<std::unique_ptr<Batiment>> listeBatiment;
    std::vector<std::unique_ptr<Badge>> listeBadge;
    std::vector<std::unique_ptr<CapteurIncendie>> listeCapteursIncendie;
    std::vector<std::unique_ptr<Utilisateur>> listeUtilisateur;
    AccesBadge *accesBadges;
    StatutBadge *statutBadges;
    Journal *journal;

public:
    // Constructeur
    SalleControle();

    // Getters
    std::vector<std::unique_ptr<Batiment>> &getListeBatiment();
    const std::vector<std::unique_ptr<Batiment>> &getListeBatiment() const;

    std::vector<std::unique_ptr<Badge>> &getListeBadge();
    const std::vector<std::unique_ptr<Badge>> &getListeBadge() const;

    std::vector<std::unique_ptr<CapteurIncendie>> &getListeCapteursIncendie();
    const std::vector<std::unique_ptr<CapteurIncendie>> &getListeCapteursIncendie() const;

    std::vector<std::unique_ptr<Utilisateur>> &getListeUtilisateur();
    const std::vector<std::unique_ptr<Utilisateur>> &getListeUtilisateur() const;

    AccesBadge *getAccesBadges() const;
    StatutBadge *getStatutBadges() const;

    // Setters
    void setListeBatiment(std::vector<std::unique_ptr<Batiment>> newListeBatiment);
    void setListeBadge(std::vector<std::unique_ptr<Badge>> newListeBadge);
    void setListeCapteursIncendie(std::vector<std::unique_ptr<CapteurIncendie>> newListeCapteursIncendie);
    void setListeUtilisateur(std::vector<std::unique_ptr<Utilisateur>> newListeUtilisateur);
    void setAccesBadges(AccesBadge *newAccesBadges);
    void setStatutBadges(StatutBadge *newStatutBadges);

    // Méthodes
    void ajouterBatiment(Batiment *batiment);
    void retirerBatiment(Batiment *batiment);
    Batiment *getBatiment(const std::string &nomBatiment);
    void ajouterBadge(Badge *badge);
    void retirerBadge(Badge *badge);
    Badge *getBadge(const int idBadge);
    Badge *creerBadgeUnique();
    void ajouterUtilisateur(Utilisateur *utilisateur);
    void retirerUtilisateur(Utilisateur *utilisateur);
    Utilisateur *getUtilisateurAvecIdBadge(int id);
    void ajouterCapteurIncendie(CapteurIncendie *capteur);
    void retirerCapteurIncendie(CapteurIncendie *capteur);
    void badgerInterieur(Batiment *batiment, Badge *badge);
    void badgerExterieur(Batiment *batiment, Badge *badge);
    void ajouterEntreeJournal(Batiment *batiment, Badge *badge);
    void ajouterSortieJournal(Batiment *batiment, Badge *badge);
    void afficherJournalEntreesSorties(const std::string &nomBatiment = "");
    void ajouterAccesBadge(Batiment *batiment, Badge *badge);
    void retirerAccessBadge(Batiment *batiment, Badge *badge);
    void setStatutBadge(Badge *badge, const std::string &statut);
    void supprimerStatutBadge(Badge *badge);
    std::vector<Utilisateur *> getUtilisateursBatiment(Batiment *batiment);
    void afficherUtilisateurs(std::vector<Utilisateur *> listeUtilisateurs);
    void afficherUtilisateurs(std::vector<std::unique_ptr<Utilisateur>> listeUtilisateur);
};

#endif // SALLE_CONTROLE_H
