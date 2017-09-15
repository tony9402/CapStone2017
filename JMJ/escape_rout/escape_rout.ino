#define Ldc 11
#define Lturn 7
#define Rdc 10
#define Rturn 9
#define trig_pinI 4
#define trig_pinR 5
#define trig_pinL 6
#define echoI_pin 2
#define echoR_pin 3
#define echoL_pin 8
void straight();
void turnLeft();
void turnRight();
void Stop();
float durationI, distanceI;
float durationL, distanceL;
float durationR, distanceR;


void setup() {
  pinMode(Lturn,OUTPUT);
  pinMode(Rturn,OUTPUT);
  pinMode(Ldc,OUTPUT);
  pinMode(Rdc,OUTPUT);
  pinMode(echoI_pin,INPUT);
  pinMode(echoR_pin,INPUT);
  pinMode(echoL_pin,INPUT);
  pinMode(trig_pinI,OUTPUT);
  pinMode(trig_pinR,OUTPUT);
  pinMode(trig_pinL,OUTPUT);
}

void loop() {
  straight();
  disCheck();
  if(distanceL>=50){
    turnLeft();
    delay(100);
    straight();
    delay(200);
    
  }
  else if(distanceI<=50){
    turnRight();
    delay(300);
 
  }
  else{
    straight();
  }


}
void Stop(){
  digitalWrite(Ldc,HIGH);
  digitalWrite(Rdc,HIGH);
  delay(1000);
}

void straight(){
  analogWrite(Ldc,150);
  analogWrite(Rdc,150);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,LOW);
}
void turnLeft(){
  digitalWrite(Ldc,LOW);
  digitalWrite(Rdc,LOW);
  digitalWrite(Lturn,HIGH);
  digitalWrite(Rturn,LOW);

}
void turnRight(){
  digitalWrite(Ldc,LOW);
  digitalWrite(Rdc,LOW);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,HIGH);
}
void disCheck(){
  digitalWrite(trig_pinI,LOW);
  digitalWrite(trig_pinL,LOW);
  digitalWrite(trig_pinR,LOW);
  
  digitalWrite(echoI_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pinI,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pinI,LOW);
  durationI = pulseIn(echoI_pin,HIGH);
  distanceI = durationI / 2.0 / 29.0;
  Serial.print("I : ");
  Serial.print(distanceI);
  Serial.println();
  
  digitalWrite(echoR_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pinR,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pinR,LOW);
  durationR = pulseIn(echoR_pin, HIGH);
  distanceR = durationR / 2.0 / 29.0;
  Serial.print("R : ");
  Serial.print(distanceR);
  Serial.println();

  digitalWrite(echoL_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pinL,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pinL,LOW);
  durationL = pulseIn(echoL_pin, HIGH);
  distanceL = durationL / 2.0 / 29.0;
  Serial.print("L : ");
  Serial.print(distanceL);
  Serial.println();
}
