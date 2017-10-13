#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define LED_PIN D5

// network credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

ESP8266WebServer server(80);

void ledOn() {
  digitalWrite(LED_PIN, HIGH);
}

void ledOff() {
  digitalWrite(LED_PIN, LOW);
}

void wifiConnect() {
  WiFi.begin(ssid, password);
  Serial.println("");

  // wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  ledOff();

  delay(1000);
  Serial.begin(115200);

  // only connect to wifi if not yet connected
  // otherwise, this would block if you e.g. restarted the esp via RST-Button or flashing while a connection is already established
  if (WiFi.status() != WL_CONNECTED)
    wifiConnect();
 
  Serial.println("");
  Serial.print("connected to ");
  Serial.println(ssid);
  Serial.print("ip address: ");
  Serial.println(WiFi.localIP());

  // blinking LED to signal successful wifi connection
  for (auto i = 0; i < 4; i++) {
    ledOn();
    delay(200);
    ledOff();
    delay(200);
  }
  
  // create routes for server
  //
  // http://[ip_address]/on should be used to turn the led on
  // http://[ip_address]/off should be used to turn the led off
  //
  // the returned website is simply "", since the server doesn't need to display any content
  server.on("/on", [](){
    server.send(200, "text/html", "");
    ledOn();
  });
  server.on("/off", [](){
    server.send(200, "text/html", "");
    ledOff();
  });

  // start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
