#include <CapacitiveSensor.h>

CapacitiveSensor   cs_3_4 = CapacitiveSensor(3,4);

void setup()
{
   cs_3_4.set_CS_AutocaL_Millis(0xFFFFFFFF);
}

void loop()
{
    long start = millis();
    long total1 =  cs_3_4.capacitiveSensor(30);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(total1);                  // print sensor output 1
    Serial.print("\t");
    Serial.print(total2);                  // print sensor output 2
    Serial.print("\t");
    Serial.println(total3);                // print sensor output 3

    delay(10);                             // arbitrary delay to limit data to serial port 
}
