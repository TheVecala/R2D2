// 1. Zkontroluj, že pole v data.h se jmenuje přesně soundData
#include "carvadele.h" 

// Pokud nemáš data.h, vlož pole sem:
// const uint16_t soundData[] = { ... };

const uint32_t sampleCount = sizeof(soundData) / sizeof(soundData[0]);

void setup() {
  // Na R4 je nutné pro A0 nastavit rozlišení
  analogWriteResolution(12); 
  pinMode(A0, OUTPUT);
}

void loop() {
  for (uint32_t i = 0; i < sampleCount; i++) {
    // Na R4 čteme data přímo, nepoužíváme pgm_read_word
    uint16_t rawVal = soundData[i];
    
    // Převedeme 16-bit (0-65535) na 12-bit (0-4095)
    uint16_t dacVal = rawVal >> 4;
    
    // Pošleme do DAC
    analogWrite(A0, dacVal);
    
    // Časování pro 8000Hz (1s / 8000 = 125 mikrosekund)
    // Zkusíme 130 pro jistotu
    delayMicroseconds(130); 
  }

  delay(2000); // Pauza mezi přehráváním
}