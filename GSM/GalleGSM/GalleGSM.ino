#include <Ethernet.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>


#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pi

SoftwareSerial sms(2, 3); // RX | TX 
LiquidCrystal lcd(9,A1,A2,A3,A4,A5); 

int maximumRange = 800; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance
int temp =0;  
int hight = 0;
int buzz = 5;
const int gsmpow=4;
const int aCpow=A0;
int ac=0;
int acPin=6;
int rdlog[50]; 
 
int numberofReadings =25;
int averageDistance =0;
int i =0;
int x=0;
int y=0;
int masterDelay=247000;
int sensorValue = 0;
char loc[]="1004";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 10, 80, 1, 245};
byte server[] = {10, 10, 1,225}; // Server IP
uint8_t subnet[4] = {255, 255, 255, 0}; 
uint8_t gwaddr[4] = {10, 80, 1, 254};  
uint8_t dnsadr[4] = {10, 10, 1, 241}; 

String msg="";
String cmd="";
String svNo="+94776258166";
//String svNo="+94777548249";
EthernetClient client;


void(* resetFunc) (void) = 0;
void gsmPower();
void tideDataSend(); 
void gsmSetup();
int getDistance();
void sendSms(int height,float temp,int ac,int dir,int sp);
void setup() { 
     pinMode(aCpow, INPUT_PULLUP);
     pinMode(acPin, INPUT_PULLUP);
     Serial.begin (2400);
      sms.begin (2400);
     pinMode(gsmpow, OUTPUT);
     delay(3000);
     digitalWrite(gsmpow, HIGH);
     Ethernet.begin(mac, ip, dnsadr, gwaddr, subnet); 
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);
     pinMode(buzz,OUTPUT);
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
     
}

void loop() {

   tideDataSend();
   lcd.clear();
   lcd.setCursor(1, 0);
   lcd.print("AVG Tide Hight");
   lcd.setCursor(5, 1);
   lcd.print( averageDistance);
   lcd.print( "cm"); 
   delay(60000);
        //sensorValue = analogRead(A0);
      //Serial.println( sensorValue );

      //delay(2700);
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
     Serial.println("-1");
     
    for(int i=0; i<8; i++) 
    	{
               digitalWrite(buzz, HIGH);
               delay(5);
               digitalWrite(buzz, LOW);
    	}
     delay(1000);
      resetFunc();  //call reset
    }
     else {
      distance=170-distance;
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



void tideDataSend()
{
   
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
         digitalWrite(buzz, HIGH);
          
         delay(10);
         digitalWrite(buzz, LOW);
          
         
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
                     digitalWrite(buzz, HIGH);
                     delay(10);
                     digitalWrite(buzz, LOW);
          }
        lcd.clear(); 
        sensorValue = analogRead(A0);
      Serial.println("SeVal"+sensorValue);
        gsmSetup();
        delay(2000);
        sendSms(averageDistance,0,0,0,0);
        delay(2000);
        
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
    sms.print("at+ifc=1\r");
    
    while(sms.available())
    {  
        sms.write(sms.read());
    }
    
    sms.flush();
    
    sms.print("at");
    while(sms.available())
    {  
        Serial.write(sms.read());
    }
     sms.flush();
    delay(1000);
    sms.print("AT+CMGF=1\r");    
    while(sms.available())
      {  
          Serial.write(sms.read());
      }
       sms.flush();
     delay(2000);
  sms.println("AT + CMGS =\""+svNo+"\""); 
   while(sms.available())
    {  
        Serial.write(sms.read());
    } 
  delay(1000);
  sms.flush(); 
  sms.print(",tide,*");
  sms.print(height);
  sms.print("*");
  sms.print(temp);
  sms.print("*");
  sms.print(ac);
  sms.print("*");
  sms.print(sp);
  sms.print("*");
  sms.print(dir);
  sms.print("*");
  sms.write(0x1A);
  while (sms.available())
    {  
        Serial.write(sms.read());
    }
    delay(1000);
  sms.write(0x1A);
  sms.flush();
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Send SMS"); 
  while (sms.available())
    {  
        Serial.write(sms.read());
    }
  
   
  delay(500);

}

void gsmPower()
{
  
  digitalWrite(gsmpow, LOW);
  delay(2000);
  digitalWrite(gsmpow, HIGH);
  delay(2000);
}

void gsmSetup()
{
   delay(2000);
      sensorValue = analogRead(A0);
      Serial.println("SeVal"+sensorValue);
      
     if(sensorValue<500)
     {
       Serial.println("GSM ON");
         gsmPower();
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Power On GSM ");
        delay(2000);
     }
 
}




