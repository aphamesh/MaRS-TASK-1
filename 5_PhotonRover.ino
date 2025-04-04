
#define ENA 9   // Speed control for Motor 1
#define IN1 7
#define IN2 6
#define ENB 10  // Speed control for Motor 2
#define IN3 5
#define IN4 4


#define LDR_PIN A0  


#define TRIG 11  
#define ECHO 12  

void setup() {
    Serial.begin(9600);
    
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
}

void loop() {
    
    int distance = getDistance(); // obstacle distance

    if (distance < 150) {
        stopMotors();
        Serial.println("Obstacle Detected! Stopping motors.");
    } else {
    int lightValue = analogRead(LDR_PIN); // Read LDR value
    int motorSpeed = map(lightValue, 0, 1023, 50, 255); 
    
    Serial.print("Light Level: "); Serial.print(lightValue);
    Serial.print(" | Motor Speed: "); Serial.println(motorSpeed);
    
        moveForward(motorSpeed);
    }

    delay(200);
}

// Move Forward Function
void moveForward(int speed) {
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

// Stop Motors Function
void stopMotors() {
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

// Ultrasonic Distance Function
int getDistance() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    
    long duration = pulseIn(ECHO, HIGH);
    int distance = duration * 0.034 / 2;
    return distance;
}
