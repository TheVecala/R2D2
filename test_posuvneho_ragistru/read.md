mám čip Posuvný registr SN74HC595N 74HC595 8bit DIP-16 <br>
chci vyzkoušet ovládání nejprve 8 diod, potom segmentovky
na nepájivém poli, ovládání pomocí arduina uno

Propojení s Arduinem:
    Pin 16 (VCC) → 5V
    Pin 8 (GND) → GND
    Pin 10 (SRCLR) → 5V (Reset – držíme v neaktivním stavu)
    Pin 13 (OE) → GND (Output Enable – výstupy jsou stále aktivní)
    Pin 14 (Data/SER) → Arduino D11 (modrá linka)
    Pin 12 (Latch/RCLK) → Arduino D8 (zelená linka)
    Pin 11 (Clock/SRCLK) → Arduino D12 (žlutá linka)
LED diody:
    Zapoj 8 LEDek na piny 15 (Q0) a 1 až 7 (Q1–Q7).
    Každá LEDka musí mít svůj rezistor (220 Ω až 1k Ω) zapojený k zemi (GND).
