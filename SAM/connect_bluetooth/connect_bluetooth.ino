/*
 * 02-Mar-2016 from Sam Moon
 * Connect betweem Arduino with HC-06 Bluetooth V2.1 Chip
 * and App Inventor 2 App with Android Phone
 */

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2,3);//아두이노의 RX,TX에 블투루스 모듈의 RX,TX를 연결
void setup() {
  // 아두이노의 시리얼 전송속도(BAUD Rate)와 블루투스의 데이터 전송속도를 같게 해 줌
  Serial.begin(9600);
  BTSerial.begin(9600);

}

void loop() {
  // 블루투스 시리얼이 연결되어 사용가능하다면, 블루투스를 통해 스마트폰에서 보내온(읽은) 데이터를 아두이노의 시리얼 모니터에 보여줌
  if(BTSerial.available()){
    Serial.write(BTSerial.read());
  }
//아두이노의 시리얼 모니터가 연결되어 있다면, 시리얼 모니터에서 보내온(읽은) 데이터를 블루투스를 통해 스마트폰에 보여줌
if (Serial.available()){
  BTSerial.write(Serial.read());
}
}
