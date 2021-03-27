#include <Servo.h>

#define DEBUG Serial
#define potPin A0
#define servoSignal 3
#define sensPin A1

Servo Servo; 

int val = 0;
int sens = 0;

void setup() {
  Servo.attach(servoSignal);
  #ifdef DEBUG
    DEBUG.begin(115200);
  #endif
}

void loop() {
  val = analogRead(potPin);            
  val = map(val, 0, 1023, 0, 180);
  sens = analogRead(sensPin);
  sens = map(sens, 0, 1023, 0, 100);
  int pos = Servo.read();
  if (val > pos){
    Servo.write(pos + 1);
  } else if (val < pos){
    Servo.write(pos - 1);
  }
  delay(sens);
  
  #ifdef DEBUG
    DEBUG.print("Tempo de delay: ");
    DEBUG.println(sens);
  #endif                        
}
