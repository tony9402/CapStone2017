/* SDA pin10
 * SCK pin13
 * MOSI pin 11
 * MISO pin 12
 * IRQ N.C
 * GND GND
 * RST 9
 * 3.3V 3.3V
 */

#include<SoftwareSerial.h>
#include<MFRC522.h>
#include<SPI.h>

#define Rx 3
#define Tx 2
#define RST_PIN 9
#define SS_PIN 10


SoftwareSerial BT(Tx,Rx);
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
    delay(2000);
}


