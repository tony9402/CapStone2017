//
#define Ldc 11
#define Lturn 7
#define Rdc 10
#define Rturn 9
#define trig_pin 4
#define echoI_pin 2
#define echoR_pin 3
#define echoL_pin 6
#define LEFT 1
#define RIGHT 2
   
void straight();
void turnLeft();
void turnRight();
void disCheck();
void Stop();

float distanceI, distanceR, distanceL;
char turnCheck = NULL;
char escapeVersion = NULL;
bool versionCheck = false;
bool escape = false;

void setup() {
  pinMode(Lturn,OUTPUT);
  pinMode(Rturn,OUTPUT);
  pinMode(Ldc,OUTPUT);
  pinMode(Rdc,OUTPUT);
  pinMode(trig_pin,OUTPUT);
  pinMode(echoI_pin,INPUT);
  pinMode(echoR_pin,INPUT);
  pinMode(echoL_pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  disCheck();
  if(escape == false){
    if(versionCheck != true){
      if(distanceL > 20.0 && distanceR > 20.0){
        versionCheck = true;
        while(distanceI > 20.0){
          straight();
          disCheck();
        }
      }else if(distanceL > 20.0){
        versionCheck = true;
        while(distanceI > 20.0){
          straight();
          disCheck();
        }
        turnLeft();
      }else if(distanceR > 20.0){
        versionCheck = true;
        while(distanceI > 20.0){
          straight();
          disCheck();
        }
        turnRight();
      }
    }else{
      if(distanceI <= 20.0){
        if(distanceL <= 20.0 && turnCheck != RIGHT){
          turnCheck = RIGHT;
          turnRight();
        }else if(distanceR <= 20.0 && turnCheck != LEFT){
          turnCheck = LEFT;
          turnLeft();
        }else{
          if(turnCheck == RIGHT){
            turnRight();
            delay(100);
            turnRight();
            escape = true;
            escapeVersion = RIGHT;
          }else{
            turnLeft();
            delay(100);
            turnLeft();
            escape = true;
            escapeVersion = LEFT;
          }
        }
      }else{
        straight();
      }
    }
  }else if(escape == true){
    switch(escapeVersion){
      case LEFT:
        while(distanceL <= 20.0){
          straight();
          disCheck();
        }
        break;
      case RIGHT:
        while(distanceR <= 20.0){
          straight();
          disCheck();
        }
        break;
    }
  }
}

void disCheck(){
  float durationI, durationR, durationL;
  digitalWrite(trig_pin,LOW);
  
  digitalWrite(echoI_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);
  durationI = pulseIn(echoI_pin,HIGH,60000UL);
  distanceI = durationI / 2.0 / 29.0;
  Serial.print("I : ");
  Serial.print(distanceI);
  Serial.println();
  
  digitalWrite(echoR_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);
  durationR = pulseIn(echoR_pin, HIGH,60000UL);
  distanceR = durationR / 2.0 / 29.0;
  Serial.print("R : ");
  Serial.print(distanceR);
  Serial.println();

  digitalWrite(echoL_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);
  durationL = pulseIn(echoL_pin, HIGH,60000UL);
  distanceL = durationL / 2.0 / 29.0;
  Serial.print("L : ");
  Serial.print(distanceL);
  Serial.println();
  delay(1000);
  return;
}

void Stop(){
  digitalWrite(Ldc,HIGH);
  digitalWrite(Rdc,HIGH);
  return;
}

void straight(){
  analogWrite(Ldc,150);
  analogWrite(Rdc,150);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,LOW);
  return;
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
  return;
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

