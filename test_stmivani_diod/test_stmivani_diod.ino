byte ledPin1 = 13;              // LED D1 - pin13 PWM regulace jen pro LEONARDO pro UNO bude binarni
byte ledPin2 = 12;              // LED D2 - pin12 PWM nepodporuje - bude binarni
byte ledPin3 = 11;              // LED D3 - pin11 PWM regulace
byte ledPin4 = 10;              // LED D4 - pin10 PWM regulace

void setup()
{
      pinMode(ledPin1, OUTPUT);
      pinMode(ledPin2, OUTPUT);
      pinMode(ledPin3, OUTPUT);
      pinMode(ledPin4, OUTPUT);    // nastaveni vystupu
}

void loop()
{
               for (int i = 255; i > 200; i--)
      {
             analogWrite(ledPin1, i); // rozsvit LED D1 - intenzita dle hodnoty promenne i
             analogWrite(ledPin2, i); // totez pro LED D2
             analogWrite(ledPin3, i); // totez pro LED D3
             analogWrite(ledPin4, i); // totez pro LED D4
             delay(50);              // cekej 100 ms
      }
   
      for (int i = 200; i < 255; i++)
      {
             analogWrite(ledPin1, i); // rozsvit LED D1 - intenzita dle hodnoty promenne i
             analogWrite(ledPin2, i); // totez pro LED D2
             analogWrite(ledPin3, i); // totez pro LED D3
             analogWrite(ledPin4, i); // totez pro LED D4
             delay(50);              // cekej 100 ms
      }

       //  delay(1000);        // cekej 1 s, pak znova
} 