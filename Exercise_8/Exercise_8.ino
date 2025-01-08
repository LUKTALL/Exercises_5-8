/*
 * 8a)
 * Our MCU has a 10-bit ADC, so it is in a range of 0-1023.
 * 
 * 8b)
 * 5 V
 * 
 * 8c)
 * It reads 1.67 volts, which is about half of the 3.3 V which is sent to the joystick (a potentiometer in disguise).
 * Thus the neutral position of the joystick must be the middle resistance of the potentiometer.
 */

uint8_t red = 10;
uint8_t green = 9;
uint8_t blue = 8;

void setup() {
  pinMode(red, OUTPUT); pinMode(green, OUTPUT); pinMode(blue, OUTPUT);
  digitalWrite(red, HIGH);
  Serial.begin(9600);
}

void loop() {
  int adc = analogRead(A0);
  float V = adc/1023.0 * 5.0;
  int B = adc/(1023*3.4/5) * 255;
  analogWrite(blue, 255-B);
  Serial.println(V, 3);
  delay(10);

}
