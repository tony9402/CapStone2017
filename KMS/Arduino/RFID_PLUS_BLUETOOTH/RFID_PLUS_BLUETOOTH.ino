#include<SoftwareSerial.h>
#include<MFRC522.h>
#include<SPI.h>

#define Rx 2
#define Tx 3
#define RST_PIN 9
#define SS_PIN 10

SoftwareSerial BT(Rx,Tx);
MFRC522 mfrc(SS_PIN,RST_PIN);

unsigned int _4ByteNum = 0;

void setup()
{
 Serial.begin(9600);
 BT.begin(9600);
 SPI.begin();
 mfrc.PCD_Init(); 
}

void loop()
{
    _4ByteNum = 0;
    if((mfrc.PICC_IsNewCardPresent()) && (mfrc.PICC_ReadCardSerial()))
    {
      for(int Count = 0; Count < mfrc.uid.size;Count++){
        _4ByteNum = _4ByteNum | ((mfrc.uid.uidByte[Count] & 0xff) << 24 - 8 * Count);
        delay(1);
      }
      Serial.print(_4ByteNum,HEX);
      Serial.println();
    }
    if(_4ByteNum != 0){
      BT.write(mfrc.uid.uidByte,4);
    }
    delay(1000);
}

