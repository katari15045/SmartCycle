int x; 
int y;
int z;

void setup()
{
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);

  Serial.begin(9600);
}


void loop()
{

x=analogRead(A0);
y=analogRead(A1);
z=analogRead(A2);

Serial.print("X : ");
Serial.print(x);
Serial.print("\n");

Serial.print("Y : ");
Serial.print(y);
Serial.print("\n");

Serial.print("Z : ");
Serial.print(z);
Serial.print("\n");
delay(1000);    

}
  


