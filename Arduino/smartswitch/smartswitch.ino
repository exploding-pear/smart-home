#include <SPI.h>
#include <WiFiNINA.h>
int status = WL_IDLE_STATUS;
const char * credentials = "xxx, xxx";

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  //connect to network
  NetConnect();
  //print out network info
  NetInfo();

}

void loop() {
// check the network status connection once every 10 seconds:
  Serial.println("hello, world!");
  Serial.println(WiFi.status());
  delay(5000); //wait 5 seconds
}

void NetInfo() {
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); 
}

void NetConnect() {
  //check for WiFi module
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed");
    //don't continue
    while (true);
  }

  //check for firmware update
  if (WiFi.firmwareVersion() < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  //attempt to connect to network
  while (status != WL_CONNECTED) {
    Serial.println("Attempting to connect to network");
    status = WiFi.begin(credentials);
    delay(10000);
  }

  Serial.print("Connected to network");
}
