
int sensor_value;
int radius = 31; /* centimetres */
float circumference = 2*(3.14)*31;
int distance = 0;

void setup()
{
pinMode(13,OUTPUT);
pinMode(12,INPUT);

}

void loop()
{
sensor_value = digitalRead(12);

if(sensor_value == HIGH)
{
  digitalWrite(13,HIGH);
  distance = distance + circumference;
}

else
{
  digitalWrite(13,LOW);
}


 
}

