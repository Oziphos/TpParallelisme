#ifndef BADGE_H
#define BADGE_H

class Badge
{
private:
    // Attributs
    int id;

public:
    // Constructeur
    Badge(const int i);

    // Getters
    int getId() const;

    // Setters
    void setId(const int newId);
};

#endif // BADGE_H
