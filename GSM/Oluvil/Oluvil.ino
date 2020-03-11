#include <SoftwareSerial.h>
#include <LiquidCrystal.h>


SoftwareSerial sms(2, 3); // RX | TX
LiquidCrystal lcd(13,12,11,10,9,8); 
#define echoPin 6 // Echo Pin
#define trigPin 7 // Trigger Pi

int maximumRange = 800; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance
int temp =0;  
int hight = 0;
const int gsmpow = 4;
const int aCpow = A1;
const int led = A2;
const int buzz =5;
int sensorValue = 0;
//===================================================
String msg = "";
String cmd = "";
String svNo="+94769840923";
//String svNo="+94777548249";
int rdlog[50];  
int numberofReadings =5;
int averageDistance =0;
int i =0;
int x=0;
int y=0;

char loc[]="1005";

//==================================
void(* resetFunc) (void) = 0;
void tideDataSend(); 

void gsmSetup();
int getDistance();
void sendSms(int height,float temp,int ac);

void setup()
{
  pinMode(aCpow, INPUT_PULLUP);
  Serial.begin(2400);
  sms.begin(2400);

 
 
  pinMode(buzz, OUTPUT);
  pinMode(gsmpow, OUTPUT);
    pinMode(led, OUTPUT);
  digitalWrite(gsmpow, HIGH);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  

  lcd.begin(16, 2);
  lcd.setCursor(5, 0);
  lcd.print("Welcome");
  digitalWrite(led,HIGH);
  delay(1000);
    digitalWrite(led,LOW);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("GSM Tide");
  lcd.setCursor(5, 1);
  lcd.print("Gauage");
  gsmSetup();


  
}

void loop()
{
   tideDataSend(); 
  
    delay(5000);
    digitalWrite(gsmpow, LOW);
    delay(2000);
    digitalWrite(gsmpow, HIGH);
    delay(2000);
    while (sms.available())
  {
    Serial.write(sms.read());
  }

     sensorValue = analogRead(A0);
     Serial.println(sensorValue);
   delay(900000);
    
}

//=============================================================
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
     lcd.clear();
     lcd.setCursor(1, 0);
     lcd.print("Tide Sensor");
     lcd.setCursor(5, 1);
     lcd.print("Fail");
    
     delay(2500);
    for(int i=0; i<800; i++) 
      {
               digitalWrite(buzz, HIGH);
               delay(5);
               digitalWrite(buzz, LOW);
      }
     delay(5000);
      resetFunc();  //call reset
    }
     else {
      distance=221-distance;
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
//=====================================================
void tideDataSend()
{
   
  
    
     averageDistance=0;
     x=0;
     for(int j=0;j<numberofReadings;j++){
          rdlog[j]=getDistance();
          for(int i=0; i<5; i++) 
      {
               digitalWrite(buzz, HIGH);
               delay(5);
               digitalWrite(buzz, LOW);
      }
          y=abs(rdlog[j]-rdlog[j-1]);
          if(y<10)
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
    sendSms(averageDistance,0,0);
    for(int i=0; i<20; i++) 
      {
               digitalWrite(buzz, HIGH);
               delay(5);
               digitalWrite(buzz, LOW);
      }
     

}
//=================================================
void sendSms(int height,float temp,int ac)
{
   sensorValue = analogRead(A0);
     Serial.println(sensorValue);
  if (sensorValue < 25)
  {
    Serial.println("GSM OFF");
    delay(1000);
    digitalWrite(gsmpow, LOW);
    delay(2000);
    digitalWrite(gsmpow, HIGH);
    delay(2000);
  }

    delay(1000);
  sms.print("AT+CMGF=1\r");

  while (sms.available())
  {
    Serial.write(sms.read());
  }

  
  delay(500);
 // sms.println("AT + CMGS =\"+94777548249\"");
 sms.println("AT + CMGS =\""+svNo+"\""); 
// sms.println("AT + CMGS =\"+94777548249\""); 
  while (sms.available())
  {
    Serial.write(sms.read());
  }
  delay(500);

  sms.print(",tide,*");
  sms.print(height);
  sms.print("*");
  sms.print(temp);
  sms.print("*");
  sms.print(ac);
  sms.print("*");
  sms.print(0);
  sms.print("*");
  sms.print(0);
  sms.print("*");
  sms.write(0x1A);
  
  
  
  digitalWrite(led,HIGH);
  while (sms.available())
  {
    Serial.write(sms.read());
  }
  delay(500);

  sms.write(0x1A);
    sms.write(0x1A);
  while (sms.available())
  {
    Serial.write(sms.read());
  }

  delay(500);

  sms.write(0x1A);
  while (sms.available())
  {
    Serial.write(sms.read());
  }
  delay(500);
  Serial.println("send");
    digitalWrite(led,LOW);
}

//=========================================

void gsmSetup()
{
      
      sensorValue = analogRead(A0);
     Serial.println(sensorValue);

  if (sensorValue < 25)
  {
    delay(1000);
    digitalWrite(gsmpow, LOW);
    delay(2000);
    digitalWrite(gsmpow, HIGH);
    delay(2000);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Power On GSM ");
    

  }
  else
  {
    Serial.println(sensorValue);
  }
  
  sensorValue = analogRead(A0);
  
 Serial.println(sensorValue);




}


