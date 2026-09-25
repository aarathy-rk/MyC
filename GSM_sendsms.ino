// C Pgm to send AT commands to SIM800 GSM Modem to send SMS to a phone number. 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);       // USB serial for PC monitor
  Serial1.begin(9600);      // Hardware UART for SIM800A TX1 18 RX1 19
  delay(1000);
   
  Serial.println("Setup Complete!");
  Serial.println("Sending SMS...");

  //Serial1.write("ATD9188899385;\r\n");
  //delay(8000);

  Serial1.write("AT+CMGF=1\r\n");
  delay(1000);
 
  //Send new SMS command and message number
  Serial1.write("AT+CMGS=\"9188899385\"\r\n");
  delay(1000);
   
  //Send SMS content
  Serial1.write("testing purpose");
  delay(1000);
   
  //Send Ctrl+Z / ESC to denote SMS message is complete
  Serial1.write((char)26);
  delay(3000);
     
  Serial.println("SMS Sent!");

}
// 2nd if loop gets the AT command from Serial Monitor(virtual console in Arduino IDE)
// and writes it to GSM Modem which takes action.
// 1st if loop gets responses of AT commands and displays it in Serial Monitor
void loop() {
  // put your main code here, to run repeatedly:
  // Forward SIM800 responses to PC
  if (Serial1.available()) {
    Serial.write(Serial1.read());
  }
  // Forward PC input to SIM800
  if (Serial.available()) {
    Serial1.write(Serial.read());
  }

}
