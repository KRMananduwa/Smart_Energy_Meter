#include <Wire.h>
#include <LiquidCrystal_I2C_JHD1214.h>

  LiquidCrystal_I2C lcd(0x7C>>1, 16, 2);
 // JHD-2X16-I2C Display Device Addrress must be shift right by 1 to match in Proteus

void setup() {
  lcd.begin();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LCD DISPLAY JHD");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.printstr("1214 BY GIOROCK");
  delay(1000);
}

void loop() {
 
  lcd.setCursor(0, 1);
 
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
 
  delay(100);

}
