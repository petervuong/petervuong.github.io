
int heatsensor = 0;

int LED = 9; 

int LEDLevel = 0; 




void setup() {


analogReference(DEFAULT); 

pinMode(LED,OUTPUT);

Serial.begin(9600);

}




void loop() {


Serial.println(analogRead(heatsensor)); 
delay(1000);

int sensorvalue = analogRead(heatsensor); 

if (sensorvalue < 200 && LEDLevel < 255) 

{
  LEDLevel = map(sensorvalue, 0, 250, 255, 0); 
  // This takes the original value, sets a minimum, sets a maximum, and maps it to a range of two numbers 0->255 into LEDLevel PROPORTIONATELY
  // This way, the darker the room is, the brighter the LED will shine (we don't need full brightness all the time) 

  analogWrite(LED, LEDLevel); 
}

else

{
  analogWrite(LED, LOW); 
  LEDLevel = 0;
}

  

}
