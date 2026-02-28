 #include "thingProperties.h"
#include "Arduino_LED_Matrix.h"

// Tvoje animace
const uint32_t animation2[][4] = {
	{
		0x80000000,
		0x0,
		0x0,
		66
	},
	{
		0x40000000,
		0x0,
		0x0,
		66
	},
	{
		0x20000000,
		0x0,
		0x0,
		66
	},
	{
		0x10000000,
		0x0,
		0x0,
		66
	},
	{
		0x4000000,
		0x0,
		0x0,
		66
	},
	{
		0x2000000,
		0x0,
		0x0,
		66
	},
	{
		0x1000000,
		0x0,
		0x0,
		66
	},
	{
		0x800000,
		0x0,
		0x0,
		66
	},
	{
		0x400000,
		0x0,
		0x0,
		66
	},
	{
		0x200000,
		0x0,
		0x0,
		66
	},
	{
		0x100000,
		0x0,
		0x0,
		66
	},
	{
		0x200000,
		0x0,
		0x0,
		66
	},
	{
		0x400000,
		0x0,
		0x0,
		66
	},
	{
		0x800000,
		0x0,
		0x0,
		66
	},
	{
		0x1000000,
		0x0,
		0x0,
		66
	},
	{
		0x2000000,
		0x0,
		0x0,
		66
	},
	{
		0x4000000,
		0x0,
		0x0,
		66
	},
	{
		0x8000000,
		0x0,
		0x0,
		66
	},
	{
		0x10000000,
		0x0,
		0x0,
		66
	},
	{
		0x20000000,
		0x0,
		0x0,
		66
	},
	{
		0x40000000,
		0x0,
		0x0,
		66
	},
	{
		0x80000000,
		0x0,
		0x0,
		66
	}
};

ArduinoLEDMatrix matrix;

void setup() {
  Serial.begin(9600);
  delay(1500); 

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  matrix.begin();
  matrix.loadSequence(animation2);
}

void loop() {
  ArduinoCloud.update();
  
  // Přidáme výpis, abys v Serial Monitoru viděl, co si Arduino myslí
  static bool posledniStav = false;
  if (beziAnimace != posledniStav) {
    Serial.print("Zmena v cloudu! beziAnimace je ted: ");
    Serial.println(beziAnimace);
    posledniStav = beziAnimace;
    matrix.play(true); 
     delay(1500); 
  }
  
  if (beziAnimace == true) {
    matrix.play(true); 
  } else {
    matrix.clear();
  }
}

// --- TADY JE TA CHYBĚJÍCÍ ČÁST ---
void onBeziAnimaceChange() {
  // Cloud vyžaduje existenci této funkce
  Serial.println("Stav switche v cloudu se zmenil.");
  
}
