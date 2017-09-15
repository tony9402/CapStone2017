  int echo_pin=3;
  int trig_pin=2;
void setup() {

  Serial.begin(9600);
  pinMode(echo_pin,INPUT);
  pinMode(trig_pin,OUTPUT);

}

void loop() {
 float duration, distance;
 digitalWrite(trig_pin,HIGH);
 delayMicroseconds(2);
 digitalWrite(trig_pin,LOW);
 duration=pulseIn(echo_pin,HIGH);
 distance=(float(duration/2)/29);
Serial.print(distance);
Serial.println("cm");
delay(100);
 

}
