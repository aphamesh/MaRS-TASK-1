#define TILT_SENSOR 2  // Tilt sensor connected to D2
#define FORCE_SENSOR A0 // Force sensor connected to A0
#define BUZZER 5        // Buzzer on D5


void setup() {
    pinMode(TILT_SENSOR, INPUT);
    pinMode(BUZZER, OUTPUT);
    
    Serial.begin(9600);
}

void loop() {
    float tiltState = digitalRead(TILT_SENSOR); 
    int forceValue = analogRead(FORCE_SENSOR); 

    Serial.print("Tilt Sensor: ");
    Serial.print(tiltState);
    Serial.print(" | Force Sensor: ");
    Serial.print(forceValue);

    int earthquakeChance = 0;

    if (tiltState == 1 && forceValue > 300) {
        earthquakeChance = 90; // High probability
        digitalWrite(BUZZER, HIGH);
     
    } 
    else if (tiltState == 1 || forceValue > 200) {
        earthquakeChance = 50; // Medium probability
        digitalWrite(BUZZER, LOW);
      
    } 
    else {
        earthquakeChance = 10; // Low probability
        digitalWrite(BUZZER, LOW);
        
    }

    Serial.print(" | Earthquake Chance: ");
    Serial.print(earthquakeChance);
    Serial.println("%");

    delay(1000); // Delay for stability
}
