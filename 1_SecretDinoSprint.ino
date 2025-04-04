#include <Servo.h>

#define LDR A0          // Photoresistor connected to A0
#define TRIG 6          // HC-SR04 Trigger Pin
#define ECHO 7          // HC-SR04 Echo Pin
#define BUZZER 8        // Buzzer connected to digital pin 8
#define SERVO 9         // Servo for pressing spacebar

Servo servo;  

void setup() {
    pinMode(LDR, INPUT);
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(BUZZER, OUTPUT);
    servo.attach(SERVO);
    
    Serial.begin(9600);
}

long getDistance() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    
    long duration = pulseIn(ECHO, HIGH);
    long distance = duration * 0.034 / 2;
    return distance;
}

void loop() {
    int ldrValue = analogRead(LDR);  // LDR value
    long distance = getDistance();      // Ultrasonic distance
    
    Serial.print("LDR: ");
    Serial.print(ldrValue);
    Serial.print(" | Distance: ");
    Serial.println(distance);
    
    // If light intensity decreases (detects obstacle), trigger jump
    if (ldrValue < 500) {  // **IMPORTANT**//
      //Adjust threshold as needed
        servo.write(90);  // Simulate pressing spacebar
        delay(500);
        servo.write(180);  // Reset position
    }
    
    // If door opens (distance decreases below threshold), trigger alarm
    if (distance < 250) {  // Adjust distance threshold as needed
        Serial.println("ALERT! Door opened!");
        digitalWrite(BUZZER, HIGH);  // Buzzer ON
        delay(1000);  
        digitalWrite(BUZZER, LOW);   // Buzzer OFF
    }
    
    delay(500); 
}
