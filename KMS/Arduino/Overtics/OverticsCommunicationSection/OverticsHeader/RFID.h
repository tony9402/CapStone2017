/*
------------                  RIFD.h                -----------
------------               Version 1.0.0            -----------
------------            Date : 2017.08.23           -----------
------------             RFID : RFID-RC522          -----------
------------   Maker : Minsang Kim(SoongSil Uni.)   -----------
*/

#include<MFRC522.h>
#include<SPI.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 MFRC(SS_PIN, RST_PIN);
