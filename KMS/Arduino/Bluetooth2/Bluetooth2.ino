#include<SoftwareSerial.h>
#include<MFRC522.h>
#include<SPI.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
SoftwareSerial BTSerial(2,3);
int num = 0;

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
  byte Num = 0;
  content.toUpperCase();
  num = (int)mfrc522.uid.size;
  Serial.print(num);
  Serial.write(num);
  for(byte i=0;i<mfrc522.uid.size;i++){
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
     if(Serial.available()){
  BTSerial.print(HEX);
  }
  }
  content.toUpperCase( );


    Serial.println();
    
  
}
