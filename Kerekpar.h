#ifndef KEREKPAR_H
#define KEREKPAR_H
#include <string>
#include <fstream>
#include <vector>

//#include "JavitasiBeszamolo.h"
//#include "Elojegyzes.h"

#define ELOJEGYEZHETO "elojegyezheto"
#define KI_VAN_BERELVE "kiberelt"
#define JAVITAS_ALATT "javitas alatt"
#define TOROLT "torolt"

using namespace std;

class JavitasiBeszamolo;
class Elojegyzes;

class Kerekpar {
private:
    unsigned ID;
    string tipus;
    string marka;
    string szin;
    unsigned ar;  //amennyiert a bolt vásárolta nagyker
    unsigned gyartasEve;
    string statusz;
    unsigned kolcsonzesiDij;
    string leiras;

    vector< JavitasiBeszamolo *> javitasok;
    vector< Elojegyzes *> elojegyzesek;

    static unsigned db;
		
public:
    //constructors
    Kerekpar (){
        statusz = ELOJEGYEZHETO;
        ID = ++db;
    }

    Kerekpar ( string tipus, string marka, string szin, unsigned ar,
               unsigned gyartasEve, unsigned kolcsonzesiDij, string leiras) :
            tipus(tipus), marka(marka), szin(szin), ar(ar),
            gyartasEve(gyartasEve), kolcsonzesiDij(kolcsonzesiDij),
            leiras(leiras){

        statusz = ELOJEGYEZHETO;
        ID = ++db;
    }

    Kerekpar ( string tipus, string marka, string szin ){
        statusz = ELOJEGYEZHETO;
        ID = ++db;
        this->tipus = tipus;
        this->marka = marka;
        this->szin = szin;
    }

    Kerekpar ( unsigned kolcsonzesidij, string leiras ){
        statusz = ELOJEGYEZHETO;
        ID = ++db;
        this->kolcsonzesiDij = kolcsonzesidij;
        this->leiras = leiras;
    }

    //operators
    friend ofstream& operator <<(ofstream& ofs, const Kerekpar & kerekpar) {
        ofs<<kerekpar.ID<<endl;
        ofs<<kerekpar.tipus<<endl;
        ofs<<kerekpar.marka<<endl;
        ofs<<kerekpar.szin<<endl;
        ofs<<kerekpar.ar<<endl;
        ofs<<kerekpar.gyartasEve<<endl;
        ofs<<kerekpar.statusz<<endl;
        ofs<<kerekpar.kolcsonzesiDij<<endl;
        ofs<<kerekpar.leiras<<endl;
        return ofs;
    }

    friend ostream& operator <<(ostream& os, const Kerekpar & kerekpar) {
        os<<kerekpar.ID<<" "<<
            kerekpar.tipus<<" "<<kerekpar.marka<<" "<<
            kerekpar.szin<<" "<<kerekpar.kolcsonzesiDij;
        return os;
    }


    //setters-getters
    string getTipus() const;
    void setTipus(const string &value);
    string getMarka() const;
    void setMarka(const string &value);
    string getSzin() const;
    void setSzin(const string &value);
    unsigned getAr() const;
    void setAr(const unsigned &value);
    unsigned getGyartasEve() const;
    void setGyartasEve(const unsigned &value);
    string getStatusz() const;
    void setStatusz(const string &value);
    unsigned getKolcsonzesiDij() const;
    void setKolcsonzesiDij(const unsigned &value);
    string getLeiras() const;
    void setLeiras(const string &value);
    unsigned getID() const;
    void setID(const unsigned &value);

};

#endif // KEREKPAR_H
