#ifndef AMACIERZ_HH
#define AMACIERZ_HH
#define ROZMIAR 3
#include <iostream>
#include "wektor.hh"


/*  Niniejsza klasa modeluje macierz A			
    
    Klasa bedzie przechowywac informacje o macierzy w postaci raz kolumn 
    a innym razem w postaci wierszy. Zawiera rowniez informacje 
    o wyznaczniku - czy jest on rowny 0  lub czy jest rozny od zera*/


class AMacierz {
  private:
    Wektor Wrsz[ROZMIAR]; // Macierz zapisana w postaci wierszy
	Wektor Kol[ROZMIAR]; // Macierz zapisana w postaci kolumn
    bool DetRozny0; //Wyznacznik macierzy. Bedzie on mial wartosci true (gdy
                    // rozny od zera) oraz false (gdy bedzie rowny zero)
  public:	
	void PrzepiszDoKol();
    void PrzepiszDoWrsz();
	void Wczytaj();	
	float Daj(int i,int j) const;
	void Pokaz(int i) const;
    float Det() const;
    void TrojGorna();
    void WrszNaKoniec(int i);
    void Dzialanie(int i,int j,float czynnik);
    int DajDet() const;
	void Det(bool wartosc);    
    Wektor operator * (const Wektor &B) const;
};

#endif
