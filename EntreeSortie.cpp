#include "EntreeSortie.h"
#include <iostream>
#include <ctime>

// Constructor

// Initialise un objet EntreeSortie avec une date d'entrée, une date de sortie, un nom de bâtiment et un ID de badge.
EntreeSortie::EntreeSortie(std::chrono::system_clock::time_point entree,
                           std::chrono::system_clock::time_point sortie,
                           const std::string &batiment, int badge)
    : dateEntree(entree), dateSortie(sortie), nomBatiment(batiment), idBadge(badge) {}

// Getters

// Retourne la date et l'heure d'entrée.
std::chrono::system_clock::time_point EntreeSortie::getDateEntree() const
{
    return dateEntree;
}

// Retourne la date et l'heure de sortie.
std::chrono::system_clock::time_point EntreeSortie::getDateSortie() const
{
    return dateSortie;
}

// Retourne le nom du bâtiment associé à cette entrée/sortie.
std::string EntreeSortie::getNomBatiment() const
{
    return nomBatiment;
}

// Retourne l'identifiant du badge utilisé pour cette entrée/sortie.
int EntreeSortie::getIdBadge() const
{
    return idBadge;
}

// Setters

// Met à jour la date et l'heure d'entrée.
void EntreeSortie::setDateEntree(const std::chrono::system_clock::time_point &entree)
{
    dateEntree = entree;
}

// Met à jour la date et l'heure de sortie.
void EntreeSortie::setDateSortie(const std::chrono::system_clock::time_point &sortie)
{
    dateSortie = sortie;
}

// Met à jour le nom du bâtiment associé à cette entrée/sortie.
void EntreeSortie::setNomBatiment(const std::string &batiment)
{
    nomBatiment = batiment;
}

// Met à jour l'identifiant du badge utilisé pour cette entrée/sortie.
void EntreeSortie::setIdBadge(int badge)
{
    idBadge = badge;
}

// Methods

// Affiche les informations de l'entrée et de la sortie, y compris les dates et le bâtiment.
void EntreeSortie::afficher() const
{
    std::time_t entreeTime = std::chrono::system_clock::to_time_t(dateEntree);
    std::time_t sortieTime = std::chrono::system_clock::to_time_t(dateSortie);

    std::cout << "Entrée: " << std::ctime(&entreeTime)
              << "Sortie: " << std::ctime(&sortieTime)
              << "Bâtiment: " << nomBatiment
              << ", Badge ID: " << idBadge << std::endl;
}
