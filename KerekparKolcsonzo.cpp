#include "KerekparKolcsonzo.h"

unsigned KerekparKolcsonzo::db = 0;



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
    cin>>szuletesiDatum;

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
        kerekparTarolo.listazas( ELOJEGYEZHETO );
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
    cin>>karLeiras;

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

/// \brief KerekparKolcsonzo::szamlazas
///számla elkésítés
///Megadjuk az előjegyzések id-jait, amikből a számla el fog készülni
<<<<<<< HEAD



unsigned KerekparKolcsonzo::DiffDatum(Datum mettol, Datum meddig){
   unsigned difNap = meddig.getNap() - mettol.getNap();
   unsigned difEv =  meddig.getEv() - mettol.getEv();
   unsigned difHonap =  meddig.getHonap() - mettol.getHonap();



    return   difNap+difHonap*30+difEv*365 ;
}



void KerekparKolcsonzo::szamlazas(){
    unsigned IDtoSearch;
    cout<<"Adja meg a keresendo ID-t: ";
    cin>>IDtoSearch;
    unsigned vegosszeg =0;
    unsigned tempEv,  tempHonap,  tempNap;

    unsigned tullepesiDij =  1000; //naponta
    unsigned karterites = 0;






    //DiffDatum(elojegyzesek[i].getTetel(j).getMettol(), elojegyzesek[i].getTetel(j).getMeddig());

    for(unsigned i = 0; i<elojegyzesek.size(); i++)
    {
    //   std::cout<<   elojegyzesek[i].getID()<<std::endl;

        if( elojegyzesek[i].getID() == IDtoSearch){
            cout<<"found"<<endl;
            for(unsigned j = 0; j<elojegyzesek[i].getTetelekSzama(); j++){
                //visszavetel

                cout<<"Adja meg a visszavetel datumat: ";

                cout<<"ev: ";
                cin>>tempEv;
                cout<<"honap: ";
                cin>>tempHonap;
                 cout<<"nap: ";
                 cin>>tempNap;


                Datum visszavetelDatuma(tempEv,  tempHonap,  tempNap);


              //  cout<< elojegyzesek[i].getTetel(j).getKerekpar().getKolcsonzesiDij();
                   vegosszeg+=elojegyzesek[i].getTetel(j).getKerekpar().getKolcsonzesiDij();
                   vegosszeg+= tullepesiDij*DiffDatum(elojegyzesek[i].getTetel(j).getMeddig(), visszavetelDatuma);


           }
            cout<<"Felmerult karterites osszege: ";
            cin>>karterites;

            vegosszeg+=karterites;
        }

        cout<<"vegosszeg: "<<vegosszeg;
    }


=======
void KerekparKolcsonzo::szamlazas()
{
>>>>>>> origin/master

    
}

void KerekparKolcsonzo::menu()
{
<<<<<<< HEAD
    cout<<"---kerekparHozzaadas-----"<<endl;
        kerekparTarolo.kerekparHozzaadas();
        kerekparTarolo.kerekparHozzaadas();


    cout<<"---elojegyzesKeszites-----"<<endl;
    elojegyzesKeszites();
    cout<<"---berbeadas-----"<<endl;
    berbeadas();
    cout<<"---szamlazas-----"<<endl;
     szamlazas();
=======
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

>>>>>>> origin/master
}

///
/// \brief KerekparKolcsonzo::bejelentkezes
///
///Felhasználó bejelentkezik

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

    //menu
    menu();
}
