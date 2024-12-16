#ifndef LASER_H
#define LASER_H

#include <chrono>
#include <thread>
#include <iostream>

class Laser
{
private:
    // Attributes
    int nbPassages;

public:
    // Constructor
    Laser()
    {
        nbPassages = 0;
    }
    // Getters
    // Setters
    // Methods
    void compterPassage();
    bool startDelay(int dureeSecondes, int nbPassagesMax);
};

#endif // LASER_H