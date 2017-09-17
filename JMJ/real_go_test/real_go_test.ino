int Ldc=11;
int Lturn=7;
int Rdc=10;
int Rturn=9;

void setup() {
  // put your setup code here, to run once:
  pinMode(Lturn,OUTPUT);
  pinMode(Rturn,OUTPUT);
  pinMode(Ldc,OUTPUT);
  
  pinMode(Rdc,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//turnRight();
//turnLeft();
straight();
delay(1000);
//Stop();
}
void Stop(){
  digitalWrite(Ldc,HIGH);
  digitalWrite(Rdc,HIGH);
  return;
}

void straight(){
  analogWrite(Ldc,150);
  analogWrite(Rdc,140);
  digitalWrite(Lturn,HIGH);
  digitalWrite(Rturn,HIGH);
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
