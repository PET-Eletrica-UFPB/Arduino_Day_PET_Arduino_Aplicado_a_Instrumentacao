#define DEBUG Serial
#define interruptPin 2

volatile bool flag = 0;
volatile int freq = 0;
volatile int counter = 0;
volatile unsigned long lastTime = 0;

void setup (){
  #ifdef DEBUG
   DEBUG.begin(115200);
  #endif
  attachInterrupt(digitalPinToInterrupt(interruptPin), trigger, RISING);
}

void loop (){
  Serial.println(freq);
  if (flag == 1){
    Serial.print("Contagem: ");
    Serial.println(counter);
    flag = 0;
  }
    
}

void trigger(){
  flag = 1;
  counter = counter + 1;
  if (counter >= 3){
   freq = counter * 1000 / (millis() - lastTime);
   lastTime = millis();
   counter = 0;
  }
}
