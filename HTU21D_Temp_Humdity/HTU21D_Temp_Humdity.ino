/* 
 HTU21D Humidity Sensor Example Code
 Uses the HTU21D library to display the current humidity and temperature
 
 Open serial monitor at 9600 baud to see readings. Errors 998 if not sensor is detected. Error 999 if CRC is bad.
  
 Hardware Connections (Breakoutboard to Arduino):
 -VCC = 3.3V
 -GND = GND
 -SDA = A4 (use inline 330 ohm resistor if your board is 5V)
 -SCL = A5 (use inline 330 ohm resistor if your board is 5V)
 */

#include <Wire.h>
#include "SparkFunHTU21D.h"

//Create an instance of the object
HTU21D myHumidity;

void setup()
{
  Serial.begin(9600);
  Serial.println("HTU21D Example!");

  myHumidity.begin();
}

void loop()
{
  float humd = myHumidity.readHumidity();
  float temp = myHumidity.readTemperature();

  Serial.print("Time:");
  Serial.print(millis());
  Serial.print("   Temperature:");
  Serial.print(temp, 1);
  Serial.print("C");
  Serial.print("   Humidity:");
  Serial.print(humd, 1);
  Serial.print("%");

  Serial.println();

  if(temp>=51)
    {
      Serial.println("Warm");
      digitalWrite(21, HIGH);  //Red LED = ON
      digitalWrite(22,LOW);   //Green LED  = OFF
    }
    else if(temp<51)
    {
      Serial.println("Normal");
      digitalWrite(21, LOW);  //Red LED = OFF
      digitalWrite(22,HIGH);   //Green LED  = ON
    }
  
  delay(1000);
}
