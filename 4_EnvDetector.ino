#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0x20);

#define GAS_SENSOR A0
#define SOIL_SENSOR A1
#define TEMP_SENSOR A2

void setup() {
    Serial.begin(9600);
    
    lcd.begin(16, 2);
    lcd.setBacklight(HIGH); 

    lcd.setCursor(0, 0);
    lcd.print("Env Detector");
    delay(2000);
}

void loop() {
    
    float gasValue = analogRead(GAS_SENSOR);

    
    int soilValue = analogRead(SOIL_SENSOR);

   
    int tempValue = analogRead(TEMP_SENSOR);
    float voltage = tempValue * (5.0 / 1023.0);
    float temperature = (voltage - 0.5) * 100.0;

    
    Serial.print("Gas: "); Serial.print(gasValue);
    Serial.print(" | Soil: "); Serial.print(soilValue);
    Serial.print(" | Temp: "); Serial.print(temperature);
    Serial.println("C");

    
    lcd.setCursor(0, 0);
    lcd.print("G: "); lcd.print(gasValue);
    lcd.print(" S: "); lcd.print(soilValue);
    
    lcd.setCursor(0, 1);
    lcd.print("Temp: "); lcd.print(temperature);
    lcd.print("C   "); //

    delay(2000);
}
