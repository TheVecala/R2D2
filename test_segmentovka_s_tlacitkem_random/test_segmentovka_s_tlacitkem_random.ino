const int dataPin = 11;
const int latchPin = 12;
const int clockPin = 13;
const int buttonPin = 2; // Pin pro tlačítko

int pocitadlo = 0;       // Tady si pamatujeme aktuální číslo
bool posledniStav = HIGH; // Pro detekci změny stisku

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
  
  // Aktivujeme vnitřní odpor (tlačítko spíná proti zemi)
  pinMode(buttonPin, INPUT_PULLUP);

  // Na začátku ukážeme nulu
  aktualizujDisplej(cifry[pocitadlo]);
}

void aktualizujDisplej(byte data) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}

void loop() {
  bool aktualniStav = digitalRead(buttonPin);

  // Detekce hrany: Tlačítko bylo právě stisknuto (přechod z HIGH na LOW)
  if (aktualniStav == LOW && posledniStav == HIGH) {


    pocitadlo = random(1,7);


    aktualizujDisplej(cifry[pocitadlo]);  
    delay(200); // Jednoduchý debouncing (počkáme, až se kontakty uklidní)
  }
  
  posledniStav = aktualniStav;
}