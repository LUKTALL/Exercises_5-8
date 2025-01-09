/*
   10a)
   Cold: T =< 20
   Mild: 26 >= T > 20
   Hot: T > 26
*/

uint8_t LM35 = A0;
float T = 0;
uint8_t red = 8;
uint8_t yellow = 5;
uint8_t green = 2;

void setup() {
  pinMode(red, OUTPUT); pinMode(yellow, OUTPUT); pinMode(green, OUTPUT);
  pinMode(LM35, INPUT);
  Serial.begin(9600);
}

void loop() {
  int adc = analogRead(LM35);
  T = adc / 1023.0 * 5.0 / 0.01;
  Serial.print(T, 3);
  Serial.println("°");

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);

  if (T <= 20) {
    digitalWrite(green, HIGH);
  } else if (T >= 26) {
    digitalWrite(red, HIGH);
  } else {
    digitalWrite(yellow, HIGH);
  }
  delay(200);
}

/*
   9f)
   It seems to be stable around ~23°C, goes to 28-29°C while being squished with fingers, and drops down to steady state afterwards.
*/
