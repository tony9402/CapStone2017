/*
------------                Bluetooth.h             -----------
------------               Version 1.0.0            -----------
------------            Date : 2017.08.23           -----------
------------            Bluetooth : HC - 06         -----------
------------   Maker : Minsang Kim(SoongSil Uni.)   -----------
*/

#include<SoftwareSerial.h>

#define Rx 3
#define Tx 2

SoftwareSerial BT(Tx,Rx);
