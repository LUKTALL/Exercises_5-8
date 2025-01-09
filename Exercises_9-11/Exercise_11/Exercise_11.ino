/*
 * 11a)
 * I2C is a communication protocol, where nodes are designated as a "master" or "slave".
 * They have a common data and clock line, where masters would send out data, while slaves receive (typically?).
 * 
 * 11b)
 * We can just limit the frequency of writing to the display
 */

#include <LiquidCrystal.h>

uint8_t rs = 2;
uint8_t enable = 3;
uint8_t D4 = 10;
uint8_t D5 = 11;
uint8_t D6 = 12;
uint8_t D7 = 13;
LiquidCrystal lcd(rs, enable, D4, D5, D6, D7);

//degree symbol for the lcd
byte deg[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
};

uint8_t LM35 = A0;
float T = 0;
int n = 10;

void setup() {
  pinMode(LM35, INPUT);
  lcd.createChar(0, deg);
  lcd.begin(16,1);
  lcd.setCursor(0,0);
  lcd.print("Heeeeej!");
  Serial.begin(9600);
}

void loop() {
  T = 0;

  for(int i = 0; i<n; i++){
    int adc = analogRead(LM35);
    T += adc / 1023.0 * 5.0 / 0.01;
    delay(10);
  }
  T = T/(n * 1.0);
  Serial.print(T, 3);
  Serial.println("°");

  lcd.clear();
  lcd.setCursor(0,0);
  if (T <= 20) {
    lcd.print("A cool: ");
    lcd.print((int)T);
    lcd.write(byte(0));
    lcd.print("C");
  } else if (T >= 28) {
    lcd.print("HOTHOT: ");
    lcd.print((int)T);
    lcd.write(byte(0));
    lcd.print("C");
  } else {
    lcd.print("Temp is: ");
    lcd.print(T, 1);
    lcd.write(byte(0));
    lcd.print("C");
  }
  delay(500);
}
