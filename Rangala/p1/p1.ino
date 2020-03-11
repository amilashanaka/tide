#include <Ethernet.h>
#include <SPI.h>
#include <SD.h>



#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED


int maximumRange = 400; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

int tempsensorPin = A0;
int hightsensorpin = A1;
int temp =0;  
int hight = 0;
int buzz = 4;
const int chipSelect = 4;
char loc[]="1002";
int i =0;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 10, 30, 7, 150};
byte server[] = {10, 10, 1,225}; // Server IP
uint8_t subnet[4] = {255, 255, 255, 0}; 
uint8_t gwaddr[4] = {10, 30, 7, 254};  
uint8_t dnsadr[4] = {10, 10, 1, 241}; 
EthernetClient client;



void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 pinMode(buzz,OUTPUT);
 

  
  
  /* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 void(* resetFunc) (void) = 0; //declare reset function @ address 0
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 digitalWrite(LEDPin, HIGH); 
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);
 digitalWrite(LEDPin, LOW); 
 }
 
 //Delay 50ms before next reading.
 delay(50);
 
 
 
  
   //Ethernet.begin(mac, ip);
   Ethernet.begin(mac, ip, dnsadr, gwaddr, subnet); 
  Serial.begin(9600);
  delay(50);
  
  Serial.println("connecting...");
  
    if (client.connect(server, 80)) 
  {
      Serial.println("connected");
      String dataString = "";
      temp = analogRead(tempsensorPin);
      hight=analogRead(hightsensorpin);
      Serial.println(temp);
      Serial.println(hight);
      
      distance=219-distance;
      client.print("GET http://tide.navy.lk/datacap.aspx?Hight=");// 10&temp=45 HTTP/1.0");
      client.print(distance);
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
	
	for(i=0; i<8; i++) 
	{
	  
       digitalWrite(buzz, HIGH);
        delay(10);
         digitalWrite(buzz, LOW);
	}
	
	 resetFunc();  //call reset
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
                 delay(5000);
                setup();
              }
              
   }

}
