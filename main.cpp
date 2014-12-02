#include <iostream>

#include "KerekparKolcsonzo.h"

using namespace std;

int main()
{
    KerekparKolcsonzo prog;

    //prog.menu();

    std:: vector<Elojegyzes> Elojegyzesek;



    //for(unsigned i = 0; i<=Elojegyzesek.size(); i++)    {
    Elojegyzesek.push_back(Elojegyzes(0));
     Elojegyzesek.push_back(Elojegyzes(1));
    //}

 prog.szamlazas(Elojegyzesek);
    return 0;
}

