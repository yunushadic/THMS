#include<LiquidCrystal_I2C_Hangul.h>
#include<Wire.h>
#include "DHT.h"
#define DHTPIN 2     
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C_Hangul lcd(0x27,16,2);
void setup() {
  Serial.begin(9600);
  Serial.println(F("Sıcaklık ve Nem Ölçme Sistemine Hoş Geldiniz"));
  Serial.println(F("Tüm Hakları Saklıdır"));
  Serial.println(F("Yunus HADİÇ"));
  Serial.println(F("+90 05377800530"));
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  
  delay(2000);

  float h = dht.readHumidity();
 
  float t = dht.readTemperature();
 
  float f = dht.readTemperature(true);

  
  lcd.print("    SICAKLIK");
  lcd.setCursor(1,1);
  lcd.print(t);
  lcd.setCursor(7,1);
  lcd.print(" Celsius");
  delay(2000);
  lcd.clear();
  

  
  lcd.print("      NEM");
  lcd.setCursor(0,1);
   lcd.setCursor(3,1);
  lcd.print(" % ");
  lcd.print(h);
  delay(2000);
  lcd.clear();

 

  Serial.print(F("Nem       : "));
  Serial.print(h);
  Serial.println("  %");
  Serial.print(F("Sıcaklık  : "));
  Serial.print(t);
  Serial.println(F(" °C"));
  
}
