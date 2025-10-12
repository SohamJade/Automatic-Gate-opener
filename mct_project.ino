#include <Servo.h>

Servo servo;

const int trigPin = 11;
const int echoPin = 12;

long duration;
int distance;

// Variables for non-blocking initialization
unsigned long servoStartTime;
bool servoInitialized = false;

void setup() 
{
    servo.attach(13);
    servo.write(180);           // Move to 180°
    servoStartTime = millis();  // Record when it started moving

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    Serial.begin(9600);
}

void loop() 
{
    // Wait 1.5s non-blocking for servo to finish initial move
    if (!servoInitialized && millis() - servoStartTime < 1500) {
        return; // Skip rest of loop until servo is done moving
    }
    servoInitialized = true;

    // --- Your existing code below remains unchanged ---
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance <= 10) {
        servo.write(90);
        delay(1500);
    } else {
        for (int pos = 90; pos <= 180; pos += 1) {
            servo.write(pos);
            delay(15);
        }
    }

    delay(100);
}
