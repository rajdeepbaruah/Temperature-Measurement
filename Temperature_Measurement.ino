//Code Written By RAJDEEP BARUAH

//Libraries
#include <DHT.h>
#include<LiquidCrystal.h>

//Constants
#define DHTPIN 7    // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11 (AM2302)
DHT dht(DHTPIN, DHTTYPE);   //Initialize DHT sensor for normal 16mhz Arduino

//Variables
float hum;
float temp;

//LCD Object
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
  {
    Serial.begin(9600);
    dht.begin();
    lcd.begin(16,2);
  }

  void loop()
  {
    delay(2000);
    hum=dht.readHumidity();
    temp=dht.readTemperature();
    Serial.print("Humidity:");
    Serial.print(hum);
    Serial.print("%, Temp:");
    Serial.print(temp);
    Serial.print("Celcius");
    lcd.setCursor(0,0);
    lcd.print("Weather");
    lcd.setCursor(1,1);
    lcd.print(temp);
    lcd.print("C ");
    lcd.print(hum);
    lcd.print("%");
    
    delay(2000);
    }
