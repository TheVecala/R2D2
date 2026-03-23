mám čip Posuvný registr SN74HC595N 74HC595 8bit DIP-16 <br>
chci vyzkoušet ovládání nejprve 8 diod, potom segmentovky
na nepájivém poli, ovládání pomocí arduina uno

Propojení s Arduinem:
    Pin 16 (VCC) → 5V
    Pin 8 (GND) → GND
    Pin 10 (SRCLR) → 5V (Reset – držíme v neaktivním stavu)
    Pin 13 (OE) → GND (Output Enable – výstupy jsou stále aktivní)
	
    Pin 14 (Data/SER) → Arduino D11 
    Pin 12 (Latch/RCLK) → Arduino D12	
    Pin 11 (Clock/SRCLK) → Arduino D13  
LED diody:
    Zapoj 8 LEDek na piny 15 (Q0) a 1 až 7 (Q1–Q7).
    Každá LEDka musí mít svůj rezistor (220 Ω až 1k Ω) zapojený k zemi (GND).
    Q0 až Q7 (piny 15 a 1–7) → rezistor(220 Ω až 1k Ω) → anoda LED (+) → katoda LED na GND (-).

	diody svítí 
	
	segmentovka:
	Mám společnou katodu
	
	
	
	https://components101.com/ics/74hc595-shift-register-pinout-datasheet,
	

	byte cifry[] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

	zapojení dvou segmentovek, návod:

	https://wiki.geeetech.com/index.php/Arduino_7_segment_LED_timer_with_74HC595_module
	