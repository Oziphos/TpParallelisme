#include "Badge.h"

// Constructeur

// Initialise un objet Badge avec un ID unique.
Badge::Badge(const int i) : id(i) {}

// Getters

// Retourne l'identifiant du badge.
int Badge::getId() const
{
    return id;
}

// Setters

// Permet de modifier l'identifiant du badge.
void Badge::setId(const int newId)
{
    id = newId;
}
