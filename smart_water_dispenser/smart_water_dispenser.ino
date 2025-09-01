#define trigPin 9
#define echoPin 10
#define pumpPin 7

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Start filling if cup is in position (14 to 16 cm)
  if (distance >= 13 && distance <= 16) {
    digitalWrite(pumpPin, HIGH); // start filling
  }
  // Stop if cup is full (5 cm or less) or removed
  else if (distance <= 10 || distance > 16) {
    digitalWrite(pumpPin, LOW); // stop filling
  }

  delay(500); // Smooth readings
}
