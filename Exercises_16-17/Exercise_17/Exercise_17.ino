
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* ssid = "NameName";
const char* pass = "Etellerandet";
WiFiClient client;

unsigned long channelID = 2808244; //your TS channal
const char * APIKey = "SO3K2J4ECVWTHK3Q"; //your TS API
const char* server = "api.thingspeak.com";
const int postDelay = 20 * 1000; //post data every 20 seconds

uint8_t led = D2;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
}

float data; //measured data
void loop() {
  data = 42.0;
  int rssi = WiFi.RSSI();
  if(rssi > -40){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  
  ThingSpeak.begin(client);
  client.connect(server, 80); //connect(URL, Port)
  int lastrssi = ThingSpeak.readIntField(channelID, 2, APIKey);
  Serial.print("Last signal strength was:\t");
  Serial.println(lastrssi);
  
  ThingSpeak.setField(1, data); //set data on the X (int) graph
  ThingSpeak.setField(2, rssi);
  ThingSpeak.setField(3, digitalRead(led));
  ThingSpeak.writeFields(channelID, APIKey);//post everything to TS
  
  client.stop();
  Serial.print("Data has been sent! The signal strength is:\t");
  Serial.println(rssi);
  delay(postDelay); //wait and then post again
}

/*
 * 17c)
 * explored! :)
 */
