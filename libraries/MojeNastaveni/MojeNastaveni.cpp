#include "MojeNastaveni.h"

// Tabulka binárních kódů pro čísla 0-9 (pro společnou katodu)
const byte cifry[] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

// Konstruktor - propojení pinů
Segmentovka::Segmentovka(int dataPin, int latchPin, int clockPin) {
  _dataPin = dataPin;
  _latchPin = latchPin;
  _clockPin = clockPin;
}

// Funkce pro nastavení pinů jako VÝSTUPY
void Segmentovka::nastavit() {
  pinMode(_dataPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
}

// Funkce pro poslání čísla do posuvného registru
void Segmentovka::ukazCislo(int cislo) {
  // Ochrana před zadáním čísla mimo rozsah
  if (cislo < 0 || cislo > 9) return;

  digitalWrite(_latchPin, LOW);
  shiftOut(_dataPin, _clockPin, MSBFIRST, cifry[cislo]);
  digitalWrite(_latchPin, HIGH);
}


void Segmentovka::krouzeni(int pocetOtacek, int rychlost) {
  for (int j = 0; j < pocetOtacek; j++) {
    for (int i = 0; i < 6; i++) { // Kroužení po segmentech A-F
      digitalWrite(_latchPin, LOW);
      shiftOut(_dataPin, _clockPin, MSBFIRST, (1 << i));
      digitalWrite(_latchPin, HIGH);
      delay(rychlost);
    }
  }
}