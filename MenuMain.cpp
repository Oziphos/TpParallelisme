// #include "MenuMain.h"

// bool MenuMain::choixValide(int choix)
// {
//     return choix >= 0 && choix <= 4;
// }

// void MenuMain::traiterChoix(int choix)
// {
//     std::string statut;
//     std::string nomBatiment;
//     Batiment *batiment;
//     Badge *badge;
//     switch (choix)
//     {
//     case 0:
//         exit(EXIT_SUCCESS);
//         break;
//     case 1:
//         salle->afficherUtilisateurs(salle->getListeUtilisateur());
//         break;
//     case 2:
//         salle->creerBadgeUnique();
//         break;
//     case 3:
//         int id = getIntFromUser("Rentrez l'id du badge");
//         badge = salle->getBadge(id);
//         if (badge != nullptr)
//         {
//             statut = getStringFromUser("Rentrez le statut du badge");
//             salle->setStatutBadge(badge, statut);
//         }
//         break;
//     case 4:
//         int id = getIntFromUser("Rentrez l'id du badge");
//         badge = salle->getBadge(id);
//         if (badge != nullptr)
//         {
//             nomBatiment = getStringFromUser("Rentrez le nom du bâtiment");
//             batiment = salle->getBatiment(nomBatiment);
//             salle->ajouterAccesBadge(batiment, badge);
//         }
//         break;
//     default:
//         std::cout << "Hoo" << std::endl;
//         break;
//     }
// }

// void MenuMain::afficherMenu() const
// {
//     std::cout << " -- Menu principal -- " << std::endl;
//     std::cout << "0 - Sortir du programme" << std::endl;
//     std::cout << " - Affichage - " << std::endl;
//     std::cout << "1 - Afficher les utilisateurs" << std::endl;
//     std::cout << " - Actions - " << std::endl;
//     std::cout << "2 - Creer un badge" << std::endl;
//     std::cout << "3 - Modifier le statut d'un badge" << std::endl;
//     std::cout << "4 - Ajouter autorisation d'accès à un badge" << std::endl;
//     std::cout << "5 - Attribuer un badge à un utilisateur" << std::endl;
// }