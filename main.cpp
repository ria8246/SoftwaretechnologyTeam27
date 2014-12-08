#include <iostream>

#include "KerekparKolcsonzo.h"

using namespace std;

int main()
{
    KerekparKolcsonzo *prog = new KerekparKolcsonzo;
    prog->startUp();
    delete prog;
    return 0;
}

