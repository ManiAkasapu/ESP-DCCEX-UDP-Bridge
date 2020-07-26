### About Sketch

This is generic ESP Sketch that can receive UDP data over Wifi. This can be used as command receiver for DCC++ or similar to technologies.

### Hardware & Setup

- ESP-01 (Tested)  or similar module

Edit the following in the sketch so that it uses your own wifi details


```IPAddress ip(192, 168, 0, 201); //REPLACE YOUR IP ADDRESS
IPAddress gateway(192, 168, 1, 1); // REPLACE YOUR GATEWAY
IPAddress subnet(255, 255, 255, 0); // SUBNET MASK

const char* ssid = "YOUR_BROADBAND_NAME";   // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "YOUR_PASSWORD";     // The password of the Wi-Fi network

unsigned int localUdpPort = 123;  // CHANGE THIS ACCORDING TO YOUR TASTE
char incomingPacket[255];  // buffer for incoming packets (can also reduce this)
char  replyPacket[] = "UDP Packet Received";  // a reply string to be sent back (you can customize this to your likining)
```

There are different ways uploading a sketch (ESP_WIFI_UDP.ino) to ESP. Some links below:

https://www.instructables.com/id/Getting-Started-With-Esp-8266-Esp-01-With-Arduino-/
https://create.arduino.cc/projecthub/ROBINTHOMAS/programming-esp8266-esp-01-with-arduino-011389



#### Connections - While running the ESP

ESP         Arduino

3.3v         3.3v

GND          GND

EN           3.3v

TX           RX

RX           TX


