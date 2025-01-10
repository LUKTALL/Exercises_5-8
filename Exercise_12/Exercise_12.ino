/*
 * Some cool game or something, idk
 */

#include <LiquidCrystal.h>

// Define the pins that are connected to the LCD-display
uint8_t rs = 2;
uint8_t enable = 3;
uint8_t D4 = 10;
uint8_t D5 = 11;
uint8_t D6 = 12;
uint8_t D7 = 13;
LiquidCrystal lcd(rs, enable, D4, D5, D6, D7);

// Define the pins used for the LEDs and button
uint8_t led1 = 30;
uint8_t led2 = 28;
uint8_t led3 = 26;
uint8_t led4 = 24;
uint8_t led5 = 22;
uint8_t button = 6;

// Define the variables used for the game logic
int count = 0;
uint8_t led = 0;
uint8_t flashSpeed = 20;
uint8_t nHit = 0;
uint8_t nMiss = 0;
uint8_t level = 1;
uint8_t lastHighscore = 0;

void setup() {
  pinMode(led1, OUTPUT); pinMode(led2, OUTPUT); pinMode(led3, OUTPUT); pinMode(led4, OUTPUT); pinMode(led5, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  lcd.begin(16,2);
  lcdSetup();
  Serial.begin(9600);
}

void loop() {
  // Runs every 40 ms
  if(count%4 == 0){
    // Checks if the button is pressed
    if(digitalRead(button) != 1){
      // If we hit the right LED (#3), we go to next level. If current level is level 10, we win!!
      if(led == 3){
        if(level == 10){
          // Win screen
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("YOU WIN!!!");
          delay(1000);
          for(int i = 0; i<15; i++){
            lcd.scrollDisplayRight();
            delay(200);
          }

          // Reset game
          level = 1;
          flashSpeed = 20;
          nHit = 0;
          nMiss = 0;
          lastHighscore = 0;
          lcdSetup();
        } else {
          nHit++;
          level++;
          correctHit();
  
          lcd.setCursor(2,0);
          lcd.print(nHit);
  
          flashSpeed = ceil(flashSpeed*0.8);
          delay(1000);
        }
      // If we it the wrong LED, the level is reset. If we got a new highscore, it is updated.
      } else {
        nMiss++;
        ledErase();

        lcd.setCursor(2,1);
        lcd.print(nMiss);
        if(level > lastHighscore){
          lcd.setCursor(14,1);
          lcd.print(level);
          lastHighscore = level;
        }
        
        level = 1;
        flashSpeed = 20;
        delay(1000);
      }
      lcd.setCursor(14,0);
      lcd.print(level);
      led = 0;
    }
  }

  // Runs at variable speed, acording to flashSpeed
  if(count%flashSpeed == 0){
    // Lights the LEDs at random once level is 8 or above
    if(level >= 8){
      flashSpeed = 30;
      led = random(1,6);
    } else {
      led++;
    }

    // Lights the LED according to the led variable
    ledErase();
    switch(led){
      case 1:
        digitalWrite(led1, HIGH);
        break;
      case 2:
        digitalWrite(led2, HIGH);
        break;
      case 3:
        digitalWrite(led3, HIGH);
        break;
      case 4:
        digitalWrite(led4, HIGH);
        break;
      case 5:
        digitalWrite(led5, HIGH);
        led = 0;
        break;
    }
  }

  count++;
  delay(10);
  
}

/// Clears the LCD-display, and writes the text for the game
void lcdSetup(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("O:0");
  lcd.setCursor(0,1);
  lcd.print("X:0");
  lcd.setCursor(7,0);
  lcd.print("Level: 1");
  lcd.setCursor(5,1);
  lcd.print("HiScore: 0");
}

/// Turns off all LEDs
void ledErase(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}

/// Plays an animation on the LEDs. It is run when the correct LED is hit.
void correctHit(){
  int cSpeed = 200;
  ledErase();
  digitalWrite(led3, HIGH);
  delay(cSpeed);
  
  ledErase();
  digitalWrite(led2, HIGH);
  digitalWrite(led4, HIGH);
  delay(cSpeed);

  ledErase();
  digitalWrite(led1, HIGH);
  digitalWrite(led5, HIGH);
  delay(cSpeed);

  ledErase();
  digitalWrite(led2, HIGH);
  digitalWrite(led4, HIGH);
  delay(cSpeed);

  ledErase();
  digitalWrite(led3, HIGH);
  delay(cSpeed);

  ledErase();
  digitalWrite(led2, HIGH);
  digitalWrite(led4, HIGH);
  delay(cSpeed);

  ledErase();
  digitalWrite(led1, HIGH);
  digitalWrite(led5, HIGH);
  delay(cSpeed);

  ledErase();
  digitalWrite(led2, HIGH);
  digitalWrite(led4, HIGH);
  delay(cSpeed);

  ledErase();
  digitalWrite(led3, HIGH);
  delay(cSpeed);
}
