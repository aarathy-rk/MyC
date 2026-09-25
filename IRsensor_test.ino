int sensorPin = 8;   // OUT connected to D8
int ledPin = 13;     // onboard LED

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(sensorPin);
  if (sensorValue == LOW) {  // Obstacle detected
    digitalWrite(ledPin, HIGH);
    Serial.println("Obstacle detected!");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("No obstacle.");
  }
  delay(200);
}

