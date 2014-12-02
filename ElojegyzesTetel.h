#ifndef ELOJEGYZESTETEL_H
#define ELOJEGYZESTETEL_H

#include <fstream>
#include "Datum.h"
#include "Kerekpar.h"

using namespace std;

class Kerekpar;

class ElojegyzesTetel {
private:
    Datum mettol;
    Datum meddig;
    Kerekpar *kerekpar;

public:
    //constructors
    ElojegyzesTetel () {}

    ElojegyzesTetel ( Datum mettol, Datum meddig, Kerekpar * kerekpar ) :
                        mettol(mettol), meddig(meddig) {

        this->kerekpar = kerekpar;
    }

    //methods
    Kerekpar getKerekpar() {
        return *kerekpar;
    }

    //operators
    friend ofstream& operator <<(ofstream& ofs,
                                 const ElojegyzesTetel &elojegyzestetel) {

        ofs<< elojegyzestetel.kerekpar->getID() <<" "<<
             elojegyzestetel.mettol<<" "<<
             elojegyzestetel.meddig;
        return ofs;
    }

    friend ostream& operator <<(ostream& os,
                                 const ElojegyzesTetel &elojegyzestetel) {

        os<<"Kerekpar ID: "<< elojegyzestetel.kerekpar->getID() <<" "<<
             elojegyzestetel.mettol<<" "<<
             elojegyzestetel.meddig;
        return os;
    }



    Datum getMettol() const;
    void setMettol(const Datum &value);
    Datum getMeddig() const;
    void setMeddig(const Datum &value);
};

#endif // ELOJEGYZESTETEL_H
