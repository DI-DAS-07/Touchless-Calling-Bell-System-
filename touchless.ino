// Pin definitions
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 3;
const int ledPin = 4;

// Variables
long duration;
float distanceCm;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the echo duration
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // If object is detected within 15 cm
  if (distanceCm > 0 && distanceCm <= 15) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(1000); // Buzzer and LED ON for 1 second
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(1000); // Avoid rapid retriggering
  }

  delay(200); // Small delay to avoid bouncing
}
