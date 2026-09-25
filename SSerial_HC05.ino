//Arduino Blue Control App can be used to send commands to Mega 2560 via HC-05
#include <SoftwareSerial.h>

// Define RX and TX pins for SoftwareSerial
// On Arduino Mega, you can use pins like 10 and 11
SoftwareSerial BTSerial(10, 11); // RX, TX

// Define LED pin
//const int ledPin = 13;  // Built-in LED on Mega
const int ledPin = 6;

void setup() {
  // Initialize LED pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Start serial communication with HC-05
  BTSerial.begin(9600);   // HC-05 default baud rate
  Serial.begin(9600);     // For debugging via USB
}

void loop() {
  // Check if data is available from HC-05
  if (BTSerial.available()) {
    char c = BTSerial.read();   // Read incoming character

    // Debug print
    Serial.print("Received: ");
    Serial.println(c);

    // If 'A' is received, turn LED on for 5 seconds
    if (c == 'A') {
      digitalWrite(ledPin, HIGH);
      delay(5000);              // Keep LED on for 5 seconds
      digitalWrite(ledPin, LOW);
    }
  }
}
