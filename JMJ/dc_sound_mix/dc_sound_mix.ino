
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
void turLeft();
void turnRight();



void setup() {
  pinMode(Lturn,OUTPUT);
  pinMode(Rturn,OUTPUT);
  pinMode(Ldc,OUTPUT);
  pinMode(Rdc,OUTPUT);
  pinMode(echo_pin,INPUT);
  pinMode(trig_pin,OUTPUT);
}

void loop() {
float durationI, distanceI;
float durationL, distanceL;
float durationR, distanceR;

  digitalWrite(trig_pinI,HIGH);
  digitalWrite(trig_pinL,HIGH);
  digitalWrite(trig_pinR,HIGH);

  delay(10);
  
  digitalWrite(trig_pinI,LOW);
  digitalWrite(trig_pinL,LOW);
  digitalWrite(trig_pinR,LOW);
  
durationI=pulseIn(echo_pinI,HIGH);
distanceI=(float(durationI/2)/24);

durationL=pulseIn(echo_pinL,HIGH);
distanceL=(float(durationL/2)/24);

durationR=pulseIn(echo_pinR,HIGH);
distanceR=(float(durationR/2)/24);

if(distanceI>=25&&distanceL>=25&&distanceR>=25){
  stright();
  delay(1000);
}
if(distanceI<=25&&distanceL<=25&&distanceR>=25){
  turnRight();
  delay(1000);
}
if(distanceI>=25&&distanceL<=25&&distanceR<=25){
  turnLeft();
  delay(1000);
}
 
}

void straight(){
  digitalWrite(Ldc,LOW);
  digitalWrite(Rdc,LOW);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,LOW);
}
void turLeft(){
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




