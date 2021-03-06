void setup() {
pinMode(13,OUTPUT);
Serial.begin(9600);

}

void loop() {
  int command=Serial.read();
if(Serial.available()>0)
{
  if(command==1)
  {
    digitalWrite(13,HIGH);
    delay(1000);
    Serial.println("LED on");
  }
  else if(command==2)
  {
    digitalWrite(13,LOW);
    delay(1000);
    Serial.println("LED off");
  }
  else
  {
    Serial.println("Wrong command:"+command);
  }
}

}
