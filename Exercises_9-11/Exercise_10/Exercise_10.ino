/*
 * 9a)
 * Datasheet says 0 mV + 10 mV/°C in the range from 2°C-150°C.
 * Thus V_A0 = 10mV*T (where T is the temperature in celcius in the range [2;150])
 * 
 * 9b)
 * This should show the following in the serial monitor:
 * 0°2°4°6°
 * 
 * 9c)
 * print() interprets the input of the function as the data to be sent,
 * while write() interprets it as a single byte to be written to the serial port.
 * 
 * print(176) would print the bytes for 1, 7 and 6. while write(176) would only send the byte represented by the value 176 (in this case "°")
 */

uint8_t LM35 = A0;
float T = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LM35, INPUT);
}

void loop() {
  int adc = analogRead(LM35);
  T = adc/1023.0 * 5.0 / 0.01;
  Serial.print(T, 3);
  Serial.println("°");
  delay(200);
}

/*
 * 9f)
 * It seems to be stable around ~23°C, goes to 28-29°C while being squished with fingers, and drops down to steady state afterwards.
 */
