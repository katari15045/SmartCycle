
#include <Wire.h>

const int mpu_address = 0x68;
int16_t temperature;
int16_t ac_x,ac_y,ac_z,gy_x,gy_y,gy_z;
int ldr_pin=A3,led_pin = 9,ldr_value,map_value;
int proximity_pin=7,proximity_value;
int reed_pin = 5,reed_status;
float distance = (2)*(22/7)*(0.31) ;   /* metres  */
float speed_wheel;
int start_time,elapsed_time,revolutions;


void setup() 
{
  Wire.begin();
  Wire.beginTransmission(mpu_address);
  delay(2000);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(9600);
  pinMode(ldr_pin,INPUT);
  pinMode(led_pin,OUTPUT);
  pinMode(proximity_pin,INPUT);
}

void loop() 
{
  
  Wire.beginTransmission(mpu_address);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(mpu_address,14,true);
  ac_x = Wire.read()<<8|Wire.read();
  ac_y = Wire.read()<<8|Wire.read();
  ac_z = Wire.read()<<8|Wire.read();
  temperature = Wire.read()<<8|Wire.read();
  gy_x = Wire.read()<<8|Wire.read();
  gy_y = Wire.read()<<8|Wire.read();
  gy_z = Wire.read()<<8|Wire.read();
  delay(333);
  Serial.print("Temperature : ");
  Serial.print((int)(temperature/340.00+36.53));
  Serial.print("*C\n");

  

  ldr_value = analogRead(ldr_pin);

  if(ldr_value > 220 )
  {
    digitalWrite(led_pin,LOW);
  }

  else
  {
    map_value = map(ldr_value,0,1023,0,255);
    map_value = 255-map_value;
    analogWrite(led_pin,map_value);
    
  }
  
  
  Serial.print("LDR Value : ");
  Serial.print(ldr_value);
  Serial.print("\n");
  Serial.print("LEDs Value : ");
  Serial.print(map_value);
  Serial.print("\n");

  proximity_value = digitalRead(7);
  if(proximity_value==HIGH)
  {
    Serial.print("Vehicle too Close\n");
  }
  else
  {
    Serial.print("Nothing too Close\n");
  }

  Serial.print("------------------------------------------------\n");

  start_time = millis();
  elapsed_time = 0;
  revolutions = 0;

  while(elapsed_time <= 1000)
  {

    reed_status = digitalRead(5);

    /*Serial.print("Reed Status\n");
    Serial.print(reed_status);*/
    
    if(reed_status==HIGH)
    {
       revolutions = revolutions + 1;
    }

    elapsed_time = millis()- start_time;
  }

  distance = (2) * (22/7)*(0.31)*(revolutions);
  speed_wheel = distance;
  speed_wheel = speed_wheel / 1000;    /*  m/s to km/s  */
  speed_wheel = speed_wheel * 3600;    /* km/s to km/hr  */

  Serial.print("Speed : ");
  Serial.print(speed_wheel);
  Serial.print("km/h\n");
  

}

