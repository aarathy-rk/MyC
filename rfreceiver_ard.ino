/*RF receiver arduino mega */

#define D8 2
#define D9 3
#define D10 4
#define D11 5

void setup() 
{
  Serial.begin(9600);
  pinMode(D8, INPUT);
  pinMode(D9, INPUT);
  pinMode(D10, INPUT);
  pinMode(D11, INPUT);  
}
void loop() 
{
  int temp1=digitalRead(D11);
  int temp2=digitalRead(D10);
  int temp3=digitalRead(D9);
  int temp4=digitalRead(D8);
 
  if(temp1==1 && temp2==0 && temp3==1 && temp4==0)
   Serial.println("Got the msg");
}
