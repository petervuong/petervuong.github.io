// Learning how to manipulate codes. Still have one problem - after lowering the brightness, an extra click is required to go from off -> first brightness level. 

int button = 8;
int LED = 5; 
int LEDLevel = 0; 
boolean lastButton = LOW;
boolean currentButton = LOW;
int LEDLevelCopy = 255;



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

pinMode(button,INPUT);
pinMode(LED,OUTPUT);

}

void loop() 


{

currentButton = debounce(lastButton);

if(currentButton == HIGH && lastButton == LOW && LEDLevel != 255)

{
  LEDLevel = LEDLevel + 51; 
analogWrite(LED, LEDLevel);

}

else if (currentButton == HIGH && lastButton == LOW && LEDLevel == 255 && LEDLevelCopy != 0) 

{
  
     LEDLevelCopy = LEDLevelCopy - 51;
  analogWrite(LED, LEDLevelCopy);

}

else if (currentButton == HIGH && lastButton == LOW && LEDLevelCopy == 0)
{
 
  analogWrite(LED, LEDLevelCopy);
   LEDLevel = 0;
  LEDLevelCopy = 255; 
}

lastButton = currentButton; 


}
