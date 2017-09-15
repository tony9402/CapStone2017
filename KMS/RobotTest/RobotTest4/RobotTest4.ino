#define LDC 11
#define RDC 13
#define LTURN 7
#define RTURN 9
#define TRIG 4
#define ECHO 2
//우회전 각도 조절


char value[5] = {11,13,7,9,4};

void GO();
void RIGHT();
void STOP();
void SR04();

float distance;

void setup() {
  for(int i=0;i<5;i++){
    pinMode(value[i],OUTPUT);
  }
  pinMode(ECHO,INPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  SR04();
  if(distance < 20.0){
    RIGHT();
    Serial.print("right");
    Serial.println();
  }else{
    GO();
    Serial.print("GO");
    Serial.println();
  }
}

void SR04()
{
  digitalWrite(TRIG,LOW);
  digitalWrite(ECHO,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  float duration =  pulseIn(ECHO,HIGH);
  distance = (float)duration / 29.0 / 2.0;
  //Serial.print(*distance);
  return;
}

void RIGHT()
{
  digitalWrite(LDC,LOW);
  digitalWrite(RDC,LOW);
  digitalWrite(LTURN,LOW);
  digitalWrite(RTURN,HIGH);
  delay(500);
  digitalWrite(LDC,LOW);
  digitalWrite(RDC,LOW);
  digitalWrite(LTURN,HIGH);
  digitalWrite(RTURN,LOW);
  delay(50);
  STOP();
  return;
}

void STOP()
{
  digitalWrite(LDC,HIGH);
  digitalWrite(RDC,HIGH);
  return;
}

void GO()
{
  digitalWrite(LDC,LOW);
  digitalWrite(RDC,LOW);
  digitalWrite(LTURN,LOW);
  digitalWrite(RTURN,LOW);
  analogWrite(5,10);
  return;
}

