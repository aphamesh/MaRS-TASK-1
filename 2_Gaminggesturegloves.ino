
const int flexPin = A0;     // Flex Sensor
const int forcePin = A1;      // Force Sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  int flexValue = analogRead(flexPin);
  int forceValue = analogRead(forcePin);


  Serial.print("Flex: ");
  Serial.print(flexValue);
  Serial.print(" | Force: ");
  Serial.println(forceValue);

  if (flexValue <200) {
    Serial.println("Slide");
  }

  if (forceValue > 600) {
    Serial.println("Fire");
  }

  delay(1000); 
}
