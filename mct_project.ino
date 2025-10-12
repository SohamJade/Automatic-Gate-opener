// Define Pins
#include <Servo.h>

Servo servo;

const int trigPin = 11;
const int echoPin = 12;

// Define variables
long duration;
int distance;

void setup() 
{
    // Attach servo to pin 13 and set initial position
    servo.attach(13);
    servo.write(180);
    delay(1500);

    // Configure ultrasonic sensor pins
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    // Initialize serial communication
    Serial.begin(9600);
}

void loop() 
{
    // Clear the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Trigger the ultrasonic sensor
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the echoPin to measure the sound wave travel time
    duration = pulseIn(echoPin, HIGH);

    // Calculate distance in cm
    distance = duration * 0.034 / 2;

    // Print distance to Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    // Control servo based on distance
    if (distance <= 10) 
    { // Adjust threshold as per sensor placement
        servo.write(90);
        delay(1500);
    } 
    else {
    // Slowly move the servo from open (90) to closed (180)
        for (int pos = 90; pos <= 180; pos += 1) {
            servo.write(pos);
            delay(15); // Adjust this value to change the speed (larger = slower)
        }
    }
    delay(100); // Small delay for stability
}
