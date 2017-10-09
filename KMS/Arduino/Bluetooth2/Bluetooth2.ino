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
//Bluetooth + Mfrc
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
 Serial.begin(9600);
 BT.begin(9600);
 SPI.begin();
 mfrc.PCD_Init(); 
}

void loop()
{
    _4ByteNum = 0; //_4ByteNum의 초기화
    String content= "";
    content.toUpperCase(); //content에 있는 것들을 다 대문자로 변환
    
    if((mfrc.PICC_IsNewCardPresent()) && (mfrc.PICC_ReadCardSerial())) //새로운 MFRC카드가 있고 읽을수 있을때 True
    {
      //아래것은 실패작(이유 : Bluetooth로 보낼때와 핸드폰에서 값을 받을때 안받아지고 Serial모니터로 값을 확인할 때 4Byte가 아닌 뒤에 2Byte만 출력되는 문제가 있기 때문)
      for(int Count = 0; Count < mfrc.uid.size;Count++){
        _4ByteNum = _4ByteNum | ((mfrc.uid.uidByte[Count] & 0xff) << 24 - 8 * Count); //_4ByteNum을 RightShift를 하며 저장
        delay(1); //Delay 0.001초를 준 이유는 MFRC카드의 고유값을 제대로 못 읽는 것을 방지
      }

      //mfrc.uid.size의 값을 확인하려고 만든 것(mfrc.uid.size의 값은 4)
      //_4ByteNum = (int)mfrc.uid.size;
      
      //_4ByteNum의 값을 확인하려 만듬
      //But, 끝의 2바이트만 나옴(그 이유를 아직 제대로 안찾음)
      /*
      Serial.print(_4ByteNum);
      Serial.write(_4ByteNum);
      */
      //MFRC카드의 고유값을 1Byte씩 읽어서 문자열로 바꿔서 Serial모니터에 출력
      for(byte i=0;i<mfrc.uid.size;i++){
          Serial.print(mfrc.uid.uidByte[i] < 0x10 ? " 0" : " "); //MFRC카드의 고유값이 0x10보다 작은 경우 앞에 0을 붙여 출력 아니면 넘어가기
          Serial.print(mfrc.uid.uidByte[i], HEX); //MFRC카드의 고유값을 출력
          content.concat(String(mfrc.uid.uidByte[i] < 0x10 ? " 0" : " ")); //content에 MFRC카드의 고유값을 저장하는 과정
          content.concat(String(mfrc.uid.uidByte[i], HEX));
      }
      Serial.println(); //Serial모니터에서 줄바꿈
      delay(2000);
    }
}
