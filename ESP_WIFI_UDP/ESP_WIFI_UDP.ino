#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

IPAddress ip(192, 168, 0, 201); //REPLACE YOUR IP ADDRESS
IPAddress gateway(192, 168, 1, 1); // REPLACE YOUR GATEWAY
IPAddress subnet(255, 255, 255, 0); // SUBNET MASK

const char* ssid = "YOUR_BROADBAND_NAME";   // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "YOUR_PASSWORD";     // The password of the Wi-Fi network

WiFiUDP Udp;
unsigned int localUdpPort = 123;  // CHANGE THIS ACCORDING TO YOUR TASTE
char incomingPacket[255];  // buffer for incoming packets (can also reduce this)
char  replyPacket[] = "UDP Packet Received";  // a reply string to send back testing purposes
      
void setup() {
  
      Serial.begin(115200);  // Start the Serial communication to send messages to the computer
      delay(10);
      Serial.println('\n');

      // Static IP Setup Info Here...
      WiFi.config(ip, gateway, subnet);
      
      WiFi.begin(ssid, password);     // Connect to the network
      Serial.print("Connecting to ");
      Serial.print(ssid); 
      Serial.println(" ...");
    
      int i = 0;
      while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
        delay(1000);
        Serial.print(++i); Serial.print(' ');
      }
    
      Serial.println('\n');
      Serial.println("Connection to \'"+WiFi.SSID()+"\' established!");  
      Serial.print("IP address:\t");
      Serial.println(WiFi.localIP());         /* Send the IP address of the ESP8266 to the computer*/
    
      Udp.begin(localUdpPort);
      Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}


void loop()
{
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    // receive incoming UDP packets (test from ESP end)
    //Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    //Serial.printf("UDP packet contents: %s\n", incomingPacket);
    Serial.print(incomingPacket);
    
    // send back a reply, to the IP address and port we got the packet from
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write("Success");
    Udp.endPacket();
  }
}
