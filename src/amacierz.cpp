#include <amacierz.hh>

using namespace std;



/*	PRZEPISZ DO KOLUMN

	Metoda przepisuje wartosci z wierszy w odpowienie miejsca kolumn macierzy*/
void AMacierz::PrzepiszDoKol() {
  int i,j;
  for (i=0;i<ROZMIAR;i++) {
	for (j=0;j<ROZMIAR;j++) {
	  Kol[i].Wpisz(j,Wrsz[j].Daj(i));		// Przepisuje wartosci z wierszy
	}										// do kolumn
  }
}



/*  PRZEPISZ DO WIERSZY

    Metoda przepisuj wartosci z kolumn w odpowieni miejsca wierszy macierzy*/
void AMacierz::PrzepiszDoWrsz() {
  int i,j;
  for (i=0;i<ROZMIAR;i++) {
	for (j=0;j<ROZMIAR;j++) {
	  Wrsz[i].Wpisz(j,Kol[j].Daj(i));		// Przepisuje wartosci z wierszy
	}										// do kolumn
  }
}



/*	WCZYTAJ

	Metoda wczytuje wartosci do macierzy A		*/
void AMacierz::Wczytaj() {
  cin >> Wrsz[0];
  cin >> Wrsz[1];
  cin >> Wrsz[2];
  PrzepiszDoKol();
}



/*	DAJ

	Metoda umozliwia odczytanie danej wartosci macierzy.
	Jako argument metody nalezy podac kombinacje cyfr naturalnych liczonych
	od zera		*/
float AMacierz::Daj(int i, int j) const {
  return Wrsz[i].Daj(j);
}



/*	POKAZ

	Metoda pokazuje rownanie na wyjsciu.
	Jako argument metody nalezy podac nr wiersza. Nr wiersza przybiera 
	postac liczby naturalnej liczonej od zera			*/
void AMacierz::Pokaz(int i) const {
  cout<<Daj(i,0)<<showpos<<"*x1"<<Daj(i,1)<<"*x2"<<Daj(i,2)<<"*x3 = ";
  cout<< noshowpos;
}



/*	DET

	Metoda wylicza wyznacznik macierzy 3-wymiarowej	wg wzoru SARRUSA	*/
/*float AMacierz::Det() const {
  float Odjemna=0, Odjemnik=0;
  Odjemna=Daj(0,0)*Daj(1,1)*Daj(2,2) + Daj(0,1)*Daj(1,2)*Daj(2,0) +
		  Daj(0,2)*Daj(1,0)*Daj(2,1);
  Odjemnik=Daj(2,0)*Daj(1,1)*Daj(0,2) + Daj(2,1)*Daj(1,2)*Daj(0,0) +
		   Daj(2,2)*Daj(1,0)*Daj(0,1);	
  return Odjemna-Odjemnik;
} */      



/*	TROJKATNA GORNA

	Metoda zmienia macierz na macierz trojkatna gorna		*/
void AMacierz::TrojGorna() {
  int i, j;    // licznik zlicza cykle, zeby okreslic czy det A==0?
  float czynnik;		// Tu wpisywane beda wartosci macierzy z przekatnej
  PrzepiszDoWrsz();
  for (i=0;i<ROZMIAR;i++) {
	for (j=i+1;j<ROZMIAR;j++) {
	  czynnik=Daj(j,i)/Daj(i,i); // okresla wartosc czynnika
	  Wrsz[j]=Wrsz[j]-Wrsz[i]*czynnik;
    }
  }
  PrzepiszDoKol();              // Przepisuje wartosci do kolumn
}



/*  DZIALANIE

    Metoda pozwala odejmowac od podanego wiersza inny wiersz pomnozony
    przez liczbe. Jako argumenty nalezy podac odpowiednio:
    nr wiersza, ktory zmieniamy, 
    nr wiersza, ktory bedzie pomnozony przez czynnik
    wartosc czynnika               */
void AMacierz::Dzialanie(int i, int j, float czynnik) {
  Wrsz[j]=Wrsz[j]-Wrsz[i]*czynnik;
}



/*  WIERSZ NA KONIEC

    Metoda wyrzuca dany wiersz na koniec wszystkich wierszy, automatycznie
    przesuwajac pozostale wiersze o jeden do gory. Jako argument nalezy podac
    nr wiersza, ktory chcemy wyrzucic na koniec.        */
void AMacierz::WrszNaKoniec(int i) {
  Wektor Pom;
  Pom=Wrsz[i];
  for (i=0;i<ROZMIAR-1;i++)
    Wrsz[i]=Wrsz[i+1];
  Wrsz[ROZMIAR-1]=Pom;
}



/*  DAJ DET

    Metoda wydaje na zewnatrz wartosc wyznacznika   */
int AMacierz::DajDet() const {
  return DetRozny0;
}



/*  DET

    Wprowadzenie wartosci wyznacznika       */
void AMacierz::Det(bool wartosc) {
  DetRozny0=wartosc;
}



/*      *

    Przeciazenie operatora "*". Metoda mnozy podana macierz przez wektor
    i zwraca rowniez wektor             */
Wektor AMacierz::operator * (const Wektor &B) const {
  int i, j;
  float Pom;
  Wektor Wynik;
  for (i=0;i<ROZMIAR;i++) {
    Pom=0;
    for (j=0;j<ROZMIAR;j++) {
      Pom+=Daj(i,j)*B.Daj(j);
    }
    Wynik.Wpisz(i,Pom);
  }
  return Wynik;
}
