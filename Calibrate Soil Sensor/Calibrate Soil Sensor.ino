const int AirValue = 568;   //you need to replace this value with Value_1
const int WaterValue = 305;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;
int airMax = 450;   // Choose a number that should be around 1/2way between wet and dry as a starting point.
int waterMin = 450; // Choose a number that should be around 1/2way between wet and dry as a starting point.
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps

}

void reportMoisturePercent() {
  // Maps the current moisture value to a 1-100 scale based on pre-determined AirValue and WaterValue constraints.
  // Prints the percentage without a /n so that more data can be added to the line.
  // Is the 'if' statement needed when the map statement is already in place?
  soilmoisturepercent = map(soilMoistureValue, airMax, waterMin, 0, 100);
  if(soilmoisturepercent >= 100)
  {
    Serial.print("\t100 %");
  }
  else if(soilmoisturepercent <=0)
  {
    Serial.print("\t0 %");
  }
  else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
  {
    Serial.print("\t");
    Serial.print(soilmoisturepercent);
    Serial.print("%");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
  if (soilMoistureValue < waterMin) 
  {
    waterMin = soilMoistureValue;
  }
  if (soilMoistureValue > airMax)
  {
    airMax = soilMoistureValue;
  }
  Serial.print("Sensor reading: ");
  Serial.print(soilMoistureValue);
  reportMoisturePercent(); // Call the procedure to print the % moisture.
  Serial.print("\tWet reading: ");
  Serial.print(waterMin);
  Serial.print("\tDry reading: ");
  Serial.print(airMax);
  Serial.println();
  delay(250);
}
