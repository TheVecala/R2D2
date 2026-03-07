int pauza = 1000;
int maximum = 1000000;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  
}


void loop() {
     for(int i = 10; i < maximum; i++){
           digitalWrite(11, HIGH);   
                                
            digitalWrite(12, LOW);   
            delay(i*1);
           
            digitalWrite(12, HIGH);   
                               
            digitalWrite(11, LOW);   
            delay(i*1);

}                
}


