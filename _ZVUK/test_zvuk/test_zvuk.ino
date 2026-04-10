#include "AnalogWave.h"
#include "carvadele.h" // Tímto propojíme ten obří seznam čísel

analogWave wave(DAC);

void setup() {
  // 1. Nastav vzorkovací frekvenci (tu, co jsi měl v Audacity)
  wave.begin(8000); 

  // 2. Vypočítejme počet vzorků v poli automaticky
  uint32_t pocetVzorku = sizeof(mojeData) / sizeof(mojeData[0]);

  // 3. Nahrajeme data
  wave.load(mojeData, pocetVzorku);

  // 4. Nastavíme maximální hlasitost (pro jistotu)
  wave.amplitude(1.0);

  // 5. Jedeme!
  wave.play(); 
}

void loop() {
  // Tady se můžeš věnovat jiným věcem, zvuk běží "na pozadí"
}