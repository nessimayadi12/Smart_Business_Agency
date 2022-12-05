#include <LiquidCrystal_I2C.h>





LiquidCrystal_I2C lcd(0x27, 20, 2);
char data;






void setup() {
  
   lcd.init();// initialize the lcd
   lcd.backlight();// Print a message to the LCD.

 
  Serial.begin(9600);
  lcd.print("partnaire");
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()) {

    data = Serial.read();

    if (data == '1')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("inncorret");
      Serial.write('1');

      


    }
     if (data == '2')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("bienvenue");
      Serial.write('2');



    }
    else if (data == '0')
    {
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print(" erreur ");
      Serial.write('0'); //envoyer le nouvel état de la lampe
      lcd.clear();
      lcd.print(" erreur ");
      // Serial.print(data);
    }

    }

 
}
