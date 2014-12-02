#include "Elojegyzes.h"


unsigned Elojegyzes::db = 0;

Elojegyzes::Elojegyzes(unsigned ID){
    this->ID = ID;

    db++;
}







unsigned Elojegyzes::getID() const
{
    return ID;
}

void Elojegyzes::setID(const unsigned &value)
{
    ID = value;
}

unsigned Elojegyzes::getDb()
{
    return db;
}


