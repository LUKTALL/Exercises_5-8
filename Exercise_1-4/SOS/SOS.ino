/*
1a) 4 bits!

1b) 16!
*/

const uint8_t morseLed = LED_BUILTIN;
const int t = 200;
const char n = 2;  //chooses program ig

void setup() {
  pinMode(morseLed, OUTPUT);
}

void loop() {
  //1c) SOS thingy
  if(n == 0) {
  dot(); 
  dot();
  dot();
  
  smallSpace();
  
  dash();
  dash();
  dash();
  
  smallSpace();
  
  dot();
  dot();
  dot();
  
  bigSpace();
  }
  
  //1e) Write Mads thingy (only specifies one name. I am not writing Lukas!)
  if(n == 1) {
    dash();
    dash();
    
    smallSpace();
    
    dot();
    dash();
    
    smallSpace();
    
    dash();
    dot();
    dot();
    
    smallSpace();
    
    dot();
    dot();
    dot();
    
    bigSpace();
  }

  //1f) Write Mads (but with a lot of for loops)
  if(n == 2) {
    for(int i = 0; i < 2; i++){ 
      dash();
    }
    
    smallSpace();
    
    dot();
    dash();
    
    smallSpace();
    
    dash();
    for(int i = 0; i < 2; i++){ 
      dot();
    }
    
    smallSpace();
    for(int i = 0; i < 3; i++){ 
      dot();
    }
    dot();
    dot();
    dot();
    
    bigSpace();
  }
}

void dot(){
  digitalWrite(morseLed, HIGH);
  delay(t);
  digitalWrite(morseLed, LOW);
  delay(t);
}

void dash(){
  digitalWrite(morseLed, HIGH);
  delay(3*t);
  digitalWrite(morseLed, LOW);
  delay(t);
}

void smallSpace(){
  delay(3*t);
}

void bigSpace(){
  delay(7*t);
}
