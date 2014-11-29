#include "Szemely.h"


string Szemely::getVezetekNev() const
{
    return vezetekNev;
}

void Szemely::setVezetekNev(const string &value)
{
    vezetekNev = value;
}
string Szemely::getKeresztNev() const
{
    return keresztNev;
}

void Szemely::setKeresztNev(const string &value)
{
    keresztNev = value;
}
string Szemely::getSzuletesiDatum() const
{
    return szuletesiDatum;
}

void Szemely::setSzuletesiDatum(const string &value)
{
    szuletesiDatum = value;
}
string Szemely::getTelefonszam() const
{
    return telefonszam;
}

void Szemely::setTelefonszam(const string &value)
{
    telefonszam = value;
}



