void setup() {
//setup serial port
Serial.begin(9600);

}

void loop() {
  int sensorValue=analogRead(A0);
  int mappedsensorValue=map(sensorValue,0,1023,0,9);
  Serial.println(mappedsensorValue,DEC);
}
