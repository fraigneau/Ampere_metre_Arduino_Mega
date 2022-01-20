#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <EmonLib.h>

// adresse de l'ecrant lcd
LiquidCrystal_I2C lcd(0x27,16,2);

// creation de l'instance 
EnergyMonitor emon1;

void setup() {
  Serial.begin(9600); 


  // config calibrage Ampère_mètre
  emon1.current(1, 111.1); // truc chelou pour le calibrage 

  //lcd 
  lcd.setCursor(1,0); 
  lcd.backlight(); 
  lcd.init();

}

void loop() {
  double Irms = emon1.calcIrms(1480); // calculé juste les ampère

  // test Moniteur serie local
  Serial.print("A :");
  Serial.print(Irms*230.0);
  Serial.println(" ");


  //lcd afichage whatt (a venir)
  lcd.print("A : ");
  lcd.print(Irms);
  lcd.println("           ");
  delay(1000);
  lcd.clear();


}