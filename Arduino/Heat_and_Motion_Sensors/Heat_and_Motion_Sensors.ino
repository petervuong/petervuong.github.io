
int sensor = 0; 

int LED = 9;

int LEDLevel =0; 




void setup() {


analogReference(DEFAULT); 

pinMode(sensor, INPUT);
pinMode(LED, OUTPUT); 

Serial.begin(9600);
}


void loop() {

//Figure out value from 0->102

Serial.println(analogRead(sensor)); 
delay(500);



int value = analogRead(sensor); 

if (value < 100 && LEDLevel < 255)

{ 
  analogWrite(LED, LEDLevel); //Turn on LED if sensor is covered enough
  LEDLevel +=51; 
  delay(500); 
}

// if statement adjusts brightness levels if finger remains on sensor



else 
{
  analogWrite(LED, LOW); 
  LEDLevel = 0;
}

}
