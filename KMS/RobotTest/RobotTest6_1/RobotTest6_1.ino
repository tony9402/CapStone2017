//Version RobotTest6_1
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
#define LEFT 1
#define RIGHT 2
   
void straight();
void turnLeft();
void turnRight();
void disCheck();
void Stop();

float distanceI, distanceR, distanceL;

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

char turnCheck;
char turnRightCheck = 0;
char turnLeftCheck = 0;
bool LTL = false;
bool LTR = false;

void loop() {
   disCheck();
   if(distanceI <= 20.0 && distanceI != 0){
      if(distanceR <= 21.0){
        turnLeft();
      }else if(distanceL <= 21.0){
        turnRight();
      }else{
        turnCheck = rand() % 2;
        if(turnCheck == 0){
          if(++turnLeftCheck == 3){
            turnRight();
            turnLeftCheck = 0;
            turnRightCheck++;
          }else{
            turnLeft();
            turnLeftCheck++; 
          }
        }else{
          if(++turnRightCheck == 3){
            turnLeft();
            turnRightCheck = 0;
            turnLeftCheck++;
          }else{
            turnRight();
            turnRightCheck++; 
          }
        }
      }
   }else if(distanceL <= 15.0 && distanceR <= 15.0 && distanceI <= 15.0 && distanceL * distanceI * distanceR != 0){
    Uturn();
    while((distanceR > 21.0 || distanceR == 0) ||(distanceL > 21.0 || distanceL == 0)){
         straight();
         disCheck();
    }
   }else{
      straight();
  }
}

void Back(){
  analogWrite(Ldc,180);
  analogWrite(Rdc,170);
  digitalWrite(Lturn,HIGH);
  digitalWrite(Rturn,HIGH);
  delay(150);
  return;
}

void littleTurnLeft(){
  analogWrite(Ldc,150);
  analogWrite(Rdc,100);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,LOW);
  return;
}

void littleTurnRight(){
  analogWrite(Ldc,110);
  analogWrite(Rdc,140);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,LOW);
  return;
}

void disCheck(){
  float durationI, durationR, durationL;
  digitalWrite(trig_pinI,LOW);
  digitalWrite(trig_pinR,LOW);
  digitalWrite(trig_pinL,LOW);
  
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

void Uturn(){
  while(distanceI > 20.0 || distanceI == 0){
    turnRight();
    disCheck();
  }
  return;
}

void Stop(){
  digitalWrite(Ldc,HIGH);
  digitalWrite(Rdc,HIGH);
  return;
}

void straight(){
  analogWrite(Ldc,150);
  analogWrite(Rdc,140);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,LOW);
  return;
}

void turnLeft(){
  analogWrite(Ldc,50);
  analogWrite(Rdc,40);
  digitalWrite(Lturn,HIGH);
  digitalWrite(Rturn,LOW);
  delay(400);
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
  delay(400);
  digitalWrite(Ldc,LOW);
  digitalWrite(Rdc,LOW);
  digitalWrite(Lturn,HIGH);
  digitalWrite(Rturn,LOW);
  delay(50);
  Stop();
}

