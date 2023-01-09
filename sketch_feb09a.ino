#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 2, TXPin =5;// Here we make pin 4 as RX of arduino & pin 3 as TX of arduino 
static const uint32_t GPSBaud = 9600;


TinyGPSPlus gps;

SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(9600);
  ss.begin(GPSBaud);

 
}

void loop()
{
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
}

void displayInfo()
{
 ; 
  if (gps.location.isValid())
  {
    
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F("  Date "));
  if (gps.date.isValid())
  {
   
    Serial.print(gps.speed.kmph());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  
  Serial.println();
}
