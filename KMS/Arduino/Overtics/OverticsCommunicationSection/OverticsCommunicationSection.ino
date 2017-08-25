/*
 *  File Name : OverticsCommunicationSection
 *  Date : 2017.08.24 (THR)
 *  Version : 1.0.0
 *  Using HeaderFile : Bluetooth.h
 *                     RFID.h
 *                     CommunicationSectionFunc.h
 *  Using Pin( : 
 *      RFID(1ea):
 *        - MOSI 1ea
 *        - MISO 1ea
 *        - RST 1ea
 *        - SCK 1ea
 *        - SDA 1ea
 *        - Total 5ea
 *      Bluetooth(1ea):
 *        - Rx 1ea
 *        - Tx 1ea
 *        - Total 2ea
 *      Total : 7ea
 * Name of Competition : Capstone(2017)
 */

#include"OverticsHeader/RFID.h"
#include"OverticsHeader/Bluetooth.h"
#include"OverticsHeader/CommunicationSectionFunc.h"

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
