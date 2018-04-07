/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <Servo.h>

#include <ESP8266WiFi.h>

#include <ThingSpeak.h>

Servo servo_2;
String  i;
int  angle_of_servo;
WiFiClient client;

void setup()
{
  servo_2.attach(2);

  i = "";

  angle_of_servo = 0;
  Serial.begin(9600);
  ThingSpeak.begin(client);

  servo_2.write(0);
  delay(0);
  WiFi.disconnect();
  Serial.println("Start");
  WiFi.begin("dileep", "12345678");
  while ((!(WiFi.status() == WL_CONNECTED))) {
    Serial.print(".......");
    delay(2000);

  }
  Serial.println("connected to dileep with password..");

}


void loop()
{

  i = (ThingSpeak.readIntField(457568, 2, "1M37QUX0X2V3W623"));
  if (i == "1") {
    if(angle_of_servo == 0)
    {
      servo_2.write(90);
      angle_of_servo = 90;
      Serial.println("door opened..");
    }
    if(angle_of_servo == 90)
    {
      Serial.println("door already opened..");
    }
  }
  if (i == "0") {
    if(angle_of_servo == 90)
    {
      servo_2.write(0);
      angle_of_servo = 0;
    }
    if(angle_of_servo == 0)
    {
      Serial.println("unrecognised person");
    }

  }

}

