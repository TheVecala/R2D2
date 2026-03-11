int buzzer = 3;

void setup() {
  pinMode(buzzer, OUTPUT);

  for (int i = 0; i < 2; i++)  {
    tone(buzzer, 440);    // Spustí tón (bez parametru času)
    delay(1000);          // Nechá ho hrát 1s
    
    tone(buzzer, 1000);   // Změní frekvenci
    delay(1000);          // Nechá ho hrát 1s
  }
    
  digitalWrite(buzzer, HIGH); // TICHO
    delay(200);                 // Pauza             // Krátká pojistka pro stabilitu
}

void loop() {
  // Tady už bude ticho
}