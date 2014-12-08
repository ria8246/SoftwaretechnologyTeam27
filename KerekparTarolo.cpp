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
    //char catchEnter;
    //cin>>catchEnter; //elozo parancs utani entert még el kell kapni.
    getline (cin,leiras);
    getline (cin,leiras);
	
	char choice;
    cout<<"Hozzaadja? (i/n): "<<endl;
    cin>>choice;

    if(choice == 'i' || choice == 'I' ){
		Kerekpar ujkerekpar ( tipus, marka, szin, ar, gyartasEve,
                                        kolcsonzesiDij, leiras );
		kerekparok.push_back( ujkerekpar );
		kerekparMentes();
	}

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

void KerekparTarolo::kerekparMentes() {
{
    ofstream ofs ("kerekparMain.txt");
        ofs<< getTaroloMeret();
        ofs.flush();
    ofs.close();
}

    for ( unsigned int i = 0; i < getTaroloMeret(); i++ ) {

        char result[4]; // string which will contain the number
        sprintf ( result, "%d", i+1 ); // %d makes the result be a
                                       //decimal integer

        string mappa = "kerekpar";
        string szamu = result;
        string txt = ".txt";
        string filenev = mappa + szamu + txt;

        ofstream ofs ( filenev.c_str() );
        ofs<< getKerekpar(i);
        ofs.close();
    }

}


