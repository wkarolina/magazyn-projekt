#ifndef SuperProgram_head_hpp
#define SuperProgram_head_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <iomanip>


class magazyn;
class PZ;
class WZ;

class kontrahenci
{
public:
	std::string nazwa;
	std::string adres1;
	std::string kod_pocztowy;
	std::string miejscowosc;
	std::string nip;
	float mamy_do_zaplaty = 0;
	float ma_nam_zaplacic = 0;
	kontrahenci(std::string s1 = " ", std::string s2 = " ", std::string s3 = " ", std::string s4 = " ", std::string s5 = " ", float s6 = 0, float s7 = 0)
		: nazwa(s1), adres1(s2), kod_pocztowy(s3), miejscowosc(s4), nip(s5), mamy_do_zaplaty(s6), ma_nam_zaplacic(s7) {}
	kontrahenci(const kontrahenci& wzor)
	{
		this->nazwa = wzor.nazwa;
		this->adres1 = wzor.adres1;
		this->kod_pocztowy = wzor.kod_pocztowy;
		this->miejscowosc = wzor.miejscowosc;
		this->nip = wzor.nip;
		this->mamy_do_zaplaty = wzor.mamy_do_zaplaty;
		this->ma_nam_zaplacic = wzor.ma_nam_zaplacic;
	}
};

bool line_mark(std::fstream& file);
bool any_mark(std::fstream& file);

std::string PL(std::string znak);
char give_mark();
char give_mark4();

void szukaj_nazwa_kontrahent(std::vector<kontrahenci>& firmy);
void szukaj_nip_kontrahent(std::vector<kontrahenci>& firmy);
void szukaj_miejscowosc_kontrahent(std::vector<kontrahenci>& firmy);
void dodaj_kontrahent(std::vector<kontrahenci>& firmy);
void usun_kontrahent(std::vector<kontrahenci>& firmy);
void zmien_kontrahent(std::vector<kontrahenci> & firmy);
void zapisz_od_nowa_kontrahent(std::string &nazwa_file_kontrahenci, std::fstream &file_kontrahenci, std::vector<kontrahenci>& firmy);
void wczytaj_kontrahenci(std::string & nazwa_file_kontrahenci, std::fstream& file_kontrahenci, std::vector<kontrahenci>& firmy);
bool czy_nip_istnieje(std:: string &s5, std::vector<kontrahenci> & firmy);



class magazyn
{
private:
	std::string nazwa;
	int ilosc;
	float cena;
public:
	magazyn(std::string tmp_nazwa = "nie podano", int tmp_ilosc = 0, float tmp_cena = 0)
	: nazwa(tmp_nazwa), ilosc(tmp_ilosc), cena(tmp_cena) {}
	magazyn(const magazyn& wzor)
	{
		this->nazwa = wzor.nazwa;
		this->ilosc = wzor.ilosc;
		this->cena = wzor.cena;
	}
	
	void wyswietl_stan_magazynu(std::vector<magazyn> produkty);
	friend void szukaj_produkt(std::vector<magazyn>& produkty);
	friend bool czy_produkt_istnieje(std::string& s1, std::vector<magazyn>& produkty);
	friend void dodaj_produkt(std::vector<magazyn>& produkty);
	friend void zapisz_nowy_produkt(std::string & nazwa_file_magazyn, std::fstream& file_magazyn, std::vector<magazyn>& produkty);
	friend void usun_produkt(std::vector<magazyn>& produkty);
	friend void zapisz_produkt_od_nowa(std::string & nazwa_file_magazyn, std::fstream& file_magazyn, std::vector<magazyn>& produkty);
	friend void zmien_produkt(std::vector<magazyn>& produkty);

	friend void przyjecie_towaru(std::string& nazwa_file_PZ, std::fstream& file_PZ, std::vector<PZ>& przyjecia, std::vector<kontrahenci>& firmy, std::vector<magazyn>& produkty);
	friend void wczytaj_PZ(std::string & nazwa_file_PZ, std::fstream& file_PZ, std::vector<PZ>& przyjecia);
	friend void zapisz_PZ(std::string & nazwa_file_PZ, std::fstream& file_PZ, std::vector<PZ>& przyjecia);
	friend void wyswietl_PZ_wszystkie(std::vector<PZ>& przyjecia);
	friend void wyswietl_PZ_kontrahent(std::vector<PZ>& przyjecia);

	friend void wydanie_towaru(std::string & nazwa_file_WZ, std::fstream & file_WZ, std::vector<WZ>& wydania, std::vector<kontrahenci>& firmy, std::vector<magazyn>& produkty);
	friend void wczytaj_WZ(std::string & nazwa_file_WZ, std::fstream& file_WZ, std::vector<WZ>& wydania);
	friend void zapisz_WZ(std::string & nazwa_file_WZ, std::fstream& file_WZ, std::vector<WZ>& wydania);
	friend void wyswietl_WZ_wszystkie(std::vector<WZ>& wydania);
	friend void wyswietl_WZ_kontrahent(std::vector<WZ>& wydania);

	friend class PZ;
	friend class WZ;
};

void wczytaj_magazyn(std::string & nazwa_file_magazyn, std::fstream& file_magazyn, std::vector<magazyn>& produkty);


class PZ
{
private:
	kontrahenci dostawca;
	magazyn towar1;
	magazyn towar2;
	magazyn towar3;
	magazyn towar4;
	int numer_dokumentu;
public:
	static int ile;
	PZ(kontrahenci& tmp1, magazyn& mag1, magazyn& mag2, magazyn& mag3, magazyn& mag4, int nd);
	PZ(kontrahenci& tmp1, magazyn& mag1, magazyn& mag2, magazyn& mag3, int nd);
	PZ(kontrahenci& tmp1, magazyn& mag1, magazyn& mag2, int nd);
	PZ(kontrahenci& tmp1, magazyn& mag1, int nd);

	void ile_dokumentow()
	{
		std::cout << this->ile << PL(" dokumentów") << std::endl;
	}

	void wyswietl_PZ();
	friend void zapisz_PZ(std::string & nazwa_file_PZ, std::fstream& file_PZ, std::vector<PZ>& przyjecia);
	friend void wczytaj_PZ(std::string & nazwa_file_PZ, std::fstream& file_PZ, std::vector<PZ>& przyjecia);
	friend void wyswietl_PZ_wszystkie(std::vector<PZ>& przyjecia);
	friend void wyswietl_PZ_kontrahent(std::vector<PZ>& przyjecia);
};

void wczytaj_PZ(std::string &nazwa_file_PZ, std::fstream& file_PZ, std::vector<PZ>& przyjecia);
void przyjecie_towaru(std::string& nazwa_file_PZ, std::fstream& file_PZ, std::vector<PZ>& przyjecia, std::vector<kontrahenci>& firmy, std::vector<magazyn>& produkty);
void zapisz_PZ(std::string & nazwa_file_PZ, std::fstream& file_PZ, std::vector<PZ>& przyjecia);
void wyswietl_PZ_wszystkie(std::vector<PZ>& przyjecia);
void wyswietl_PZ_kontrahent(std::vector<PZ>& przyjecia);



class WZ
{
private:
	kontrahenci nabywca;
	magazyn towar1;
	magazyn towar2;
	magazyn towar3;
	magazyn towar4;
	int numer_dokumentu;
public:
	static int ile;
	WZ(kontrahenci& tmp1, magazyn& mag1, magazyn& mag2, magazyn& mag3, magazyn& mag4, int nd);
	WZ(kontrahenci& tmp1, magazyn& mag1, magazyn& mag2, magazyn& mag3, int nd);
	WZ(kontrahenci& tmp1, magazyn& mag1, magazyn& mag2, int nd);
	WZ(kontrahenci& tmp1, magazyn& mag1, int nd);

	void ile_dokumentow();

	void wyswietl_WZ();
	friend void wczytaj_WZ(std::string & nazwa_file_WZ, std::fstream& file_WZ, std::vector<WZ>& wydania);
	friend void zapisz_WZ(std::string & nazwa_file_WZ, std::fstream& file_WZ, std::vector<WZ>& wydania);
	friend void wyswietl_WZ_wszystkie(std::vector<WZ>& wydania);
	friend void wyswietl_WZ_kontrahent(std::vector<WZ>& wydania);
};

void wydanie_towaru(std::string& nazwa_file_WZ, std::fstream& file_WZ, std::vector<WZ>& wydania, std::vector<kontrahenci>& firmy, std::vector<magazyn>& produkty);
void zapisz_WZ(std::string & nazwa_file_WZ, std::fstream &file_WZ, std::vector<WZ>& wydania);
void wczytaj_WZ(std::string & nazwa_file_WZ, std::fstream& file_WZ, std::vector<WZ>& wydania);
void wyswietl_WZ_wszystkie(std::vector<WZ>& wydania);
void wyswietl_WZ_kontrahent(std::vector<WZ>& wydania);

#endif