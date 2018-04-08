#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <dirent.h>
//#DEFINE MAX 86

//vector<string> uzytkownicy_pobierajacy;		//Ci co moga pobierac!
//vector<string> uzytkownicy_przesylajacy;	//Ci co moga przesy³ac!
//char kod[6] = rand().c_str();
//vector<int> tablica_uwierzytelniajaca;		//S³u¿y ona do dzielenia siê plikami
//char* uzytkownicy_pobierajacy;
//char* uzytkownicy_przesylajacy;
//int* tablica_uwierzytelniajaca;
char klient_pobierajacy_1[17];
char klient_pobierajacy_2[17];
char klient_pobierajacy_3[17];
char klient_pobierajacy_4[17];
char klient_pobierajacy_5[17];
//memset(klient_pobierajacy_1, '\0', 17);
//memset(klient_pobierajacy_2, '\0', 17);
//memset(klient_pobierajacy_3, '\0', 17);
//memset(klient_pobierajacy_4, '\0', 17);
//memset(klient_pobierajacy_5, '\0', 17);

char klient_przesylajacy_1[17];
char klient_przesylajacy_2[17];
char klient_przesylajacy_3[17];
char klient_przesylajacy_4[17];
char klient_przesylajacy_5[17];
//memset(klient_przesylajacy_1, '\0', 17);
//memset(klient_przesylajacy_2, '\0', 17);
//memset(klient_przesylajacy_3, '\0', 17);
//memset(klient_przesylajacy_4, '\0', 17);
//memset(klient_przesylajacy_5, '\0', 17);
//char uzytkownicy_pobierajacy[MAX];
//char uzytkownicy_przesylajacy[MAX];
char kod[] = "maciek";


void podstawowa_obsluga_programu() {
	printf("[1] - Oczekuj na polaczenie\n");
	printf("[2] - Dodaj pliki do pobrania\n");
	printf("[3] - Usun pliki do pobrania\n");
	printf("[4] - Wylistuj katalog\n");						//OK
	printf("[5] - Nadaj uprawnienia do pobierania\n");		//OK
	printf("[6] - Nadaj uprawnienia do przesylania\n");		//OK
	printf("[7] - Odbierz uprawnienia do pobierania\n");	//OK
	printf("[8] - Odbierz uprawnienia do przesylania\n");	//OK
	printf("[9] - Zamknij gniazdo\n");						//OK
	printf("[10] - Zakoncz dzialanie serwera\n");			//OK
	//printf("[11] - Zawies po³¹czenie\n");
	//printf("[12] - W³¹cz obs³ugê wielu u¿ytkowników jednoczeœnie");
}

/*
int funkcje(int &opcja) {
	switch(opcja) {
		case 1:
			//polaczenie();
			break;
		case 2:
			//dodaj_pliki();
			break;
		case 3:
			//usun_pliki();
			break;
		case 4:
			//listuj_pliki();	
			break;
		case 5:
			//odbierz_uprawnienia_do_pobierania();
			break;
		case 6:
			//odbierz_uprawnienia_do_przesylania();
			break;
		case 7:
			//zamknij_gniazdo(gniazdo_serwera);
			break;
		case 8:
			//koniec(gniazdo_serwera);
			break;
		default:
			printf("Wybierz opcjê z dostêpnych poni¿ej.\n");
			// Wylistowanie opcji programu
			podstawowa_obsluga_programu();
			scanf("%d", opcja);
			funkcje(opcja);
			break;
	}
}
*/

/*void usun_tablice_dynamiczne() {
	delete [] uzytkownicy_pobierajacy;
	delete [] uzytkownicy_przesylajacy;
	delete [] tablica_uwierzytelniajaca;
}*/

void listuj_pliki() {
	system("ls\n");
}


int dodaj_pliki() {
	int ilosc;
	int i, j, k, m, n;
	char stara_nazwa[30];
	char nowa_nazwa[30];
	char rozszerzenie[6];
	//memset(nazwa, '\0', 30);
	//memset(rozszerzenie, '\0', 6);
	bzero(stara_nazwa, sizeof(stara_nazwa));
	bzero(nowa_nazwa, sizeof(nowa_nazwa));
	bzero(rozszerzenie, sizeof(rozszerzenie));
	m = 0;
	
	listuj_pliki();
	printf("Ile chcesz dodac plikow do udostepnienia?\n");
	scanf("%d", &ilosc);
	printf("Sizeof: %d", sizeof(kod));
	printf("Length: %d", strlen(kod));
	for(i = 0; i < ilosc; i = i + 1) {
		printf("Podaj pelna nazwe pliku\n");
		//printf("Podaj nazwê pliku (wraz z rozszerzeniem)\n");
		scanf("%s", stara_nazwa);
		strncat(nowa_nazwa, stara_nazwa, sizeof(stara_nazwa));

		for(j = 0; j < strlen(stara_nazwa); j = j + 1) {
			//printf("%d\n", strlen(nazwa));
			if(stara_nazwa[j] == '.') {
				for(k = j; stara_nazwa[k] != '\0'; k = k + 1) {
					rozszerzenie[m] = stara_nazwa[k];
					m = m + 1;
				}
				for(n = j; n < strlen(stara_nazwa); n = n + 1)
					nowa_nazwa[n] = '\0';
			}	 	
		}		
		printf("Wycieta nazwa %s\n", nowa_nazwa);
		strncat(nowa_nazwa, "_", sizeof("_"));
		strncat(nowa_nazwa, kod, sizeof(kod));
		strncat(nowa_nazwa, rozszerzenie, sizeof(rozszerzenie));
		//printf("%s\n", rozszerzenie);	
		//strncat(kod, rozszerzenie, sizeof(rozszerzenie));
		//printf("%s\n", kod);
		//strncat(nazwa)
		printf("Stara nazwa: %s\n", stara_nazwa);
		printf("Nowa nazwa: %s\n", nowa_nazwa);
		rename(stara_nazwa, nowa_nazwa);
		listuj_pliki();
		return 0;
		
		//rename(nazwa, strncat(nazwa, kod, sizeof(kod)));
		//char* n = strncat("mv", nazwa, 30);		
		//system(strncat(n, kod, 30));
		//if(rename(nazwa, strncat(nazwa, kod, 20)) <= -1)
		//	printf("Nie powiod³o siê dodanie pliku\n");
		//else 
		//	printf("Dodano plik\n");	
					
		//strlen(tablica_uwierzytelniajaca);
		//strncat(tablica_uwierzytelniajaca, nazwa, 6);
	}
}


void usun_pliki() {
	int ilosc;
	int i;
	char nazwa[30];
	bzero(nazwa, sizeof(nazwa));
	//memset(nazwa, '\0', 30);
	//plik.clear();
	
	listuj_pliki();
	printf("Ile chcesz usunac plikow do udostepnienia?\n");
	scanf("%d", &ilosc);

	for(i = 0; i < ilosc; i = i + 1) {
		printf("Podaj nazwe pliku (bez kodu)\n");
		//printf("Podaj nazwê pliku (wraz z rozszerzeniem)\n");
		scanf("%s", nazwa);
		//char nazwa[6] = (char*)rand();
		if(rename(strncat(nazwa, kod, 20), nazwa) <= -1)
			printf("Nie powiodlo sie usuniecie pliku\n");
		else
			printf("Usunieto plik\n");
		//strlen(tablica_uwierzytelniajaca);
		//strncat(tablica_uwierzytelniajaca, nazwa, sizeof(nazwa));
	}
	
}

/*
void listuj_pliki() {
	struct dirent* plik;
	DIR* sciezka;
	
	if(sciezka = opendir(".")) {
		while(plik = readdir(sciezka)) {
			puts(plik->d_name);
			closedir(sciezka);
		}	
	}
}
*/


void nadaj_uprawnienia_do_pobierania() {
	int ilosc;
	int i;
	char IP[16];
	bzero(IP, sizeof(IP));
	//memset(IP, '\0', sizeof(IP));
	//IP.clear();
	
	printf("Ilu uzytkownikom chcesz nadac prawa do pobierania plikow z serwera?\n");
	scanf("%d", &ilosc);
	
	for(i = 0; i < ilosc; i = i + 1) {
		printf("Podaj adres IP uzytkownika\n");
		scanf("%s", IP);
		//int dlugosc = sizeof(IP);
		
		if(klient_pobierajacy_1[0] == '\0')
			strncpy(klient_pobierajacy_1, IP, strlen(IP));
		else if(klient_pobierajacy_2[0] == '\0')
			strncpy(klient_pobierajacy_2, IP, strlen(IP));
		else if(klient_pobierajacy_3[0] == '\0')
			strncpy(klient_pobierajacy_3, IP, strlen(IP));
		else if(klient_pobierajacy_4[0] == '\0')
			strncpy(klient_pobierajacy_4, IP, strlen(IP));
		else if(klient_pobierajacy_5[0] == '\0')
			strncpy(klient_pobierajacy_5, IP, strlen(IP));
		// WERSJA Z WEKTOREM
		//uzytkownicy_pobierajacy.push_back(IP);
		//IP.clear();
		
		
		/*
		for(int j = 0; j < MAX - 6; j = j + 1) {
			for(int m = 0; m < dlugosc; m = m + 1) {
				if(uzytkownicy_pobierajacy[j + m] == NULL) {
					if(dlugosc == m - 1)
						
				}	
				else 
					break;	
			}
			
		}
		memset(IP, NULL, sizeof(IP));*/
		/*
		if(strstr(uzytkownicy_pobierajacy, IP) != NULL)
			printf("Ten u¿ytkownik zosta³ ju¿ wczeœniej dodany!\n");			
		else {
			strncat(uzytkownicy_pobierajacy, IP, sizeof(IP));
			printf("Nadano uprawnienia\n");
		}
		}*/
	}
}	


void nadaj_uprawnienia_do_przesylania() {
	int ilosc;
	int i;
	char IP[16];
	bzero(IP, sizeof(IP));
	//memset(IP, '\0', 30);
	//IP.clear();
	
	printf("Ilu uzytkownikom chcesz nadac prawa do przesylania plikow z serwera?\n");
	scanf("%d", &ilosc);
	
	for(i = 0; i < ilosc; i = i + 1) {
		printf("Podaj adres IP uzytkownika\n");
		scanf("%s", IP);
		
		if(klient_przesylajacy_1[0] == '\0')
			strncpy(klient_przesylajacy_1, IP, strlen(IP));	
		else if(klient_przesylajacy_2[0] == '\0')
			strncpy(klient_przesylajacy_2, IP, strlen(IP));
		else if(klient_przesylajacy_3[0] == '\0')
			strncpy(klient_przesylajacy_3, IP, strlen(IP));
		else if(klient_przesylajacy_4[0] == '\0')
			strncpy(klient_przesylajacy_4, IP, strlen(IP));
		else if(klient_przesylajacy_5[0] == '\0')
			strncpy(klient_przesylajacy_5, IP, strlen(IP));
		// WERSJA Z WEKTOREM
		//uzytkownicy_przesylajacy.push_back(IP);
		//IP.clear();
		/*
		if(strstr(uzytkownicy_przesylajacy, IP) != NULL)
			printf("Ten u¿ytkownik zosta³ ju¿ wczeœniej dodany!\n");			
		else {
			strncat(uzytkownicy_przesylajacy, IP, sizeof(IP));
			printf("Nadano uprawnienia\n");
		}*/
	}
	// WERSJA Z WEKTOREM
	//uzytkownicy_przesylajacy.push_back(IP);
	//memset(IP, NULL, sizeof(IP));
}


void odbierz_uprawnienia_do_pobierania() {
	int ilosc;
	int i;
	char IP[16];
	bzero(IP, sizeof(IP));
	//memset(IP, '\0', 16);
	
	printf("Ilu uzytkownikom chcesz odebrac prawa do pobierania plikow z serwera?\n");
	scanf("%d", &ilosc);
	
	for(i = 0; i < ilosc; i = i + 1) {
		printf("Podaj adres IP uzytkownika\n");
		scanf("%s", IP);

		if(strcmp(klient_pobierajacy_1, IP) == 0)
			memset(klient_pobierajacy_1, '\0', 17);
		else if(strcmp(klient_pobierajacy_2, IP) == 0)
			memset(klient_pobierajacy_2, '\0', 17);
		else if(strcmp(klient_pobierajacy_3, IP) == 0)
			memset(klient_pobierajacy_3, '\0', 17);
		else if(strcmp(klient_pobierajacy_4, IP) == 0)
			memset(klient_pobierajacy_4, '\0', 17);
		else if(strcmp(klient_pobierajacy_5, IP) == 0)
			memset(klient_pobierajacy_5, '\0', 17);

		//WERSJA Z WEKTOREM
		//for(int j = 0; j < uzytkownicy_pobierajacy.size(); j = j + 1) {
		//	if(!strcmp(uzytkownicy_pobierajacy[j], IP))
		//		uzytkownicy_pobierajacy.erase(j);
		//}
		//memset(IP, NULL, sizeof(IP));

/*
		char* miejsce = strstr(uzytkownicy_pobierajacy, IP);
		if(char* == NULL)
			printf("Nie znaleziono takiego u¿ytkownika!\n");
		else 
			memset()
			*/
	}
}


void odbierz_uprawnienia_do_przesylania() {
	int ilosc;
	int i;
	char IP[16];
	bzero(IP, sizeof(IP));
	
	printf("Ilu uzytkownikom chcesz odebrac prawa do przesylania plikow z serwera?\n");
	scanf("%u", &ilosc);
	
	for(i = 0; i < ilosc; i = i + 1) {
		printf("Podaj adres IP uzytkownika\n");
		scanf("%s", IP);
		
		if(strcmp(klient_przesylajacy_1, IP) == 0)
			memset(klient_przesylajacy_1, '\0', 17);
		else if(strcmp(klient_przesylajacy_2, IP) == 0)
			memset(klient_przesylajacy_2, '\0', 17);
		else if(strcmp(klient_przesylajacy_3, IP) == 0)
			memset(klient_przesylajacy_3, '\0', 17);
		else if(strcmp(klient_przesylajacy_4, IP) == 0)
			memset(klient_przesylajacy_4, '\0', 17);
		else if(strcmp(klient_przesylajacy_5, IP) == 0)
			memset(klient_przesylajacy_5, '\0', 17);
		
		//WERSJA Z WEKTOREM
		//for(int j = 0; j < uzytkownicy_przesylajacy.size(); j = j + 1) {
		//	if(!strcmp(uzytkownicy_przesylajacy[j], IP))
		//		uzytkownicy_przesylajacy.erase(j);
		//}
		//memset(IP, NULL, sizeof(IP));
	}
}


void zamknij_gniazdo(int* gniazdo_serwera) {
	if(!(*gniazdo_serwera))
		printf("Error! Zadne gniazdo nie istnieje\n");
		//goto OPCJE;
	else {
		close(*gniazdo_serwera);
		printf("Pomyslnie zamknieto gniazdo\n");
		//goto OPCJE;
	}
}


int koniec(int* gniazdo_serwera) {
	if(!(*gniazdo_serwera)) {
		printf("Koniec\n");
		//usun_tablice_dynamiczne();
		return 0;
	}
	else {
		close(*gniazdo_serwera);
		printf("Pomyslnie zamknieto gniazdo\n");
		//usun_tablice_dynamiczne();
		return 0;
	}
}


//void polaczenie() {
//	
//}


int main() 
{
	struct sockaddr_in serwer;
	int gniazdo_serwera, port;
	char adres_IP[16];
	char nadawca_IP[16];
	char bufor[1024];
	// wyzerowanie przydzielonej pamiêci
	//bzero( & serwer, sizeof( serwer ) );
	int opcja;
	//char kod[20];
	//bzero(kod, sizeof(kod));
	//memset(kod, '\0', 20);
	//int* wsk_gs;
	//for(int k = 0; k < 159; k = k + 1) {
	//	uzytkownicy_pobierajacy[k] = '*';
	//}
	
	memset(klient_pobierajacy_1, '\0', 17);
	memset(klient_pobierajacy_2, '\0', 17);
	memset(klient_pobierajacy_3, '\0', 17);
	memset(klient_pobierajacy_4, '\0', 17);
	memset(klient_pobierajacy_5, '\0', 17);

	memset(klient_przesylajacy_1, '\0', 17);
	memset(klient_przesylajacy_2, '\0', 17);
	memset(klient_przesylajacy_3, '\0', 17);
	memset(klient_przesylajacy_4, '\0', 17);
	memset(klient_przesylajacy_5, '\0', 17);

	//char* uzytkownicy_pobierajacy;
	//uzytkownicy_pobierajacy = new char[160];
	//memset(uzytkownicy_pobierajacy, NULL, 160);		//???
	
	//char* uzytkownicy_przesylajacy;
	//uzytkownicy_przesylajacy = new char[160];
	//memset(uzytkownicy_przesylajacy, NULL, 160);	//???
	
	//int* tablica_uwierzytelniajaca;
	//tablica_uwierzytelniajaca = new int[60];
	//memset(tablica_uwierzytelniajaca, NULL, 60);
	
	printf("Witaj w programie obslugujacym podstawowe funkcje serwera :)\n");
	//printf("Podaj kod dla plików\n");
	//scanf("%s", kod);
	
	
	while(1) {
		//OPCJE:
		printf("Wybierz opcje z dostepnych ponizej\n");
		// Wylistowanie opcji programu
		podstawowa_obsluga_programu();
		scanf("%d", &opcja);
		//funkcje(opcja);
		switch(opcja) {
			case 1:
				goto POLACZENIE;
				//polaczenie();
				break;
			case 2:
				dodaj_pliki();
				break;
			case 3:
				usun_pliki();
				break;
			case 4:
				listuj_pliki();	
				break;
			case 5:
				nadaj_uprawnienia_do_pobierania();
				break;
			case 6:
				nadaj_uprawnienia_do_przesylania();
				break;
			case 7:
				odbierz_uprawnienia_do_pobierania();
				break;
			case 8:
				odbierz_uprawnienia_do_przesylania();
				break;
			case 9:
				zamknij_gniazdo(&gniazdo_serwera);
				break;
			case 10:
				koniec(&gniazdo_serwera);
				break;
			default:
				//goto OPCJE;
				break;
		}
	}

	
	POLACZENIE:
	
	// IP w wersji 4
	serwer.sin_family = AF_INET;

	// przypisanie numeru portu
	printf("Prosze podac numer portu\n");
	scanf("%u", &port);
	
	if(port <= 1023) 
		printf("Nalezy podac numer, ktory na pewno nie jest zajety (musi byc wiekszy, niz 1023)!\n");
	else
		serwer.sin_port = htons(port);
	
	// Przyk³adowy adres IP
	//inet_pton(AF_INET, "126.127.128.1", & serwer.sin_addr );
		
	// przypisanie adresu IP
	printf("Prosze podac adres IP\n");
	scanf("%s", adres_IP);
	
	if(strcmp(adres_IP, "127.0.0.1") == 0)
		printf("Nie wolno podawac adresu localhosta!\n");
	else 
		inet_pton(AF_INET, adres_IP, &serwer.sin_addr);
		//serwer.sin_addr = adres_IP;
	
	// Tworzy gniazdo po stronie serwera
	gniazdo_serwera = socket(AF_INET, SOCK_DGRAM, 0);	
	//wsk_gs = &gniazdo_serwera;
	
	// 1001 – to przyk³adowa wartoœæ. Nale¿y pamiêtaæ o tym, aby wybraæ wolny port, który nie jest zajêty.
	
	// dwa sposoby przypisania adresu IP :
	// a) dowolnego adresu wybranego przez system operacyjny:
	//( INADDR_ANY ) serwer.sin_addr.s_addr = htonl( INADDR_ANY );
	// b) konkretnego adresu
	
	// Nadawanie IP
	//printf("Proszê nadaæ adres IP (w systemie dziesi¹tkowym)\n");
	//scanf(%s, adres_IP)
	//inet_pton(AF_INET, adres_IP, & serwer.sin_addr );
	// Je¿eli adres IP nie bêdzie o cal³kowitej mo¿liwej d³ugosci to wype³nia pozosta³¹ czesc NULL'ami
	//if(strlen(adres_IP) <  15) {
	//	for( int i = strlen(adres_IP) + 1; i <= 15; i++) {
	//		adres_IP[i] = NULL;
	//	}
	//}
	
	// Tworzy powi¹zanie z gniazdem
	//int powiazanie = bind(gniazdo_serwerowe, (struct sockaddr*)&serwer, sizeof(serwer));
	if(bind(gniazdo_serwera, (struct sockaddr*)&serwer, sizeof(serwer)))
		printf("Error! Nie mozna powiazac gniazda\n");
	else
		printf("Podlaczono gniazdo do serwera\n");
			
	//ssize_t sendto(int sockfd, const void * buf, size_t len, int flags, const struct sockaddr * dest_addr, socklen_t addrlen );
	//ssize_t recvfrom( int sockfd, void * buf, size_t len, int flags, struct sockaddr * src_addr, socklen_t * addrlen );
	
	
	
	
	// OBS£UGA ¯¥DAÑ KLIENTÓW****************************************************
	
	while(1)	{
		// Na razie tylko 1 klient
		struct sockaddr_in klient;
		bzero(&klient, sizeof(klient));
		bzero(bufor, sizeof(bufor));
		
		// ¯¹dania wysy³ane przez u¿ytkowników (dotycz¹ce nadaawania uprawnieñ)
		//recvfrom(gniazdo_serwera, bufor, sizeof(bufor), MSG_OOB, struct sockaddr * src_addr, socklen_t * addrlen )
		
		printf("Czekaj na polaczenie\n");

		ssize_t len = sizeof(klient);
        	//recvfrom (sd, buf, sizeof (buf), 0, (struct sockaddr *) &caddr, &len);
		
		ssize_t wielkosc_danych = recvfrom(gniazdo_serwera, bufor, sizeof(bufor), 0, (struct sockaddr*) &klient, &len);
		if(wielkosc_danych < 0)
			printf("Error! Nie udalo sie niczego odebrac\n");
		else
			printf("Udalo sie odebrac %d bajtow :D", wielkosc_danych);
		/*
		if(1 and 2) printf ("Klient prosi o uprawnienia do pobierania i przesy³ania plików");	
		else if(1) printf("Klient prosi o uprawnienie do pobierania plików");
		else if(2) printf("Klient prosi o uprawnienie do przesy³ania plików");
		*/		
 
		// Otrzymujemy adres IP nadawcy (wy³¹czono w celach testowych)
		//inet_ntop(AF_INET, &klient.sin_addr, nadawca_IP, sizeof(nadawca_IP));
	}
	
	// zamyka gniazdo
	close(gniazdo_serwera);
	// zwalnia obszar przydzielony tablicom
	//usun_tablice_dynamiczne();
	return 0;
}


