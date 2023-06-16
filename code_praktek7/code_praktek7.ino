// RFID
// SDA > D4/SDA
// SCK > D5/SCK
// MOSI> D7/MOSI
// MISO> D6/MISO
// IRQ> (kosong)
// RST> D3
// GND>GND
// 3.3V>Power nodemcu 8266 // pin rfid ke nodemcu

#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN D4
#define RST_PIN D3 // library buat sensor rfid

MFRC522 mfrc522(SS_PIN, RST_PIN); // deklarasi RFID

void setup() {
  Serial.begin(115200);
  
  SPI.begin(); //
  mfrc522.PCD_Init();
  
  Serial.println();
  Serial.println("Start");
  
  delay(1000);
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  // Menampilkan UID TAG Di Serial Monitor
  Serial.print("No Kartu :");
  String content = "";
  
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  Serial.println();

  delay(1000);
}
