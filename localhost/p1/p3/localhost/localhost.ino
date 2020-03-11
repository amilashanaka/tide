#include <Ethernet.h>
#include <SPI.h>
#include <SD.h>



#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED

int maximumRange = 800; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

int tempsensorPin = A0;
int hightsensorpin = A1;
int temp =0;  
int hight = 0;
int buzz = 9;
int numberofReadings =5;
const int chipSelect = 4;
int averageDistance =0;
char loc[]="1002";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 10, 10, 5, 78};
byte server[] = {10, 10, 5, 171 }; // Server IP

uint8_t subnet[4] = {255, 255, 255, 0}; 
uint8_t gwaddr[4] = {10, 10, 5, 254};  
uint8_t dnsadr[4] = {10, 10, 1, 241}; 
EthernetClient client;

 void(* resetFunc) (void) = 0;

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 
  for(int j=0;j<numberofReadings;j++)
  {
    
       /* The following trigPin/echoPin cycle is used to determine the
     distance of the nearest object by bouncing soundwaves off of it. */ 
     digitalWrite(trigPin, LOW); 
     delayMicroseconds(2); 
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10); 
     digitalWrite(trigPin, LOW);
     duration = pulseIn(echoPin, HIGH);
      //Calculate the distance (in cm) based on the speed of sound.
     distance = duration/58.2;
     if (distance >= maximumRange || distance <= minimumRange){
     /* Send a negative number to computer and Turn LED ON 
     to indicate "out of range" */
     Serial.println("-1");
     
      for(int i=0; i<8; i++) 
	{
	  
       digitalWrite(buzz, HIGH);
        delay(5);
         digitalWrite(buzz, LOW);
	}
     }
     else {
     /* Send the distance to the computer using Serial protocol, and
     turn LED OFF to indicate successful reading. */
      
     
      averageDistance = averageDistance+distance;
      
       Serial.print(j);
       Serial.print(" ");
      Serial.println(distance);
      delay(1000);
     }
     
  }

     averageDistance=averageDistance/numberofReadings;
      Serial.println(" Avarage Distence:");
      Serial.println( averageDistance);


 

 
 
 
  
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
      
      
      client.print("GET /tide/datacap.aspx?Hight=");// 10&temp=45 HTTP/1.0");
      client.print(78);
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
    
    for(int i=0; i<8; i++) 
	{
	  
       digitalWrite(buzz, HIGH);
        delay(10);
         digitalWrite(buzz, LOW);
	}
	  Serial.println("Restarting...");
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
