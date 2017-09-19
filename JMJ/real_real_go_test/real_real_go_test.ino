#define Ldc 11
#define Lturn 7
#define Rdc 10
#define Rturn 9
void straight();
void turnLeft();
void turnRight();
void Stop();
void setup() {
  pinMode(Lturn,OUTPUT);
  pinMode(Rturn,OUTPUT);
  pinMode(Ldc,OUTPUT);
  pinMode(Rdc,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
straight();
}
void Stop(){
  digitalWrite(Ldc,HIGH);
  digitalWrite(Rdc,HIGH);
  return;
}

void straight(){
  analogWrite(Ldc,50);
  analogWrite(Rdc,40);
  digitalWrite(Lturn,LOW);
  digitalWrite(Rturn,LOW);
  return;
}

void turnLeft(){
  analogWrite(Ldc,50);
  analogWrite(Rdc,40);
  digitalWrite(Lturn,HIGH);
  digitalWrite(Rturn,LOW);
  delay(500);
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
