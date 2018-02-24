#include <Servo.h>

String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete

const int insertAngle = 20;
const int removeAngle = 100;
const int servoPin = 9;

Servo linearActuator;  // create servo object to control a servo

void setup() 
{
  // initialize serial:
  Serial.begin(115200);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  linearActuator.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  linearActuator.write(removeAngle);
}

void loop() 
{
  // print the string when a newline arrives:
  if (stringComplete) 
  {
    Serial.println("Received command: " + inputString);
    
    if (inputString == "insert\n")
    {
        Serial.println("Insert card");
        linearActuator.write(insertAngle);
    }
    else if (inputString == "remove\n")
    {
        Serial.println("Remove card");
        linearActuator.write(removeAngle);
    }
    else 
    {
      Serial.println("Nothing to do");
    }
    
    // clear the string:  
    inputString = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() 
{
  while (Serial.available()) 
  {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n')
    {
      stringComplete = true;
    }
  }
}
