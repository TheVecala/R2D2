zadání: mám čip Posuvný registr SN74HC595N 74HC595 8bit DIP-16 <br>
chci vyzkoušet ovládání nejprve 8 diod, potom segmentovky
na nepájivém poli, ovládání pomocí arduina uno

Propojení s Arduinem:
    Pin 16 (VCC) → 5V
    Pin 8 (GND) → GND
    Pin 10 (SRCLR) → 5V (Reset – držíme v neaktivním stavu)
    Pin 13 (OE) → GND (Output Enable – výstupy jsou stále aktivní)

    Pin 14 (Data/SER) → Arduino D11  
    Pin 12 (Latch/RCLK) → Arduino D8  
    Pin 11 (Clock/SRCLK) → Arduino D12   
LED diody:
    Zapoj 8 LEDek na piny 15 (Q0) a 1 až 7 (Q1–Q7):
     
    Q0 až Q7 (piny 15 a 1–7) → rezistor(220 Ω až 1k Ω) → anoda LED (+) → katoda LED na GND (-).
