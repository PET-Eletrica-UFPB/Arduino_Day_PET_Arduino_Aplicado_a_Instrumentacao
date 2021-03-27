
#include <LiquidCrystal.h>

#define resPin A0
#define tmpPin A1
#define numAmostras 5
#define intervalo 3000 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int tmp = 0;
float tens = 0;
unsigned long lastTime = 0;
int oldTmp = 0;
float oldTens = 0;

void setup() {
  beginLCD();
  Serial.begin(9600);
}

void loop() {
  if (millis() - lastTime > intervalo){
    tmp = 0;
    tens = 0;
    for (int i = 0; i < numAmostras; i++){
      int temporaryTmp = readTMP();
      float temporaryTens = readPhoto();
      tmp = tmp + temporaryTmp;
      tens = tens + temporaryTens;
      Serial.println(temporaryTmp);
    }
    tmp = tmp / numAmostras;
    tens = tens / numAmostras;
    if (tmp != oldTmp || tens != oldTens){
      printLCD(tmp, tens);
      oldTmp = tmp;
      oldTens = tens;
    }
    lastTime = millis();
  }
}

void beginLCD(){
  lcd.begin(16, 2);
}

int readTMP(){
 float volts = 5.0 * analogRead(tmpPin) / 1023.0;
 return (volts - 0.5) / 0.01;
}

float readPhoto(){
  return 5 * analogRead(resPin) / 1023.0;
}

void printLCD(int tmp, float tens){
  Serial.println("Função printLCD chamada");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tmp);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("A0: ");
  lcd.print(tens);
  lcd.print("V");
  delay(250);
}
 
