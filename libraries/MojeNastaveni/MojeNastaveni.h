#ifndef MOJE_NASTAVENI_H
#define MOJE_NASTAVENI_H

#include <Arduino.h>

class Segmentovka {
  private:
    // Soukromé proměnné (schované uvnitř objektu)
    int _dataPin;
    int _latchPin;
    int _clockPin;

  public:
    // Konstruktor (spustí se při vytvoření objektu a uloží piny)
    Segmentovka(int dataPin, int latchPin, int clockPin);

    // Veřejné funkce (metody), které budeš volat v hlavním programu
    void nastavit();
    void ukazCislo(int cislo);
	void krouzeni(int pocetOtacek, int rychlost); // NOVÁ FUNKCE
};

#endif