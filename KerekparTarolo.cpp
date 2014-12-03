#include "KerekparTarolo.h"



void KerekparTarolo::kerekparEltavolitas()
{
    listazas();
    cout<<"Valassza ki az eltavolitando kerekpart (ID): ";
    unsigned id;
    cin>>id;
    for ( unsigned i = 0; i< kerekparok.size(); i++ ) {
        if ( kerekparok[i].getID() == id ) {
            kerekparok[i].setStatusz( TOROLT );
        }
    }

}


void KerekparTarolo::kerekparHozzaadas()
{
    cout<<"Kerem adja meg a kerekpar adatait: "<<endl;
    cout<<"-Tipusa: ";
    string tipus;
    cin>>tipus;

    cout<<"-Markaja: ";
    string marka;
    cin>>marka;

    cout<<"-Szine: ";
    string szin;
    cin>>szin;

    cout<<"-Ara: ";
    unsigned ar;
    cin>>ar;

    cout<<"-Gyartas eve: ";
    unsigned gyartasEve;
    cin>>gyartasEve;

    cout<<"-Kolcsonzesi dija: ";
    unsigned kolcsonzesiDij;
    cin>>kolcsonzesiDij;

    cout<<"-Rovid leirasa: ";
    string leiras;
    cin>>leiras;

    Kerekpar ujkerekpar ( tipus, marka, szin, ar, gyartasEve,
                          kolcsonzesiDij, leiras );
    kerekparok.push_back( ujkerekpar );

}
void KerekparTarolo::kerekparBetoltes(){

    // unsigned ID;
    string tipus;
    string marka;
    string szin;
    unsigned ar;
    unsigned gyartasEve;
    string statusz;
    unsigned kolcsonzesiDij;
    string leiras;

    unsigned kerekparokSzama;

    ifstream ifs ("kerekparMain.txt");

    if(ifs.is_open()){

        ifs >> kerekparokSzama;
        ifs.close();
    }else{
        cout<< "nem sikerult a file-t megnyitni";
    }

               for ( unsigned i =0; i < kerekparokSzama; i++ ) {

            char result[4]; // string which will contain the number
            sprintf ( result, "%d", i+1 ); // %d makes the result be a
            //decimal integer

            string mappa = "kerekpar";
            string szamu = result;
            string txt = ".txt";
            string filenev = mappa + szamu + txt;

            ifstream ifs ( filenev.c_str() );
            //TODO
            // ifs>> ID;
            ifs>> tipus;
            ifs>> marka;
            ifs>> szin;
            ifs>> ar;
            ifs>> gyartasEve;
            ifs>> statusz;
            ifs>> kolcsonzesiDij;
            ifs>> leiras;



            kerekparok.push_back(Kerekpar( tipus,  marka,  szin,  ar, gyartasEve,  kolcsonzesiDij,  leiras));
        }
        ifs.close();
    }



    void KerekparTarolo::listazas(string statusz )
    {
        if ( statusz == "" ) {
            for ( unsigned i = 0; i < kerekparok.size(); i++ ) {
                cout<<kerekparok[i]<<endl;
            }

        } else if ( statusz == ELOJEGYEZHETO ) {
            for ( unsigned i = 0; i < kerekparok.size(); i++ ) {
                if ( kerekparok[i].getStatusz() == ELOJEGYEZHETO ) {
                    cout<<kerekparok[i]<<endl;
                }
            }

        } else if ( statusz == KI_VAN_BERELVE ) {
            for ( unsigned i = 0; i < kerekparok.size(); i++ ) {
                if ( kerekparok[i].getStatusz() == KI_VAN_BERELVE ) {
                    cout<<kerekparok[i]<<endl;
                }
            }

        } else if ( statusz == JAVITAS_ALATT ) {
            for ( unsigned i = 0; i < kerekparok.size(); i++ ) {
                if ( kerekparok[i].getStatusz() == JAVITAS_ALATT ) {
                    cout<<kerekparok[i]<<endl;
                }
            }

        }

    }
