/* 
 modified 02/20/2018
 by Justin Pontius
*/

#include <Servo.h>
int led = D3;                             // Cereat LED object
Servo myservo;                            // Cereat servo object to control a servo

int pos = 0;                              // Variable to store the servo position

void setup() {
  Serial.begin(115200);                   // Setup serial port for debugging.
  delay(10);                              // Small delay at start
  pinMode(led, OUTPUT);                   // Set LED pin to ouput.
  pinMode(D5, INPUT_PULLUP);              // Set switch pin to input with internal pullup.
  myservo.attach(D4);                     // Attaches the servo on pin 'D4' to the servo object
  Serial.println();                       // Debugging
  Serial.println();                       // Debugging
  Serial.println("Started.");             // Debugging
}


void loop() {
  
  if (digitalRead(D5)==LOW) {             // Read the toggle switch value, if low then run 0-90 sweep.
    digitalWrite(led, LOW);               // Turn LED off.
    for (pos = 0; pos <= 90; pos += 1) {  // Goes from 0 degrees to 90 degrees in steps of 1 degree
      myservo.write(pos);                 // Tell servo to go to position in variable 'pos'
      if (digitalRead(D5)!=LOW) {         // If statement to check if we changed the switch and break out of loop.
        break;
      }
      delay(150);                         // Delay 150ms to set speed of sweep.
    }
                                          // Sweep servo backwards.
    for (pos = 90; pos >= 0; pos -= 1) {  // Goes from 90 degrees to 0 degrees
      myservo.write(pos);                 // Tell servo to go to position in variable 'pos'
      if (digitalRead(D5)!=LOW) {         // If statement to check if we changed the switch and break out of loop.
       break;
      }
      delay(150);                         // Delay 150ms to set speed of sweep.
    }
  }

  
  if (digitalRead(D5)==HIGH) {           // Read the toggle switch value, if HIGH then run 0-180 sweep.
    digitalWrite(led, HIGH);             // Turn LED on.
   for (pos = 0; pos <= 180; pos += 1) { // Goes from 0 degrees to 180 degrees in steps of 1 degree
    myservo.write(pos);                  // Tell servo to go to position in variable 'pos'
     if (digitalRead(D5)!=HIGH) {        // If statement to check if we changed the switch and break out of loop.
      break;
    }
    delay(150);                         // Delay 150ms to set speed of sweep.
  }
                                        // Sweep servo backwards.
  for (pos = 180; pos >= 0; pos -= 1) { // Goes from 180 degrees to 0 degrees
    myservo.write(pos);                 // Tell servo to go to position in variable 'pos'
    if (digitalRead(D5)!=HIGH) {        // If statement to check if we changed the switch and break out of loop.
      break;
      }
    delay(150);                         // Delay 150ms to set speed of sweep.
  }
  }
}

