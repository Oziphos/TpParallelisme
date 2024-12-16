#include "CapteurIncendie.h"

// Constructeur

// Initialise un objet CapteurIncendie associé à un bâtiment et désactive l'alarme par défaut.
CapteurIncendie::CapteurIncendie(Batiment *b) : batiment(b), statutAlarme(false) {}

// Getters

// Retourne le bâtiment associé au capteur.
Batiment *CapteurIncendie::getBatiment() const
{
    return batiment;
}

// Indique si l'alarme est activée (true) ou désactivée (false).
bool CapteurIncendie::getStatutAlarme() const
{
    return statutAlarme;
}

// Setters

// Permet de changer le bâtiment surveillé par le capteur.
void CapteurIncendie::setBatiment(Batiment *b)
{
    batiment = b;
}

// Permet de modifier l'état de l'alarme (activée/désactivée).

void CapteurIncendie::setStatutAlarme(bool s)
{
    statutAlarme = s;
}

// Méthodes

// Implémente la logique de surveillance du capteur pour détecter des incendies.
void CapteurIncendie::surveiller()
{
    // Implémentation de la méthode surveiller
}

// Active l'alarme incendie.
void CapteurIncendie::allumerAlarme()
{
    // Implémentation de la méthode allumerAlarme
}

// Désactive l'alarme incendie.
void CapteurIncendie::eteindreAlarme()
{
    // Implémentation de la méthode eteindreAlarme
}
