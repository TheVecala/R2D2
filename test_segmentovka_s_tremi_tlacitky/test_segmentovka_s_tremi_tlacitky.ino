const int dataPin = 11;
const int latchPin = 12;
const int clockPin = 13;
const int button1Pin = 2; // Pin pro tlačítko
const int button2Pin = 4; // Pin pro tlačítko
const int button3Pin = 6; // Pin pro tlačítko

int pocitadlo = 0;       // Tady si pamatujeme aktuální číslo
bool button1PosledniStav = HIGH; // Pro detekci změny stisku
bool button2PosledniStav = HIGH; // Pro detekci změny stisku
bool button3PosledniStav = HIGH; // Pro detekci změny stisku

byte cifry[] = {
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

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  
 
  pinMode(button1Pin, INPUT_PULLUP);  // Aktivujeme vnitřní odpor (tlačítko spíná proti zemi)
  pinMode(button2Pin, INPUT_PULLUP);  // Aktivujeme vnitřní odpor (tlačítko spíná proti zemi)
  pinMode(button3Pin, INPUT_PULLUP);  // Aktivujeme vnitřní odpor (tlačítko spíná proti zemi)

  // Na začátku ukážeme nulu
  aktualizujDisplej(cifry[pocitadlo]);
}

void aktualizujDisplej(byte data) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}

void loop() {

  bool button1Stav = digitalRead(button1Pin); // Detekce hrany: Tlačítko bylo právě stisknuto (přechod z HIGH na LOW) 
  bool button2Stav = digitalRead(button2Pin); // Detekce hrany: Tlačítko bylo právě stisknuto (přechod z HIGH na LOW) 
  bool button3Stav = digitalRead(button3Pin); // Detekce hrany: Tlačítko bylo právě stisknuto (přechod z HIGH na LOW) 


// ----------------button 1-------------------------------------------------------------------------------
  if (button1Stav == LOW && button1PosledniStav == HIGH) {

  
for (int j = 0; j < 3; j++) {

  for (int i = 0; i < 6; i++) {
    digitalWrite(latchPin, LOW); // 1. Odemknout zápis
    shiftOut(dataPin, clockPin, MSBFIRST, (1 << i));  // 2. Poslat data (rozsvítí i-tou LED) 
    digitalWrite(latchPin, HIGH);  // 3. Zamknout a zobrazit 
    delay(50);
  }
   }
    pocitadlo = random(1,7);
    aktualizujDisplej(cifry[pocitadlo]); 

    delay(200); // Jednoduchý debouncing (počkáme, až se kontakty uklidní)
  }

// ----------------button 2-------------------------------------------------------------------------------

    if (button2Stav == LOW && button2PosledniStav == HIGH) {

    pocitadlo = 0;
    aktualizujDisplej(cifry[pocitadlo]);  


    delay(200); // Jednoduchý debouncing (počkáme, až se kontakty uklidní)
  }

// ----------------button 3-------------------------------------------------------------------------------

    if (button3Stav == LOW && button3PosledniStav == HIGH) {


  for (int i = 0; i < 6; i++) {
    
    digitalWrite(latchPin, LOW); // 1. Odemknout zápis
    shiftOut(dataPin, clockPin, MSBFIRST, (1 << i));  // 2. Poslat data (rozsvítí i-tou LED) 
    digitalWrite(latchPin, HIGH);  // 3. Zamknout a zobrazit
    
    delay(200);
  }



    delay(200); // Jednoduchý debouncing (počkáme, až se kontakty uklidní)
  }

// ------------------------------------------------------------------------------------------------------

  button1PosledniStav = button1Stav;
  button2PosledniStav = button2Stav;
  button3PosledniStav = button3Stav;
}