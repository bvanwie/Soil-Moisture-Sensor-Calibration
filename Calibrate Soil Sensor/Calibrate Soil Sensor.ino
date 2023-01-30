const int AirValue = 568;   //you need to replace this value with Value_1
const int WaterValue = 305;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps

}

void loop() {
  // put your main code here, to run repeatedly:
soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
Serial.print(soilMoistureValue);
soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
if(soilmoisturepercent >= 100)
{
  Serial.println("\t100 %");
}
else if(soilmoisturepercent <=0)
{
  Serial.println("\t0 %");
}
else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
{
  Serial.print("\t");
  Serial.print(soilmoisturepercent);
  Serial.println("%");
  
}
  delay(250);
}
