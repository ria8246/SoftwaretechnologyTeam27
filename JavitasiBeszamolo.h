#ifndef JAVITASIBESZAMOLO_H
#define JAVITASIBESZAMOLO_H
#include <string>
#include <fstream>

#include "Kerekpar.h"

using namespace std;

class Kerekpar;

class JavitasiBeszamolo {
private:
    string karLeiras;
    unsigned javitasiKoltseg;

    Kerekpar * kerekpar;
	
public:
    //constructors
    JavitasiBeszamolo () {}

    JavitasiBeszamolo ( string karleiras, unsigned javitasikoltseg,
                        Kerekpar * kerekpar ) {

        this->karLeiras = karleiras;
        this->javitasiKoltseg = javitasikoltseg;
        this->kerekpar = kerekpar;
    }


    //operators
    friend ofstream& operator <<(ofstream& ofs,
                               const JavitasiBeszamolo &javitasiBeszamolo) {

        ofs<<javitasiBeszamolo.javitasiKoltseg<<endl<<
             (*javitasiBeszamolo.kerekpar).getID()<<endl<<
             javitasiBeszamolo.karLeiras<<endl;
        return ofs;
    }

    //setters-getters
    string getKarLeiras() const;
    void setKarLeiras(const string &value);
    unsigned getJavitasiKoltseg() const;
    void setJavitasiKoltseg(const unsigned &value);
};

#endif // JAVITASIBESZAMOLO_H
