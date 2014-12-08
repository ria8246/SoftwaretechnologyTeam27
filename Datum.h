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

    bool operator < ( const Datum & masik ) {
        if ( ev < masik.ev ) {
            return true;
        } else if ( ev == masik.ev ) {
            if ( honap < masik.honap ) {
                return true;
            } else if ( honap == masik.honap ) {
                if ( nap < masik.nap ) {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator == ( const Datum & masik ) {
        if ( ev == masik.ev && honap == masik.honap && nap == masik.nap ) {
            return true;
        }
        return false;
    }

    bool operator != ( const Datum & masik ) {
        if ( !(ev == masik.ev && honap == masik.honap && nap == masik.nap) ){
            return true;
        }
        return false;
    }

    Datum operator ++ () {
        nap++;
        if ( nap > 30 ) {
            nap = 1;
            honap ++;
        }
        if ( honap > 12 ) {
            honap = 1;
            ev++;
        }
        return *this;
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
