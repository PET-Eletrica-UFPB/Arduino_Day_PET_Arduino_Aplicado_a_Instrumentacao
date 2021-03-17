#include <Servo.h>

#define DEBUG Serial
#define potPin A0
#define servoSignal 3

Servo Servo; 

int val = 0;

void setup() {
  Servo.attach(servoSignal);
  #ifdef DEBUG
    DEBUG.begin(115200);
  #endif
}

void loop() {
  val = analogRead(potPin);            
  val = map(val, 0, 1023, 0, 180);     
  Servo.write(val); 
  #ifdef DEBUG
    DEBUG.println(Servo.read());
  #endif
  delay(15);                           
}
