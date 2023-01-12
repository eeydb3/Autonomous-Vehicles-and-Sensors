/* Digital Trundle Wheel
   takes input from a 6 cycle (4 positions per cycle) quadrature encoder
*/

// include encoder library
#include <Encoder.h>

// change these two numbers (if needed) to enable pins connected to encoder
Encoder myEnc(2, 3); //enable pins with interrupt capability

long oldPosition  = -999;
float distance;

void setup() 
{
  Serial.begin(9600); 
  Serial.println("Rotary Encoder: ");
}

void loop() 
{
  long newPosition = myEnc.read();
  
  // check if encoder has moved
  if (newPosition != oldPosition) 
  {
    distance = newPosition + oldPosition;
    oldPosition = newPosition;
        
  // edit the code below to calculate the distance moved, +1 increment = (diameter*pi)/encoder count per revolution
    distance = distance * 1.0;
  // ***
    
    // output distance to the serial monitor                    
    Serial.print("Distance(m): ");
    Serial.println(distance);
    }
}
