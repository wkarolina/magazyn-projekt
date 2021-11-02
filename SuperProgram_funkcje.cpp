#include "SuperProgram_head.hpp"

using namespace std;

bool line_mark(fstream& file)
{
	char a;
	for (; ; ) {
		file.clear();
		a = file.peek();
		if (file.fail())
			return false;

		if (!isspace(a))
			return false;

		file.get(a);
		if (file.fail())
			return false;

		if (a == '\n')
			return true;
	}
}

bool any_mark(fstream& file)
{
	char a;
	for (; ; ) {
		file.clear();
		a = file.peek();
		if (file.fail())
			return false;

		if (!isspace(a))
			return false;

		file.get(a);
		if (file.fail())
			return false;

		if (isalnum(a))
			return true;
	}
}

string PL(std::string znak)
{
    for (unsigned i = 0; i < znak.size(); i++) {
        switch (znak[i]) {
        case 'π':
            znak[i] = static_cast <char>(165);
            break;

        case 'Ê':
            znak[i] = static_cast <char>(134);
            break;

        case 'Í':
            znak[i] = static_cast <char>(169);
            break;

        case '≥':
            znak[i] = static_cast <char>(136);
            break;

        case 'Ò':
            znak[i] = static_cast <char>(228);
            break;

        case 'Û':
            znak[i] = static_cast <char>(162);
            break;

        case 'ú':
            znak[i] = static_cast <char>(152);
            break;

        case 'ü':
            znak[i] = static_cast <char>(171);
            break;

        case 'ø':
            znak[i] = static_cast <char>(190);
            break;

        case '•':
            znak[i] = static_cast <char>(164);
            break;

        case '∆':
            znak[i] = static_cast <char>(143);
            break;

        case ' ':
            znak[i] = static_cast <char>(168);
            break;

        case '£':
            znak[i] = static_cast <char>(157);
            break;

        case '—':
            znak[i] = static_cast <char>(227);
            break;

        case '”':
            znak[i] = static_cast <char>(224);
            break;

        case 'å':
            znak[i] = static_cast <char>(151);
            break;

        case 'è':
            znak[i] = static_cast <char>(141);
            break;

        case 'Ø':
            znak[i] = static_cast <char>(189);
            break;
        }
    }
    return znak;
}

int podaj_liczbe()
{
    int a;
    bool b;
    do {
        cin >> a;
        b = cin.fail();
        if (b) {
            cout << PL("Podana wartoúÊ nie jest liczbπ, sprÛbuj ponownie ") << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (b);
    return a;
}

float podaj_liczbe_nieujemna()
{
    float a;
    bool b;
    do {
        cin >> a;
        b = cin.fail();
        if (b) {
            cout << PL("Podana wartoúÊ nie jest liczbπ, sprÛbuj ponownie ") << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if (a < 0) {
            cout << PL("Podana wartoúÊ jest ujemna - sprÛbuj ponownie ") << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (b || a < 0);
    return a;
}

int intpodaj_liczbe_nieujemna()
{
    int a;
    bool b;
    do {
        cin >> a;
        b = cin.fail();
        if (b) {
            cout << PL("Podana wartoúÊ nie jest liczbπ, sprÛbuj ponownie ") << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if (a < 0) {
            cout << PL("Podana wartoúÊ jest ujemna - sprÛbuj ponownie ") << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (b || a < 0);
    cin.clear();
    return a;
}

void szukaj_nazwa_kontrahent(vector<kontrahenci>& firmy)
{
    bool b = false;
    string tmp;
    cin.seekg(0, ios::end);
    cin.clear();
    
    cout << PL("Podaj nazwÍ firmy: ");
    getline(cin, tmp);
    cout << endl;

    for (vector<kontrahenci>::iterator it = firmy.begin(); it < firmy.end(); it++) {
        if (it->nazwa.find(tmp) != string::npos) {
            cout << it->nazwa << ", " << it->adres1 << ", " << it->kod_pocztowy << " " << it->miejscowosc << ", NIP: " << it->nip << endl;
            cout << PL("Nasze zobowiπzania wobec kontrahenta: ") << it->mamy_do_zaplaty << PL(" z≥otych") << endl;
            cout << PL("Kontrahent ma nam do zap≥aty: ") << it->ma_nam_zaplacic << PL(" z≥otych") << endl << endl;
            b = true;
        }
    }

    if (b == false)
        cout << "Nie odnaleziono kontrahenta o podanej nazwie..." << endl << endl;
}

void szukaj_nip_kontrahent(vector<kontrahenci>& firmy)
{
    bool b = false;
    string tmp;
    cin.seekg(0, ios::end);
    cin.clear();
    
    cout << "Podaj NIP: ";
    getline(cin, tmp);
    cout << endl;

        for (vector<kontrahenci>::iterator it = firmy.begin(); it < firmy.end(); it++) {
            if (it->nip.find(tmp) != string::npos) {
                cout << it->nazwa << ", " << it->adres1 << ", " << it->kod_pocztowy << " " << it->miejscowosc << ", NIP: " << it->nip << endl;
                cout << PL("Nasze zobowiπzania wobec kontrahenta: ") << it->mamy_do_zaplaty << PL(" z≥otych") << endl;
                cout << PL("Kontrahent ma nam do zap≥aty: ") << it->ma_nam_zaplacic << PL(" z≥otych") << endl << endl;
                b = true;
            }
        }

    if (b == false)
        cout << "Nie odnaleziono kontrahenta o podanym NIPie..." << endl << endl;
}

void szukaj_miejscowosc_kontrahent(vector<kontrahenci>& firmy)
{
    bool b = false;
    string tmp;
    cin.seekg(0, ios::end);
    cin.clear();
    
    cout << PL("Podaj nazwÍ miejscowoúci: ");
    getline(cin, tmp);
    cout << endl;

        for (vector<kontrahenci>::iterator it = firmy.begin(); it < firmy.end(); it++) {
            if (it->miejscowosc.find(tmp) != string::npos) {
                cout << it->nazwa << ", " << it->adres1 << ", " << it->kod_pocztowy << " " << it->miejscowosc << ", NIP: " << it->nip << endl;
                cout << PL("Nasze zobowiπzania wobec kontrahenta: ") << it->mamy_do_zaplaty << PL(" z≥otych") << endl;
                cout << PL("Kontrahent ma nam do zap≥aty: ") << it->ma_nam_zaplacic << PL(" z≥otych") << endl << endl;
                b = true;
            }
        }

    if (b == false)
        cout << PL("Nie odnaleziono kontrahentÛw w podanej miejscowoúci...") << endl << endl;
}

bool czy_nip_istnieje(string& s5, vector<kontrahenci>& firmy)
{
    for (int i = 0; i < firmy.size(); i++) {
        if (s5 == firmy[i].nip)
            return false;
    }
    return true;
}

void dodaj_kontrahent(vector<kontrahenci>& firmy)
{
    string s1, s2, s3, s4, s5;
    bool b;
    cin.seekg(0, ios::end);
    cin.clear();
    
    cout << "Podaj NIP nowego kontrahenta: ";
    do {
        getline(cin, s5);
        b = czy_nip_istnieje(s5, firmy);
        if (b == false)
            cout << PL("Kontrahent o podanym NIPie juø istnieje, wpisz ponownie NIP") << endl;
    } while (b == false);
    cout << PL("Podaj nazwÍ firmy nowego kontrahenta: ");
    getline(cin, s1);
    cout << PL("Podaj pierwszπ linijkÍ adresu nowego kontrahenta (ulica i numer budynku/lokalu): ");
    getline(cin, s2);
    cout << "Podaj kod pocztowy nowego kontrahenta: ";
    getline(cin, s3);
    cout << PL("Podaj miejscowoúÊ, w ktÛrej znajduje siÍ firma kontrahenta: ");
    getline(cin, s4);
    firmy.push_back({ s1, s2, s3, s4, s5 });
}

void usun_kontrahent(vector<kontrahenci>& firmy)
{
    string tmpx;
    bool b = false;
    char mark03;
    cin.seekg(0, ios::end);
    cin.clear();
    
        cout << PL("KtÛrego kontrahenta chcesz usunπÊ? Podaj nazwÍ: ");
        getline(cin, tmpx);
        int licznik = 0;

        for (vector<kontrahenci>::iterator it = firmy.begin(); it < firmy.end(); it++) {
            if (it->nazwa.find(tmpx) != string::npos) {
                cout << licznik+1 << ". " << it->nazwa << ", " << it->adres1 << ", " << it->kod_pocztowy << " " << it->miejscowosc << ", NIP: " << it->nip << endl << endl;
                licznik++;
                b = true;
            }
        }

        if (b == false)
            cout << "Nie odnaleziono szukanego kontrahenta..." << endl << endl;

        if (licznik > 0) {
            vector<kontrahenci> chwilowy;
            int co_usunac;

            for (vector<kontrahenci>::iterator it = firmy.begin(); it < firmy.end(); it++) {
                if (it->nazwa.find(tmpx) != string::npos) {
                    chwilowy.push_back({ it->nazwa, it->adres1, it->kod_pocztowy, it->miejscowosc, it->nip, it->mamy_do_zaplaty, it->ma_nam_zaplacic });
                }
            }

            cout << PL("KtÛrego kontrahenta chcesz usunπÊ? Podaj numer: ");
            do {
                co_usunac = podaj_liczbe();
                if (co_usunac < 1 || co_usunac > licznik)
                    cout << PL("Nie ma kontrahenta o takim numerze, sprÛbuj ponownie ") << endl;
            } while (co_usunac < 1 || co_usunac > licznik);

            bool c = false;
            if (chwilowy[co_usunac - 1].mamy_do_zaplaty > 0 || chwilowy[co_usunac - 1].ma_nam_zaplacic > 0) {
                cout << PL("Nie moøna usunπÊ klienta, mamy wobec niego zobowiπzania") << endl;
                c = true;
            }

            if (c == false) {
                cout << PL("Czy w≥aúnie tego kontrahenta mam usunπÊ?") << endl;
                cout << "[1] - Tak" << endl;
                cout << "[0] - Rezygnuj" << endl;
                mark03 = give_mark4();
                switch (mark03) {
                    case '1': {
                        for (int j = 0; j < firmy.size(); j++) {
                            if (firmy[j].nazwa == chwilowy[co_usunac - 1].nazwa) {
                                firmy.erase(firmy.begin() + j);
                            }
                        }
                        cout << PL("Wybrany kontrahent zosta≥ usuniÍty!") << endl;
                        break;
                    }
                    case '0': {
                        break;
                    }
                }
            }
                
    } 
}

void zmien_kontrahent(vector<kontrahenci>& firmy)
{
    string tmp, s1, s2, s3;
    char mark03;
    bool b = false;
    int licznik = 0;
    cin.seekg(0, ios::end);
    cin.clear();
    
    cout << PL("KtÛrego kontrahenta dane chcesz zmieniÊ?") << endl;
    cout << PL("Podaj nazwÍ: ");
    getline(cin, tmp);

    for (vector<kontrahenci>::iterator it = firmy.begin(); it < firmy.end(); it++) {
        if (it->nazwa.find(tmp) != string::npos) {
            cout << licznik+1 << ". " << it->nazwa << ", " << it->adres1 << ", " << it->kod_pocztowy << " " << it->miejscowosc << ", NIP: " << it->nip << endl << endl;
            licznik++;
            b = true;
        }
    }

    if (b == false)
        cout << "Nie odnaleziono szukanego kontrahenta..." << endl << endl;

    if (licznik > 0) {
        vector<kontrahenci> chwilowy;
        int co_zmienic;

        for (vector<kontrahenci>::iterator it = firmy.begin(); it < firmy.end(); it++) {
            if (it->nazwa.find(tmp) != string::npos) {
                chwilowy.push_back({ it->nazwa, it->adres1, it->kod_pocztowy, it->miejscowosc, it->nip });
            }
        }

        cout << PL("KtÛrego kontrahenta chcesz zmieniÊ? Podaj numer: ");
        do {
            co_zmienic = podaj_liczbe();
            if (co_zmienic < 1 || co_zmienic > licznik)
                cout << PL("Nie ma kontrahenta o takim numerze, sprÛbuj ponownie ") << endl;
        } while (co_zmienic < 1 || co_zmienic > licznik);

        do {
            cout << endl << PL("Jakie dane chcesz zmieniÊ?") << endl;
            cout << "[1] - Nazwa firmy" << endl;
            cout << "[2] - Adres firmy" << endl;
            cout << "[0] - Rezygnuj" << endl << endl;
            mark03 = give_mark();
            switch (mark03) {
            case '1': {
                cin.seekg(0, ios::end);
                cin.clear();
                cout << PL("Podaj nowπ nazwÍ firmy: ");
                getline(cin, s1);
                for (int j = 0; j < firmy.size(); j++) {
                    if (firmy[j].nazwa == chwilowy[co_zmienic - 1].nazwa) {
                        firmy[j].nazwa = s1;
                    }
                }
                cout << PL("Nazwa kontrahenta zosta≥a zmieniona!") << endl;

                break;
            }
            case '2': {
                cin.seekg(0, ios::end);
                cin.clear();
                cout << PL("Podaj nowπ nazwÍ ulicy i numer budynku/lokalu: ");
                getline(cin, s1);
                cout << "Podaj nowy kod pocztowy: ";
                getline(cin, s2);
                cout << PL("Podaj nowπ nazwÍ miejscowoúci: ");
                getline(cin, s3);
                for (int j = 0; j < firmy.size(); j++) {
                    if (firmy[j].nazwa == chwilowy[co_zmienic - 1].nazwa) {
                        firmy[j].adres1 = s1;
                        firmy[j].kod_pocztowy = s2;
                        firmy[j].miejscowosc = s3;
                    }
                }
                cout << PL("Dane adresowe kontrahenta zosta≥y zmienione!") << endl;

                system("PAUSE");
                break;
            }
            case '0': {
                break;
            }
            }
        } while (mark03 != '0');
    }
}


void wczytaj_kontrahenci(string& nazwa_file_kontrahenci, fstream& file_kontrahenci, vector<kontrahenci>& firmy)
{
    string tmp_nazwa, tmp_adres1, tmp_kod, tmp_miejscowosc, tmp_nip;
    float tmp_mamy_do_zaplaty, tmp_ma_nam_zaplacic;

    file_kontrahenci.open(nazwa_file_kontrahenci.c_str(), ios::in);

    if (!file_kontrahenci.good()) {
        cout << PL("Nie uda≥o siÍ otworzyÊ pliku. Sprawdü adres! KoÒczÍ pracÍ programu!") << endl;
        exit(0);
    }
    else {
        while (!file_kontrahenci.eof()) {
            do {
                getline(file_kontrahenci, tmp_nazwa);
                getline(file_kontrahenci, tmp_adres1);
                getline(file_kontrahenci, tmp_kod);
                getline(file_kontrahenci, tmp_miejscowosc);
                getline(file_kontrahenci, tmp_nip);
                file_kontrahenci >> tmp_mamy_do_zaplaty;
                file_kontrahenci >> tmp_ma_nam_zaplacic;
                firmy.push_back({ tmp_nazwa, tmp_adres1, tmp_kod, tmp_miejscowosc, tmp_nip, tmp_mamy_do_zaplaty, tmp_ma_nam_zaplacic });
            } while (line_mark(file_kontrahenci));
        }
        file_kontrahenci.close();
    }
}

void zapisz_od_nowa_kontrahent(string & nazwa_file_kontrahenci, fstream& file_kontrahenci, vector<kontrahenci>& firmy)
{
    file_kontrahenci.open(nazwa_file_kontrahenci.c_str(), ios::out | ios::trunc);

    if (!file_kontrahenci.good()) {
        cout << PL("Nie uda≥o siÍ otworzyÊ pliku - zmiany nie zostanπ zapisane. Sprawdü plik! KoÒczÍ pracÍ programu!") << endl;
        exit(0);
    }
    else {
        for (int i = 0; i < firmy.size() - 1; i++) {
            file_kontrahenci << firmy[i].nazwa << '\n';
            file_kontrahenci << firmy[i].adres1 << '\n';
            file_kontrahenci << firmy[i].kod_pocztowy << '\n';
            file_kontrahenci << firmy[i].miejscowosc << '\n';
            file_kontrahenci << firmy[i].nip << '\n';
            file_kontrahenci << firmy[i].mamy_do_zaplaty << '\n';
            file_kontrahenci << firmy[i].ma_nam_zaplacic << '\n';
        }
        file_kontrahenci << firmy[firmy.size() - 1].nazwa << '\n';
        file_kontrahenci << firmy[firmy.size() - 1].adres1 << '\n';
        file_kontrahenci << firmy[firmy.size() - 1].kod_pocztowy << '\n';
        file_kontrahenci << firmy[firmy.size() - 1].miejscowosc << '\n';
        file_kontrahenci << firmy[firmy.size() - 1].nip << '\n';
        file_kontrahenci << firmy[firmy.size() - 1].mamy_do_zaplaty << '\n';
        file_kontrahenci << firmy[firmy.size() - 1].ma_nam_zaplacic;
        file_kontrahenci.close();
    }
}


void wczytaj_magazyn(string & nazwa_file_magazyn, fstream& file_magazyn, vector<magazyn>& produkty)
{
    string tmp_nazwa;
    int tmp_ilosc;
    float tmp_cena;

    file_magazyn.open(nazwa_file_magazyn.c_str(), ios::in);

    if (!file_magazyn.good()) {
        cout << PL("Nie uda≥o siÍ otworzyÊ pliku. Sprawdü adres! KoÒczÍ pracÍ programu!") << endl;
        exit(0);
    }
    else {
        while (!file_magazyn.eof()) {
            do {
                getline(file_magazyn, tmp_nazwa);
                file_magazyn.seekg(0, ios::cur);
                file_magazyn >> tmp_ilosc;
                file_magazyn >> tmp_cena;
                produkty.push_back({ tmp_nazwa, tmp_ilosc, tmp_cena });
            } while (line_mark(file_magazyn));
        }
        file_magazyn.close();
    }
}

void magazyn::wyswietl_stan_magazynu(vector<magazyn> produkty)
{
    for (vector<magazyn>::iterator it = produkty.begin(); it < produkty.end(); it++) {
        cout << it->nazwa << endl;
        cout << PL("IloúÊ: ") << it->ilosc << PL(", Cena za sztukÍ: ") << it->cena << endl;
        if (it->ilosc < 20)
            cout << PL("UWAGA: Na magazynie znajduje siÍ mniej niø 20 sztuk produktu!") << endl;
        cout << endl;
    }
}

void szukaj_produkt(vector<magazyn>& produkty)
{
    bool b = false;
    string tmp;
    cin.seekg(0, ios::end);
    cin.clear();
    
    cout << PL("Jakie produkt mam wyszukaÊ?: ");
    getline(cin, tmp);

        for (vector<magazyn>::iterator it = produkty.begin(); it < produkty.end(); it++) {
            if (it->nazwa.find(tmp) != string::npos) {
                cout << it->nazwa << endl;
                cout << PL("IloúÊ: ") << it->ilosc << PL(", Cena za sztukÍ: ") << it->cena << endl << endl;
                b = true;
            }
        }

    if (b == false)
        cout << PL("Nie odnaleziono szukanych produktÛw...") << endl << endl;
}

void zapisz_nowy_produkt(string & nazwa_file_magazyn, fstream& file_magazyn, vector<magazyn>& produkty)
{
    file_magazyn.open(nazwa_file_magazyn.c_str(), ios::out | ios::app);

    if (!file_magazyn.good()) {
        cout << PL("Nie uda≥o siÍ otworzyÊ pliku. Sprawdü adres! KoÒczÍ pracÍ programu!") << endl;
        exit(0);
    }
    else {
        file_magazyn << '\n' << produkty[produkty.size() - 1].nazwa << '\n';
        file_magazyn << produkty[produkty.size() - 1].ilosc << '\n';
        file_magazyn << produkty[produkty.size() - 1].cena;
        cout << endl << PL("Nowy produkt zosta≥ zapisany!") << endl;
    }
    file_magazyn.close();
}

bool czy_produkt_istnieje(string& s1, vector<magazyn>& produkty)
{
    for (int i = 0; i < produkty.size(); i++) {
        if (s1 == produkty[i].nazwa)
            return false;
    }
    return true;
}

void dodaj_produkt(vector<magazyn>& produkty)
{
    string s1;
    int s2;
    float s3;
    bool b;
    cin.seekg(0, ios::end);
    cin.clear();
    
    cout << PL("Podaj nazwÍ nowego produktu: ");
    do {
        getline(cin, s1);
        b = czy_produkt_istnieje(s1, produkty);
        if (b == false)
            cout << PL("Produkt o podanej nazwie juø istnieje, wpisz ponownie nazwÍ") << endl;
    } while (b == false);
    
    cout << PL("Podaj iloúÊ produktu, ktÛry dodajemy do magazynu: ");
    s2 = intpodaj_liczbe_nieujemna();
    cout << PL("Podaj cenÍ w z≥otych za jednπ sztukÍ nowego produktu: ");
    s3 = podaj_liczbe_nieujemna();
    produkty.push_back({ s1, s2, s3 });
    cout << PL("Nowy produkt zosta≥ dodany!") << endl;
}

void usun_produkt(vector<magazyn>& produkty)
{
    bool b = false;
    string tmp;
    int licznik = 0;

    cout << PL("Jaki produkt usunπÊ? Podaj nazwÍ: ");
    cin.seekg(0, ios::end);
    cin.clear();
    
    getline(cin, tmp);

    for (vector<magazyn>::iterator it = produkty.begin(); it < produkty.end(); it++) {
        if (it->nazwa.find(tmp) != string::npos) {
            cout << licznik+1 << ". " << it->nazwa << endl;
            cout << PL("IloúÊ: ") << it->ilosc << PL(", Cena za sztukÍ: ") << it->cena << endl << endl;
            licznik++;
            b = true;
        }
    }

    if (licznik > 0) {
        vector<magazyn> chwilowy;
        int co_usunac;

        for (vector<magazyn>::iterator it = produkty.begin(); it < produkty.end(); it++) {
            if (it->nazwa.find(tmp) != string::npos) {
                chwilowy.push_back({ it->nazwa, it->ilosc, it->cena });
            }
        }

        cout << PL("KtÛry produkt mam usunπÊ? Podaj numer: ");
        do {
            co_usunac = podaj_liczbe();
            if (co_usunac < 1 || co_usunac > licznik)
                cout << PL("Nie ma produktu o takim numerze, sprÛbuj ponownie ") << endl;
        } while (co_usunac < 1 || co_usunac > licznik);

        cout << endl << "Usuwamy:" << endl;
        cout << chwilowy[co_usunac - 1].nazwa << endl;

        
        for (vector<magazyn>::iterator it = produkty.begin(); it < produkty.end(); it++) {
            if (it->nazwa == chwilowy[co_usunac - 1].nazwa) {
                produkty.erase(it);
                break;
            }
        }

        cout << PL("Wybrany produkt zosta≥ usuniÍty!") << endl;
    }

    if (b == false)
        cout << PL("Nie odnaleziono szukanych produktÛw...") << endl << endl;
}

void zapisz_produkt_od_nowa(string & nazwa_file_magazyn, fstream& file_magazyn, vector<magazyn>& produkty)
{
    file_magazyn.open(nazwa_file_magazyn.c_str(), ios::out | ios::trunc);

    if (!file_magazyn.good()) {
        cout << PL("Nie uda≥o siÍ otworzyÊ pliku. Sprawdü adres! KoÒczÍ pracÍ programu!") << endl;
        exit(0);
    }
    else {
        for (int i = 0; i < produkty.size() - 1; i++) {
            file_magazyn << produkty[i].nazwa << '\n';
            file_magazyn << produkty[i].ilosc << '\n';
            file_magazyn << produkty[i].cena << '\n';
        }
        file_magazyn << produkty[produkty.size() - 1].nazwa << '\n';
        file_magazyn << produkty[produkty.size() - 1].ilosc << '\n';
        file_magazyn << produkty[produkty.size() - 1].cena;
    }
    file_magazyn.close();
}

void zmien_produkt(vector<magazyn>& produkty)
{
    bool b = false;
    string tmp;
    int licznik = 0;

    cout << PL("Jakiego produktu cenÍ chcesz zmieniÊ? Podaj nazwÍ: ");
    cin.seekg(0, ios::end);
    cin.clear();
    
    getline(cin, tmp);

    for (vector<magazyn>::iterator it = produkty.begin(); it < produkty.end(); it++) {
        if (it->nazwa.find(tmp) != string::npos) {
            cout << licznik + 1 << ". " << it->nazwa << endl;
            cout << PL("IloúÊ: ") << it->ilosc << PL(", Cena za sztukÍ: ") << it->cena << endl << endl;
            licznik++;
            b = true;
        }
    }

    if (licznik > 0) {
        vector<magazyn> chwilowy;
        int co_zmienic;

        for (vector<magazyn>::iterator it = produkty.begin(); it < produkty.end(); it++) {
            if (it->nazwa.find(tmp) != string::npos) {
                chwilowy.push_back({ it->nazwa, it->ilosc, it->cena });
            }
        }

        cout << PL("KtÛrego produktu cenÍ mam zmieniÊ? Podaj numer: ");
        do {
            co_zmienic = podaj_liczbe();
            if (co_zmienic < 1 || co_zmienic > licznik)
                cout << PL("Nie ma produktu o takim numerze, sprÛbuj ponownie ") << endl;
        } while (co_zmienic < 1 || co_zmienic > licznik);

        cout << endl << "Stara cena: " << chwilowy[co_zmienic - 1].cena << PL(" z≥otych") << endl;
        float nowa_cena = 0;
        cout << PL("Podaj nowπ cenÍ: ") << endl;
        nowa_cena = podaj_liczbe_nieujemna();

        for (int j = 0; j < produkty.size(); j++) {
            if (produkty[j].nazwa == chwilowy[co_zmienic - 1].nazwa) {
                produkty[j].cena = nowa_cena;
            }
        }
        cout << PL("Cena produktu zosta≥a zmieniona!") << endl;
    }

    if (b == false)
        cout << "Nie odnaleziono szukanego produktu..." << endl << endl;
}



int PZ::ile;

PZ::PZ(kontrahenci& tmp1, magazyn& mag1, magazyn& mag2, magazyn& mag3, magazyn& mag4, int nd)
    : numer_dokumentu(nd)
{
    ile++;
    dostawca = tmp1;
    towar1 = mag1;
    towar2 = mag2;
    towar3 = mag3;
    towar4 = mag4;
}

PZ::PZ(kontrahenci& tmp1, magazyn& mag1, magazyn& mag2, magazyn& mag3, int nd)
    : numer_dokumentu(nd)
{
    ile++;
    dostawca = tmp1;
    towar1 = mag1;
    towar2 = mag2;
    towar3 = mag3;
}

PZ::PZ(kontrahenci& tmp1, magazyn& mag1, magazyn& mag2, int nd)
    : numer_dokumentu(nd)
{
    ile++;
    dostawca = tmp1;
    towar1 = mag1;
    towar2 = mag2;
}

PZ::PZ(kontrahenci& tmp1, magazyn& mag1, int nd)
    : numer_dokumentu(nd)
{
    ile++;
    dostawca = tmp1;
    towar1 = mag1;
}

void PZ::wyswietl_PZ()
{
    cout << "Numer dokumentu: " << this->numer_dokumentu << endl << endl;

    cout << "Dostawca:" << endl;
    cout << this->dostawca.nazwa << endl;
    cout << this->dostawca.adres1 << endl;
    cout << this->dostawca.kod_pocztowy << " " << this->dostawca.miejscowosc << endl;
    cout << this->dostawca.nip << endl << endl;

    cout << PL("PrzyjÍty towar:") << endl;
    cout << "Nazwa: " << this->towar1.nazwa << endl;
    cout << PL("\tIloúÊ: ") << this->towar1.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << this->towar1.cena << PL("\t\tWartoúÊ: ") << this->towar1.ilosc * this->towar1.cena << endl;
    if(this->towar2.ilosc > 0) {
        cout << "Nazwa: " << this->towar2.nazwa << endl;
        cout << PL("\tIloúÊ: ") << this->towar2.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << this->towar2.cena << PL("\t\tWartoúÊ: ") << this->towar2.ilosc * this->towar2.cena << endl;
    }
    if (this->towar3.ilosc > 0) {
        cout << "Nazwa: " << this->towar3.nazwa << endl;
        cout << PL("\tIloúÊ: ") << this->towar3.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << this->towar3.cena << PL("\t\tWartoúÊ: ") << this->towar3.ilosc * this->towar3.cena << endl;
    }
    if (this->towar4.ilosc > 0) {
        cout << "Nazwa: " << this->towar4.nazwa << endl;
        cout << PL("\tIloúÊ: ") << this->towar4.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << this->towar4.cena << PL("\t\tWartoúÊ: ") << this->towar4.ilosc * this->towar4.cena << endl;
    }
    float suma = (this->towar1.ilosc * this->towar1.cena) + (this->towar2.ilosc * this->towar2.cena) + (this->towar3.ilosc * this->towar3.cena) + (this->towar4.ilosc * this->towar4.cena);
    cout << endl << PL("Mamy do zap≥aty: ") << fixed << setprecision(2) << suma << PL(" z≥") << endl << endl;
}

void przyjecie_towaru(string& nazwa_file_PZ, fstream& file_PZ, vector<PZ>& przyjecia, vector<kontrahenci>& firmy, vector<magazyn>& produkty)
{
    string tmp1;
    bool b;
    int licznik = 0;
    vector<kontrahenci> chwilowy;
    kontrahenci wybrany_kontrahent;

    cin.seekg(0, ios::end);
    cin.clear();
    
    cout << PL("PrzyjÍcie towaru do magazynu") << endl << endl;

    if (firmy.size() == 0) {
        cout << PL("W bazie nie odnaleziono øadnych kontrahentÛw...") << endl << endl;
        return;
    }

    cout << PL("Od kogo odbierasz towar? Podaj nazwÍ: ");
    
    do {
        getline(cin, tmp1);
        b = false;
        licznik = 0;
        for (vector<kontrahenci>::iterator it = firmy.begin(); it < firmy.end(); it++) {
            if (it->nazwa.find(tmp1) != string::npos) {
                cout << licznik + 1 << ". " << it->nazwa << ", " << it->adres1 << ", " << it->kod_pocztowy << " " << it->miejscowosc << ", NIP: " << it->nip << endl << endl;
                licznik++;
                b = true;
            }
        }

        if (b == false) {
            cout << endl << "Nie odnaleziono szukanego kontrahenta..." << endl;
            cout << PL("SprÛbuj ponownie: ") << endl << endl;
        }
    } while (licznik == 0 && b == false);
    

    if (licznik > 0 && b == true) {
        int wybierz_kto;

        for (vector<kontrahenci>::iterator it = firmy.begin(); it < firmy.end(); it++) {
            if (it->nazwa.find(tmp1) != string::npos) {
                chwilowy.push_back({ it->nazwa, it->adres1, it->kod_pocztowy, it->miejscowosc, it->nip });
            }
        }

        cout << endl << PL("KtÛrego kontrahenta chcesz wybraÊ? Podaj numer: ");
        do {
            wybierz_kto = podaj_liczbe();
            if (wybierz_kto < 1 || wybierz_kto > licznik)
                cout << PL("Nie ma kontrahenta o takim numerze, sprÛbuj ponownie ") << endl;
        } while (wybierz_kto < 1 || wybierz_kto > licznik);

        
        for (int j = 0; j < firmy.size(); j++) {
            if (firmy[j].nazwa == chwilowy[wybierz_kto - 1].nazwa) {
                wybrany_kontrahent.nazwa = firmy[j].nazwa;
                wybrany_kontrahent.adres1 = firmy[j].adres1;
                wybrany_kontrahent.kod_pocztowy = firmy[j].kod_pocztowy;
                wybrany_kontrahent.miejscowosc = firmy[j].miejscowosc;
                wybrany_kontrahent.nip = firmy[j].nip;
                wybrany_kontrahent.mamy_do_zaplaty = 0;
                wybrany_kontrahent.ma_nam_zaplacic = 0;
            }
        }
    }

    
    char wybor;
    bool b1;
    vector<magazyn> chwilowy1;
    vector<magazyn> prod;

    if (produkty.size() == 0) {
        cout << PL("W bazie nie odnaleziono øadnych produktÛw...") << endl << endl;
        return;
    }
    
    do {
        system("cls");
        chwilowy1.clear();
        cin.seekg(0, ios::end);
        cin.clear();
        
        do {
            cin.seekg(0, ios::end);
            cin.clear();
            cout << endl << PL("Podaj nazwÍ przyjmowanego towaru: ");
            getline(cin, tmp1);
            b1 = false;
            licznik = 0;

            for (vector<magazyn>::iterator it = produkty.begin(); it < produkty.end(); it++) {
                if (it->nazwa.find(tmp1) != string::npos) {
                    cout << licznik + 1 << ". " << it->nazwa << endl;
                    cout << PL("IloúÊ: ") << it->ilosc << PL(", Cena za sztukÍ: ") << it->cena << endl << endl;
                    licznik++;
                    b1 = true;
                }
            }

            if (b1 == false) {
                char wybor1;
                cout << endl << "Nie odnaleziono szukanego produktu..." << endl;
                cout << PL("[1] - SprÛbuj ponownie, podaj nazwÍ: ") << endl;
                cout << PL("[0] - SprawdzÍ o co chodzi w magazynie (powrÛt)") << endl << endl;
                wybor1 = give_mark4();
                switch (wybor1) {
                case '1': {
                    break;
                }
                case '0': {
                    return;
                    break;
                }
                }
            }
        } while (licznik == 0 && b1 == false);

        if (licznik > 0 && b1 == true) {
            int wybierz_co;

            for (vector<magazyn>::iterator it = produkty.begin(); it < produkty.end(); it++) {
                if (it->nazwa.find(tmp1) != string::npos) {
                    chwilowy1.push_back({ it->nazwa, it->ilosc, it->cena });
                }
            }

            cout << endl << PL("KtÛry produkt chcesz wybraÊ? Podaj numer: ");
            do {
                wybierz_co = podaj_liczbe();
                if (wybierz_co < 1 || wybierz_co > licznik)
                    cout << PL("Nie ma produktu o takim numerze, sprÛbuj ponownie ") << endl;
            } while (wybierz_co < 1 || wybierz_co > licznik);

            cout << PL("Jakπ iloúÊ towaru przyjmujesz: ");
            int ilosc_przyjeta = intpodaj_liczbe_nieujemna();

            
            if (ilosc_przyjeta > 0) {
                bool n = false;
                for (int j = 0; j < prod.size(); j++) {
                    if (prod[j].nazwa == chwilowy1[wybierz_co - 1].nazwa)
                        n = true;
                }

                if (n == false) {
                    for (int j = 0; j < produkty.size(); j++) {
                        if (produkty[j].nazwa == chwilowy1[wybierz_co - 1].nazwa) {
                            produkty[j].ilosc += ilosc_przyjeta;
                            prod.push_back({ produkty[j].nazwa, ilosc_przyjeta, produkty[j].cena });
                        }
                    }
                }
                else {
                    for (int j = 0; j < produkty.size(); j++) {
                        if (produkty[j].nazwa == chwilowy1[wybierz_co - 1].nazwa) {
                            produkty[j].ilosc += ilosc_przyjeta;
                            for (int k = 0; k < prod.size(); k++) {
                                if (prod[k].nazwa == chwilowy1[wybierz_co - 1].nazwa)
                                    prod[k].ilosc += ilosc_przyjeta;
                            }
                        }
                    }
                }
            }
        }
        
        if (prod.size() < 4) {
            cout << endl << PL("Czy chcesz przyjπÊ kolejny produkt?") << endl;
            cout << "[1] - Tak" << endl;
            cout << "[0] - Nie" << endl;

            wybor = give_mark4();
            switch (wybor) {
                case '1': {
                    break;
                }
                case '0': {
                    break;
                }
            }
        }
        
    } while (wybor != '0' && prod.size() < 4);
    
    int a = prod.size();
    if (a > 0) {
        if (a == 1) {
            magazyn mag1 = prod[0];
            int x = przyjecia.size() + 1;
            przyjecia.push_back({ wybrany_kontrahent, mag1, x });
        }
        else if (a == 2) {
            magazyn mag1 = prod[0];
            magazyn mag2 = prod[1];
            int x = przyjecia.size() + 1;
            przyjecia.push_back({ wybrany_kontrahent, mag1, mag2, x });
        }
        else if (a == 3) {
            magazyn mag1 = prod[0];
            magazyn mag2 = prod[1];
            magazyn mag3 = prod[2];
            int x = przyjecia.size() + 1;
            przyjecia.push_back({ wybrany_kontrahent, mag1, mag2, mag3, x });
        }
        else if (a == 4) {
            magazyn mag1 = prod[0];
            magazyn mag2 = prod[1];
            magazyn mag3 = prod[2];
            magazyn mag4 = prod[3];
            int x = przyjecia.size() + 1;
            przyjecia.push_back({ wybrany_kontrahent, mag1, mag2, mag3, mag4, x });
        }


        float zaplata = 0;
        for (int j = 0; j < produkty.size(); j++) {
            for (int k = 0; k < prod.size(); k++) {
                if (produkty[j].nazwa == prod[k].nazwa)
                    zaplata += (prod[k].cena * prod[k].ilosc);
            }
        }

        for (int j = 0; j < firmy.size(); j++) {
            if (firmy[j].nazwa == wybrany_kontrahent.nazwa) {
                firmy[j].mamy_do_zaplaty += zaplata;
            }
        }

        system("cls");
        przyjecia[przyjecia.size() - 1].wyswietl_PZ();
        zapisz_PZ(nazwa_file_PZ, file_PZ, przyjecia);
    }
    else 
        cout << PL("Nie dodano øadnego produktu, dokument PZ nie zosta≥ utworzony") << endl << endl;

}

void wczytaj_PZ(string & nazwa_file_PZ, fstream& file_PZ, vector<PZ>& przyjecia)
{
    string t1, t2, t3, t4, t5, t6, t7, t8, t9;
    float f1, f2, f3, f4, f5, f6;
    int i1, i2, i3, i4;
    kontrahenci k;
    magazyn m1, m2, m3, m4;
    int i = 1;
    
    file_PZ.open(nazwa_file_PZ.c_str(), ios::in);

    if (!file_PZ.good()) {
        cout << PL("Nie uda≥o siÍ otworzyÊ pliku. Sprawdü adres! KoÒczÍ pracÍ programu!") << endl;
        exit(0);
    }
    else {
        while (!file_PZ.eof()) {
            do {
                file_PZ.clear();
                file_PZ.get();
                file_PZ.seekg(-1, ios::cur);
                getline(file_PZ, t1);
                getline(file_PZ, t2);
                getline(file_PZ, t3);
                getline(file_PZ, t4);
                getline(file_PZ, t5);
                file_PZ.seekg(0, ios::cur);
                file_PZ >> f1;
                file_PZ >> f2;
                k = { t1, t2, t3, t4, t5, f1, f2 };

                file_PZ.clear();
                file_PZ.get();
                getline(file_PZ, t6);
                file_PZ.seekg(0, ios::cur);
                file_PZ >> i1;
                file_PZ >> f3;
                m1 = { t6, i1, f3 };

                file_PZ.clear();
                file_PZ.get();
                getline(file_PZ, t7);
                file_PZ.seekg(0, ios::cur);
                file_PZ >> i2;
                file_PZ >> f4;
                m2 = { t7, i2, f4 };

                file_PZ.clear();
                file_PZ.get();
                getline(file_PZ, t8);
                file_PZ.seekg(0, ios::cur);
                file_PZ >> i3;
                file_PZ >> f5;
                m3 = { t8, i3, f5 };

                file_PZ.clear();
                file_PZ.get();
                getline(file_PZ, t9);
                file_PZ.seekg(0, ios::cur);
                file_PZ >> i4;
                file_PZ >> f6;
                m4 = { t9, i4, f6 };

                przyjecia.push_back({ k, m1, m2, m3, m4, i });
                i++;
            } while (line_mark(file_PZ) || any_mark(file_PZ));
        }  
    }
    file_PZ.close();
}

void zapisz_PZ(string & nazwa_file_PZ, fstream& file_PZ, vector<PZ>& przyjecia)
{
    file_PZ.open(nazwa_file_PZ.c_str(), ios::out | ios::app);

    if (!file_PZ.good()) {
        cout << PL("Nie uda≥o siÍ otworzyÊ pliku. Sprawdü adres! KoÒczÍ pracÍ programu!") << endl;
        exit(0);
    }
    else {
        file_PZ << '\n' << przyjecia[przyjecia.size() - 1].dostawca.nazwa << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].dostawca.adres1 << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].dostawca.kod_pocztowy << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].dostawca.miejscowosc << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].dostawca.nip << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].dostawca.mamy_do_zaplaty << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].dostawca.ma_nam_zaplacic << '\n';

        file_PZ << przyjecia[przyjecia.size() - 1].towar1.nazwa << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].towar1.ilosc << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].towar1.cena << '\n';

        file_PZ << przyjecia[przyjecia.size() - 1].towar2.nazwa << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].towar2.ilosc << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].towar2.cena << '\n';

        file_PZ << przyjecia[przyjecia.size() - 1].towar3.nazwa << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].towar3.ilosc << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].towar3.cena << '\n';

        file_PZ << przyjecia[przyjecia.size() - 1].towar4.nazwa << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].towar4.ilosc << '\n';
        file_PZ << przyjecia[przyjecia.size() - 1].towar4.cena;
    }
    file_PZ.close();
}

void wyswietl_PZ_wszystkie(vector<PZ>& przyjecia)
{
    float suma = 0;
    for (int i = 0; i < przyjecia.size(); i++) {
        cout << "Numer dokumentu: " << przyjecia[i].numer_dokumentu << endl;

        cout << "Dostawca:" << endl;
        cout << przyjecia[i].dostawca.nazwa << ", NIP: " << przyjecia[i].dostawca.nip << endl;
        cout << przyjecia[i].dostawca.adres1 << ", " << przyjecia[i].dostawca.kod_pocztowy << " " << przyjecia[i].dostawca.miejscowosc << endl;
        
        cout << PL("PrzyjÍty towar:") << endl;
        cout << "Nazwa: " << przyjecia[i].towar1.nazwa << endl;
        cout << PL("\tIloúÊ: ") << przyjecia[i].towar1.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << przyjecia[i].towar1.cena << PL("\t\tWartoúÊ: ") << przyjecia[i].towar1.ilosc * przyjecia[i].towar1.cena << endl;
        if (przyjecia[i].towar2.ilosc > 0) {
            cout << "Nazwa: " << przyjecia[i].towar2.nazwa << endl;
            cout << PL("\tIloúÊ: ") << przyjecia[i].towar2.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << przyjecia[i].towar2.cena << PL("\t\tWartoúÊ: ") << przyjecia[i].towar2.ilosc * przyjecia[i].towar2.cena << endl;
        }
        if (przyjecia[i].towar3.ilosc > 0) {
            cout << "Nazwa: " << przyjecia[i].towar3.nazwa << endl;
            cout << PL("\tIloúÊ: ") << przyjecia[i].towar3.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << przyjecia[i].towar3.cena << PL("\t\tWartoúÊ: ") << przyjecia[i].towar3.ilosc * przyjecia[i].towar3.cena << endl;
        }
        if (przyjecia[i].towar4.ilosc > 0) {
            cout << "Nazwa: " << przyjecia[i].towar4.nazwa << endl;
            cout << PL("\tIloúÊ: ") << przyjecia[i].towar4.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << przyjecia[i].towar4.cena << PL("\t\tWartoúÊ: ") << przyjecia[i].towar4.ilosc * przyjecia[i].towar4.cena << endl;
        }
        cout << endl << endl;
        suma += (przyjecia[i].towar1.ilosc * przyjecia[i].towar1.cena) + (przyjecia[i].towar2.ilosc * przyjecia[i].towar2.cena) + (przyjecia[i].towar3.ilosc * przyjecia[i].towar3.cena) + (przyjecia[i].towar4.ilosc * przyjecia[i].towar4.cena);
    }
    cout << PL("£πczne zobowiπzanie wobec kontrahentÛw wynosi: ") << fixed << setprecision(2) << suma << PL(" z≥otych") << endl << endl;
}

void wyswietl_PZ_kontrahent(vector<PZ>& przyjecia)
{
    bool b = false;
    string tmp;
    cin.seekg(0, ios::end);
    cin.clear();

    cout << PL("Podaj nazwÍ firmy: ");
    getline(cin, tmp);
    cout << endl;

    for (vector<PZ>::iterator it = przyjecia.begin(); it < przyjecia.end(); it++) {
        if (it->dostawca.nazwa.find(tmp) != string::npos) {
            cout << "Numer dokumentu: " << it->numer_dokumentu << endl;

            cout << "Dostawca:" << endl;
            cout << it->dostawca.nazwa << ", NIP: " << it->dostawca.nip << endl;
            cout << it->dostawca.adres1 << ", " << it->dostawca.kod_pocztowy << " " << it->dostawca.miejscowosc << endl;

            cout << PL("PrzyjÍty towar:") << endl;
            cout << "Nazwa: " << it->towar1.nazwa << endl;
            cout << PL("\tIloúÊ: ") << it->towar1.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << it->towar1.cena << PL("\t\tWartoúÊ: ") << it->towar1.ilosc * it->towar1.cena << endl;
            if (it->towar2.ilosc > 0) {
                cout << "Nazwa: " << it->towar2.nazwa << endl;
                cout << PL("\tIloúÊ: ") << it->towar2.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << it->towar2.cena << PL("\t\tWartoúÊ: ") << it->towar2.ilosc * it->towar2.cena << endl;
            }
            if (it->towar3.ilosc > 0) {
                cout << "Nazwa: " << it->towar3.nazwa << endl;
                cout << PL("\tIloúÊ: ") << it->towar3.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << it->towar3.cena << PL("\t\tWartoúÊ: ") << it->towar3.ilosc * it->towar3.cena << endl;
            }
            if (it->towar4.ilosc > 0) {
                cout << "Nazwa: " << it->towar4.nazwa << endl;
                cout << PL("\tIloúÊ: ") << it->towar4.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << it->towar4.cena << PL("\t\tWartoúÊ: ") << it->towar4.ilosc * it->towar4.cena << endl;
            }
            cout << endl << endl;
            b = true;
        }
    }

    if (b == false)
        cout << "Nie ma wystawionych PZ dla kontrahenta o podanej nazwie..." << endl << endl;
}



int WZ::ile;

void WZ::ile_dokumentow()
{
    std::cout << this->ile << PL(" dokumentÛw") << std::endl;
}

WZ::WZ(kontrahenci & tmp1, magazyn & mag1, magazyn & mag2, magazyn & mag3, magazyn & mag4, int nd)
    : numer_dokumentu(nd)
{
    ile++;
    nabywca = tmp1;
    towar1 = mag1;
    towar2 = mag2;
    towar3 = mag3;
    towar4 = mag4;
}

WZ::WZ(kontrahenci& tmp1, magazyn& mag1, magazyn& mag2, magazyn& mag3, int nd)
    : numer_dokumentu(nd)
{
    ile++;
    nabywca = tmp1;
    towar1 = mag1;
    towar2 = mag2;
    towar3 = mag3;
}

WZ::WZ(kontrahenci& tmp1, magazyn& mag1, magazyn& mag2, int nd)
    : numer_dokumentu(nd)
{
    ile++;
    nabywca = tmp1;
    towar1 = mag1;
    towar2 = mag2;
}

WZ::WZ(kontrahenci& tmp1, magazyn& mag1, int nd)
    : numer_dokumentu(nd)
{
    ile++;
    nabywca = tmp1;
    towar1 = mag1;
}

void WZ::wyswietl_WZ()
{
    cout << "Numer dokumentu: " << this->numer_dokumentu << endl << endl;

    cout << "Nabywca:" << endl;
    cout << this->nabywca.nazwa << endl;
    cout << this->nabywca.adres1 << endl;
    cout << this->nabywca.kod_pocztowy << " " << this->nabywca.miejscowosc << endl;
    cout << this->nabywca.nip << endl << endl;

    cout << PL("Wydany towar:") << endl;
    cout << "Nazwa: " << this->towar1.nazwa << endl;
    cout << PL("\tIloúÊ: ") << this->towar1.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << this->towar1.cena << PL("\t\tWartoúÊ: ") << this->towar1.ilosc * this->towar1.cena << endl;
    if (this->towar2.ilosc > 0) {
        cout << "Nazwa: " << this->towar2.nazwa << endl;
        cout << PL("\tIloúÊ: ") << this->towar2.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << this->towar2.cena << PL("\t\tWartoúÊ: ") << this->towar2.ilosc * this->towar2.cena << endl;
    }
    if (this->towar3.ilosc > 0) {
        cout << "Nazwa: " << this->towar3.nazwa << endl;
        cout << PL("\tIloúÊ: ") << this->towar3.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << this->towar3.cena << PL("\t\tWartoúÊ: ") << this->towar3.ilosc * this->towar3.cena << endl;
    }
    if (this->towar4.ilosc > 0) {
        cout << "Nazwa: " << this->towar4.nazwa << endl;
        cout << PL("\tIloúÊ: ") << this->towar4.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << this->towar4.cena << PL("\t\tWartoúÊ: ") << this->towar4.ilosc * this->towar4.cena << endl;
    }
    float suma = (this->towar1.ilosc * this->towar1.cena) + (this->towar2.ilosc * this->towar2.cena) + (this->towar3.ilosc * this->towar3.cena) + (this->towar4.ilosc * this->towar4.cena);
    cout << endl << PL("Kontrahent ma nam zap≥aciÊ: ") << fixed << setprecision(2) << suma << PL(" z≥") << endl << endl;
}

void wydanie_towaru(string& nazwa_file_WZ, fstream& file_WZ, vector<WZ>& wydania, vector<kontrahenci>& firmy, vector<magazyn>& produkty)
{
    string tmp1;
    bool b;
    int licznik = 0;
    vector<kontrahenci> chwilowy;
    kontrahenci wybrany_kontrahent;

    cin.seekg(0, ios::end);
    cin.clear();

    cout << "Wydanie towaru z magazynu" << endl << endl;

    if (firmy.empty()) {
        cout << PL("W bazie nie odnaleziono øadnych kontrahentÛw...") << endl << endl;
        return;
    }

        do {
            getline(cin, tmp1);
            b = false;
            licznik = 0;
            for (vector<kontrahenci>::iterator it = firmy.begin(); it < firmy.end(); it++) {
                if (it->nazwa.find(tmp1) != string::npos) {
                    cout << licznik + 1 << ". " << it->nazwa << ", " << it->adres1 << ", " << it->kod_pocztowy << " " << it->miejscowosc << ", NIP: " << it->nip << endl << endl;
                    licznik++;
                    b = true;
                }
            }

            if (b == false) {
                cout << endl << "Nie odnaleziono szukanego kontrahenta..." << endl;
                cout << PL("SprÛbuj ponownie, podaj nazwÍ: ") << endl << endl;
            }
        } while (licznik == 0 && b == false);


        if (licznik > 0 && b == true) {
            int wybierz_kto;

            for (vector<kontrahenci>::iterator it = firmy.begin(); it < firmy.end(); it++) {
                if (it->nazwa.find(tmp1) != string::npos) {
                    chwilowy.push_back({ it->nazwa, it->adres1, it->kod_pocztowy, it->miejscowosc, it->nip });
                }
            }

            cout << endl << PL("KtÛrego kontrahenta chcesz wybraÊ? Podaj numer: ");
            do {
                wybierz_kto = podaj_liczbe();
                if (wybierz_kto < 1 || wybierz_kto > licznik)
                    cout << PL("Nie ma kontrahenta o takim numerze, sprÛbuj ponownie: ") << endl;
            } while (wybierz_kto < 1 || wybierz_kto > licznik);


            for (int j = 0; j < firmy.size(); j++) {
                if (firmy[j].nazwa == chwilowy[wybierz_kto - 1].nazwa) {
                    wybrany_kontrahent.nazwa = firmy[j].nazwa;
                    wybrany_kontrahent.adres1 = firmy[j].adres1;
                    wybrany_kontrahent.kod_pocztowy = firmy[j].kod_pocztowy;
                    wybrany_kontrahent.miejscowosc = firmy[j].miejscowosc;
                    wybrany_kontrahent.nip = firmy[j].nip;
                    wybrany_kontrahent.mamy_do_zaplaty = 0;
                    wybrany_kontrahent.ma_nam_zaplacic = 0;
                }
            }
        }


        char wybor;
        bool b1;
        vector<magazyn> chwilowy1;
        vector<magazyn> prod;

        if (produkty.size() == 0) {
            cout << PL("W bazie nie odnaleziono øadnych produktÛw...") << endl << endl;
            return;
        }

        do {
            system("cls");
            chwilowy1.clear();
            cin.seekg(0, ios::end);
            cin.clear();

            do {
                cin.seekg(0, ios::end);
                cin.clear();
                cout << endl << PL("Podaj nazwÍ wydawanego towaru: ");
                getline(cin, tmp1);
                b1 = false;
                licznik = 0;

                for (vector<magazyn>::iterator it = produkty.begin(); it < produkty.end(); it++) {
                    if (it->nazwa.find(tmp1) != string::npos) {

                        if (it->ilosc == 0)
                            continue;
                        if (it->ilosc > 0) {
                            cout << licznik + 1 << ". " << it->nazwa << endl;
                            cout << PL("IloúÊ: ") << it->ilosc << PL(", Cena za sztukÍ: ") << it->cena << endl << endl;

                            b1 = true;
                        }
                        licznik++;
                    }
                }

                if (b1 == false) {
                    char wybor1;
                    cout << endl << "Nie odnaleziono szukanego produktu..." << endl;
                    cout << PL("[1] - SprÛbuj ponownie, podaj nazwÍ: ") << endl;
                    cout << PL("[0] - SprawdzÍ o co chodzi w magazynie (powrÛt)") << endl << endl;
                    wybor1 = give_mark4();
                    switch (wybor1) {
                    case '1': {
                        break;
                    }
                    case '0': {
                        return;
                        break;
                    }
                    }
                }
            } while (licznik == 0 && b1 == false);

            if (licznik > 0 && b1 == true) {
                int wybierz_co;

                for (vector<magazyn>::iterator it = produkty.begin(); it < produkty.end(); it++) {
                    if (it->nazwa.find(tmp1) != string::npos) {
                        if (it->ilosc == 0)
                            continue;
                        chwilowy1.push_back({ it->nazwa, it->ilosc, it->cena });
                    }
                }

                cout << endl << PL("KtÛry produkt chcesz wybraÊ? Podaj numer: ");
                do {
                    wybierz_co = podaj_liczbe();
                    if (wybierz_co < 1 || wybierz_co > licznik)
                        cout << PL("Nie ma produktu o takim numerze, sprÛbuj ponownie ") << endl;
                } while (wybierz_co < 1 || wybierz_co > licznik);


                cout << PL("Jakπ iloúÊ towaru chcesz wydaÊ: ");
                int ilosc_wydana;
                bool d;
                do {
                    d = true;
                    ilosc_wydana = intpodaj_liczbe_nieujemna();
                    for (int j = 0; j < produkty.size(); j++) {
                        if (produkty[j].nazwa == chwilowy1[wybierz_co - 1].nazwa) {
                            if (produkty[j].ilosc < ilosc_wydana) {
                                cout << PL("Nie ma wystarczajπcej iloúci produktu na magazynie") << endl;
                                cout << PL("Maksymalna iloúÊ, ktÛrπ moøna wydaÊ to: ") << produkty[j].ilosc << endl;
                                cout << PL("Wprowadü wartoúÊ ponownie: ");
                                d = false;
                            }
                        }
                    }
                } while (d == false);

                if (ilosc_wydana > 0) {
                    bool n = false;
                    for (int j = 0; j < prod.size(); j++) {
                        if (prod[j].nazwa == chwilowy1[wybierz_co - 1].nazwa)
                            n = true;
                    }

                    if (n == false) {
                        for (int j = 0; j < produkty.size(); j++) {
                            if (produkty[j].nazwa == chwilowy1[wybierz_co - 1].nazwa) {
                                produkty[j].ilosc -= ilosc_wydana;
                                prod.push_back({ produkty[j].nazwa, ilosc_wydana, produkty[j].cena });
                            }
                        }
                    }
                    else {
                        for (int j = 0; j < produkty.size(); j++) {
                            if (produkty[j].nazwa == chwilowy1[wybierz_co - 1].nazwa) {
                                produkty[j].ilosc -= ilosc_wydana;
                                for (int k = 0; k < prod.size(); k++) {
                                    if (prod[k].nazwa == chwilowy1[wybierz_co - 1].nazwa)
                                        prod[k].ilosc += ilosc_wydana;
                                }
                            }
                        }
                    }
                }
            }

            if (prod.size() < 4) {
                cout << endl << PL("Czy chcesz wydaÊ kolejny produkt?") << endl;
                cout << "[1] - Tak" << endl;
                cout << "[0] - Nie" << endl;

                wybor = give_mark4();
                switch (wybor) {
                case '1': {
                    break;
                }
                case '0': {
                    break;
                }
                }
            }
        } while (wybor != '0' && prod.size() < 4);

        int a = prod.size();
        if (a > 0) {
            if (a == 1) {
                magazyn mag1 = prod[0];
                int x = wydania.size() + 1;
                wydania.push_back({ wybrany_kontrahent, mag1, x });
            }
            else if (a == 2) {
                magazyn mag1 = prod[0];
                magazyn mag2 = prod[1];
                int x = wydania.size() + 1;
                wydania.push_back({ wybrany_kontrahent, mag1, mag2, x });
            }
            else if (a == 3) {
                magazyn mag1 = prod[0];
                magazyn mag2 = prod[1];
                magazyn mag3 = prod[2];
                int x = wydania.size() + 1;
                wydania.push_back({ wybrany_kontrahent, mag1, mag2, mag3, x });
            }
            else if (a == 4) {
                magazyn mag1 = prod[0];
                magazyn mag2 = prod[1];
                magazyn mag3 = prod[2];
                magazyn mag4 = prod[3];
                int x = wydania.size() + 1;
                wydania.push_back({ wybrany_kontrahent, mag1, mag2, mag3, mag4, x });
            }

            float zaplata = 0;
            for (int j = 0; j < produkty.size(); j++) {
                for (int k = 0; k < prod.size(); k++) {
                    if (produkty[j].nazwa == prod[k].nazwa)
                        zaplata += (prod[k].cena * prod[k].ilosc);
                }
            }

            for (int j = 0; j < firmy.size(); j++) {
                if (firmy[j].nazwa == wybrany_kontrahent.nazwa) {
                    firmy[j].ma_nam_zaplacic += zaplata;
                }
            }

            system("cls");
            wydania[wydania.size() - 1].wyswietl_WZ();
            zapisz_WZ(nazwa_file_WZ, file_WZ, wydania);
        }
        else {
            cout << PL("Nie dodano øadnego produktu, dokument WZ nie zosta≥ utworzony") << endl << endl;
        }
}

void zapisz_WZ(string & nazwa_file_WZ, fstream& file_WZ, vector<WZ>& wydania)
{
    file_WZ.open(nazwa_file_WZ.c_str(), ios::out | ios::app);

    if (!file_WZ.good()) {
        cout << PL("Nie uda≥o siÍ otworzyÊ pliku. Sprawdü adres! KoÒczÍ pracÍ programu!") << endl;
        exit(0);
    }
    else {
        file_WZ << '\n' << wydania[wydania.size() - 1].nabywca.nazwa << '\n';
        file_WZ << wydania[wydania.size() - 1].nabywca.adres1 << '\n';
        file_WZ << wydania[wydania.size() - 1].nabywca.kod_pocztowy << '\n';
        file_WZ << wydania[wydania.size() - 1].nabywca.miejscowosc << '\n';
        file_WZ << wydania[wydania.size() - 1].nabywca.nip << '\n';
        file_WZ << wydania[wydania.size() - 1].nabywca.mamy_do_zaplaty << '\n';
        file_WZ << wydania[wydania.size() - 1].nabywca.ma_nam_zaplacic << '\n';

        file_WZ << wydania[wydania.size() - 1].towar1.nazwa << '\n';
        file_WZ << wydania[wydania.size() - 1].towar1.ilosc << '\n';
        file_WZ << wydania[wydania.size() - 1].towar1.cena << '\n';

        file_WZ << wydania[wydania.size() - 1].towar2.nazwa << '\n';
        file_WZ << wydania[wydania.size() - 1].towar2.ilosc << '\n';
        file_WZ << wydania[wydania.size() - 1].towar2.cena << '\n';

        file_WZ << wydania[wydania.size() - 1].towar3.nazwa << '\n';
        file_WZ << wydania[wydania.size() - 1].towar3.ilosc << '\n';
        file_WZ << wydania[wydania.size() - 1].towar3.cena << '\n';

        file_WZ << wydania[wydania.size() - 1].towar4.nazwa << '\n';
        file_WZ << wydania[wydania.size() - 1].towar4.ilosc << '\n';
        file_WZ << wydania[wydania.size() - 1].towar4.cena;
    }
    file_WZ.close();
}

void wczytaj_WZ(string & nazwa_file_WZ, fstream& file_WZ, vector<WZ>& wydania)
{
    string t1, t2, t3, t4, t5, t6, t7, t8, t9;
    float f1, f2, f3, f4, f5, f6;
    int i1, i2, i3, i4;
    kontrahenci k;
    magazyn m1, m2, m3, m4;
    int i = 1;

    file_WZ.open(nazwa_file_WZ.c_str(), ios::in);

    if (!file_WZ.good()) {
        cout << PL("Nie uda≥o siÍ otworzyÊ pliku. Sprawdü adres! KoÒczÍ pracÍ programu!") << endl;
        exit(0);
    }
    else {
        while (!file_WZ.eof()) {
            do {
                file_WZ.clear();
                file_WZ.get();
                file_WZ.seekg(-1, ios::cur);
                getline(file_WZ, t1);
                getline(file_WZ, t2);
                getline(file_WZ, t3);
                getline(file_WZ, t4);
                getline(file_WZ, t5);
                file_WZ.seekg(0, ios::cur);
                file_WZ >> f1;
                file_WZ >> f2;
                k = { t1, t2, t3, t4, t5, f1, f2 };

                file_WZ.clear();
                file_WZ.get();
                getline(file_WZ, t6);
                file_WZ.seekg(0, ios::cur);
                file_WZ >> i1;
                file_WZ >> f3;
                m1 = { t6, i1, f3 };

                file_WZ.clear();
                file_WZ.get();
                getline(file_WZ, t7);
                file_WZ.seekg(0, ios::cur);
                file_WZ >> i2;
                file_WZ >> f4;
                m2 = { t7, i2, f4 };

                file_WZ.clear();
                file_WZ.get();
                getline(file_WZ, t8);
                file_WZ.seekg(0, ios::cur);
                file_WZ >> i3;
                file_WZ >> f5;
                m3 = { t8, i3, f5 };

                file_WZ.clear();
                file_WZ.get();
                getline(file_WZ, t9);
                file_WZ.seekg(0, ios::cur);
                file_WZ >> i4;
                file_WZ >> f6;
                m4 = { t9, i4, f6 };

                wydania.push_back({ k, m1, m2, m3, m4, i });
                i++;
            } while (line_mark(file_WZ) || any_mark(file_WZ));
        }
    }
    file_WZ.close();
}

void wyswietl_WZ_wszystkie(vector<WZ>& wydania)
{
    float suma = 0;
    for (int i = 0; i < wydania.size(); i++) {
        cout << "Numer dokumentu: " << wydania[i].numer_dokumentu << endl;

        cout << "Nabywca:" << endl;
        cout << wydania[i].nabywca.nazwa << ", NIP: " << wydania[i].nabywca.nip << endl;
        cout << wydania[i].nabywca.adres1 << ", " << wydania[i].nabywca.kod_pocztowy << " " << wydania[i].nabywca.miejscowosc << endl;

        cout << PL("Wydany towar:") << endl;
        cout << "Nazwa: " << wydania[i].towar1.nazwa << endl;
        cout << PL("\tIloúÊ: ") << wydania[i].towar1.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << wydania[i].towar1.cena << PL("\t\tWartoúÊ: ") << wydania[i].towar1.ilosc * wydania[i].towar1.cena << endl;
        if (wydania[i].towar2.ilosc > 0) {
            cout << "Nazwa: " << wydania[i].towar2.nazwa << endl;
            cout << PL("\tIloúÊ: ") << wydania[i].towar2.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << wydania[i].towar2.cena << PL("\t\tWartoúÊ: ") << wydania[i].towar2.ilosc * wydania[i].towar2.cena << endl;
        }
        if (wydania[i].towar3.ilosc > 0) {
            cout << "Nazwa: " << wydania[i].towar3.nazwa << endl;
            cout << PL("\tIloúÊ: ") << wydania[i].towar3.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << wydania[i].towar3.cena << PL("\t\tWartoúÊ: ") << wydania[i].towar3.ilosc * wydania[i].towar3.cena << endl;
        }
        if (wydania[i].towar4.ilosc > 0) {
            cout << "Nazwa: " << wydania[i].towar4.nazwa << endl;
            cout << PL("\tIloúÊ: ") << wydania[i].towar4.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << wydania[i].towar4.cena << PL("\t\tWartoúÊ: ") << wydania[i].towar4.ilosc * wydania[i].towar4.cena << endl;
        }
        cout << endl << endl;
        suma += (wydania[i].towar1.ilosc * wydania[i].towar1.cena) + (wydania[i].towar2.ilosc * wydania[i].towar2.cena) + (wydania[i].towar3.ilosc * wydania[i].towar3.cena) + (wydania[i].towar4.ilosc * wydania[i].towar4.cena);
    }
    cout << PL("£πczne zad≥uøenie kontrahentÛw wynosi: ") << fixed << setprecision(2) << suma << PL(" z≥otych") << endl << endl;
    
}

void wyswietl_WZ_kontrahent(vector<WZ>& wydania)
{
    bool b = false;
    string tmp;
    cin.seekg(0, ios::end);
    cin.clear();

    cout << PL("Podaj nazwÍ firmy: ");
    getline(cin, tmp);
    cout << endl;

    for (vector<WZ>::iterator it = wydania.begin(); it < wydania.end(); it++) {
        if (it->nabywca.nazwa.find(tmp) != string::npos) {
            cout << "Numer dokumentu: " << it->numer_dokumentu << endl;

            cout << "Nabywca:" << endl;
            cout << it->nabywca.nazwa << ", NIP: " << it->nabywca.nip << endl;
            cout << it->nabywca.adres1 << ", " << it->nabywca.kod_pocztowy << " " << it->nabywca.miejscowosc << endl;

            cout << PL("Wydany towar:") << endl;
            cout << "Nazwa: " << it->towar1.nazwa << endl;
            cout << PL("\tIloúÊ: ") << it->towar1.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << it->towar1.cena << PL("\t\tWartoúÊ: ") << it->towar1.ilosc * it->towar1.cena << endl;
            if (it->towar2.ilosc > 0) {
                cout << "Nazwa: " << it->towar2.nazwa << endl;
                cout << PL("\tIloúÊ: ") << it->towar2.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << it->towar2.cena << PL("\t\tWartoúÊ: ") << it->towar2.ilosc * it->towar2.cena << endl;
            }
            if (it->towar3.ilosc > 0) {
                cout << "Nazwa: " << it->towar3.nazwa << endl;
                cout << PL("\tIloúÊ: ") << it->towar3.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << it->towar3.cena << PL("\t\tWartoúÊ: ") << it->towar3.ilosc * it->towar3.cena << endl;
            }
            if (it->towar4.ilosc > 0) {
                cout << "Nazwa: " << it->towar4.nazwa << endl;
                cout << PL("\tIloúÊ: ") << it->towar4.ilosc << "\tCena za szt.: " << fixed << setprecision(2) << it->towar4.cena << PL("\t\tWartoúÊ: ") << it->towar4.ilosc * it->towar4.cena << endl;
            }
            cout << endl << endl;
            b = true;
        }
    }

    if (b == false)
        cout << "Nie ma wystawionych WZ dla kontrahenta o podanej nazwie..." << endl << endl;
}