#include <MojeNastaveni.h>

Segmentovka displej(11, 12, 13);

const int button1Pin = 2; // Kostka
const int button2Pin = 4; // Odpočet
const int button3Pin = 6; // Reset

int pocitadlo = 0;
bool button1PosledniStav = HIGH;
bool button2PosledniStav = HIGH;
bool button3PosledniStav = HIGH;

// PROMĚNNÉ PRO ODPOČET (To je ten náš známý systém)
bool odpocetBezi = false;
int zbyvajiciCas = 9;
unsigned long predchoziCas = 0;
const long interval = 1000; // 1 sekunda

void setup() {
  displej.nastavit(); 
  
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);

  displej.ukazCislo(0); // Úvodní nula
}

void loop() {
  unsigned long aktualniCas = millis(); // Načteme aktuální čas pro odpočet

  bool b1Stav = digitalRead(button1Pin);
  bool b2Stav = digitalRead(button2Pin);
  bool b3Stav = digitalRead(button3Pin);

  // --- TLAČÍTKO 1: KOSTKA ---
  if (b1Stav == LOW && button1PosledniStav == HIGH) {
    odpocetBezi = false; // Pokud běžel odpočet, stiskem kostky ho zrušíme
    
    displej.krouzeni(3, 50); // Tvůj efekt z knihovny
    pocitadlo = random(1, 7); 
    displej.ukazCislo(pocitadlo); 
    delay(200);
  }

  // --- TLAČÍTKO 2: ODPOČET ---
  if (b2Stav == LOW && button2PosledniStav == HIGH) {
    odpocetBezi = true;
    zbyvajiciCas = 9;
    predchoziCas = aktualniCas; // Vynulujeme stopky pro první sekundu
    
    displej.ukazCislo(zbyvajiciCas); 
    delay(200); 
  }

  // --- TLAČÍTKO 3: RESET ---
  if (b3Stav == LOW && button3PosledniStav == HIGH) {
    odpocetBezi = false; // Zastavíme běžící odpočet
    pocitadlo = 0;
    displej.ukazCislo(pocitadlo); 
    delay(200);
  }

  // --- LOGIKA SAMOTNÉHO ODPOČTU ---
  // Tento kód běží neustále na pozadí, ale "střílí" jen když je odpocetBezi = true
  if (odpocetBezi) {
    if (aktualniCas - predchoziCas >= interval) {
      predchoziCas = aktualniCas; // Restartujeme stopky pro další sekundu
      zbyvajiciCas--;

      if (zbyvajiciCas >= 0) {
        displej.ukazCislo(zbyvajiciCas);
      } else {
        // Tady odpočet došel na nulu
        odpocetBezi = false;
        displej.krouzeni(2, 30); // Na konci odpočtu uděláme efekt kroužení jako alarm!
        displej.ukazCislo(0);
      }
    }
  }

  button1PosledniStav = b1Stav;
  button2PosledniStav = b2Stav;
  button3PosledniStav = b3Stav;
}