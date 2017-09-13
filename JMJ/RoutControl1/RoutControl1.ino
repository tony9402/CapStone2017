
int Ldc=11;
int Lturn=7;
int Rdc=13;
int Rturn=9;
int echoL_pin=6;
int trigL_pin=4;
int echoI_pin=5;
int echoR_pin=3;
void straight();
void turnLeft();
void turnRight();
void caseFTR();
void caseFTL();
void disCheck();
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
  while(1){
    disCheck();
    straight();
    
    if (distanceI<=10 && distanceL<=10){
      Stop();
      turnRight();
      disCheck();
      straight();
      
      if(distanceI<=10 && distanceL<=10){
        Stop();
        turnRight();
        continue;
      }
      else{
        delay(1000);
        caseFTR();
      }
    }
    
    else if(distanceI<=10 && distanceR<=10){
      turnLeft();
      disCheck();
      straight();
      
      if(distanceI<=10 && distanceR<=10){
        Stop();
        turnLeft();
        continue;
      }
      
      else{
        delay(1000);
        caseFTL();
      }
    }
    else{
      continue;
    }
  }
}

void Stop(){
  digitalWrite(Ldc,HIGH);
  digitalWrite(Rdc,HIGH);
  delay(1000);
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
  delay(350);
  digitalWrite(Ldc,LOW);
  digitalWrite(Rdc,LOW);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,HIGH);
  delay(50);
  Stop();
}
void turnRight(){
  digitalWrite(Ldc,LOW);
  digitalWrite(Rdc,LOW);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,HIGH);
  delay(350);
  digitalWrite(Ldc,LOW);
  digitalWrite(Rdc,LOW);
  digitalWrite(Lturn,HIGH);
  digitalWrite(Rturn,LOW);
  delay(50);
  Stop();
}
void caseFTR(){
  turnRight();
  delay(300);
  straight();
  while(1){
    disCheck();
    
    if(distanceI<=10 && distanceL>=10 && distanceR>=10){
      Stop();
      turnLeft();
      delay(300);
      straight();
      delay(1000);
      caseFTL();
    }
    
    else if(distanceI<=10 && distanceL<=10){
      Stop();
      turnRight();
      delay(300);
      straight();
      delay(1000);
      caseFTR();
    }
  }
}
void caseFTL(){
  turnLeft();
  delay(300);
  straight();
  while(1){
    disCheck();
    
    if(distanceI<=10 && distanceL>=10 && distanceR>=10){
      Stop();
      turnRight();
      delay(300);
      straight();
      delay(1000);
      caseFTR();
    }
    
    else if(distanceI<=10 && distanceR<=10){
      Stop();
      turnLeft();
      delay(300);
      straight();
      delay(1000);
      caseFTL();
    }
  }
}

void disCheck(){
  digitalWrite(trigL_pin,HIGH);

  delay(10);
  
  digitalWrite(trigL_pin,LOW);
  
durationI=pulseIn(echoI_pin,HIGH);
distanceI=(float(durationI/2)/24);

durationL=pulseIn(echoL_pin,HIGH);
distanceL=(float(durationL/2)/24);

durationR=pulseIn(echoR_pin,HIGH);
distanceR=(float(durationR/2)/24);
}


