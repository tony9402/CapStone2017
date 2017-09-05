int left_ccw=7;
int left_ena=11;
int right_ccw=9;
int right_ena=13;
int echo_pin=3;
int trig_pin=5;

void setup() {
  pinMode(7,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(11,OUTPUT);
pinMode(13,OUTPUT);
//11,7왼쪽
//13,9오른쪽
}

void loop() {
//앞
digitalWrite(11,LOW);
digitalWrite(13,LOW);
digitalWrite(7,LOW);
digitalWrite(9,LOW);
delay(1000);
//뒤
digitalWrite(11,LOW);
digitalWrite(13,LOW);
digitalWrite(7,HIGH);
digitalWrite(9,HIGH);
delay(1000);
//좌회전
digitalWrite(11,LOW);
digitalWrite(13,LOW);
digitalWrite(7,HIGH);
digitalWrite(9,LOW);
delay(1000);
//오른쪽
digitalWrite(11,LOW);
digitalWrite(13,LOW);
digitalWrite(7,LOW);
digitalWrite(9,HIGH);
delay(1000);
}
