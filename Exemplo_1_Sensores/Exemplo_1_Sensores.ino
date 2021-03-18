
#include <LiquidCrystal.h>

#define LCD 1
#define resPin A0
#define tmpPin A1


#ifdef LCD
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#endif

void setup() {
  beginLCD();
}

void loop() {
  int tmp = readTMP();
  float tens = readPhoto();
  printLCD(tmp, tens);
}

void beginLCD(){
  #ifdef LCD
    lcd.begin(16, 2);
  #endif
}

int readTMP(){
 float volts = 5.0 * analogRead(tmpPin) / 1023.0;
 return (volts - 0.5) / 0.01;
}

float readPhoto(){
  return 5 * analogRead(resPin) / 1023.0;
}

void printLCD(int tmp, float tens){
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
 
