#include"OverticsHeader/RFID.h"
#include"OverticsHeader/Bluetooth.h"
#include"OverticsHeader/FunctionDefine.h"
#include"OverticsHeader/Motor.h"
#include"OverticsHeader/UltrasonicSensor.h"

void setup() {
 //MRFC Setup
 MFRC.PCD_Init();
 SPI.begin();
 //Bluetooth Setup
 BT.begin();
 //UltrasonicSensor Setup
 pinMode(EchoPinForward,INPUT);
 pinMode(EchoPinLeft,INPUT);
 pinMode(EchoPinRight,INPUT);
 pinMode(TrigPinAll,OUTPUT);
 //Serial Setup
 Serial.begin(9600);
}

void loop() {
  
}
