#include "Kerekpar.h"


unsigned Kerekpar::db = 0;



string Kerekpar::getTipus() const
{
    return tipus;
}

void Kerekpar::setTipus(const string &value)
{
    tipus = value;
}

string Kerekpar::getMarka() const
{
    return marka;
}

void Kerekpar::setMarka(const string &value)
{
    marka = value;
}

string Kerekpar::getSzin() const
{
    return szin;
}

void Kerekpar::setSzin(const string &value)
{
    szin = value;
}

unsigned Kerekpar::getAr() const
{
    return ar;
}

void Kerekpar::setAr(const unsigned &value)
{
    ar = value;
}

unsigned Kerekpar::getGyartasEve() const
{
    return gyartasEve;
}

void Kerekpar::setGyartasEve(const unsigned &value)
{
    gyartasEve = value;
}

string Kerekpar::getStatusz() const
{
    return statusz;
}

void Kerekpar::setStatusz(const string &value)
{
    statusz = value;
}

unsigned Kerekpar::getKolcsonzesiDij() const
{
    return kolcsonzesiDij;
}

void Kerekpar::setKolcsonzesiDij(const unsigned &value)
{
    kolcsonzesiDij = value;
}

string Kerekpar::getLeiras() const
{
    return leiras;
}

void Kerekpar::setLeiras(const string &value)
{
    leiras = value;
}

unsigned Kerekpar::getID() const
{
    return ID;
}

void Kerekpar::setID(const unsigned &value)
{
    ID = value;
}




