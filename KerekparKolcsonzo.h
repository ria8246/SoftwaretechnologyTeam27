#ifndef KEREKPARKOLCSONZO_H
#define KEREKPARKOLCSONZO_H

#include <iostream>
#include <vector>

#include "Elojegyzes.h"
#include "HibaBejegyzes.h"
#include "JavitasiBeszamolo.h"
#include "KerekparTarolo.h"

#define ADMIN "admin";
#define ELADO "elado";
#define SZERVIZ "szerviz";


class KerekparKolcsonzo {
private:
    string jogosultsag;

    std::vector< Elojegyzes > elojegyzesek;

    std::vector< JavitasiBeszamolo > javitasiBeszamolok;

    std::vector< HibaBejegyzes > hibaBejegyzesek;

    KerekparTarolo kerekparTarolo;


    ///Private methods

    //unsigned DiffDatum(Datum mettol, Datum meddig);
	
public:
     unsigned DiffDatum(Datum mettol, Datum meddig);
    //constructors
    KerekparKolcsonzo () {}

    //methods
    void elojegyzesKeszites();

    void berbeadas();

    void javitasiBeszamoloKeszites();

    void szamlazas();

    void menu();

    void bejelentkezes();

    void startUp();

    //setters-getters
    string getJogosultsag() const;
    void setJogosultsag(const string &value);
};

#endif // KEREKPARKOLCSONZO_H
