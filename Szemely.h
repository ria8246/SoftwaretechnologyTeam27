#ifndef SZEMELY_H
#define SZEMELY_H
#include <string>
#include <fstream>

using namespace std;

class Szemely {
private:
    string vezetekNev;
    string keresztNev;
    string szuletesiDatum;
    string telefonszam;

public:
    //constructors
    Szemely () {

    }

    Szemely ( string vnev, string knev, string szuldat, string telsz ) {
        this->vezetekNev = vnev;
        this->keresztNev = knev;
        this->szuletesiDatum = szuldat;
        this->telefonszam = telsz;
    }

    //operators
    friend ofstream& operator <<(ofstream& ofs, const Szemely &szemely) {
        ofs<<szemely.vezetekNev<<" "<<szemely.keresztNev<<endl<<
             szemely.szuletesiDatum<<endl<<szemely.telefonszam;
        return ofs;
    }

    friend ostream& operator <<(ostream& os, const Szemely &szemely) {
        os<<szemely.vezetekNev<<" "<<szemely.keresztNev<<" "<<
            szemely.szuletesiDatum<<" "<<szemely.telefonszam;
        return os;
    }

    //setters-getters
    string getVezetekNev() const;
    void setVezetekNev(const string &value);

    string getKeresztNev() const;
    void setKeresztNev(const string &value);

    string getSzuletesiDatum() const;
    void setSzuletesiDatum(const string &value);

    string getTelefonszam() const;
    void setTelefonszam(const string &value);

};

#endif // SZEMELY_H
