// Definice pinu pro bzučák
const int buzzerPin = 8;

void setup() {
  // Pin 8 bude ovládat náš tranzistor
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // R2D2 styl: Rychlé skoky mezi frekvencemi
  for (int i = 0; i < 16; i++) {
    int frequency = random(440, 2000); // Náhodný tón
    int duration = random(50, 200);    // Náhodná délka
    
    tone(buzzerPin, frequency, duration);
    delay(duration + 40); // Krátká pauza mezi tóny
  }
  
  delay(2000); // Pauza mezi "větami"
}