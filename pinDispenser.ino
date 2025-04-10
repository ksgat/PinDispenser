#include <Servo.h>

Servo esc;  

const int escPin = 9;
const int minThrottle = 1000;  
const int maxThrottle = 2000;  
const int stopSpeed = 1500; 

const int buttonPin = 0;    
const int runTime = 3 * 1000; 
const int buttonSpeed = 1800;  
void setup() {
  Serial.begin(9600);
  Serial.println("ESC Control Initializing");
  
  esc.attach(escPin, minThrottle, maxThrottle);
  
  esc.writeMicroseconds(stopSpeed);
  delay(1000); 
  
  pinMode(buttonPin, INPUT_PULLUP); 
  Serial.println("ESC Ready. Send values between 1000 (full reverse) and 2000 (full forward)");
  Serial.println("1500 is stop/neutral");
}

void loop() {
  
  if (Serial.available() > 0) {
    Serial.println("Speed");
    int speedValue = Serial.parseInt();  
    speedValue = constrain(speedValue, minThrottle, maxThrottle);
    
    Serial.println("Time (in seconds)");
    int buttonTime = Serial.parseInt() * 1000;
    
    Serial.print("Speed set to: ");
    Serial.println(speedValue);
    Serial.print("Time set to: ");
    Serial.println(buttonTime);

    */
    if (digitalRead(buttonPin) == LOW) { 
    
    Serial.println("Button pressed - starting motor");
    esc.writeMicroseconds(speedValue);
    delay(buttonTime);                    
    esc.writeMicroseconds(stopSpeed);  
    Serial.println("Motor stopped");
    delay(500);
    }
  
  }

}