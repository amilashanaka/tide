#include <Ethernet.h>
#include <SPI.h>
#include <SD.h>
#include <stdio.h>
#include <DS1302.h>
#include <LiquidCrystal.h>

#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); 

int maximumRange = 800; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

//int tempsensorPin = A0;
//int hightsensorpin = A1;
int temp =0;  
int hight = 0;
int buzz = 2;
int numberofReadings =13;
int averageDistance =0;
const int chipSelect = 4;
char loc[]="1002";
int i =0;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 10,10, 5, 179};
byte server[] = {10, 10, 5,171}; // Server IP
uint8_t subnet[4] = {255, 255, 255, 0}; 
uint8_t gwaddr[4] = {10, 10, 5, 254};  
uint8_t dnsadr[4] = {10, 10, 1, 241}; 
EthernetClient client;

void(* resetFunc) (void) = 0;

const int kCePin   = 3;  // Chip Enable
const int kIoPin   = 5;  // Input/Output
const int kSclkPin = 6;  // Serial Clock

    // Create a DS1302 object.
    DS1302 rtc(kCePin, kIoPin, kSclkPin);
    String  printTime();
    void cardSetup();
    void getDistance();
  
void setup() {
     Serial.begin (9600);
     Ethernet.begin(mac, ip, dnsadr, gwaddr, subnet); 
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);
     pinMode(buzz,OUTPUT);
     lcd.begin(16, 2);
     lcd.setCursor(5, 0);
       lcd.print("Welcome");
       delay(500);
       lcd.clear();
      lcd.setCursor(1, 0);
       lcd.print("Automatic Tide");
       lcd.setCursor(5, 1);
         lcd.print("Gauage");
       delay(1000);
       lcd.clear();
     //Set the time and date on the chip uncomment and run.
       //Time t(2016, 6, 6, 15,48 , 0, t.day);
      //rtc.time(t);

       Serial.println(printTime());
       averageDistance=0;
       for(int j=0;j<numberofReadings;j++){
          getDistance();
          averageDistance = averageDistance+distance;
          delay(1000);
     }
    averageDistance=averageDistance/numberofReadings;
    Serial.println(" Avarage Distence:");
    Serial.println( averageDistance);
    delay(500);

  Serial.println("connecting...");
    if (client.connect(server, 80)) 
    {
      Serial.println("connected");
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Connected");
      String dataString = "";
      client.print("GET /tide/datacap.aspx?Hight=");
      client.print(averageDistance);
      client.print("&Temp=");
      client.print(temp);
      client.print("&Loc=");
      client.print(loc);
      client.println(" HTTP/1.0");
      client.println();
      delay(500);
  }
  else 
  {
    Serial.println("connection failed");
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("No Network");
        for(i=0; i<800; i++) 
	{
             digitalWrite(buzz, HIGH);
             delay(10);
             digitalWrite(buzz, LOW);
	}
             lcd.clear();
	   
        delay(500);
        cardSetup();
   
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
                    delay(1000);
                    setup();
                  }
              
   }

}

String  printTime() {
    // Get the current time and date from the chip.
       Time t = rtc.time();
      
  // Format the time and date and insert into the temporary buffer.
     char buf[50];
     snprintf(buf, sizeof(buf), " %02d/%02d/%04d %02d:%02d:%02d",
          
           t.mon, t.date, t.yr,
           t.hr, t.min, t.sec);
   rtc.writeProtect(false);
  rtc.halt(false);
  // Print the formatted string to serial so we can see the time.
     return buf;
}


void cardSetup(){
  String dataString = "";
  
        Serial.print("Initializing SD card...");
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Initializing SD card ");
        delay(5000);
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Data Save..");
        delay(5000);
        pinMode(10, OUTPUT);
        // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Card Failed..");
        delay(1000);
        // don't do anything more:
        for(i=0; i<300; i++) 
    	{
                 digitalWrite(buzz, HIGH);
                 delay(50);
                 digitalWrite(buzz, LOW);
    	}
        resetFunc();  //call reset
  }
  else{
  Serial.println("card initialized.");
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Card initialized");
     delay(500);
  
}

    dataString = "";
    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile) {
      dataString = printTime()+"   "+averageDistance;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(printTime());
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
    delay(5000);
    resetFunc();  //call reset
   }  
  // if the file isn't open, pop up an error:
   else {
    Serial.println("error opening datalog.txt");
    
   }
 
}


void getDistance(){
     
     duration=0;
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
     delay(500);
      resetFunc();  //call reset
    }
     else {
     // distance=250-distance;
      Serial.print(" ");
      Serial.println(distance);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Tide Hight : ");
      lcd.setCursor(5, 1);
      lcd.print(distance);
      lcd.print(" Cm");
     }
      
}
