#ifndef KEREKPARTAROLO_H
#define KEREKPARTAROLO_H

#include <vector>
#include <iostream>

#include "Kerekpar.h"

using namespace std;

class KerekparTarolo {
private:

    std::vector< Kerekpar > kerekparok;
	
public:
    //constructors
    KerekparTarolo () {

    }

    //methods
    Kerekpar & getKerekpar ( int index ) {
        return kerekparok[index];
    }

    void addKerekpar ( Kerekpar kerekpar ) {
        kerekparok.push_back( kerekpar );
    }

    unsigned getTaroloMeret () {
        return kerekparok.size();
    }

    void kerekparEltavolitas();

    void kerekparHozzaadas();

    void listazas(string statusz = "");
	
	void kerekparMentes();
	
    //void kerekparBetoltes();

};

#endif // KEREKPARTAROLO_H
