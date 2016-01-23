/**
  ******************************************************************************
  *bissimillahirrohmanirrohim semoga barokah manfaat dunia akhirat sebuah progam
  *arduino yang menggunakan modul easy voice recognition sehingga 
  */
  
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"
#include <Servo.h>

/**        
  Connection
  Arduino    VoiceRecognitionModule
   2   ------->     TX
   3   ------->     RX
*/
VR myVR(2,3);    // 2:RX 3:TX, you can choose your favourite pins.

uint8_t record[7]; // save record
uint8_t buf[64];

int lampu2 =13;
int kipas2=5;
int group = 0;

#define sistem        (0)
#define lampu       (1) 
#define garasi      (2) 
#define kipas       (3) 
#define keamanan    (4) 
#define mati        (5) 
#define nyala       (6) 
#define tertutup     (7) 
#define terbuka      (8) 
#define blink1       (9) 
#define patroli      (10) 
#define sirine       (11) 
#define normal       (12)


void setup()
{
  Servo ke1;
  Servo ke2;
  ke1.attach(9);
  ke2.attach(10);
  /** initialize */
  myVR.begin(9600);
  
  Serial.begin(115200);
  Serial.println("Elechouse Voice Recognition V3 Module\r\nMulti Commands sample");

  pinMode(lampu2,OUTPUT);
  pinMode(kipas2,OUTPUT);  
  if(myVR.clear() == 0){
    Serial.println("Recognizer cleared.");
  }else{
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while(1);
    
  }
  
  record[0] = sistem;
  record[1] = lampu;
  record[2] = garasi;
  record[3] = kipas;
  record[4] = keamanan;
  record[5] = normal;
  if(myVR.load(record, 7) >= 0){
    printRecord(record, 7);
    Serial.println(F("loaded."));

  }
  
}

void loop()
{
  int ret;
  ret = myVR.recognize(buf, 50);
  if(ret>0){
    switch(buf[1]){
      case sistem:{
          myVR.clear();
          record[0] = sistem;
          record[1] = lampu;
          record[2] = garasi;
          record[3] = kipas;
          record[4] = keamanan;
          record[5] = normal;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("loaded."));
          }           
         break;
        }
        case lampu:{
          myVR.clear();
          record[0] = sistem;
          record[1] = mati;
          record[2] = nyala;
          record[3] = blink1;
          record[4] = lampu;
          record[5] = normal;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("loaded."));
          }           
          int y=0;
        while(y==0){
          int lampu1;
          lampu1=myVR.recognize(buf,50);
          if(lampu1>0){
            switch(buf[1]){
              case sistem:{
          myVR.clear();
          record[0] = sistem;
          record[1] = lampu;
          record[2] = garasi;
          record[3] = kipas;
          record[4] = keamanan;
          record[5] = normal;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("loaded."));
          }
          y=1;           
         break;
              }
              case mati:{
                digitalWrite(lampu2,HIGH);
                y=1;
              break;
              }
              case nyala:{
                digitalWrite(lampu2,HIGH);
                y=1;
              break;
              }
            }
          }
        }
        }
          break;
        case garasi:{
          int pos=0;//store posisi
          myVR.clear();
          record[0] = sistem;
          record[1] = tertutup;
          record[2] = terbuka;
          record[3] = blink1;
          record[4] = lampu;
          record[5] = normal;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("loaded."));
          }           
          int y=0;
        while(y==0){
          int garasi1;
          garasi1=myVR.recognize(buf,50);
          if(garasi1>0){
            switch(buf[1]){
              case sistem:{
          myVR.clear();
          record[0] = sistem;
          record[1] = lampu;
          record[2] = garasi;
          record[3] = kipas;
          record[4] = keamanan;
          record[5] = normal;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("loaded."));
          }
          y=1;           
         break;
          
        }
        case tertutup:{
          pos=0;
          ke1.write(pos);
          break;
        }
        case terbuka:{
          pos=90;
          ke1.write(pos);
          break;
        }
        }
            }
          }
        }
        case kipas:{
          break;
        }
        case keamanan:{
          
          int pos=0;//store posisi
          myVR.clear();
          record[0] = sistem;
          record[1] = tertutup;
          record[2] = terbuka;
          record[3] = blink1;
          record[4] = lampu;
          record[5] = normal;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("loaded."));
          }           
          int y=0;
        while(y==0){
          int garasi1;
          garasi1=myVR.recognize(buf,50);
          if(garasi1>0){
            switch(buf[1]){
              case sistem:{
          myVR.clear();
          record[0] = sistem;
          record[1] = lampu;
          record[2] = garasi;
          record[3] = kipas;
          record[4] = keamanan;
          record[5] = normal;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("loaded."));
          }
          y=1;           
         break;
          
        }
        case tertutup:{
          pos=0;
          ke1.write(pos);
        }
        case terbuka:{
          pos=90;
          ke1.write(pos);
        }
        }
            }
          }
        }
        case normal:{
          break;
        }
          
      default:
        break;
    }
    /** voice recognized */
    printVR(buf);
  }
}

/**
  @brief   Print signature, if the character is invisible, 
           print hexible value instead.
  @param   buf     --> command length
           len     --> number of parameters
*/
void printSignature(uint8_t *buf, int len)
{
  int i;
  for(i=0; i<len; i++){
    if(buf[i]>0x19 && buf[i]<0x7F){
      Serial.write(buf[i]);
    }
    else{
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}

/**
  @brief   Print signature, if the character is invisible, 
           print hexible value instead.
  @param   buf  -->  VR module return value when voice is recognized.
             buf[0]  -->  Group mode(FF: None Group, 0x8n: User, 0x0n:System
             buf[1]  -->  number of record which is recognized. 
             buf[2]  -->  Recognizer index(position) value of the recognized record.
             buf[3]  -->  Signature length
             buf[4]~buf[n] --> Signature
*/
void printVR(uint8_t *buf)
{
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if(buf[0] == 0xFF){
    Serial.print("NONE");
  }
  else if(buf[0]&0x80){
    Serial.print("UG ");
    Serial.print(buf[0]&(~0x80), DEC);
  }
  else{
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if(buf[3]>0){
    printSignature(buf+4, buf[3]);
  }
  else{
    Serial.print("NONE");
  }
//  Serial.println("\r\n");
  Serial.println();
}

void printRecord(uint8_t *buf, uint8_t len)
{
  Serial.print(F("Record: "));
  for(int i=0; i<len; i++){
    Serial.print(buf[i], DEC);
    Serial.print(", ");
  }
}
