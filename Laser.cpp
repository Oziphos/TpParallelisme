#include "Laser.h"

// False si nbPassagesMax est depassée pendant dureeSecondes, true sinon à la fin de la durée
// /!\ Ajouter mutex pour garantir que la lecture de nbPassages se passe bien
bool Laser::startDelay(int dureeSecondes, int nbPassagesMax)
{
    // Temps de départ
    auto startTime = std::chrono::steady_clock::now();

    // Boucle pour vérifier la durée
    while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - startTime).count() < dureeSecondes)
    {
        // Vérifier si le nombre de passages dépasse la limite
        if (nbPassages > nbPassagesMax)
        {
            nbPassages = 0; // Réinitialiser le compteur de passages
            return false;   // Retourner false si le nombre de passages est trop élevé
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Pause de 100 ms
    }

    nbPassages = 0; // Réinitialiser le compteur de passages
    return true;
}

// /!\ Ajouter mutex pour garantir que l'incrementation de nbPassages se passe bien
void Laser::compterPassage()
{
    nbPassages++;
}