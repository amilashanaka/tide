#include <OneWire.h>
#include <Ethernet.h>
#include <SPI.h>
#include <SD.h>
#include <stdio.h>
#include <LiquidCrystal.h>
#include <OneWire.h>

#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pi

OneWire  ds(A8); 
LiquidCrystal lcd(30, 31, 32, 33, 34, 35);


int maximumRange = 800; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance
int temp =0;  
int hight = 0;
int buzz1 = 36;
int buzz2 = 37;
const int gsmpow=38;
const int aCpow=39;
int wspeed =0;
int wdirect=0;
int ac=0;
int acPin=39;
int windPin=46;
int ledtide=41;
int ledwdir=43;
int ledwsp=45;
int ledtemp=47;
int ledsms=49;
int ledNet=50;
int rdlog[50]; 
 
int numberofReadings =15;
int averageDistance =0;
int i =0;
int x=0;
int y=0;
int masterDelay=247000;
int sensorValue = 0;
const int chipSelect = 4;
char loc[]="1005";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 10, 90, 17, 253};
byte server[] = {10, 10, 1,225}; // Server IP
uint8_t subnet[4] = {255, 255, 255, 0}; 
uint8_t gwaddr[4] = {10,90,17,254};  
uint8_t dnsadr[4] = {10, 10, 1, 241}; 

String msg="";
String cmd="";
String svNo="+94769840923";
EthernetClient client;

void(* resetFunc) (void) = 0;
const int kCePin   = 3;  // Chip Enable
const int kIoPin   = 5;  // Input/Output
const int kSclkPin = 6;  // Serial Clock
 
 
void gsmPower();
void tideDataSend(); 
void windDataSend();
void gsmSetup();
int getDistance();
float temperature();
void getWind();
void sendSms(int height,float temp,int ac,int dir,int sp);
void setup() {
     
     pinMode(aCpow, INPUT_PULLUP);
     pinMode(acPin, INPUT_PULLUP);
     Serial.begin (2400);
     Serial1.begin (2400);
     Serial2.begin(2400); 
     pinMode(gsmpow, OUTPUT);
     pinMode(windPin, OUTPUT);
     pinMode(41, OUTPUT);
     pinMode(43, OUTPUT);  
     pinMode(45, OUTPUT);  
     pinMode(47, OUTPUT);  
     pinMode(49, OUTPUT);  
     pinMode(42, OUTPUT); 
     pinMode(40,OUTPUT);
     digitalWrite(41, HIGH); 
     digitalWrite(43, HIGH);  
     digitalWrite(45, HIGH);  
     digitalWrite(47, HIGH);  
     digitalWrite(49, HIGH);  
     digitalWrite(42, HIGH);

     delay(3000);
     digitalWrite(41, LOW); 
     digitalWrite(43, LOW);  
     digitalWrite(45, LOW);  
     digitalWrite(47, LOW);  
     digitalWrite(49, LOW);  
     digitalWrite(42, LOW);  
         
     digitalWrite(gsmpow, HIGH);
     Ethernet.begin(mac, ip, dnsadr, gwaddr, subnet); 
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);
     pinMode(buzz1,OUTPUT);
     pinMode(buzz2,OUTPUT);
     lcd.begin(16, 2);
     lcd.setCursor(5, 0);
     lcd.print("Welcome");
     delay(1000);
     lcd.clear();
     lcd.setCursor(1, 0);
     lcd.print("Automatic Tide");
     lcd.setCursor(5, 1);
     lcd.print("Gauage");
     lcd.clear();
     gsmSetup();
}
//while (!Serial2) {
//    ; // wait for serial port to connect. Needed for native USB port only
//  }
void loop() {

    
   
      getWind();
     
     for(int i=0;i<10;i++){
        getWind();
        windDataSend();
         
     }
   
    
     tideDataSend(); 
     delay(180000);    
}

int getDistance(){
     
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
               digitalWrite(buzz1, HIGH);
               delay(5);
               digitalWrite(buzz1, LOW);
    	}
     delay(1000);
      resetFunc();  //call reset
    }
     else {
      distance=214-distance;
      Serial.print(" ");
      Serial.println(distance);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Tide Hight : ");
      lcd.setCursor(5, 1);
      lcd.print(distance);
      lcd.print(" Cm");
     }

      return distance;
}

float temperature()
{
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius, fahrenheit;
  
  if ( !ds.search(addr)) {
    Serial.println("No more addresses.");
   // Serial.println();
    ds.reset_search();
    delay(250);
    digitalWrite(ledtemp,HIGH);
    celsius=0;
  }
  
  //Serial.print("ROM =");
  for( i = 0; i < 8; i++) {
    //Serial.write(' ');
    //Serial.print(addr[i], HEX);
  }

  if (OneWire::crc8(addr, 7) != addr[7]) {
      Serial.println("CRC is not valid!");

       for(int i=0; i<8; i++) 
  {
           digitalWrite(buzz2, HIGH);
             digitalWrite(ledtemp, HIGH);
           delay(5);
           digitalWrite(buzz2, LOW);
           digitalWrite(ledtemp, LOW);
  }
  }
 // Serial.println();
 
  // the first ROM byte indicates which chip
  switch (addr[0]) {
    case 0x10:
      //Serial.println("  Chip = DS18S20");  // or old DS1820
      type_s = 1;
      break;
    case 0x28:
      //Serial.println("  Chip = DS18B20");
      type_s = 0;
      break;
    case 0x22:
     // Serial.println("  Chip = DS1822");
      type_s = 0;
      break;
    default:
      Serial.println("Device is not a DS18x20 family device.");
     
  } 

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);        // start conversion, with parasite power on at the end
  
  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.
  
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad

 
  //Serial.print(" ");
  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
   
  }
 
 
  // Convert the data to actual temperature
  // because the result is a 16 bit signed integer, it should
  // be stored to an "int16_t" type, which is always 16 bits
  // even when compiled on a 32 bit processor.
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // "count remain" gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
  }
  celsius = (float)raw / 16.0;
  fahrenheit = celsius * 1.8 + 32.0;
  //Serial.print("  Temperature = ");
 
  //Serial.print(" Celsius, ");
 
  return celsius;
}

void tideDataSend()
{
   digitalWrite(ledtemp, LOW);
   float temp=0;
   temp= temperature(); 
   if(temp<10){
     digitalWrite(ledtemp, HIGH);
    temp= temperature(); 
   }

   digitalWrite(ledtemp, LOW);
   averageDistance=0;
    x=0;
     for(int j=0;j<numberofReadings;j++){
          rdlog[j]=getDistance();
          y=abs(rdlog[j]-rdlog[j-1]);
          if(y<8)
          {
          averageDistance = averageDistance+distance;
           x++;
          }
          else{
            Serial.println("Not add");
          }
          delay(3000);
     }
    lcd.clear();
    lcd.setCursor(1, 0);
   
    delay(1000);
    averageDistance=averageDistance/x;
    Serial.println(" Avarage Distence:");
    Serial.println(averageDistance);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("AVG Tide Hight");
    lcd.setCursor(5, 1);
    lcd.print( averageDistance);
    lcd.print( " cm");
    
    Serial.println("connecting...");

     
   if (client.connect(server, 80)) 
    {
       
      Serial.println("connected");
      String dataString = "";
      //client.print("GET http://tide.navy.lk/datacap.aspx?Hight=");
      client.print("GET http://tide.navy.lk/datacap.aspx?Hight=");
      client.print(averageDistance);
      client.print("&Temp=");
      client.print(temp);
      client.print("&Loc=");
      client.print(loc);
      client.println(" HTTP/1.0");
      client.println();
      delay(1000);
      for(i=0; i<10; i++) 
      {
         digitalWrite(buzz1, HIGH);
          
         delay(10);
         digitalWrite(buzz1, LOW);
          
         
      }
         digitalWrite(ledtide, HIGH);
         delay(2000);
         digitalWrite(ledtide, LOW);
                  
  }
  else 
  {
    Serial.println("connection failed");
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("No Network");
        digitalWrite(ledtide, HIGH);
        for(i=0; i<80; i++) 
          {
                     digitalWrite(buzz1, HIGH);
                     delay(10);
                     digitalWrite(buzz1, LOW);
          }
        lcd.clear(); 
        digitalWrite(ledsms, HIGH); 
        sendSms(averageDistance,temp,ac,wdirect,wspeed);
        setup();
  }


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
                  }
              
   }
  
}

void windDataSend()
{  float temp=0;
   temp=temperature();
   while(temp<10){
    temp= temperature(); 
   }
 
    Serial.println("connecting...");
    if(wspeed==0)
    {
        digitalWrite(ledwsp, HIGH);
         
    }

    if(wdirect==0)
    {
      digitalWrite(ledwdir, HIGH);
    }

     
   if (client.connect(server, 80)) 
    {
      
       
      Serial.println("connected");
      String dataString = "";
      client.print("GET /wind/datacap.aspx?Loc=");
      client.print(loc);
      client.print("&Sp=");
      client.print(wspeed);
      client.print("&Wdir=");
      client.print(wdirect);
      client.println(" HTTP/1.0");
      client.println();
      delay(1000);
      for(i=0; i<10; i++) 
      {
         digitalWrite(buzz1, HIGH);
         delay(10);
         digitalWrite(buzz1, LOW);
      }
                    
  }
  else 
  {
        Serial.println("connection failed");
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("No Network");
        for(i=0; i<80; i++) 
          {
                     digitalWrite(buzz1, HIGH);
                     delay(10);
                     digitalWrite(buzz1, LOW);
          }
        delay(3000);
         lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Call"); 
           lcd.setCursor(5, 1);
    lcd.print("12468");
        //sendSms(averageDistance,temp);
        //delay(masterDelay);// Master delay
         delay(3000);
         //resetFunc(); 
  }


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
                     
                  }
              
   }
  
}

void sendSms(int height,float temp,int ac,int dir,int sp)
{

    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("SMS Gatway");
    lcd.setCursor(5, 1);
    lcd.print("Starting..");
    delay(1000);
    Serial1.print("at+ifc=1\r");
    
    while(Serial1.available())
    {  
        Serial.write(Serial1.read());
    }
    
    Serial1.flush();
    
    Serial1.print("at");
    while(Serial1.available())
    {  
        Serial.write(Serial1.read());
    }
     Serial1.flush();
    delay(1000);
    Serial1.print("AT+CMGF=1\r");    
    while(Serial1.available())
      {  
          Serial.write(Serial1.read());
      }
       Serial1.flush();
     delay(2000);
  Serial1.println("AT + CMGS =\""+svNo+"\""); 
   while(Serial1.available())
    {  
        Serial.write(Serial1.read());
    } 
  delay(1000);
  Serial1.flush(); 
  Serial1.print(",tide,*");
  Serial1.print(height);
  Serial1.print("*");
  Serial1.print(temp);
  Serial1.print("*");
  Serial1.print(ac);
  Serial1.print("*");
  Serial1.print(sp);
  Serial1.print("*");
  Serial1.print(dir);
  Serial1.print("*");
  Serial1.write(0x1A);
  while (Serial1.available())
    {  
        Serial.write(Serial1.read());
    }
    delay(1000);
  Serial1.write(0x1A);
  Serial1.flush();
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Send SMS"); 
  while (Serial1.available())
    {  
        Serial.write(Serial1.read());
    }
  
   
  delay(500);

}

void gsmPower()
{
  
  digitalWrite(gsmpow, LOW);
  delay(1000);
  digitalWrite(gsmpow, HIGH);
  delay(2000);
}

void gsmSetup()
{
      
      sensorValue = analogRead(A7);
        
      
     if(sensorValue<350)
     {
        gsmPower();
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Power On GSM ");
        delay(2000);
     }
     else
     {
        
     }

      
  
}

void getWind()
{ 

    digitalWrite(ledtemp, LOW);
    float temp=0;
    temp= temperature();
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Temperature");
    lcd.setCursor(5, 1);
    lcd.print(temp);
     digitalWrite(windPin, LOW);
       delay(100);
        digitalWrite(windPin, HIGH);
        
    Serial.print("Tempecture :");
    Serial.print(temp); 
    ac=digitalRead(acPin);
    String wdst=Serial2.readString();
    delay(500);
    String input = wdst;
    float firstVal, secondVal;

for (int i = 0; i < input.length(); i++) {
  if (input.substring(i, i+1) == "-") {
    firstVal = input.substring(0, i).toFloat();
    secondVal = input.substring(i+1).toFloat();
    break;
  }
}

    wspeed =abs((int)firstVal);
    wdirect=abs((int)secondVal);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Wind Speed");
    lcd.setCursor(5, 1);
    lcd.print(wspeed);
    lcd.print( "m/s");

    delay(1000);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Wind Angle");
    lcd.setCursor(5, 1);
    lcd.print(wdirect);
     Serial.println();
    Serial.println("Wind Speed");
    Serial.print(wspeed);
    Serial.println();
    Serial.println("Wind Angle" );
    Serial.print(wdirect);
    Serial.println();

}


