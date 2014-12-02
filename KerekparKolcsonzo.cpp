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
    javitasiBeszamolok.push_back( ujBeszamolo );
    cout<<"A beszamolo elkeszult!"<<endl;
}

/// \brief KerekparKolcsonzo::szamlazas
///számla elkésítés
///Megadjuk az előjegyzések id-jait, amikből a számla el fog készülni



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



    
}

void KerekparKolcsonzo::menu()
{
    cout<<"---kerekparHozzaadas-----"<<endl;
        kerekparTarolo.kerekparHozzaadas();
        kerekparTarolo.kerekparHozzaadas();


    cout<<"---elojegyzesKeszites-----"<<endl;
    elojegyzesKeszites();
    cout<<"---berbeadas-----"<<endl;
    berbeadas();
    cout<<"---szamlazas-----"<<endl;
     szamlazas();
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
        jogosultsag = ADMIN;
        cout<<"Koszontjuk Admin!"<<endl;

    } else if ( felhasznalo == "Elado" && jelszo == "iamtheelado" ) {
        jogosultsag = ELADO;
        cout<<"Koszontjuk Piroska neni!"<<endl;

    } else if ( felhasznalo == "Szerviz" && jelszo == "iamtheszerviz" ) {
        jogosultsag = SZERVIZ;
        cout<<"Koszontjuk Pista bacsi!"<<endl;

    } else {
        cout<<"Rosz felhasznalo nev vagy//es jelszo! " <<
              "Kerem probalkozzon ujra!" <<endl;
    }
}

void KerekparKolcsonzo::startUp()
{
    
}
