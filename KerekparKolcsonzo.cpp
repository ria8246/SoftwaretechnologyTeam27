#include "KerekparKolcsonzo.h"



string KerekparKolcsonzo::getJogosultsag() const
{
    return jogosultsag;
}

void KerekparKolcsonzo::setJogosultsag(const string &value)
{
    jogosultsag = value;
}


void KerekparKolcsonzo::elojegyzesKeszites()
{

    cout<<"Adja meg a szemelyes adatait: "<<endl;
    cout<<"-Vezetek neve: ";
    string vezetekNev;
    cin>>vezetekNev;

    cout<<"-Kereszt neve: ";
    string keresztNev;
    cin>>keresztNev;

    cout<<"-Szuletesi datuma: ";
    string szuletesiDatum;
    getline (cin, szuletesiDatum);
    getline (cin, szuletesiDatum);

    cout<<"-Telefonszama: ";
    string telefonszam;
    cin>>telefonszam;

    Szemely elojegyzo ( vezetekNev, keresztNev, szuletesiDatum,
                        telefonszam );
    Elojegyzes ujElojegyzes( elojegyzo );


    cout<<"Hany kerekpart szeretne elojegyezni? :";
    unsigned kerekparokszama;
    cin>>kerekparokszama;

    for ( unsigned i = 0; i < kerekparokszama; i++ ) {
        cout<<"------------------------------------"<<endl;
        kerekparTarolo.listazas( ELOJEGYEZHETO );
        cout<<"------------------------------------"<<endl;

        cout<<"Valassza ki a(z) "<< i+1 <<"-ik kerekpart (ID): ";
        unsigned id;
        cin>>id;

        Kerekpar * kerekpar;
        for ( unsigned i = 0; i< kerekparTarolo.getTaroloMeret(); i++ ) {
            if ( kerekparTarolo.getKerekpar(i).getID() == id ) {
                kerekpar = &(kerekparTarolo.getKerekpar(i));
            }
        }

        cout<<"Adja meg, hogy mikor szeretne elvinni a kerekpart:"<<endl;
        cout<<"-Ev: ";
        unsigned ev;
        cin>>ev;

        cout<<"-Honap: ";
        unsigned honap;
        cin>>honap;

        cout<<"-Nap: ";
        unsigned nap;
        cin>>nap;

        Datum mettol(ev, honap, nap);

        cout<<"Adja meg, hogy meddig szeretne kikolcsonozni a kerekpart:"
           <<endl;
        cout<<"-Ev: ";
        cin>>ev;

        cout<<"-Honap: ";
        cin>>honap;

        cout<<"-Nap: ";
        cin>>nap;

        Datum meddig(ev, honap, nap);

        //*kerekpar->elojegyzesek.push_back( &ujElojegyzes ); //TODO
        ElojegyzesTetel ujtetel( mettol, meddig, kerekpar );
        ujElojegyzes.addElojegyzesTetel( ujtetel );
    }

    elojegyzesek.push_back( ujElojegyzes );
    cout<<"Az elojegyzes sikerult!"<<endl;
}


void KerekparKolcsonzo::berbeadas()
{
    cout<<"Kerem adja meg, hogy ki tette meg az elojegyzest:"<<endl;
    cout<<"-Vezetek neve: ";
    string vezetekNev;
    cin>>vezetekNev;

    cout<<"-Kereszt neve: ";
    string keresztNev;
    cin>>keresztNev;
    
    for ( unsigned i = 0; i < elojegyzesek.size(); i++ ) {
        if ( elojegyzesek[i].getSzemely().getVezetekNev() == vezetekNev ||
             elojegyzesek[i].getSzemely().getKeresztNev() == keresztNev ) {

            cout<<elojegyzesek[i]<<endl;
        }
    }

    cout<<"Kerem valassza ki a megfelelo elojegyzest (ID): ";
    unsigned id;
    cin>>id;

    for ( unsigned i = 0; i < elojegyzesek.size(); i++ ) {
        if ( elojegyzesek[i].getID() == id ) {
            for ( unsigned j=0; j< elojegyzesek[i].getTetelekSzama(); j++ ){
                elojegyzesek[i].getTetel(j).getKerekpar()
                        .setStatusz(KI_VAN_BERELVE);
            }
        }
    }
    cout<<"A kerekparokat most mar elviheti a berlo!"<<endl;

}


void KerekparKolcsonzo::javitasiBeszamoloKeszites()
{
    kerekparTarolo.listazas( JAVITAS_ALATT );
    cout<<"Valassza ki a megjavitott kerekpart (ID): ";
    unsigned id;
    cin>>id;

    cout<<"Adja meg a karnak a rovid leirasat: ";
    string karLeiras;
    getline (cin, karLeiras);
    getline (cin, karLeiras);

    cout<<"Adja meg a javitas koltseget: ";
    unsigned javitasiKoltseg;
    cin>>javitasiKoltseg;

    Kerekpar * kerekpar;
    for ( unsigned i = 0; i< kerekparTarolo.getTaroloMeret(); i++ ) {
        if ( kerekparTarolo.getKerekpar(i).getID() == id ) {
            kerekparTarolo.getKerekpar(i).setStatusz( ELOJEGYEZHETO );
            kerekpar = &(kerekparTarolo.getKerekpar(i));
        }
    }

    JavitasiBeszamolo ujBeszamolo ( karLeiras, javitasiKoltseg, kerekpar );
    //*kerekpar->javitasok.push_back( &ujBeszamolo ); //TODO
    javitasiBeszamolok.push_back( ujBeszamolo );
    cout<<"A beszamolo elkeszult!"<<endl;
}


unsigned KerekparKolcsonzo::tulLepes(Datum elso, Datum masodik){
    unsigned tullepes = 0;

    if ( elso < masodik ) {
        Datum tmpelso = elso;
        Datum tmpmaso = masodik;

        while ( tmpelso != tmpmaso ) {
            ++tmpelso;
            tullepes++;
        }
    }
    return tullepes;
}


void KerekparKolcsonzo::szamlazas()
{
	unsigned IDtoSearch;
    cout<<"Adja meg az elojegyzes ID-at: ";
    cin>>IDtoSearch;
	
	unsigned vegosszeg =0;

    unsigned tempEv,  tempHonap,  tempNap;
    unsigned tullepesiDij = 1000; //naponta
    unsigned karterites = 0;
	
	for(unsigned i = 0; i<elojegyzesek.size(); i++) {

        if( elojegyzesek[i].getID() == IDtoSearch){

            cout<< elojegyzesek[i].getSzemely() <<endl;

            for(unsigned j = 0; j<elojegyzesek[i].getTetelekSzama(); j++) {

                cout<<elojegyzesek[i].getTetel(j)<<endl;

                cout<<"Adja meg a visszavetel datumat: "<<endl;
                cout<<"-Ev: ";
                cin>>tempEv;

                cout<<"-Honap: ";
                cin>>tempHonap;

                cout<<"-Nap: ";
                cin>>tempNap;

                Datum visszavetelDatuma(tempEv, tempHonap, tempNap);

                //kolcsonzesi dij * eltelt napok szama
                vegosszeg+=elojegyzesek[i].getTetel(j).getKerekpar()
                                    .getKolcsonzesiDij()*
                        tulLepes(elojegyzesek[i].getTetel(j).getMettol(),
                                 elojegyzesek[i].getTetel(j).getMeddig() );

                //tullepesi dij * tullepett napok szama
                vegosszeg+=tullepesiDij*
                        tulLepes(elojegyzesek[i].getTetel(j).getMeddig(),
                                                    visszavetelDatuma);

                cout<<"Felmerult karterites osszege: ";
                cin>>karterites;
                vegosszeg+=karterites;

                if ( karterites == 0 ) {
                    elojegyzesek[i].getTetel(j).getKerekpar().setStatusz(
                                                          ELOJEGYEZHETO );
                } else {
                    elojegyzesek[i].getTetel(j).getKerekpar().setStatusz(
                                                          JAVITAS_ALATT );
                }

            }

        }

        cout<<"Vegosszeg: "<< vegosszeg << endl;
		
	}
	  
}


void KerekparKolcsonzo::menu()
{
    unsigned parancs;

    do {
//Admin
        if ( jogosultsag == "ADMIN" ) {
            cout << "-----------------------------------------------"<<endl;
            cout << "1: Kerekpar Hozzaadas"<<endl;
            cout << "2: Kerekpar Eltavolitas"<<endl;
            cout << "3: Osszes Kerekpar Listazasa"<<endl;
            cout << "4: Kijelentkezes"<<endl;
            cout << "9: Kilepes"<<endl;
            cout << "-----------------------------------------------"<<endl;
            cout << "Adja meg a parancs sorszamat!: ";
            cin >> parancs;

            if ( parancs == 1 ) {
                kerekparTarolo.kerekparHozzaadas();
            } else if ( parancs == 2 ) {
                kerekparTarolo.kerekparEltavolitas();
            } else if ( parancs == 3 ) {
                kerekparTarolo.listazas();
            } else if ( parancs == 4 ) {
                kijelentkezes ();
            } else if ( parancs == 9 ) {
                //Kilepes
            }
//Szerviz
        } else if ( jogosultsag == "SZERVIZ" ) {
            cout << "-----------------------------------------------"<<endl;
            cout << "1: Javitasi Bezamolo Keszites"<<endl;
            cout << "2: Javitas alatti Kerekparok Listazasa"<<endl;
            cout << "3: Kijelentkezes"<<endl;
            cout << "9: Kilepes"<<endl;
            cout << "-----------------------------------------------"<<endl;
            cout << "Adja meg a parancs sorszamat!: ";
            cin >> parancs;

            if ( parancs == 1 ) {
                javitasiBeszamoloKeszites();
            } else if ( parancs == 2 ) {
                kerekparTarolo.listazas( JAVITAS_ALATT );
            } else if ( parancs == 3 ) {
                kijelentkezes ();
            } else if ( parancs == 9 ) {
                //Kilepes
            }
//Elado
        } else if ( jogosultsag == "ELADO" ) {
            cout << "-----------------------------------------------"<<endl;
            cout << "1: Elojegyzes Keszites"<<endl;
            cout << "2: Berbeadas"<<endl;
            cout << "3: Elojegyzesek listazasa"<<endl;
            cout << "4: Kibérelt Kerekparok Listazasa"<<endl;
            cout << "5: Szamlazas"<<endl;
            cout << "6: Kijelentkezes"<<endl;
            cout << "9: Kilepes"<<endl;
            cout << "-----------------------------------------------"<<endl;
            cout << "Adja meg a parancs sorszamat!: ";
            cin >> parancs;

            if ( parancs == 1 ) {
                elojegyzesKeszites();
            } else if ( parancs == 2 ) {
                berbeadas();
            } else if ( parancs == 3 ) {
                for ( unsigned i = 0; i < elojegyzesek.size(); i++ ) {
                    cout<<elojegyzesek[i]<<endl;
                }
            } else if ( parancs == 4 ) {
                kerekparTarolo.listazas( KI_VAN_BERELVE );
            } else if ( parancs == 5 ) {
                szamlazas();
            } else if ( parancs == 6 ) {
                kijelentkezes ();
            } else if ( parancs == 9 ) {
                //Kilepes
            }
//Vendeg
        } else {
            cout << "-----------------------------------------------"<<endl;
            cout << "1: Elojegyzes Keszites"<<endl;
            cout << "2: Berelheto Kerekparok Listazasa"<<endl;
            cout << "3: Bejelentkezes"<<endl;
            cout << "9: Kilepes"<<endl;
            cout << "-----------------------------------------------"<<endl;
            cout << "Adja meg a parancs sorszamat!: ";
            cin >> parancs;

            if ( parancs == 1 ) {
                elojegyzesKeszites();
            } else if ( parancs == 2 ) {
                kerekparTarolo.listazas( ELOJEGYEZHETO );
            } else if ( parancs == 3 ) {
                bejelentkezes ();
            } else if ( parancs == 9 ) {
                //Kilepes
            }
        }
    } while ( parancs != 9 );

}


void KerekparKolcsonzo::bejelentkezes()
{
    cout<<"Kerem adja meg a felhasznalo nevet: ";
    string felhasznalo;
    cin >> felhasznalo;
    cout<<"Kerem adja meg a megfelelo jelszot: ";
    string jelszo;
    cin >> jelszo;

    if ( felhasznalo == "Admin" && jelszo == "iamtheadmin" ) {
        jogosultsag = "ADMIN";
        cout<<"Koszontjuk Admin!"<<endl;

    } else if ( felhasznalo == "Elado" && jelszo == "iamtheelado" ) {
        jogosultsag = "ELADO";
        cout<<"Koszontjuk Piroska neni!"<<endl;

    } else if ( felhasznalo == "Szerviz" && jelszo == "iamtheszerviz" ) {
        jogosultsag = "SZERVIZ";
        cout<<"Koszontjuk Pista bacsi!"<<endl;

    } else {
        cout<<"Rosz felhasznalo nev vagy//es jelszo! " <<
              "Kerem probalkozzon ujra!" <<endl;
    }
}


void KerekparKolcsonzo::startUp()
{
    //beolvasas
    beolvas();

    //menu
    menu();

    //mentes
    mentes();
}


void KerekparKolcsonzo::mentes()
{

//kerekparok

{
    ofstream ofs ("kerekparMain.txt");
        ofs<< kerekparTarolo.getTaroloMeret();
        ofs.flush();
    ofs.close();
}

    for ( unsigned int i = 0; i < kerekparTarolo.getTaroloMeret(); i++ ) {

        char result[4]; // string which will contain the number
        sprintf ( result, "%d", i+1 ); // %d makes the result be a
                                       //decimal integer

        string mappa = "kerekpar";
        string szamu = result;
        string txt = ".txt";
        string filenev = mappa + szamu + txt;

        ofstream ofs ( filenev.c_str() );
        ofs<< kerekparTarolo.getKerekpar(i);
        ofs.close();
    }

//elojegyzesek
{
    ofstream ofs ("elojegyzesMain.txt");
        ofs<< elojegyzesek.size();
        ofs.flush();
    ofs.close();
}

    for ( unsigned int i = 0; i < elojegyzesek.size(); i++ ) {

        char result[4]; // string which will contain the number
        sprintf ( result, "%d", i+1 ); // %d makes the result be a
                                       //decimal integer

        string mappa = "elojegyzes";
        string szamu = result;
        string txt = ".txt";
        string filenev = mappa + szamu + txt;

        ofstream ofs ( filenev.c_str() );
        ofs<< elojegyzesek[i];
        ofs.close();
    }

//javitasi beszamolok
    {
        ofstream ofs ("javitasiMain.txt");
            ofs<< javitasiBeszamolok.size();
            ofs.flush();
        ofs.close();
    }
    for ( unsigned int i = 0; i < javitasiBeszamolok.size(); i++ ) {

        char result[4]; // string which will contain the number
        sprintf ( result, "%d", i+1 ); // %d makes the result be a
                                       //decimal integer

        string mappa = "javbesz";
        string szamu = result;
        string txt = ".txt";
        string filenev = mappa + szamu + txt;

        ofstream ofs ( filenev.c_str() );
        ofs<< javitasiBeszamolok[i];
        ofs.close();
    }

//hibabejegyzesek
    {
        ofstream ofs ("hibaMain.txt");
            ofs<< hibaBejegyzesek.size();
            ofs.flush();
        ofs.close();
    }
    for ( unsigned int i = 0; i < hibaBejegyzesek.size(); i++ ) {

        char result[4]; // string which will contain the number
        sprintf ( result, "%d", i+1 ); // %d makes the result be a
                                       //decimal integer

        string mappa = "hiba";
        string szamu = result;
        string txt = ".txt";
        string filenev = mappa + szamu + txt;

        ofstream ofs ( filenev.c_str() );
        ofs<< hibaBejegyzesek[i];
        ofs.close();
    }

}





void KerekparKolcsonzo::beolvas()
{
//kerekparok
{
        ifstream ifs ("kerekparMain.txt");
            unsigned kerekparokSzama;
            ifs >> kerekparokSzama;
        ifs.close();


    for ( unsigned i =0; i < kerekparokSzama; i++ ) {

        char result[4]; // string which will contain the number
        sprintf ( result, "%d", i+1 ); // %d makes the result be a
                                       //decimal integer

        string mappa = "kerekpar";
        string szamu = result;
        string txt = ".txt";
        string filenev = mappa + szamu + txt;

        ifstream ifs ( filenev.c_str() );

        if ( ifs.is_open() ) {
            unsigned ID;
            ifs>> ID;

            string tipus;
            ifs>> tipus;

            string marka;
            ifs>> marka;

            string szin;
            ifs>> szin;

            unsigned ar;
            ifs>> ar;

            unsigned gyartasEve;
            ifs>> gyartasEve;

            string statusz;
            ifs>> statusz;

            unsigned kolcsonzesiDij;
            ifs>> kolcsonzesiDij;

            string leiras;
            //char catchEnter;
            //ifs>>catchEnter;
                            //elozo parancs utani entert még el kell kapni.
            getline (ifs, leiras);
            getline (ifs, leiras);


            Kerekpar ujkerekpar ( tipus, marka, szin, ar, gyartasEve,
                                  kolcsonzesiDij, leiras);
            ujkerekpar.setStatusz( statusz );
            ujkerekpar.setID( ID );

            kerekparTarolo.addKerekpar( ujkerekpar );
        } else {
            cout << filenev.c_str() << " nevu fajlt nem tudtuk megnyitni!"
                    <<endl;
        }

        ifs.close();
    }
}

//elojegyzesek
{
        ifstream ifs ("elojegyzesMain.txt");
            unsigned elojegyzesekSzama;
            ifs >> elojegyzesekSzama;
        ifs.close();


    for ( unsigned i =0; i < elojegyzesekSzama; i++ ) {

        char result[4]; // string which will contain the number
        sprintf ( result, "%d", i+1 ); // %d makes the result be a
                                       //decimal integer

        string mappa = "elojegyzes";
        string szamu = result;
        string txt = ".txt";
        string filenev = mappa + szamu + txt;

        ifstream ifs ( filenev.c_str() );

        if ( ifs.is_open() ) {

            unsigned elojegyzesID;
            ifs>> elojegyzesID;

            string vezetekNev;
            ifs>> vezetekNev;

            string keresztNev;
            ifs>> keresztNev;

            string szuletesiDatum;
            //char catchEnter;
            //ifs>>catchEnter;
                            //elozo parancs utani entert még el kell kapni.
            getline (ifs, szuletesiDatum );
            getline (ifs, szuletesiDatum );

            string telefonszam;
            ifs>> telefonszam;

            Szemely szemely ( vezetekNev, keresztNev, szuletesiDatum,
                              telefonszam );

            Elojegyzes elojegyzes ( szemely );
            elojegyzes.setID( elojegyzesID );

            unsigned tetelekSzama;
            ifs>> tetelekSzama;
            for ( i=0; i < tetelekSzama; i++ ) {

                unsigned kerekparID;
                ifs>> kerekparID;

                Kerekpar * kerekpar;

                for ( unsigned i=0; i<kerekparTarolo.getTaroloMeret(); i++){
                    if ( kerekparTarolo.getKerekpar(i).getID() ==
                                                              kerekparID ) {
                        kerekpar = &( kerekparTarolo.getKerekpar(i) );
                    }
                }

                unsigned ev;
                ifs>> ev;

                unsigned honap;
                ifs>> honap;

                unsigned nap;
                ifs>> nap;

                Datum mettol ( ev, honap, nap );

                ifs>> ev;

                ifs>> honap;

                ifs>> nap;

                Datum meddig ( ev, honap, nap );

                ElojegyzesTetel elojegyTetel ( mettol, meddig, kerekpar );

                elojegyzes.addElojegyzesTetel( elojegyTetel );

            }
            elojegyzesek.push_back( elojegyzes );

        } else {
            cout << filenev.c_str() << " nevu fajlt nem tudtuk megnyitni!"
                    <<endl;
        }


        ifs.close();
    }
}

//javitasi beszamolok
{
        ifstream ifs ("javitasiMain.txt");
            unsigned javbeszSzama;
            ifs >> javbeszSzama;
        ifs.close();


    for ( unsigned int i = 0; i < javbeszSzama; i++ ) {

        char result[4]; // string which will contain the number
        sprintf ( result, "%d", i+1 ); // %d makes the result be a
                                       //decimal integer

        string mappa = "javbesz";
        string szamu = result;
        string txt = ".txt";
        string filenev = mappa + szamu + txt;

        ifstream ifs ( filenev.c_str() );

        if ( ifs.is_open() ) {
            unsigned javitasiKoltseg;
            ifs>> javitasiKoltseg;

            unsigned kerekparID;
            ifs>> kerekparID;

            string karLeiras;
            //char catchEnter;
            //ifs>>catchEnter;
                            //elozo parancs utani entert még el kell kapni.
            getline (ifs,karLeiras);
            getline (ifs,karLeiras);

            Kerekpar * kerekpar;

            for ( unsigned i = 0; i < kerekparTarolo.getTaroloMeret(); i++ ){
                if ( kerekparTarolo.getKerekpar(i).getID() == kerekparID ) {
                    kerekpar = &( kerekparTarolo.getKerekpar(i) );
                }
            }

            JavitasiBeszamolo javbesz(karLeiras, javitasiKoltseg, kerekpar);

            javitasiBeszamolok.push_back( javbesz );
        } else {
            cout << filenev.c_str() << " nevu fajlt nem tudtuk megnyitni!"
                    <<endl;
        }

        ifs.close();
    }
}

//hiba bejegyzesek
{
        ifstream ifs ("hibaMain.txt");
            unsigned hibakSzama;
            ifs >> hibakSzama;
        ifs.close();

    for ( unsigned int i = 0; i < hibakSzama; i++ ) {

        char result[4]; // string which will contain the number
        sprintf ( result, "%d", i+1 ); // %d makes the result be a
                                       //decimal integer

        string mappa = "hiba";
        string szamu = result;
        string txt = ".txt";
        string filenev = mappa + szamu + txt;

        ifstream ifs ( filenev.c_str() );

        if ( ifs.is_open() ) {
            string hibauzenet;
            //char catchEnter;
            //ifs>>catchEnter;
                            //elozo parancs utani entert még el kell kapni.
            getline (ifs,hibauzenet);
            getline (ifs,hibauzenet);

            HibaBejegyzes hiba ( hibauzenet );
            hibaBejegyzesek.push_back( hiba );
        } else {
            cout << filenev.c_str() << " nevu fajlt nem tudtuk megnyitni!"
                    <<endl;
        }

        ifs.close();
    }
}

}
