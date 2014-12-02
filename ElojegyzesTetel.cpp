#include "ElojegyzesTetel.h"



Datum ElojegyzesTetel::getMeddig() const
{
    return meddig;
}

void ElojegyzesTetel::setMeddig(const Datum &value)
{
    meddig = value;
}
Datum ElojegyzesTetel::getMettol() const
{
    return mettol;
}

void ElojegyzesTetel::setMettol(const Datum &value)
{
    mettol = value;
}
