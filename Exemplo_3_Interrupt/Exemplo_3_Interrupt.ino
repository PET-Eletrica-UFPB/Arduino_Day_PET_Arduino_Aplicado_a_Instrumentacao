#define DEBUG Serial
#define interruptPin 2

volatile bool flag = 0;
unsigned long lastTime = 0;

void setup (){
  #ifdef DEBUG
    DEBUG.begin(115200);
  #endif
  attachInterrupt(digitalPinToInterrupt(interruptPin), trigger, CHANGE);
}

void loop (){
  checkForFlag();
}

void trigger(){
  flag = 1;
}

void checkForFlag(){
    if (flag){
      #ifdef DEBUG
        Serial.println("Algo ocorreu!");
      #endif
      flag = 0;
    } else if (millis() - lastTime > 200){
      #ifdef DEBUG
        Serial.println(".");
      #endif
      lastTime = millis();
    }
}
