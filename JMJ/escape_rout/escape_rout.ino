int Ldc=11;
int Lturn=7;
int Rdc=10;
int Rturn=9;
int echoL_pin=6;
int trigL_pin=4;
int echoI_pin=5;
int echoR_pin=3;
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
  pinMode(trigL_pin,OUTPUT);
}

void loop() {
  straight();
  delay(300);
  Stop();
  disCheck();
  if(distanceL>=20){
    turnLeft();
    delay(300);
    Stop();
  }
  else if(distanceL<=20 && distanceI<=20){
    turnRight();
    delay(300);
    Stop();
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
  digitalWrite(trigL_pin,HIGH);

  delayMicroseconds(2);
  
  digitalWrite(trigL_pin,LOW);
  
durationI=pulseIn(echoI_pin,HIGH);
distanceI=(float(durationI/2)/29);

durationL=pulseIn(echoL_pin,HIGH);
distanceL=(float(durationL/2)/29);

durationR=pulseIn(echoR_pin,HIGH);
distanceR=(float(durationR/2)/29);
}
