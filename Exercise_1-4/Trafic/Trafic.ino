/*
2a) Modulus! Answer is 2.
*/

const uint8_t red = 13;
const uint8_t yellow = 7;
const uint8_t green = 2;
const int t = 1000;
const char n = 1;  //chooses program ig

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  Serial.begin(115200); //I care about your baudrate
}

void loop() {
  //2b) Trafic light!
  if(n == 0){
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  Serial.println("HALT TARNISHED!");
  delay(t);

  digitalWrite(yellow, HIGH);
  Serial.println("PREPARE THYSELF!");
  delay(t);

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  Serial.println("pwease dwrive...");
  delay(2*t);

  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  Serial.println("DOWNTREND THY VELOCITY!");
  delay(t);
  }

  //2c) Binary counter
  if(n == 1){
    uint8_t bit1 = 1;
    uint8_t bit2 = 2;
    uint8_t bit3 = 4;

    for(int i = 0; i<8; i++){
      digitalWrite(red, LOW); digitalWrite(yellow, LOW); digitalWrite(green, LOW);
      
      if((i & bit1) == 1){
        digitalWrite(green, HIGH);
      }
      if((i & bit2) == 2){
        digitalWrite(yellow, HIGH);
      }
      if((i & bit3) == 4){
        digitalWrite(red, HIGH);
      }
      delay(t);
    }
  }
}

/*
2d) using %2 can check, if the LSB is high. By checking each bit with right shifts (>>) in series, the state of each bit can be checked.
*/
