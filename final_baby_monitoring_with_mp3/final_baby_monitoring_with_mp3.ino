#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(6, 7); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char command;
int pausa = 0;
uint8_t id,pa;

 
void setup ()
{
   mySoftwareSerial.begin(9600);
   Serial.begin(9600);
 lcd.begin(16, 2);
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("      BABY");
   lcd.setCursor(0, 1);
  lcd.print(" MONITOR SYSTEM");
  delay (2000);
 
if (!myDFPlayer.begin(mySoftwareSerial))
{
while (true);
}
myDFPlayer.setTimeOut(500); //Timeout serial 500ms
myDFPlayer.volume(30); //Volume 5
myDFPlayer.EQ(0); //Equalizacao normal  

   pinMode(2,OUTPUT); 
          pinMode(3,OUTPUT); 

}

void loop() 
{

float w = analogRead(A0);
delay(100); 
w = w * (5.0 / 1023.0);
delay(100);
w=1/w*100;
delay(100);

float s = analogRead(A1);
delay(100); 
s = s * (5.0 / 1023.0);
delay(100);
s=s*10;


float t = analogRead(A2);
delay(100); 
t = t* (5.0 / 1023.0);
delay(100);
t=t*100;


  lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("W:");
    lcd.print(w);
    lcd.setCursor (10,0);
    lcd.print("S:");
    lcd.print(s);
    lcd.setCursor (0,1);
    lcd.print("T:");
    lcd.print(t);
    delay(1000);
Serial.print(t); 
Serial.print(","); 
Serial.println(w);
   delay(500);




if(s>3)
{

  
digitalWrite(3,HIGH);
  lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("BABY CRY");
 myDFPlayer.play(01);
 delay(10000);

}

else if(w>30)
{
digitalWrite(2,HIGH);
  lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("WET HIGH");
}
else if(t>50)
{
digitalWrite(2,HIGH);
  lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("TEMPERATURE HIGH");
}

else
{
digitalWrite(3,LOW);
digitalWrite(2,LOW);
}


 
  }  


  

 