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
const int chipSelect = 4;
char loc[]="1002";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 10, 10, 5, 78};
byte server[] = {10, 10, 5, 171 }; // Server IP

uint8_t subnet[4] = {255, 255, 255, 0}; 
uint8_t gwaddr[4] = {10, 10, 5, 254};  
uint8_t dnsadr[4] = {10, 10, 1, 241}; 
EthernetClient client;



void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 
const int numOfReadings = 30;  
                    // stores the distance readings in an array
int arrayIndex = 0;                             // arrayIndex of the current item in the array
int total = 0;                                  // stores the cumlative total
int averageDistance = 0;                        // stores the average value


 for (int thisReading = 0; thisReading < numOfReadings; thisReading++) {
     
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
     digitalWrite(LEDPin, HIGH); 
     }
     else {
     
     averageDistance = averageDistance+distance;
     
       Serial.print(thisReading);
        Serial.print(" ");
      Serial.println(distance);
      delay(30000);
      
   }
 }


    averageDistance=averageDistance/numOfReadings;
 
  Serial.println(" Avarage Distence:");
   Serial.println( averageDistance);
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
      client.print(averageDistance);
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
                 delay(100);
                setup();
              }
              
   }

}
