#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	struct sockaddr_in klient;
	unsigned int gniazdo_klienta, port;
	char bufor[100000];
	
	// wyzerowanie przydzielonej pamiêci
	bzero(&servaddr, sizeof(klient));
	
	// IP w wersji 4
	klient.sin_family = AF_INET;
	
	/*
	AF_INET – makro, które mówi o tym, ¿e bêdziemy korzystali z adresów IP 
	w wersji 4.
	AF_INET6 – adresy IP w wersji 6.
	*/
	
	// przypisanie numeru portu
	printf("Proszê podaæ numer portu\n");
	scanf("%u", port);
	
	if(port <= 1023) 
		printf("Nale¿y podaæ numer, który na pewno nie jest zajêty (musi byæ wiêkszy, ni¿ 1023)!\n");
	else
		klient.sin_port = htons(port);
		
	// przypisanie adresu IP
	printf("Proszê podaæ adres IP\n")
	scanf("%s", adres_IP);
	
	if(adres_IP == "127.0.0.1")
		printf("Nie wolno podawaæ adresu localhosta!\n");
	else 
		inet_pton(AF_INET, adres_IP, &klient.sin_addr);
	
	// utworzenie gniazda klienta	
	gniazdo_klienta = socket(AF_INET, SOCK_DGRAM, 0);	
	// 1001 – to przyk³adowa wartoœæ. Nale¿y pamiêtaæ o tym, aby wybraæ wolny port, który nie jest zajêty.
	
	// powi¹zanie struktury klienta z gniazdem klienta
	bind(gniazdo_klienta,(struct sockaddr*) &klient, sizeof(klient));
	
	
	// wys³anie danych do serwera (bez ustawionych flag)
	int wielkosc_danych = sendto(gniazdo_klienta, bufor, strlen(bufor), 0, (struct sockaddr*)&klient, sizeof(klient));
	if(wielkosc_danych <= -1) 
		printf("B³¹d! Nie uda³o siê wys³aæ danych z bufora\n");
	else 
		printf("Pomyœlnie wys³ano dane z bufora\n");
	
	// w przypadku odpowiedzi serwera (bez flag)
	memset(bufor, NULL, sizeof(bufor));
	recvfrom(gniazdo_klienta, bufor, sizeof(bufor), 0, (struct sockaddr*)&serwer, sizeof(serwer));
	
	// dwa sposoby przypisania adresu IP :
	// a) dowolnego adresu wybranego przez system operacyjny:
	//(INADDR_ANY) klient.sin_addr.s_addr = htonl( INADDR_ANY );
	// b) konkretnego adresu
	//inet_pton( AF_INET, "127.0.0.1", & servaddr.sin_addr );

	close(gniazdo_klienta);
	return 0;
}
