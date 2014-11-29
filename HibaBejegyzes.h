#ifndef HIBABEJEGYZES_H
#define HIBABEJEGYZES_H
#include <string>
#include <fstream>

using namespace std;

class HibaBejegyzes {
private:
    string hibauzenet;
	
public:
    //constructors
    HibaBejegyzes () {}

    HibaBejegyzes ( string hibauzenet ) {
        this->hibauzenet = hibauzenet;
    }

    //operators
    friend ofstream& operator <<(ofstream& ofs,
                                 const HibaBejegyzes &hibaBejegyzes){
        ofs<<hibaBejegyzes.hibauzenet<<endl;
        return ofs;
    }

    //setters-getters
    string getHibauzenet() const;
    void setHibauzenet(const string &value);
};

#endif // HIBABEJEGYZES_H
