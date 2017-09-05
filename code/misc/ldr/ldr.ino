

int sensor_value;
int mapped_value;

void setup()
{
 
pinMode(A0,INPUT);
pinMode(9,OUTPUT);
  
}

void loop()
{

sensor_value = analogRead(A0);
mapped_value = map(sensor_value,0,1023,0,255);
analogWrite(9,mapped_value);
  
}

