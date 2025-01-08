/*
 * 6a)
 * A char uses 8 bits.
 * 
 * 6b)
 * Talking in base10, the char '4' = 52. Removing '0' = 48 would be 4, an "END OF TRANSMISSION" char.
 * Adding 'A' = 65 and removing 1 would be 68, of which a char would be 'D'.
 */

char in;

void setup() {
  DDRA = 0b00011111;
}

void loop() {
  if(Serial.available() != 0){
    PORTA = 0x00;
    in = Serial.read();
    switch (in){
      case 'a':
        PORTA |= (1<<DDA0);
        break;
      case 'b':
        PORTA |= (1<<DDA1);
        break;
      case 'c':
        PORTA |= (1<<DDA2);
        break;
      case 'd':
        PORTA |= (1<<DDA3);
        break;
      case 'e':
        PORTA |= (1<<DDA4);
        break;
      default:
        PORTA = 0x00; //redundant, but oh well
        break;
    }
  }
}
