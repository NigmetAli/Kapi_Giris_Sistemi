#include <Keypad.h>
#include <LiquidCrystal.h>
const byte satirSayisi= 4;
const byte sutunSayisi= 4;

char tuslar[satirSayisi][sutunSayisi]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte satirPinleri[satirSayisi] = {9,8,7,6};
byte sutunPinleri[sutunSayisi]= {5,4,3,2};
String degisken="";
String sifre = "1595";

Keypad tusTakimi= Keypad(makeKeymap(tuslar), satirPinleri, sutunPinleri, satirSayisi, sutunSayisi);
LiquidCrystal lcd(12,11,5,4,3,2);
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("SIFRE GIRINIZ");
  lcd.setCursor(0,1);
  pinMode(10,OUTPUT);
}

void loop(){
char basilanTus = tusTakimi.getKey();

  if (basilanTus != NO_KEY){
    degisken += basilanTus;
    
    lcd.print("*");      
    
    digitalWrite(10,HIGH);
    delay(100);
    digitalWrite(10,LOW);
      
   if(degisken.length()==4)
   {
    if(degisken == sifre)
    {
      Serial.println("Sifre Dogru");
      lcd.clear();
      lcd.print("VAAAY GARDASIM");
      lcd.setCursor(0,1);
      lcd.print("HOSGELDIN");
      degisken="";
      digitalWrite(10,HIGH);
      delay(1000);
      digitalWrite(10,LOW);
      
      lcd.clear();
      lcd.print("SIFRE GIRINIZ");
      lcd.setCursor(0,1);
        
    }  
    else
    {
      degisken="";
      Serial.println("Sifre Yanlis Tekrar Deneyin");
   
      lcd.clear();
      lcd.print("YANLIS SIFRE");
      lcd.setCursor(0,1);
      lcd.print("TEKRAR DENEYINIZ");  
      
        digitalWrite(10,HIGH);
        delay(100);
        digitalWrite(10,LOW);
        delay(10);
        digitalWrite(10,HIGH);
        digitalWrite(10,LOW);
        delay(10);
        digitalWrite(10,HIGH);
        delay(100);
        digitalWrite(10,LOW);
        
        delay(1500);
        
        lcd.clear();
        lcd.print("SIFRE GIRINIZ");
        lcd.setCursor(0,1);
     
    }
 
   } 
  }

  char gelenSifre[5] = "    ";
}

