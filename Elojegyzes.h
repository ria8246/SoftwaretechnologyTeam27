#ifndef ELOJEGYZES_H
#define ELOJEGYZES_H

#include <fstream>
#include <vector>

#include "ElojegyzesTetel.h"
#include "Szemely.h"


class Elojegyzes {
private:
    unsigned ID;
    Szemely szemely;

    static unsigned db;

    std::vector< ElojegyzesTetel > elojegyzesTetelek;
	
public:
    //constructors
    Elojegyzes (){
        ID = ++db;
    }

    Elojegyzes(unsigned ID);

    Elojegyzes ( Szemely szemely ) : szemely(szemely) {
        ID = ++db;
    }

//Ellenorizni !!!!!!!!!!!!!
//    Elojegyzes ( vector< ElojegyzesTetel > elojegyTetelek ){
//        ID = ++db;
//        for ( unsigned i = 0; i < elojegyTetelek.size(); i++ ) {
//            elojegyzesTetelek.push_back( elojegyTetelek[i] );
//        }
//    }

    //methods
    void addElojegyzesTetel ( ElojegyzesTetel & ujtetel ) {
        elojegyzesTetelek.push_back( ujtetel );
    }

    Szemely getSzemely () {
        return szemely;
    }



    unsigned getTetelekSzama () {
        return elojegyzesTetelek.size();
    }

    ElojegyzesTetel getTetel ( unsigned index ) {
        return elojegyzesTetelek[index];
    }

    //operators
    friend ofstream& operator <<(ofstream& ofs,
                                 const Elojegyzes &elojegyzes) {

        ofs<<elojegyzes.ID<<endl;
        ofs<<elojegyzes.szemely<<endl;
        for (unsigned i = 0; i < elojegyzes.elojegyzesTetelek.size(); i++ ) {
            ofs<<elojegyzes.elojegyzesTetelek[i]<<endl;
        }
        return ofs;
    }

    friend ostream& operator <<(ostream& os,
                                 const Elojegyzes &elojegyzes) {

        os<<elojegyzes.ID<<endl;
        os<<elojegyzes.szemely<<endl;
        for (unsigned i = 0; i < elojegyzes.elojegyzesTetelek.size(); i++ ) {
            os<<elojegyzes.elojegyzesTetelek[i]<<endl;
        }
        return os;
    }

    //setters-getters
    unsigned getID() const;
    void setID(const unsigned& value);

    static unsigned getDb();


};

#endif // ELOJEGYZES_H
