//C code for 7 segment led array - Low to select segment high for active led on
void setup() {
  // put your setup code here, to run once:

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);//G
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);//A
  pinMode(10, OUTPUT);//dp

  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //0
  digitalWrite(2,LOW);
  digitalWrite(10, LOW); 
  digitalWrite(9, HIGH); //A
  digitalWrite(8, HIGH); 
  digitalWrite(7, HIGH); 
  digitalWrite(6, HIGH); 
  digitalWrite(5, HIGH); 
  digitalWrite(4, HIGH); 
  digitalWrite(3, LOW);//G
  delay(2000); 
  //1
  digitalWrite(10, LOW); 
  digitalWrite(9, LOW); 
  digitalWrite(8, HIGH); 
  digitalWrite(7, HIGH); 
  digitalWrite(6, LOW); 
  digitalWrite(5, LOW); 
  digitalWrite(4, LOW); 
  digitalWrite(3, LOW);
  delay(2000); 
  //2
  digitalWrite(10, LOW); 
  digitalWrite(9, HIGH); 
  digitalWrite(8, HIGH); 
  digitalWrite(7, LOW); 
  digitalWrite(6, HIGH); 
  digitalWrite(5, HIGH); 
  digitalWrite(4, LOW); 
  digitalWrite(3, HIGH);
  delay(2000); 
  //3
  digitalWrite(10, LOW); 
  digitalWrite(9, HIGH); 
  digitalWrite(8, HIGH); 
  digitalWrite(7, HIGH); 
  digitalWrite(6, HIGH); 
  digitalWrite(5, LOW); 
  digitalWrite(4, LOW); 
  digitalWrite(3, HIGH); 
  delay(2000); 
  //4
  digitalWrite(10, LOW); 
  digitalWrite(9, LOW); 
  digitalWrite(8, HIGH); 
  digitalWrite(7, HIGH); 
  digitalWrite(6, LOW); 
  digitalWrite(5, LOW); 
  digitalWrite(4, HIGH); 
  digitalWrite(3, HIGH); 
  delay(2000); 
  //5
  digitalWrite(10, LOW); 
  digitalWrite(9, HIGH); 
  digitalWrite(8, LOW); 
  digitalWrite(7, HIGH); 
  digitalWrite(6, HIGH); 
  digitalWrite(5, LOW); 
  digitalWrite(4, HIGH); 
  digitalWrite(3, HIGH);
  delay(2000); 
  //6
  digitalWrite(10, LOW); 
  digitalWrite(9, HIGH); 
  digitalWrite(8, LOW); 
  digitalWrite(7, HIGH); 
  digitalWrite(6, HIGH); 
  digitalWrite(5, HIGH); 
  digitalWrite(4, HIGH); 
  digitalWrite(3, HIGH); 
  delay(2000); 
  //7
  digitalWrite(10, LOW); 
  digitalWrite(9, HIGH); 
  digitalWrite(8, HIGH); 
  digitalWrite(7, HIGH); 
  digitalWrite(6, LOW); 
  digitalWrite(5, LOW); 
  digitalWrite(4, HIGH); 
  digitalWrite(3, LOW); 
  delay(2000); 
  //8
  digitalWrite(10, LOW); 
  digitalWrite(9, HIGH); 
  digitalWrite(8, HIGH); 
  digitalWrite(7, HIGH); 
  digitalWrite(6, HIGH); 
  digitalWrite(5, HIGH); 
  digitalWrite(4, HIGH); 
  digitalWrite(3, HIGH);
  delay(2000);
  //dp
  digitalWrite(10, HIGH); 
  digitalWrite(9, LOW); 
  digitalWrite(8, LOW); 
  digitalWrite(7, LOW); 
  digitalWrite(6, LOW); 
  digitalWrite(5, LOW); 
  digitalWrite(4, LOW); 
  digitalWrite(3, LOW);
  delay(2000);

}
