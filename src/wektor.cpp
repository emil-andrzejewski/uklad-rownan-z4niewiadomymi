#include <iostream>
#include <iomanip>
#include <cmath>
#include <wektor.hh>
using namespace std;

/*	ODCZYT

	Umozliwia odczytanie wartosci wektora		*/
void Wektor::Odczyt(float *zm0,float *zm1,float *zm2) const {
  *zm0=(Tab[0]);
  *zm1=(Tab[1]);
  *zm2=(Tab[2]);
}

/*	DAJ
	
	Metoda umozliwia odczytanie danej wartosci wektora

	Jako argument metody nalezy podac nr pozycji wartosci wektora, ktora
	chcemy uzyskac. Nalezy ja podac jako liczbe naturalna zaczynajac liczyc
	od zera
*/
float Wektor::Daj(int pozycja) const {
  return Tab[pozycja];
}

/*	WPISZ

	Metoda umozliwia wpisanie na odpowiedniej pozycji wektora dana wartosc.
	Pozycje nalezy podac jako liczbe naturalna zaczynajac liczyc od zera. */
void Wektor::Wpisz(int pozycja, float liczba) {
  Tab[pozycja]=liczba;
}

/*			+

	Metoda dodawania do siebie wektorow				*/
Wektor Wektor::operator + (const Wektor &Skladnik) const {
  int i;
  Wektor Pom;
  for (i=0;i<ROZMIAR; i++) {
	Pom.Tab[i] = Tab[i]+Skladnik.Tab[i];
  }
  return Pom;
}

/*			-

	Metoda odejmowania od siebie wektorow		*/
Wektor Wektor::operator - (const Wektor &Odjemnik) const {
  int i;
  Wektor Pom;
  for (i=0;i<ROZMIAR; i++) {
	Pom.Tab[i] = Tab[i]-Odjemnik.Tab[i];
  }
  return Pom;
}


/*			*

	Metoda mnożenia wektora przez liczbe */
Wektor Wektor::operator * (const float &liczba) const {
  int i;
  Wektor Pom;
  for (i=0;i<ROZMIAR; i++) {
	Pom.Tab[i] = Tab[i]*liczba;
  }
  return Pom;
}

/*			/

	Metoda dzielenia macierzy przez liczbe		*/
Wektor Wektor::operator / (const float &liczba) const {
  int i;
  Wektor Pom;
  for (i=0;i<ROZMIAR; i++) {
	Pom.Tab[i] = Tab[i]/liczba;
  }
  return Pom;
}


/*  WARTOSC NA KONIEC

    Metoda przesuwa dana wartosc na koniec wektora. Reszta wartoscie jest 
    automatycznie przeszuwana o 1 do przodu. Jako argument nalezy podac 
    nr wartosci, ktora chcemy przesunac na koniec           */
void Wektor::WartNaKoniec(int i) {
  float x;
  x=Tab[i];
  for (i=0;i<ROZMIAR-1;i++)
    Tab[i]=Tab[i+1];
  Tab[ROZMIAR-1]=x;
}

/*  DZIALANIE

    Metoda pozwala odejmowac od podanego wartosci wektora inna wartosc 
    pomnozona przez liczbe. Jako argumenty nalezy podac odpowiednio:
    pozycje wartosci, ktora zmieniamy, 
    pozycje wartosci, ktora bedzie pomnozona przez czynnik
    wartosc czynnika               */
void Wektor::Dzialanie(int i,int j,float czynnik) {
  Tab[j]=Tab[j]-Tab[i]*czynnik;
}

/*  NORMA

    Metoda liczy norme (modul) wektora      */
float Wektor::Norma() const {
  int i;
  float Pom=0;
  for (i=0;i<ROZMIAR;i++)
    Pom+=Tab[i]*Tab[i];
  return sqrt(Pom);
}
