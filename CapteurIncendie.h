#ifndef CAPTEUR_INCENDIE_H
#define CAPTEUR_INCENDIE_H

#include "Batiment.h" // Assurez-vous que Batiment.h est inclus pour utiliser Batiment

class CapteurIncendie
{
private:
    // Attributs
    Batiment *batiment;
    bool statutAlarme;

public:
    // Constructeur
    CapteurIncendie(Batiment *b);

    // Getters
    Batiment *getBatiment() const;
    bool getStatutAlarme() const;

    // Setters
    void setBatiment(Batiment *b);
    void setStatutAlarme(bool s);

    // Méthodes
    void surveiller();
    void allumerAlarme();
    void eteindreAlarme();
};

#endif // CAPTEUR_INCENDIE_H
