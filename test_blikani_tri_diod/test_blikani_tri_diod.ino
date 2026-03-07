int pauza = 1000;
int maximum = 1000000;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);;
  pinMode(10, OUTPUT);
  
}


void loop() {
     for(int i = 1; i < 3; i++){
           digitalWrite(11, HIGH);   
                                
            digitalWrite(12, LOW);   
            delay(200);
           
            digitalWrite(12, HIGH);   
                               
            digitalWrite(11, LOW);   
            delay(200);
            }
             digitalWrite(11, LOW);
              digitalWrite(12, LOW);    
     for(int i = 1; i < 2; i++){
           digitalWrite(10, HIGH);   
                               
            delay(1000);
                                  
            digitalWrite(10, LOW);   
            delay(1000);
                }
              digitalWrite(10, LOW);

       for(int i = 1; i < 3; i++){
           digitalWrite(11, HIGH);   
                                
            digitalWrite(12, LOW);   
            delay(200);
           
            digitalWrite(12, HIGH);   
                               
            digitalWrite(11, LOW);   
            delay(200);
            }
             digitalWrite(11, LOW);
              digitalWrite(12, LOW);    
     for(int i = 1; i < 1; i++){
           digitalWrite(10, HIGH);   
                               
            delay(2000);
                                  
            digitalWrite(10, LOW);   
            delay(2000);
                }
              digitalWrite(10, LOW);

}


