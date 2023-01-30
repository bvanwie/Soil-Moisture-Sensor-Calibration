/*
  Calibrate Soil Sensor

  Requires an Arduino Uno and Capacitive Soil Sensor v1.2.
  Sensor is connected to 3.3V, GND, and A0 of the Uno.

  Reads input on analog pin 0 of an Arduino Uno, prints the result to the serial monitor.
  Keeps track of the minimum and maximum readings in order to map to a PERCENTAGE.
  While running, at some point have the sensor completely dry to obtain a maximum value,
  and submerged in water to obtain a minimum value.

  Bill Van Wie
  1/30/2023

*/

int soilMoistureValue = 0;  // Value read via analogRead()
int soilmoisturepercent = 0;  // Value mapped to a percentage
int airMax = 450;   // Choose a number that should be around 1/2way between wet and dry as a starting point.
int waterMin = 450; // Choose a number that should be around 1/2way between wet and dry as a starting point.
void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}

void reportMoisturePercent() {
  // Maps the current moisture value to a 1-100 scale based on airMax and waterMin constraints.
  // Prints the percentage without a \n so that more data can be added to the line.
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
  soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
  // If the value read is less than the stored minimum value, change minimum value to this value.
  if (soilMoistureValue < waterMin) 
  {
    waterMin = soilMoistureValue;
  }
  // If the value read is higher than the stored maximum value, change maximum value to this value.
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
