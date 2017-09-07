
int Ldc=11;
int Lturn=7;
int Rdc=13;
int Rturn=9;
int echoL_pin=6;
int trigL_pin=4;
int echoI_pin=5;
int trigI_pin=2;
int echoR_pin=3;
int trigR_pin=1;
void straight();
void turnLeft();
void turnRight();
void caseFTR();
void caseFTL();
float durationI, distanceI;
float durationL, distanceL;
float durationR, distanceR;

void setup() {
  pinMode(Lturn,OUTPUT);
  pinMode(Rturn,OUTPUT);
  pinMode(Ldc,OUTPUT);
  pinMode(Rdc,OUTPUT);
  pinMode(echoI_pin,INPUT);
  pinMode(trigI_pin,OUTPUT);
  pinMode(echoR_pin,INPUT);
  pinMode(trigR_pin,OUTPUT);
  pinMode(echoL_pin,INPUT);
  pinMode(trigL_pin,OUTPUT);

}

void loop() {


  digitalWrite(trigI_pin,HIGH);
  digitalWrite(trigL_pin,HIGH);
  digitalWrite(trigR_pin,HIGH);

  delay(10);
  
  digitalWrite(trigI_pin,LOW);
  digitalWrite(trigL_pin,LOW);
  digitalWrite(trigR_pin,LOW);
  
durationI=pulseIn(echoI_pin,HIGH);
distanceI=(float(durationI/2)/24);

durationL=pulseIn(echoL_pin,HIGH);
distanceL=(float(durationL/2)/24);

durationR=pulseIn(echoR_pin,HIGH);
distanceR=(float(durationR/2)/24);

straight();
if (distanceI<=10 && distanceL<=10){
  turnRight();
  straight;
  if(distanceI<=10 && distanceL<=10){
    turnRight();
  }
  else{
    delay(1000);
    caseFTR();
  }
  
}


}

void straight(){
  digitalWrite(Ldc,LOW);
  digitalWrite(Rdc,LOW);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,LOW);
}
void turnLeft(){
  digitalWrite(Ldc,LOW);
  digitalWrite(Rdc,LOW);
  digitalWrite(Lturn,HIGH);
  digitalWrite(Rturn,LOW);
  delay(1000);
}
void turnRight(){
  digitalWrite(Ldc,LOW);
  digitalWrite(Rdc,LOW);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,HIGH);
  delay(1000);
}
void caseFTR(){
  turnRight();
  straight();
  while(1){
    if(distanceI<=10 && distanceL>=10 && distanceR>=10){
      turnLeft();
      straight();
      delay(1000);
      caseFTL();
    }
    else if(distanceI<=10 && distanceL<=10){
      turnRight();
      straight();
      delay(1000);
      caseFTR();
    }
    else{
      continue;
    }
  }
}
void caseFTL(){
  turnLeft();
  straight();
  while(1){
    if(distanceI<=10 && distanceL>=10 && distanceR>=10){
      turnRight();
      straight();
      delay(1000);
      caseFTR();
    }
    else if(distanceI<=10 && distanceR<=10){
      turnLeft();
      straight();
      delay(1000);
      caseFTL();
    }
    else{
      continue;
    }
  }
}


