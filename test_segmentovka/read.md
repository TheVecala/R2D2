// odpočet 0-9
const int dataPin = 11;
const int latchPin = 12;
const int clockPin = 13;

// Binární masky pro čísla 0-9 (Společná katoda)
// Pořadí bitů v bajtu: DP g f e d c b a
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
}

void loop() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(latchPin, LOW);
    // MSBFIRST zajistí, že bity půjdou ve správném pořadí
    shiftOut(dataPin, clockPin, MSBFIRST, cifry[i]);
    digitalWrite(latchPin, HIGH);
    
    delay(1000); // Změna čísla každou sekundu
  }
}