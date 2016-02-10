
/**
  ******************************************************************************
  *bissimillahirrohmanirrohim semoga barokah manfaat dunia akhirat sebuah progam
  *arduino yang menggunakan modul easy voice recognition 
  */
  
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"
#include <Servo.h>
#include <stdio.h>
#include <string.h>

/**        
  Connection
  Arduino    VoiceRecognitionModule
   2   ------->     TX
   3   ------->     RX
*/
VR myVR(2,3);    // 2:RX 3:TX, you can choose your favourite pins.

uint8_t record[7]; // save record
uint8_t buf[64];
//string

String sandi1s;
String sandis;
//deklarasi pin
int ledpir1=55;
int ledpir2=58;
int ledpir3=23;
int lampu2 =12;
int kipas2=4;
int pir1=15;
int pir2=7;
int pir3=14;
int padam1=8;
int servoo=10;
int servooo=9;
int buzzer=5;
int ldr1=1;
int lm35=2;
int ldr2=3;


//variabel g penting
int group = 0;

//variabel kondisi
int varlampu;
int varkeamanan;
int varkipas;
int varsmart;
int varnormal;
//...............daftar voice febryn..................//
#define sistem        (0)
#define lampu         (1) 
#define garasi        (2) 
#define kipas         (3) 
#define keamanan      (4) 
#define mati          (5) 
#define nyala         (6) 
#define tertutup      (7) 
#define terbuka       (8) 
#define smartt        (9) 
#define patroli       (10) 
#define sirine












(11) 
#define normal        (12)
////siti
//#define sistem        (13)
//#define lampu         (14) 
//#define garasi        (15) 
//#define kipas         (16) 
//#define keamanan      (17) 
//#define mati          (18) 
//#define nyala         (19) 
//#define tertutup      (20) 
//#define terbuka       (21) 
//#define smartt        (22) 
//#define patroli       (23) 
//#define sirine        (24) 
//#define normal        (25)
////sopoiki
//#define sistem        (26)
//#define lampu         (27) 
//#define garasi        (28) 
//#define kipas         (29) 
//#define keamanan      (30) 
//#define mati          (31) 
//#define nyala         (32) 
//#define tertutup      (33) 
//#define terbuka       (34) 
//#define smartt        (35) 
//#define patroli       (36) 
//#define sirine        (37) 
//#define normal        (38)
//...................................................//
//servo
 //servo setup
  Servo ke1;
  Servo ke2;
void setup()
{
 
  ke1.attach(servoo);
  ke2.attach(servooo);
int  pos=0;
          ke1.write(pos);
  /** initialize */
  
  //pinMODE
  pinMode(lampu2,OUTPUT);
  pinMode(kipas2,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(pir1,INPUT); 
  pinMode(pir2,INPUT);
  pinMode(pir3,INPUT);
  pinMode(padam1,INPUT);
  pinMode(13,OUTPUT); 
 
  //modul voice
  myVR.begin(9600);
   //serial begin
 Serial.begin(9600);
  Serial.println("Elechouse Voice Recognition V3 Module\r\nMulti Commands sample");
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
  record[5] = smartt;
  if(myVR.load(record, 7) >= 0){
    printRecord(record, 7);
    Serial.println(F("loaded."));
  }
  
}

void loop()
{digitalWrite(13,HIGH);
 //.........progam disini berjalan tanpa voice comand..........//
 /*progam yang berjalan tanpa voice recognition diantaranya:
  * 1. pemadam api
  * 2. keamanan,(tapi untuk menyalakan atau mematikan keamanan menggunakan
  * pasword atau voice.
  * 3. apabila progam smart diaktifkan,, maka berikut fitur yang
  * ikut tidak menggunakan voice:
  * a. lampu
  * b. kipas
  */
  //pemadam api:
  pemadam();
  //keamanan
  //keamanane();
  //lawang
  lawange();
  //untuk smart:
if (varsmart==1){
smarte();
}
else{
//lampune();
kipase();
}
if(varnormal>11)
{varnormal=0;
varsmart=0;
varlampu=0;
varkipas=0;
varkeamanan=1;
digitalWrite(lampu2,HIGH);
}
 //............................................................//
 //........progam dibawah untuk voice recognition..............//
 
  int ret;
  ret = myVR.recognize(buf, 50);
  if(ret>0){
//dibawah ini switch untuk progam voice utama
    switch(buf[1]){
//switch utama
case sistem:{
          myVR.clear();
          record[0] = sistem;
          record[1] = lampu;
          record[2] = garasi;
          record[3] = kipas;
          record[4] = keamanan;
          record[5] = smartt;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("Hi, Master!"));
          }           
         break;
        }
//swithch utama
case lampu:{
          myVR.clear();
          record[0] = sistem;
          record[1] = mati;
          record[2] = nyala;
          record[3] = normal;
          record[4] = lampu;
          record[5] = smartt;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("Lampu:"));
          }           
          int y=0;
        while(y==0){
          int lampu1;
          lampu1=myVR.recognize(buf,50);
          if(lampu1>0){
//siwtch dilampu
            switch(buf[1]){
              case sistem:{
          myVR.clear();
          record[0] = sistem;
          record[1] = lampu;
          record[2] = garasi;
          record[3] = kipas;
          record[4] = keamanan;
          record[5] = smartt;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("Hi, Master!"));
          }
          y=1;           
         break;
              }
              case mati:{
                digitalWrite(lampu2,LOW);
              break;
              }
              case nyala:{digitalWrite(lampu2,HIGH);
              break;
              }
            }
          }
        }
        }
          break;
 //swithch utama
 case garasi:{
          int pos=0;//store posisi
          myVR.clear();
          record[0] = sistem;
          record[1] = tertutup;
          record[2] = terbuka;
          record[3] = normal;
          record[4] = lampu;
          record[5] = smartt;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("loaded."));
          }           
          int y=0;
        while(y==0){
          int garasi1;
          garasi1=myVR.recognize(buf,50);
          if(garasi1>0){
//switch garasi
            switch(buf[1]){
              case sistem:{
          myVR.clear();
          record[0] = sistem;
          record[1] = lampu;
          record[2] = garasi;
          record[3] = kipas;
          record[4] = keamanan;
          record[5] = smartt;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("Garasi"));
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
//swithch utama
case kipas:{
          break;
        }
case keamanan:{
        
          int pos=0;//store posisi
          myVR.clear();
          record[0] = sistem;
          record[1] = nyala;
          record[2] = mati;
          record[3] = patroli;
          record[4] = sirine;
          record[5] = smartt;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("Keamanan."));
          }           
          int y=0;
        while(y==0){
          int keamanan1;
          keamanan1=myVR.recognize(buf,50);
          if(keamanan1>0){
//switch keamanan
            switch(buf[1]){
              case sistem:{
          myVR.clear();
          record[0] = sistem;
          record[1] = lampu;
          record[2] = garasi;
          record[3] = kipas;
          record[4] = keamanan;
          record[5] = smartt;
          
          if(myVR.load(record, 7) >= 0){
            printRecord(record, 7);
            Serial.println(F("Hi, Master!"));
          }
          y=1;           
         break;
          
        }
        case nyala:{
          varkeamanan=0;
          
        }
        case mati:{
          varkeamanan=1;
        }
        case patroli:{
          patrolian();
        }
        case sirine:{
         digitalWrite(buzzer,HIGH);
        }
        }
        }
            }
          }
          //swithch utama
case smartt:{
  varsmart=1;
         
        }
        }


          
      
    }
    /** voice recognized */
    printVR(buf);
  }

//patrolian adalah fungsi untuk mengontrol servo untuk memutar kamera
void patrolian(){
  int pos1=0;
  for (pos1 = 0; pos1 <= 180; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    ke2.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos1 = 180; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    ke2.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
//lampune adalah pengontrol lampu untuk mati atau nyala berdasar perintah suara

void lampune(){
  if (varlampu>1){
  digitalWrite(lampu2,HIGH);}
  else {
    digitalWrite(lampu2,LOW);
  }
}
//keamanane adaah fungsi untuk mengaktifkan sistem keamanan rumah dengan sensor pir
void keamanane(){
//  if(varkeamanan=1){
//   { if (pir1==HIGH){
//      //digitalWrite(ledpir1,HIGH);
//      ke2.write(40);
//      //digitalWrite(buzzer,HIGH);}
//      else{
//      //digitalWrite(ledpir1,LOW);
//      //digitalWrite(buzzer,LOW);
//      ke1.write(0);}
//   }
//    {if (pir2==HIGH){
//      //digitalWrite(ledpir2,HIGH);
//      //digitalWrite(buzzer,HIGH);
//      ke2.write(60);
//    }
//    else {
//    //digitalWrite(ledpir2,LOW);
//    //digitalWrite(buzzer,LOW);
//      ke2.write(0);}
//    }
//    {if (pir3==HIGH){
//      //digitalWrite(ledpir3,HIGH);
//      //digitalWrite(buzzer,HIGH);
//      ke1.write(80);
//    }
//    else {
//      //digitalWrite(ledpir3,LOW);
//      digitalWrite(buzzer,LOW);
//      ke1.write(0);
//    }
//    }}
}
void lawange(){
  //pintutertutup
  if(Serial.available()>0){
    Serial.print(Serial.read());
    char sandi1=(char)Serial.read();
    sandi1s=String(sandi1);
  if (sandi1s.equals("1234")){
    digitalWrite(buzzer,LOW);}
  }
  //pintuterbuka  
  int cahaya1=analogRead(ldr2);
  if(cahaya1>100);{
  if(Serial.available()>0){
  char sandi=(char)Serial.read();
  sandis=String(sandi);
  {
  if (sandis.equals("1234")){
    digitalWrite(buzzer,LOW);}
    else{
      digitalWrite(buzzer,HIGH);
      }

  
    }}}}
  
// kipase untuk mengatur nyala atau mati dengan sensor suara
void kipase(){
  
  if (varkipas=1){
    digitalWrite(kipas2,HIGH);
  }
  else{
    digitalWrite(kipas2,LOW);
    }
}
//pemadam() fungsi yang berjalan terus apabila ada api terdeteksi di rumah dengan sensor api
void pemadam(){
  while(padam1==HIGH){
    digitalWrite(kipas2,HIGH);
  }
}
//smarte adalah fungsi pada rumah untuk mengkatifkan fitur smart building, 
//lampu nyala dan mati sesuai sensor ldr dan m35
void smarte(){
  int cahaya=analogRead(ldr1);
  int suhu=analogRead(lm35);
  {
  if (cahaya<300)
  digitalWrite(lampu,HIGH);
  else
  digitalWrite(lampu,LOW);}
  {
  if (suhu>300)
  digitalWrite(kipas2,HIGH);
  else 
  digitalWrite(kipas2,LOW);}
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
