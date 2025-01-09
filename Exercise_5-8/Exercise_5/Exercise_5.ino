/*
 * 5a)
 * If there are more than 0 bytes available in the serial communication, it will then proceede to read it.
 * Then it prints a confirmation message to the serial monitor and prints whatever it read before in decimal format.
 */

int incomingByte = 0;
  void setup() {
  Serial.begin(9600);
  }
void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println((char)incomingByte);
  }
}

/*
 * 5d)
 * We specify in the println command, that we want the value of incomingByte in decimal.
 * We get back the ASCII value in decimal format.
 * 
 * 5e)
 * We receive another number, 10. This represents the LF (line feed) special character in ASCII (line end).
 * 
 * 5f)
 * The (char) before the variable converts it to a char. Thus we just get the letters back to us.
 */
