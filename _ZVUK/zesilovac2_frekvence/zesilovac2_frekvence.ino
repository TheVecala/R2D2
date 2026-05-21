// R2D2 info : zvyšuje a snižuje frekvence pomocí příkazu v serial monitoru 
// A0-analog vystup signalu, použit jednotranzistorový zesilovač
#include "analogWave.h" // Knihovna specifická pro Uno R4

analogWave wave(DAC);   // DAC je na pinu A0

int freq = 440;         // Startovní frekvence (tón A)

void setup() {
  Serial.begin(9600); 
  while (!Serial); // Počkej na otevření monitoru

  Serial.println("--- Zesilovač Test Ready ---");
  Serial.println("Příkazy: '+' pro vyšší frekvenci, '-' pro nižší, 's' pro automatický sweep.");

  // Inicializace DACu na A0
 // wave.begin(1024); // 1024 je velikost vzorkovacího bufferu
  wave.sine(freq);      // Začni čistým tónem
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read();

    if (cmd == '+') {
      freq += 100;
      updateWave();
    } else if (cmd == '-') {
      freq -= 100;
      if (freq < 50) freq = 50;
      updateWave();
    } else if (cmd == 's') {
      runSweep();
    }
  }
}

void updateWave() {
  Serial.print("Aktuální frekvence: ");
  Serial.print(freq);
  Serial.println(" Hz");
  wave.freq(freq);
}

void runSweep() {
  Serial.println("Spouštím automatický sweep (200Hz - 2000Hz)...");
  for (int f = 200; f <= 2000; f += 10) {
    wave.freq(f);
    delay(20); // Rychlost průběhu
  }
  wave.freq(freq); // Návrat k původní frekvenci
  Serial.println("Sweep dokončen.");
}