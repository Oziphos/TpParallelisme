// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include <iostream>
// #include <limits>

// class Menu
// {
// private:
//     // Attributes
// public:
//     // Constructor
//     // Getters
//     // Setters
//     // Methods
//     bool virtual choixValide(int choix) = 0;

//     int getChoix()
//     {
//         int choix = -1;
//         while (!choixValide(choix))
//         {

//             printf("Veuillez entrer un entier : ");
//             while (scanf("%d", &choix) != 1)
//             {
//                 while (getchar() != '\n')
//                     ;
//                 printf("Entrée invalide. Veuillez entrer un entier : ");
//             }
//         }
//         return choix;
//     }

//     void virtual traiterChoix(int choix) = 0;

//     void virtual afficherMenu() const = 0;

//     void menu()
//     {
//         afficherMenu();
//         int choix = getChoix();
//         traiterChoix(choix);
//         menu();
//     }

//     int getIntFromUser(const std::string &title)
//     {
//         int userInput;
//         std::cout << title << std::endl;
//         std::cin >> userInput;

//         // Vérification si l'entrée est un entier valide
//         while (std::cin.fail())
//         {
//             std::cin.clear();                                                   // Réinitialiser l'état d'erreur
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer l'entrée incorrecte
//             std::cout << "Entrée invalide. Veuillez entrer un entier: ";
//             std::cin >> userInput;
//         }

//         return userInput;
//     }

//     std::string getStringFromUser(const std::string &title)
//     {
//         std::string userInput;
//         std::cout << title << std::endl;
//         std::getline(std::cin, userInput);
//         return userInput;
//     }
// };