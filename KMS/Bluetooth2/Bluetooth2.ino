#include<SoftwareSerial.h>
#include<MFRC522.h>
#include<SPI.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
SoftwareSerial BTSerial(2,3);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Loading...");
  BTSerial.begin(9600);
}

void loop() {
  if(BTSerial.available()){
  Serial.write(BTSerial.read());
  }
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  String content= "";
  byte letter;
  content.toUpperCase();
  for(byte i=0;i<mfrc522.uid.size;i++){
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase( );

  if(Serial.available()){
  BTSerial.write(mfrc522.uid.uidByte,mfrc522.uid.size);
  }
}
