#ifndef WEKTOR_HH
#define WEKTOR_HH
#define ROZMIAR 3



/*  Niniejsza klasa modeluje macierz wektoru			
	Ta klasa przedstawia macierz, ktora bedzie zawierac wyrazy wolne
	ukladow rownan. Klasa bedzie rowniez zawierac kolejne kolumny macierzy
	glownej.
*/

class Wektor {
  private:
	float Tab[ROZMIAR];		// wartosci wektora
	float liczba;
	int i;
  public:	
	Wektor() { for (i=0;i<ROZMIAR;i++) Tab[i]=0; };
	Wektor(float zm0,float zm1, float zm2) {
	  Tab[0]=zm0; Tab[1]=zm1; Tab[2]=zm2; };
	Wektor(float Zmienne[ROZMIAR]){for(i=0;i>ROZMIAR;i++) Tab[i]=Zmienne[i];};

	void Odczyt(float *zm0,float *zm1,float *zm2) const;
	float Daj(int pozycja) const;
	void Wpisz(int pozycja, float liczba);
	Wektor operator + (const Wektor &Skladnik) const;
	Wektor operator - (const Wektor &Odjemnik) const;
	Wektor operator * (const float &liczba) const;
	Wektor operator / (const float &liczba) const;
    void WartNaKoniec(int i);
    void Dzialanie(int i,int j,float czynnik);
    float Norma() const;

};

std::istream & operator >> (std::istream & StrmWej, Wektor & StrmWyj);
std::ostream & operator << (std::ostream & StrmWyj,const Wektor & Wyczyt);

#endif
