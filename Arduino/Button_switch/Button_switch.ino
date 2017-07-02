// Learning how to use a button to turn LED on and off 

int button = 8; 
int LED = 13;
boolean lastButton = LOW;
boolean LEDStatus = false;
boolean currentButton = LOW;

// Fixes light source from bouncing

boolean debounce(boolean last)

{
  boolean current = digitalRead(button);
  if (last != current)
  {
    delay(5);
    current = digitalRead(button);
  }
  return current;
  
}




void setup() {


// Set IO pins 

pinMode(button, INPUT);
pinMode(LED, OUTPUT);


 

}

void loop() {

// You want the status of the current button to update after debouncing

currentButton = debounce(lastButton);

if(currentButton == HIGH && lastButton == LOW)

{

  LEDStatus =!LEDStatus;
 
}


  lastButton = currentButton;
  digitalWrite(LED,LEDStatus);

}
