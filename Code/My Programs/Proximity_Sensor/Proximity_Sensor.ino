
int sensor_value;

void setup()
{

Serial.begin(9600);
pinMode(7,INPUT);
  
}



void loop()
{
  
 sensor_value=digitalRead(7);

 if(sensor_value==HIGH)
 {
  Serial.print("Obstacle");
  Serial.print("\n");
 }

 else
 {

  Serial.print("No Obstacle");
  Serial.print("\n");

 }
  
  
 }

