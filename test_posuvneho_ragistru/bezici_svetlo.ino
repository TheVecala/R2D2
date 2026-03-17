const int dataPin = 11;   // DS
const int latchPin = 12;  // STCP
const int clockPin = 13;  // SHCP

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    // 1. Odemknout zápis
    digitalWrite(latchPin, LOW);
    
    // 2. Poslat data (rozsvítí i-tou LED)
    shiftOut(dataPin, clockPin, MSBFIRST, (1 << i));
    
    // 3. Zamknout a zobrazit
    digitalWrite(latchPin, HIGH);
    
    delay(200);
  }
}
