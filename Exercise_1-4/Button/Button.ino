/*
3a) One is an input with a pull-up resister, the other is not. This is used for pins you want active LOW (protects against noise).

3b) ! is the "not" operator. Inverts the operand (or checks if a thing is not something else).
*/

const uint8_t led = 13;
const uint8_t button = 3;
const int t = 40;
bool s = 0;
const char n = 1;  //chooses program ig

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  //3c.1) On while press
  if(n == 0) {
    if(digitalRead(button) == LOW){
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
  }
  
  //3c.2) Toggle on
  if(n == 1){
    if(digitalRead(button) == LOW){
      s = !s;
      delay(t);
      digitalWrite(led, s);
      while(digitalRead(button) == LOW){
        //yuppiii!!!
      }
      delay(t);
    }
  }
}


/*
3d) currently it checks every clock-cycle, so about 16M times a second. We have a makeshift "debounce" to stop it from toggeling while being held
*/
