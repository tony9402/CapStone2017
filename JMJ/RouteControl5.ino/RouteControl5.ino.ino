타자연습#define Ldc 11
#define Lturn 7
#define Rdc 10
#define Rturn 9
#define trig_pinI 4
#define trig_pinR 5
#define trig_pinL 6
#define echoI_pin 2
#define echoR_pin 3
#define echoL_pin 8
void caseFTR();
void caseFTL();
void straight();
void turnLeft();
void turnRight();
void disCheck();
void Stop();

float distanceI, distanceR, distanceL;
bool loopescape = false;

void setup() {  
  pinMode(Lturn,OUTPUT);
  pinMode(Rturn,OUTPUT);
  pinMode(Ldc,OUTPUT);
  pinMode(Rdc,OUTPUT);
  pinMode(trig_pinI,OUTPUT);
  pinMode(trig_pinR,OUTPUT);
  pinMode(trig_pinL,OUTPUT);
  pinMode(echoI_pin,INPUT);
  pinMode(echoR_pin,INPUT);
  pinMode(echoL_pin,INPUT);
  Serial.begin(9600);

}

void loop() {
  while(1){
    disCheck();
    if(distanceI > 27.0 || distanceI == 0.00){
      straight(); 
    }
    
    if ((distanceI<=27.0 && distanceL<=27.0 && (distanceI * distanceL) != 0.00)){
      turnRight();
      disCheck();
      
      
      if(distanceI<=23.0 && distanceL<=23.0 && (distanceI * distanceL) != 0.00){
        Stop();
        turnRight();
        break;
      }
      else{
        straight();
        delay(1000);
        caseFTR();
        if(loopescape == true){
          loopescape = false;
          return;
        }
      }
    }
    
    else if(distanceI<=27.0 && distanceR<=27.0 && (distanceI*distanceR) != 0.00){
      Stop();
      turnLeft();
      disCheck();
      
      
      if(distanceI<=23.0 && distanceR<=23.0 && (distanceI*distanceR )!= 0.00){
        turnLeft();
        break;
      }
      
      else{
        straight();
        delay(1000);
        caseFTL();
        if(loopescape == true){
          loopescape = false;
          return;
        }        
      }
    }

    else{
      continue;
    }
  }
}
  
void disCheck(){
  float durationI, durationR, durationL;
  digitalWrite(trig_pinI,LOW);
  
  digitalWrite(echoI_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pinI,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pinI,LOW);
  durationI = pulseIn(echoI_pin,HIGH,60000UL);
  distanceI = durationI / 2.0 / 29.0;
  Serial.print("I : ");
  Serial.print(distanceI);
  Serial.println();
  
  digitalWrite(echoR_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pinR,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pinR,LOW);
  durationR = pulseIn(echoR_pin, HIGH,60000UL);
  distanceR = durationR / 2.0 / 29.0;
  Serial.print("R : ");
  Serial.print(distanceR);
  Serial.println();

  digitalWrite(echoL_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pinL,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pinL,LOW);
  durationL = pulseIn(echoL_pin, HIGH,60000UL);
  distanceL = durationL / 2.0 / 29.0;
  Serial.print("L : ");
  Serial.print(distanceL);
  Serial.println();
  return;
}
void Stop(){
  digitalWrite(Ldc,HIGH);
  digitalWrite(Rdc,HIGH);
  return;
}

void straight(){
  analogWrite(Ldc,100);
  analogWrite(Rdc,100);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,LOW);
  return;
}

void turnLeft(){
  analogWrite(Ldc,50);
  analogWrite(Rdc,40);
  digitalWrite(Lturn,HIGH);
  digitalWrite(Rturn,LOW);
  delay(605);
  digitalWrite(Ldc,LOW);
  digitalWrite(Rdc,LOW);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,HIGH);
  delay(50);
  Stop();
  return;
}

void turnRight(){
  analogWrite(Ldc,50);
  analogWrite(Rdc,40);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,HIGH);
  delay(700);
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
    if(distanceI > 27.0 || distanceI == 0.00){
      straight(); 
    }
    if(distanceI<=27.0 && distanceL>=27.0 &&distanceI != 0 || distanceL == 0){
      Stop();
      turnLeft();
      delay(300);
      disCheck();
      if(distanceI<=27.0){
        turnLeft();
        loopescape = true;
        return;
      }
      else{
      straight();
      delay(1000);
      caseFTL();
      }
    }
    
    else if(distanceI<=23.0 && distanceL<=23.0 && distanceI * distanceL != 0){
      Stop();
      turnRight();
      delay(300);
      //탈출해보자
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
    if(distanceI > 27.0 || distanceI == 0.00){
      straight(); 
    }
    if(distanceI<=23.0 && distanceR>=23.0 && distanceI != 0 || distanceR == 0){
      Stop();
      turnRight();
      delay(300);
      disCheck();

      if(distanceI<=23.0){
        turnRight();
        loopescape = true;
        return;
      }
      else{
      straight();      
      delay(1000);
      caseFTR();
      }
    }
    
    else if(distanceI<=23.0 && distanceR<=23.0 && distanceI * distanceR != 0){
      Stop();
      turnLeft();
      delay(300);
      straight();
      delay(1000);
      caseFTL();
    }
  }
    
  
}
