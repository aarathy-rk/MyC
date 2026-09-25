/*
  Arduino Mega 2560 + SIM800A
  Receive SMS, extract sender number and message text
  TXD (modem) -> RX1 (Mega pin 19)
  RXD (modem) -> TX1 (Mega pin 18) via level shifter
  GND (modem) -> GND (Mega)
*/
// C pgm to receive SMS <on SIM800 from some phone number whose details such as phone no and SMS text will be extracted by Mega 
#define BUFFER_SIZE 128

char lineBuffer[BUFFER_SIZE];
int bufIndex = 0;
bool expectingSmsText = false;

void setup() {
  Serial.begin(9600);       // USB serial for PC monitor
  Serial1.begin(9600);      // Hardware UART for SIM800A
  delay(1000);

  Serial.println("Initializing SIM800A...");

  // Set SMS text mode
  Serial1.println("AT+CMGF=1");
  delay(1000);

  // Configure to show SMS details immediately
  Serial1.println("AT+CNMI=1,2,0,0,0");
  delay(1000);

  Serial.println("Ready to receive SMS.");
}

void loop() {
  while (Serial1.available()) {
    char c = Serial1.read();

    // Collect into buffer until newline
    if (c != '\r' && c != '\n' && bufIndex < BUFFER_SIZE - 1) {
      lineBuffer[bufIndex++] = c;
    } else if(c=='\n'){
      lineBuffer[bufIndex] = '\0'; // terminate string
      bufIndex = 0;

      // Process line
      if (expectingSmsText) {
        // This line is the SMS text
        Serial.print("Message: ");
        Serial.println(lineBuffer);
        expectingSmsText = false;
      } else if (strncmp(lineBuffer, "+CMT:", 5) == 0) {
        // Example: +CMT: "+919188899385","","24/08/02,12:10:00+22"
        char *firstQuote = strchr(lineBuffer, '"');
        if (firstQuote) {
          char *secondQuote = strchr(firstQuote + 1, '"');
          if (secondQuote) {
            int len = secondQuote - firstQuote - 1;
            char sender[32];
            if (len > 31) len = 31;
            strncpy(sender, firstQuote + 1, len);
            sender[len] = '\0'; 

            Serial.print("Sender: ");
            Serial.println(sender);
          }
        }
        // Next line will be SMS text
        expectingSmsText = true;
      }

      // Clear buffer for next line
      lineBuffer[0] = '\0';
    }
  }
}
