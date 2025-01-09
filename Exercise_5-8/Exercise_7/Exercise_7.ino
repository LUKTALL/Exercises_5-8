/*
 * 7a)
 * We can make a lot of colors with red, green and blue light (RGB light). The values between 0-255 is the intensity of each color.
 * Each color value is represented with a single byte (8 bits), thus the range from 0-255.
 * 
 * 7b)
 * Searches for the next integer in the serial communication.
 */

uint8_t red = 10;
uint8_t green = 9;
uint8_t blue = 8;
uint8_t RGB[3] = {0, 0, 0};
int n = 1;

void setup() {
  pinMode(red, OUTPUT); pinMode(green, OUTPUT); pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Serial chosen values
  if(n == 0){
    analogWrite(red, RGB[0]);
    analogWrite(green, RGB[1]);
    analogWrite(blue, RGB[2]);
    if(Serial.available() != 0){
      for(int i = 0; i<3; i++){
        int temp = Serial.parseInt();
        RGB[i] = temp;
        Serial.println(temp);
      }
    }
  }

  // Red-purple fade
  if(n == 1){
    digitalWrite(red, HIGH);
    delay(100);
    for(int i = 0; i<256; i++){
      analogWrite(blue, i);
      delay(10);
    }
  }
}
