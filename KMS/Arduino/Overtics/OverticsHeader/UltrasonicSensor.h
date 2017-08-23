/*
------------            UltrasonicSensor.h          -----------
------------               Version 1.0.0            -----------
------------            Date : 2017.08.23           -----------
------------      UltrasonicSensor : RCW - 0001     -----------
------------   Maker : Minsang Kim(SoongSil Uni.)   -----------
*/

#define EchoPinForward  
#define EchoPinLeft  
#define EchoPinRight  
#define TrigPinAll 


void CheckDistance(int);

void CheckDistance(int Way)
{
	digitalWrite(TrigPinAll,HIGH);
	delay(10);
	digitalWrite(TrigPinAll,LOW);
	
	float duration = pulseIn(Way,HIGH);
	float distance = duartion / 2.0 / 24.0;          // 'cm'
	
	return;
}
