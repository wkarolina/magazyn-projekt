#include "SuperProgram_head.hpp"

using namespace std;

class logs
{
private:
	string login;
	string password;
public:
	logs(string &login_tmp, string &password_tmp);
	friend bool check_logs(string& tmp1, string& tmp2, vector<logs>& users);
	friend string newlogin(vector<logs>& users);
	friend string newpassword(vector<logs>& users);
	friend bool search(string& login_tmp, vector<logs>& users);
	friend void file_save(fstream& file, vector<logs>& users);
	friend void rejestracja(string& nazwa_file_logs, vector<logs>& users, fstream& file_logs);
	friend void logowanie(string& nazwa_file_logs, char mark01, vector<logs>& users, fstream& file_logs);
};
logs::logs(string &login_tmp, string &password_tmp)
: login(login_tmp), password(password_tmp) {}


char give_mark();
char give_mark1();
char give_mark2();
char give_mark3();


bool check_logs(string &tmp1, string &tmp2, vector<logs>& users);
bool search_marks(string &tmp2);
string newlogin(vector<logs>& users);
string newpassword(vector<logs>& users);
void file_save(fstream &file, vector<logs>& users);
void rejestracja(string& nazwa_file_logs, vector<logs>& users, fstream& file_logs);
void logowanie(string& nazwa_file_logs, char mark01, vector<logs>& users, fstream& file_logs);



int main()
{
	vector<logs> users;
	string tmp1 = "", tmp2 = "";
	string nazwa_file_logs = "plik_logowanie.txt";//"C:/Users/micha/Desktop/zadania/SuperProgram.3.0/pliki_tekst/plik_logowanie.txt";
	
	fstream file_logs;
	file_logs.open(nazwa_file_logs.c_str(), ios::in);

	if (!file_logs.good()) {
		cout << PL("Nie udało się otworzyć pliku. Sprawdź adres! Kończę pracę programu!") << endl;
		return 0;
	}
	else {
		while (!file_logs.eof()) {
			do {
				file_logs >> tmp1;
				file_logs >> tmp2;
				users.push_back({ tmp1, tmp2 });
			} while (line_mark(file_logs) && any_mark(file_logs));
		}
		file_logs.close();
	}
	

	vector<kontrahenci> firmy;
	string nazwa_file_kontrahenci = "plik_baza_kontrahentow.txt";//"C:/Users/micha/Desktop/zadania/SuperProgram.3.0/pliki_tekst/plik_baza_kontrahentow.txt";
	fstream file_kontrahenci;
	wczytaj_kontrahenci(nazwa_file_kontrahenci, file_kontrahenci, firmy);

	vector<magazyn> produkty;
	string nazwa_file_magazyn = "plik_produkty.txt";//"C:/Users/micha/Desktop/zadania/SuperProgram.3.0/pliki_tekst/plik_produkty.txt";
	fstream file_magazyn;
	wczytaj_magazyn(nazwa_file_magazyn, file_magazyn, produkty);

	vector<PZ> przyjecia;
	string nazwa_file_PZ = "plik_PZ.txt";//"C:/Users/micha/Desktop/zadania/SuperProgram.3.0/pliki_tekst/plik_PZ.txt";
	fstream file_PZ;
	wczytaj_PZ(nazwa_file_PZ, file_PZ, przyjecia);

	vector<WZ> wydania;
	string nazwa_file_WZ = "plik_WZ.txt";//"C:/Users/micha/Desktop/zadania/SuperProgram.3.0/pliki_tekst/plik_WZ.txt";
	fstream file_WZ;
	wczytaj_WZ(nazwa_file_WZ, file_WZ, wydania);


	cout << "Witaj!\n";
	cout << PL("Aby uzyskać dostęp do pełnych danych trzeba się zalogować!") << endl;
	cout << PL("Jeśli nie masz swojego konta - stwórz nowe - zuuuuupełnie darmowe!") << endl << endl;
	cout << PL("[1] - Zaloguj sie") << endl;
	cout << PL("[2] - Zarejestruj się") << endl;
	cout << PL("[0] - Zakończ") << endl;

	char mark01;
	mark01 = give_mark();
	switch (mark01) {
		case '1': {
			cout << endl;
			logowanie(nazwa_file_logs, mark01, users, file_logs);
			break;
		}
		case '2': {
			cout << endl;
			rejestracja(nazwa_file_logs, users, file_logs);
			cout << endl << PL("Teraz możesz się zalogować") << endl;
			logowanie(nazwa_file_logs, mark01, users, file_logs);
			break;
		}
		case '0': {
			cout << PL("Kończę program!") << endl;
			return 0;
			break;
		}
	}
	
	system("cls");
	cout << "Zalogowano:)" << endl << endl;
	cout << PL("Witaj w naszym znakomitym systemie magazynowym SuperProgram.3.0!") << endl;
	Sleep(1200);

	do {
		system("cls");
		cout << endl << PL("[1] - Przyjęcie towaru") << endl;
		cout << "[2] - Wydanie towaru" << endl;
		cout << "[3] - Stan magazynu" << endl;
		cout << PL("[4] - Baza kontrahentów") << endl;
		cout << PL("[0] - Zakończ program") << endl << endl;

		mark01 = give_mark2();
		switch (mark01) {
			case '1': {
				cout << PL("Przyjęcie towarów do magazynu") << endl;
				char mark05;

				do {
					system("cls");
					cout << endl << PL("[1] - Przyjmuję towar") << endl;
					cout << PL("[2] - Wyświetl dokumenty PZ") << endl;
					cout << PL("[0] - Powrót") << endl << endl;

					mark05 = give_mark();
					switch (mark05) {
						case '1': {
							przyjecie_towaru(nazwa_file_PZ, file_PZ, przyjecia, firmy, produkty);
							zapisz_produkt_od_nowa(nazwa_file_magazyn, file_magazyn, produkty);
							zapisz_od_nowa_kontrahent(nazwa_file_kontrahenci, file_kontrahenci, firmy);
							system("PAUSE");
							break;
						}
						case '2': {
							char mark06;

							do {
								system("cls");
								cout << endl << "Dokumenty PZ" << endl;
								cout << PL("[1] - Wyświetl wszystkie - "); przyjecia[0].ile_dokumentow();
								cout << PL("[2] - Wyświetl dla kontrahenta") << endl;
								cout << PL("[0] - Powrót") << endl << endl;
								mark06 = give_mark();
								switch (mark06) {
									case '1': {
										wyswietl_PZ_wszystkie(przyjecia);
										system("PAUSE");
										break;
									}
									case '2': {
										wyswietl_PZ_kontrahent(przyjecia);
										system("PAUSE");
										break;
									}
									case '0': {
										break;
									}
								}
							} while (mark06 != '0');
	
							break;
						}
						case '0': {
							break;
						}
					}	
				} while (mark05 != '0');
	
				break;
				}
			case '2': {
				cout << PL("Wydanie towarów z magazynu") << endl;
				char mark05;

				do {
					system("cls");
					cout << endl << PL("[1] - Wydaję towar") << endl;
					cout << PL("[2] - Wyświetl dokumenty WZ") << endl;
					cout << PL("[0] - Powrót") << endl << endl;

					mark05 = give_mark();
					switch (mark05) {
					case '1': {
						wydanie_towaru(nazwa_file_WZ, file_WZ, wydania, firmy, produkty);
						zapisz_produkt_od_nowa(nazwa_file_magazyn, file_magazyn, produkty);
						zapisz_od_nowa_kontrahent(nazwa_file_kontrahenci, file_kontrahenci, firmy);
						system("PAUSE");
						break;
					}
					case '2': {
						char mark06;

						do {
							system("cls");
							cout << endl << "Dokumenty WZ" << endl;
							cout << PL("[1] - Wyświetl wszystkie - "); wydania[0].ile_dokumentow();
							cout << PL("[2] - Wyświetl dla kontrahenta") << endl;
							cout << PL("[0] - Powrót") << endl << endl;
							mark06 = give_mark();
							switch (mark06) {
							case '1': {
								wyswietl_WZ_wszystkie(wydania);
								system("PAUSE");
								break;
							}
							case '2': {
								wyswietl_WZ_kontrahent(wydania);
								system("PAUSE");
								break;
							}
							case '0': {
								break;
							}
							}
						} while (mark06 != '0');

						break;
					}
					case '0': {
						break;
					}
					}
				} while (mark05 != '0');

				break;
			}
			case '3': {
				produkty.clear();
				wczytaj_magazyn(nazwa_file_magazyn, file_magazyn, produkty);

				char mark02;
				do {
					system("cls");
					cout << endl << PL("Baza produktów") << endl;
					cout << PL("[1] - Wyświetl produkty na magazynie") << endl;
					cout << "[2] - Wyszukaj produkt" << endl;
					cout << "[3] - Dodaj nowy produkt" << endl;
					cout << PL("[4] - Usuń produkt") << endl;
					cout << PL("[5] - Zmień cenę produktu") << endl;
					cout << PL("[0] - Powrót") << endl << endl;

					mark02 = give_mark3();
					switch (mark02) {
						case '1': {
							produkty[0].wyswietl_stan_magazynu(produkty);
							system("PAUSE");
							break;
						}
						case '2': {
							szukaj_produkt(produkty);
							system("PAUSE");
							break;
						}
						case '3': {
							dodaj_produkt(produkty);
							zapisz_nowy_produkt(nazwa_file_magazyn, file_magazyn, produkty);
							system("PAUSE");
							break;
						}
						case '4': {
							usun_produkt(produkty);
							zapisz_produkt_od_nowa(nazwa_file_magazyn, file_magazyn, produkty);
							system("PAUSE");
							break;
						}
						case '5': {
							zmien_produkt(produkty);
							zapisz_produkt_od_nowa(nazwa_file_magazyn, file_magazyn, produkty);
							system("PAUSE");
							break;
						}
						case '0': {
							break;
						}
					}
				} while (mark02 != '0');

				break;
			}
			case '4': {
				firmy.clear();
				wczytaj_kontrahenci(nazwa_file_kontrahenci, file_kontrahenci, firmy);

					char mark02;
					do {
						system("cls");
						cout << endl << PL("Baza kontrahentów") << endl;
						cout << PL("[1] - Wyświetl kontrahentów") << endl;
						cout << "[2] - Wyszukaj kontrahenta" << endl;
						cout << "[3] - Dodaj kontrahenta" << endl;
						cout << PL("[4] - Usuń kontrahenta") << endl;
						cout << PL("[5] - Zmień dane kontrahenta") << endl;
						cout << PL("[0] - Powrót") << endl << endl;

						mark02 = give_mark3();
						switch (mark02) {
							case '1': {
								for (int i = 0; i < firmy.size(); i++) {
									cout << i + 1 << ". " << firmy[i].nazwa << ", " << firmy[i].adres1 << ", " << firmy[i].kod_pocztowy << " " << firmy[i].miejscowosc << ", NIP: " << firmy[i].nip << endl;
									cout << PL("Nasze zobowiązania wobec kontrahenta: ") << fixed << setprecision(2) << firmy[i].mamy_do_zaplaty << PL(" złotych") << endl;
									cout << PL("Kontrahent ma nam do zapłaty: ") << fixed << setprecision(2) << firmy[i].ma_nam_zaplacic << PL(" złotych") << endl << endl;
								}
									
								system("PAUSE");
								break;
							}
							case '2': {
								char mark03;
								string tmp;
								do {
									system("cls");
									cout << endl << PL("Po czym szukać?") << endl;
									cout << "[1] - Szukaj po nazwie" << endl;
									cout << "[2] - Szukaj po numerze NIP" << endl;
									cout << PL("[3] - Szukaj w miejscowości") << endl;
									cout << PL("[0] - Powrót") << endl;

									mark03 = give_mark1();
									switch (mark03) {
										case '1': {
											szukaj_nazwa_kontrahent(firmy);
											system("PAUSE");
											break;
										}
										case '2': {
											szukaj_nip_kontrahent(firmy);
											system("PAUSE");
											break;
										}
										case '3': {
											szukaj_miejscowosc_kontrahent(firmy);
											system("PAUSE");
											break;
										}
										case '0': {
											break;
										}
									}
								} while (mark03 != '0');
								break;
							}
							case '3': {
								dodaj_kontrahent(firmy);
								
								file_kontrahenci.open(nazwa_file_kontrahenci.c_str(), ios::out | ios::app);

								if (!file_kontrahenci.good()) {
									cout << PL("Nie udało się zapisać nowego kontrahenta. Sprawdź plik! Kończę pracę programu!") << endl;
									exit(0);
								}
								else {
									file_kontrahenci << '\n' << firmy[firmy.size() - 1].nazwa << '\n';
									file_kontrahenci << firmy[firmy.size() - 1].adres1 << '\n';
									file_kontrahenci << firmy[firmy.size() - 1].kod_pocztowy << '\n';
									file_kontrahenci << firmy[firmy.size() - 1].miejscowosc << '\n';
									file_kontrahenci << firmy[firmy.size() - 1].nip;
									cout << endl << PL("Nowy kontrahent został zapisany!") << endl;
								}
									
								file_kontrahenci.close();
								system("PAUSE");
								break;
							}
							case '4': {
								usun_kontrahent(firmy);
								zapisz_od_nowa_kontrahent(nazwa_file_kontrahenci, file_kontrahenci, firmy);
								system("PAUSE");
								break;
							}
							case '5': {
								zmien_kontrahent(firmy);
								zapisz_od_nowa_kontrahent(nazwa_file_kontrahenci, file_kontrahenci, firmy);
								system("PAUSE");
								break;
							}
							case '0': {
								break;
							}
						}
					} while (mark02 != '0');
			
				break;
			}
			case '0': {
				cout << PL("Kończę program!") << endl;
				return 0;
				break;
			}
		}
	} while (mark01 != '0');

	return 0;
}



char give_mark()
{
	char a;
	do {
		a = _getch();
		if (a != '1' && a != '2' && a != '0')
			cout << PL("Spróbuj ponownie!") << endl;
	} while (a != '1' && a != '2' && a != '0');
	return a;
}

char give_mark1()			
{
	char a;
	do {
		a = _getch();
		if (a != '1' && a != '2' && a != '3' && a != '0')
			cout << PL("Spróbuj ponownie!") << endl;
	} while (a != '1' && a != '2' && a != '3' && a != '0');
	return a;
}

char give_mark2()
{
	char a;
	do {
		a = _getch();
		if (a != '1' && a != '2' && a != '3' && a != '4' && a != '0')
			cout << PL("Spróbuj ponownie!") << endl;
	} while (a != '1' && a != '2' && a != '3' && a != '4' && a != '0');
	return a;
}

char give_mark3()
{
	char a;
	do {
		a = _getch();
		if (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '0')
			cout << PL("Spróbuj ponownie!") << endl;
	} while (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '0');
	return a;
}

char give_mark4()
{
	char a;
	do {
		a = _getch();
		if (a != '1' && a != '0')
			cout << PL("Spróbuj ponownie!") << endl;
	} while (a != '1' && a != '0');
	return a;
}

bool check_logs(string& tmp1, string& tmp2, vector<logs>& users)
{
	for (int i = 0; i < users.size(); i++) {
		if (tmp1 == users[i].login && tmp2 == users[i].password)
			return true;
	}
	return false;
}

bool search(string& login_tmp, vector<logs>& users)
{
	for (int i = 0; i < users.size(); i++) {
		if (login_tmp == users[i].login)
			return false;
	}
	return true;
}

bool search_marks(string& tmp2)
{
	size_t mark1 = tmp2.find(" ");
	if (mark1 != string::npos)
		return false;
	else
		return true;
}

string newlogin(vector<logs>& users)
{
	bool b, c;
	string temp;
	cin.clear();
	do {
		getline(cin, temp);
		b = search(temp, users);
		c = search_marks(temp);
		if (!b)
			cout << PL("Wprowadzony login już istnieje, spróbuj ponownie") << endl;
		if (c == false)
			cout << PL("Podany login nie może zawierać spacji, spróbuj ponownie") << endl;
	} while (!b || c == false);
	return temp;
}

string newpassword(vector<logs>& users)
{
	bool b;
	string temp;
	cin.clear();
	do {
		getline(cin, temp);
		b = search_marks(temp);
		if (b == false)
			cout << PL("Podane hasło nie może zawierać spacji, spróbuj ponownie") << endl;
	} while (b == false);
	return temp;
}

void file_save(fstream& file, vector<logs>& users)
{
		file << '\n' << users[users.size() - 1].login << '\t';
		file << users[users.size() - 1].password;
}

void rejestracja(string & nazwa_file_logs, vector<logs>& users, fstream& file_logs)
{
	string tmp1, tmp2;
	cin.clear();
	cout << "Podaj nowy login: ";
	tmp1 = newlogin(users);
	cout << PL("Podaj nowe hasło: ");
	tmp2 = newpassword(users);

	users.push_back({ tmp1, tmp2 });
	cout << PL("Nowy użytkownik został utworzony!") << endl;

	file_logs.open(nazwa_file_logs.c_str(), ios::out | ios::app);

	if (!file_logs.good()) {
		cout << PL("Nie udało się otworzyć pliku. Sprawdź adres! Kończę pracę programu!") << endl;
		exit(0);
	}
	else
		file_save(file_logs, users);

	file_logs.close();
}

void logowanie(string& nazwa_file_logs, char mark01, vector<logs>& users, fstream& file_logs)
{
	string tmp1, tmp2;
	int counter = 0, attempt = 3;
	bool b;
	cin.clear();
	do {
		cout << "Podaj login: ";
		getline(cin, tmp1);
		cout << PL("Podaj hasło: ");
		getline(cin, tmp2);
		b = check_logs(tmp1, tmp2, users);
		if (b == false) {
			counter++;
			if (counter == attempt) {
				cout << PL("Osiągnięto liczbę prób! Kończę program!") << endl;
				exit(0);
			}
			cout << PL("Podany login lub hasło nie istnieje, pozostało prób: ") << attempt - counter << endl;
			cout << PL("[1] - Próbuję dalej") << endl;
			cout << PL("[2] - Chcę stworzyć nowe konto") << endl;
			cout << PL("[0] - Zakończ program") << endl;
			mark01 = give_mark();
			switch (mark01) {
				case '1': {
					break;
				}
				case '2': {
					rejestracja(nazwa_file_logs, users, file_logs);
					break;
				}
				case '0': {
					cout << PL("Kończę program!") << endl;
					exit(0);
					break;
				}
			}
		}
	} while (b == false);
}