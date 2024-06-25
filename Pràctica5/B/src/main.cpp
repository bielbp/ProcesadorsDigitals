//Programa perque posi hello world

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,40,4);  // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
  


}

void loop() {

    // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Hello world!");
  
  lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
  lcd.print("LCD Tutorial");

  lcd.setCursor(1,2);   //Move cursor to character 2 on line 1
  lcd.print("Ander ves al metge");
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);   //Move cursor to character 2 on line 1
  lcd.print("Ander ves al metge");


}

//pagina per aprendre a fer servir el lcd https://lastminuteengineers.com/esp32-i2c-lcd-tutorial/

//Llibreria per el sensor de temperatura "enjoyering"