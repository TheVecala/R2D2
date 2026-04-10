int buzzer = 3; 

void setup() {
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH); // Nejdřív ho umlčíme (HIGH = ticho)

  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzer, LOW);  // PÍSKEJ
    delay(200);                 // Krátké pípnutí
    digitalWrite(buzzer, HIGH); // TICHO
    delay(200);                 // Pauza
  }

    for (int i = 0; i < 3; i++) {
    digitalWrite(buzzer, LOW);  // PÍSKEJ
    delay(400);                 // Krátké pípnutí
    digitalWrite(buzzer, HIGH); // TICHO
    delay(200);                 // Pauza
  }

    for (int i = 0; i < 3; i++) {
    digitalWrite(buzzer, LOW);  // PÍSKEJ
    delay(200);                 // Krátké pípnutí
    digitalWrite(buzzer, HIGH); // TICHO
    delay(200);                 // Pauza
  }
}

void loop() {
  // Tady už bude zaručeně ticho
}