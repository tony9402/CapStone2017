  int echo_pin=3;
  int trig_pin=5;
void setup() {

  Serial.begin(9600);
  pinMode(echo_pin,INPUT);
  pinMode(trig_pin,OUTPUT);

}

void loop() {
 float duration, distance;
 digitalWrite(trig_pin,HIGH);
 delay(10);
 digitalWrite(trig_pin,LOW);
 duration=pulseIn(echo_pin,HIGH);
 distance=(float(duration/2)/24);
Serial.print(distance);
Serial.println("cm");
delay(1000);
 

}
