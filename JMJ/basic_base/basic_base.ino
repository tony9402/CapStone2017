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

void loop() {
  // put your main code here, to run repeatedly:

}
