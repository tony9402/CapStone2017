
void setup() {
  pinMode(7,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(11,OUTPUT);
pinMode(13,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(11,LOW);
digitalWrite(13,LOW);
digitalWrite(7,HIGH);
digitalWrite(9,LOW);
delay(1000);
digitalWrite(11,LOW);
digitalWrite(13,LOW);
digitalWrite(7,HIGH);
digitalWrite(9,HIGH);
delay(1000);
digitalWrite(11,LOW);
digitalWrite(13,LOW);
digitalWrite(7,LOW);
digitalWrite(9,LOW);
delay(1000);
digitalWrite(11,LOW);
digitalWrite(13,LOW);
digitalWrite(7,HIGH);
digitalWrite(9,HIGH);
delay(1000);
digitalWrite(11,HIGH);
digitalWrite(13,HIGH);
digitalWrite(7,LOW);
digitalWrite(9,LOW);
delay(1000);
}
