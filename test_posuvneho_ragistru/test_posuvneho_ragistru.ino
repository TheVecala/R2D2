const int dataPin = 11;
const int latchPin = 12;
const int clockPin = 13;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void posliData(byte data) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}

void loop() {
  // Posun tam
  for (int i = 0; i < 8; i++) {
    posliData(1 << i); // To je ten náš trik s posunem jedničky
    delay(100);
  }
  // Posun zpět
  for (int i = 6; i > 0; i--) {
    posliData(1 << i);
    delay(100);
  }
}