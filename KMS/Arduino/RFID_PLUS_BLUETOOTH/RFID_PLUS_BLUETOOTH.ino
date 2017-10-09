/* MFRC
 * SDA pin10
 * SCK pin13
 * MOSI pin 11
 * MISO pin 12
 * IRQ N.C
 * GND GND
 * RST 9
 * 3.3V 3.3V
 * Bluetooth
 * VCC 3.3V
 * Tx 2
 * Rx 3
 * GND GND
 */


/*
 * 성공 작품(RFID + Bluetooth)
 */
#include<SoftwareSerial.h>
#include<MFRC522.h>
#include<SPI.h>

#define Rx 3 //Bluetooth의 Rx를 3번에
#define Tx 2 //Bluetooth의 Tx를 2번에
#define RST_PIN 9
#define SS_PIN 10


SoftwareSerial BT(Tx,Rx);
MFRC522 mfrc(SS_PIN,RST_PIN);

/* 
 * MFRC로부터 1바이트씩 mfrc.uid.size 즉 4번을 입력받음
 * 한번씩 받을때마다 RightShift 연산자를 이용해 _4ByteNum에 저장하기 위해 만든 변수
 */
unsigned int _4ByteNum = 0;

void setup()
{
 Serial.begin(9600); //Serial통신속도를 9600으로 설정
 BT.begin(9600); //Bluetooth통신속도를 9600으로 설정
 SPI.begin();
 mfrc.PCD_Init(); //MFRC 초기화
}

void loop()
{
    _4ByteNum = 0; //_4ByteNum의 초기화
    if((mfrc.PICC_IsNewCardPresent()) && (mfrc.PICC_ReadCardSerial())) //새로운 MFRC카드가 있고 읽을수 있을때 True
    {
      //실패작이지만 밑에가서 MFRC고유값을 읽었는지 안읽었는지 확인하는 용도로 사용
      for(int Count = 0; Count < mfrc.uid.size;Count++){
        _4ByteNum = _4ByteNum | ((mfrc.uid.uidByte[Count] & 0xff) << 24 - 8 * Count); //_4ByteNum을 RightShift를 하며 저장
        delay(1); //Delay 0.001초를 준 이유는 MFRC카드의 고유값을 제대로 못 읽는 것을 방지
      }
      Serial.print(_4ByteNum,HEX); //_4ByteNum에 저장된 값을 Serial모니터로 출력(But, 제대로 출력되지 않음)
      Serial.println(); //Serial모니터에서 줄바꿈
    }
    if(_4ByteNum != 0){ //MFRC고유값을 읽었다면 Bluetooth 통신
      BT.write(mfrc.uid.uidByte,4); //mfrc.uid.uidByte에 있는 MFRC값들을 총 4바이트 보냄(mfrc.uid.uidByte : char형이며 4개의 방이 있음 따라서 1바이트씩 보냄)
    }
    delay(2000);
}


