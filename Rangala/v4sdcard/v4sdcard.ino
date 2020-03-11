#include <Ethernet.h>
#include <SPI.h>
#include <SD.h>
#include <stdio.h>
#include <DS1302.h>

#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
 
int maximumRange = 800; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

int tempsensorPin = A0;
int hightsensorpin = A1;
int temp =0;  
int hight = 0;
int buzz = 2;
int numberofReadings =2;
int averageDistance =0;
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

void(* resetFunc) (void) = 0;

const int kCePin   = 3;  // Chip Enable
const int kIoPin   = 5;  // Input/Output
const int kSclkPin = 6;  // Serial Clock

// Create a DS1302 object.
DS1302 rtc(kCePin, kIoPin, kSclkPin);

String  printTime() {
  // Get the current time and date from the chip.
  Time t = rtc.time();
 

  // Format the time and date and insert into the temporary buffer.
  char buf[50];
  snprintf(buf, sizeof(buf), " %02d/%02d/%04d %02d:%02d:%02d",
          
           t.mon, t.date, t.yr,
           t.hr, t.min, t.sec);

  // Print the formatted string to serial so we can see the time.
  
  return buf;
}



















void setup() {
 Serial.begin (9600);
  Ethernet.begin(mac, ip, dnsadr, gwaddr, subnet); 

 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 
 pinMode(buzz,OUTPUT);
 averageDistance =0;
 
//Time t(2014, 10, 3, 14,52 , 10, t.day);
// Set the time and date on the chip.
//rtc.time(t);
String dataString = "";
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
    // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    for(i=0; i<300; i++) 
	{
             digitalWrite(buzz, HIGH);
             delay(10);
             digitalWrite(buzz, LOW);
	}
  }
  else{
  Serial.println("card initialized.");
}
 
  
  {  /* The following trigPin/echoPin cycle is used to determine the
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
        resetFunc();  //call reset
     }
     else {
     /* Send the distance to the computer using Serial protocol, and
     turn LED OFF to indicate successful reading. */
      distance=219-distance;
      
     
       Serial.print(" ");
      Serial.println(distance);
      delay(15000);
     }
     
  }

     
      Serial.println(" Avarage Distence:");
      

   //Ethernet.begin(mac, ip);
  
  delay(50);
  
 dataString = "";
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile) {
      
      dataString = printTime()+"   "+averageDistance;
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
    
  }
  
  
  Serial.println("connecting...");
  
    if (client.connect(server, 80)) 
  {
      Serial.println("connected");
      String dataString = "";
      
     
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
	
	for(i=0; i<600; i++) 
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
                    delay(60000);
                    setup();
                  }
              
   }

}
