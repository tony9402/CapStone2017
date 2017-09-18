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
    String content= "";
    content.toUpperCase();
    if((mfrc.PICC_IsNewCardPresent()) && (mfrc.PICC_ReadCardSerial()))
    {
      for(int Count = 0; Count < mfrc.uid.size;Count++){
        _4ByteNum = _4ByteNum | ((mfrc.uid.uidByte[Count] & 0xff) << 24 - 8 * Count);
        delay(1);
      }
      _4ByteNum = (int)mfrc.uid.size;
      for(byte i=0;i<mfrc.uid.size;i++){
        Serial.print(mfrc.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(mfrc.uid.uidByte[i], HEX);
          content.concat(String(mfrc.uid.uidByte[i] < 0x10 ? " 0" : " "));
          content.concat(String(mfrc.uid.uidByte[i], HEX));
       
          
      
    }
    Serial.println();
    
}

 if(mfrc.uid.uidByte[0]==0xB6 && mfrc.uid.uidByte[1]==0xDF && mfrc.uid.uidByte[2]==0x05 && mfrc.uid.uidByte[3]==0x85)
 //내가 가지고 있는 RFID의 uid 
 {
    Serial.println("<< OK !!! >>  Card of Door!");
    //시리얼 모니터에 출력하는 용도 카드 맞는지 확인용(작업시)

    if(digitalRead(8)==LOW)
    //만약 8번핀에 신호가 없다면
    {
      digitalWrite(8,HIGH);
      //8번핀에 신호를 준다
    }
    if(digitalRead(8)==HIGH)
    //만약 8번핀에 신호가 있다면
    {
      digitalWrite(8,LOW);
      //8번핀에 신호를 없앤다
    }
    
    delay(1000);
 }
delay(2000);
}

