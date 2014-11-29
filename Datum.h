#ifndef DATUM_H
#define DATUM_H
#include <fstream>


using namespace std;

class Datum {
private:
    unsigned ev;
    unsigned honap;
    unsigned nap;

public:
    //constructors
    Datum () {

    }

    Datum ( unsigned ev, unsigned honap, unsigned nap ) {
        this->ev = ev;
        this->honap = honap;
        this->nap = nap;
    }

    //operators
    friend ofstream &operator <<(ofstream &ofs, const Datum &datum) {
        ofs<<datum.ev<<" "<<datum.honap<<" "<<datum.nap;
        return ofs;
    }

    friend ostream& operator <<(ostream & os, const Datum &datum) {
        os<<datum.ev<<" "<<datum.honap<<" "<<datum.nap;
        return os;
    }

    //setters-getters
    unsigned getEv() const;
    void setEv(const unsigned &value);

    unsigned getHonap() const;
    void setHonap(const unsigned &value);

    unsigned getNap() const;
    void setNap(const unsigned &value);


};

#endif // DATUM_H
