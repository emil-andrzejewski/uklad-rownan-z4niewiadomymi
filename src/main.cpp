/*  Nad programem pracowal: Emil Andrzejewski	
	Nr indeksu: 180392

	UWAGA !!!
	W programie uzywalem tabulatorow o rozmiarze: 4							*/


#include <iostream>
#include <wektor.hh>
#include <amacierz.hh>

using namespace std;


void TrojGorna(AMacierz &A,Wektor &B);
void Wylicz(AMacierz &A,Wektor &B,Wektor &Wyniki);
void Menu();
void AOpcja(AMacierz &A,AMacierz &KopiaA);
void BOpcja(Wektor &B,Wektor &KopiaB);
void POpcja(AMacierz &A,Wektor &B);
void ROpcja(AMacierz &A,Wektor &B,Wektor &Wynik,AMacierz &KopiaA,
                                                            Wektor &KopiaB);


/*	Umozliwia wczytanie wektora ze strumienia wejscia
	
	Parametry:
	  StrmWej - strumien wejsciowy, z ktorego bedzie wczytany wektor
	  StrmWyj - do niego bedzie wczytany wektor ze strumienia wejsciowego
	
	Warunki koncowe:
	  StrmWyj - zawiera wczytany wektor pod warunkiem,ze ze strumienia zostaly
		wczytane trzy liczby typu float, jak np.: (1.2 22 -3.4). W przeciwnym
		wypadku dzialanie programu zostanie przerwane z komunikatem bledu

	Zwracane wartosci:
	  Referencja do strumienia, na ktorym zostala wykonana operacja odczytu
	  wektora.
*/
istream & operator >> (istream & StrmWej, Wektor & StrmWyj) {
  float zm0, zm1, zm2;
  StrmWej >> zm0;
  StrmWej >> zm1;
  StrmWej >> zm2;
  StrmWyj = Wektor(zm0,zm1,zm2);
  return StrmWej;
}



/* Umozliwia wypisanie symbolu do strumienia wyjscia.

	Parametry:
  	  StrmWyj - Strumien wyjsciowy, do ktorego ma byc wyczytany wektor
	  Wyczyt - z niej ma byc czytany wektor do strumienia wyjsciowego

	Zwracane wartosci:
	  Refernecja do strumienia, na ktorym wykonana zostala
	  operacja wypisu symobolu
*/
ostream & operator << (ostream & StrmWyj,const Wektor & Wyczyt) {
  float zm0, zm1, zm2;
  Wyczyt.Odczyt(&zm0,&zm1,&zm2); // odczytanie wartosci wektora
  cout << zm0 << " " << zm1 << " " << zm2 << endl;
  return StrmWyj;
}



/*	TROJKATNA GORNA

	Metoda zmienia macierz na macierz trojkatna GORNA. Gdy potrzeba
    zmienia rowniez pozycje wartosci w wektorze wyrazow wolnych 		*/
void TrojGorna(AMacierz &A,Wektor &B) {
  int i, j, licznik;    // licznik zlicza cykle, zeby okreslic czy det A==0?
  float czynnik;		// Tu wpisywane beda wartosci macierzy z przekatnej
  A.PrzepiszDoWrsz();
  A.Det(true);             // Zakladam, ze wyznacznik rozny od 0
  for (i=0;i<ROZMIAR;i++) {
	for (j=i+1;j<ROZMIAR;j++) {
      licznik=0;
      while (A.Daj(i,i)==0) { // Gdy wartosc dzielnika wynosi 0 to przesuwamy
        A.WrszNaKoniec(i);    // wiersze oraz wartosci wyrazow wolnych 
        B.WartNaKoniec(i);    // na koniec
        licznik++;
        if (licznik==ROZMIAR) {
          A.Det(false);     // Zmienia wyznacznik macierzy na false
          break;
        }
      }
	  czynnik=A.Daj(j,i)/A.Daj(i,i); // okresla wartosc czynnika
      A.Dzialanie(i,j,czynnik);
      B.Dzialanie(i,j,czynnik);
    }
  }
  A.PrzepiszDoKol(); 
}



/*  WYLICZ

    Funkcja rozwiazuje podane rownanie, podaje wynik, oraz blad rozwiazania */
void Wylicz(AMacierz &A,Wektor &B,Wektor &Wyniki) {
  int i, j;
  float Wynik,Posredni;
  for (i=ROZMIAR-1;i>=0;i--) {
    Posredni=0;
    for (j=i+1;j<ROZMIAR;j++) 
    // Tu zawarta jest suma wartosci wynikow wiadomych pomnozonych
    // przez odpowiednie wartosci macierzy
      Posredni += A.Daj(i,j) * Wyniki.Daj(j);  
    Wynik=(B.Daj(i)-Posredni)/A.Daj(i,i);
    Wyniki.Wpisz(i,Wynik);
  }
}



//  MENU
void Menu() {
  cout << endl<< " Rozwiazywane rownanie:  Ax = b " << endl<< endl;
  cout<<" Uwaga!"<<endl<<" Program radzi sobie rowniez w sytuacji, gdy"<<endl;
  cout << " w czasie wyznaczania macierzy trojkatnej na " << endl;
  cout << " przekatnej pojawia sie zera" << endl<< endl;
  cout << " a - wczytaj macierz wspolczynnikow A" << endl;
  cout << " b - wczytaj wektor wyrazow wolnych b" << endl;
  cout << " p - pokaz rownanie" << endl;
  cout << " r - rozwiaz, pokaz wynik i blad" << endl;
  cout << " ? - ponowne wyswietlenie menu" << endl;
  cout << " q - wyjscie z programu" << endl;

}



//	Opcja "a"
void AOpcja(AMacierz &A,AMacierz &KopiaA) {
  cout << " Wprowadz wspolczynniki macierzy ukladu rownan." << endl;
  cout << " Nalezy je podac w kolejnosci: A_11 A_12 A_13 A_21 itd." << endl;
  cout << "    A_11 A_12 A_13" << endl<<"    A_21 A_22 A_23" << endl;
  cout << "    A_31 A_32 A_33" << endl<< endl;
  A.Wczytaj();
  KopiaA=A;
}
	
//	Opcja "b"
void BOpcja(Wektor &B,Wektor &KopiaB) {
  cout << " Wprowadz wspolczynniki wektora wyrazow wolnych." << endl;
  cout << " Nalezy je podac w kolejnosci: b_1 b_2 b_3" << endl;
  cin >> B;
  KopiaB=B;
}



//	Opcja "p"
void POpcja(AMacierz &A,Wektor &B) {
  int i;
  for (i=0;i<ROZMIAR;i++) {
	A.Pokaz(i);
	cout <<noshowpos<< B.Daj(i)<< endl;
  }
}



// Opcja "r"
void ROpcja(AMacierz &A,Wektor &B,Wektor &Wynik,AMacierz &KopiaA,
                                                         Wektor & KopiaB) {
  int i;
  TrojGorna(A,B);
  Wylicz(A,B,Wynik);
  if (A.DajDet()==false) {
  cout <<" Wyznacznik macierzy rowny 0." << endl;
  cout <<" Uklad rowna jest zalezny." << endl;
  }
  else {
    cout <<noshowpos<< " Rozwiazanie (x1,x2,x3): ("<<Wynik.Daj(0);
    for (i=1;i<ROZMIAR;i++)
      cout <<", "<<Wynik.Daj(i);
    cout << ")"<<endl;
  cout <<endl<< " Blad: " ;
  cout << (KopiaB-KopiaA*Wynik).Norma()<< endl;     // Blad obliczen
  }
  A=KopiaA;
  B=KopiaB;
}

int main () {
  char wybor;
  int doswitcha, dowhilea=0;
  AMacierz A, KopiaA;
  Wektor B, KopiaB;
  Wektor Wynik;
  while (dowhilea==0) {
	dowhilea=1;
    Menu();
	doswitcha=0;
	while (doswitcha==0) {
	  cout << endl<<"Twoj wybor?> ";
	  cin >> wybor;
	  cout << endl<< endl;
	  switch(wybor) {
		case 'a': AOpcja(A,KopiaA);
				  break;
		case 'b': BOpcja(B,KopiaB);
				  break;
		case 'p': POpcja(A,B);
				  break;
        case 'r': ROpcja(A,B,Wynik,KopiaA,KopiaB);
                  break;
		case '?': dowhilea=0;
				  doswitcha=1;
				  break;
		case 'q': doswitcha=1;
				  break;
		default:cout<<"Wybrano niepoprawna opcje. Sprobuj jeszcze raz."<<endl;
				break;
	  }
	}
  }
}
