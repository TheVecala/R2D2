const int dataPin = 11;
const int latchPin = 12;
const int clockPin = 13;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
    digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0b01001111);
  digitalWrite(latchPin, HIGH);
}

void posliData(byte data) {

}

void loop() {     
 
    delay(1000);
 
  
}