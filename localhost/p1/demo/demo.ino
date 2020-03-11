#include <Ethernet.h>
#include<SPI.h>

int temp=0;
int tempsensorPin = A0;
 
char loc[]="1002";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 10, 10, 5, 148};
byte server[] = {10, 10, 5, 171 }; // Server IP

uint8_t subnet[4] = {255, 255, 255, 0}; 
uint8_t gwaddr[4] = {10, 10, 5, 254};  
uint8_t dnsadr[4] = {10, 10, 1, 241}; 
EthernetClient client;



void setup() {

   Ethernet.begin(mac, ip);
   //Ethernet.begin(mac, ip, dnsadr, gwaddr, subnet); 
  Serial.begin(9600);
  delay(10);
  
  Serial.println("connecting...");
  
    if (client.connect(server, 80)) 
  {
      Serial.println("connected");
      String dataString = "";
      temp = analogRead(tempsensorPin);
    
      Serial.println(temp);
 
      
      
      client.print("GET /tide/datacap.aspx?Hight=");// 10&temp=45 HTTP/1.0");
      client.print(temp);
      client.print("&Temp=");
      client.print(temp);
      client.print("&Loc=");
      client.print(loc);
      client.println(" HTTP/1.0");
      client.println();
     
      delay(10);
  }
  
  else 
  {
    Serial.println("connection failed");
  }
  
  
}

void loop() {
  
  while (client.connected())
   {
              if (client.available()) {
                char c = client.read();
                Serial.print(c);
               
              }
              if (!client.connected()) {
                Serial.println();
                Serial.println("disconnecting.");
                client.stop();
                 delay(10);
                setup();
              }
              
   }

}
