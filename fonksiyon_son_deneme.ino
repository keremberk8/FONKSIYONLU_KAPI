#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <IRremote.hpp>
#include <SoftwareSerial.h>

char keys[4][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
byte satirpinleri[4]={5,10,9,7};
byte sutunpinleri[3]={6,4,8};
Keypad keypad=Keypad(makeKeymap(keys),satirpinleri,sutunpinleri,4,3);
LiquidCrystal_I2C lcd(0x27,20,4);
#define Role A1
unsigned long baslangic,gecen_zaman;
String sonuc;
int sure=0;
int ses_sensoru=3;
int kumandaPin=5;
int alkis=0;
bool isik_durumu=false;
SoftwareSerial Bluetooth(13,12);

// Kişiye özel tetikleyiciler kaldırıldı; genel komutlar kullanılır.
const char* KAPI_KOMUTU="kapıyı aç";
const char* KAPI_KOMUTU_2="kapı aç";

void setup(){
 pinMode(2,OUTPUT); pinMode(A0,OUTPUT); pinMode(Role,OUTPUT); pinMode(ses_sensoru,INPUT);
 Serial.begin(9600); Bluetooth.begin(9600); IrReceiver.begin(kumandaPin,ENABLE_LED_FEEDBACK);
 lcd.init(); lcd.backlight(); lcd.clear(); lcd.setCursor(0,0); lcd.print("Kapiyi acmak icin"); lcd.setCursor(0,1); lcd.print("Kareye basiniz(#)");
}
void loop(){
 sure=0; char key=keypad.getKey();
 if(key && key=='#'){
  buzzer(); String rastgele=String(random(0,10));
  lcd.clear(); lcd.setCursor(0,0); lcd.print("Verilen fonksiyonun"); lcd.setCursor(0,1); lcd.print("sonucunu girin:"); lcd.setCursor(0,2); lcd.print("f("+rastgele+")");
  int fonksiyon_donusu=fonksiyon(rastgele.toInt()); sonuc=""; baslangic=millis(); int i=0;
  while(sure==0){
   gecen_zaman=millis(); key=keypad.getKey(); unsigned long zaman=gecen_zaman-baslangic;
   if(zaman>7000 || key=='*') sure=1;
   if(key && key!='*'){ buzzer(); sonuc+=key; lcd.setCursor(i,3); lcd.print("*"); i++; }
   lcd.setCursor(15,3); int kalan=7-(zaman/1000); if(kalan<0) kalan=0; lcd.print("("+String(kalan)+") ");
  }
  if(fonksiyon_donusu==sonuc.toInt()){
   giris(); giris_buzzer(); digitalWrite(2,HIGH); delay(1500); digitalWrite(2,LOW);
   lcd.clear(); lcd.setCursor(0,0); lcd.print("Kapiyi acmak icin"); lcd.setCursor(0,1); lcd.print("Kareye basiniz(#)");
  }else yanlis_giris();
 }
 int sensor_durumu=digitalRead(ses_sensoru);
 if(sensor_durumu==1){ if(alkis==0){baslangic=millis();gecen_zaman=millis();alkis++;} else if(millis()-gecen_zaman>=60){gecen_zaman=millis();alkis++;} }
 if(millis()-baslangic>=400){ if(alkis==2){if(!isik_durumu){isik_durumu=true;isik_ac();}else{isik_durumu=false;isik_kapa();}} alkis=0; }
 if(IrReceiver.decode()){
  unsigned long kod=IrReceiver.decodedIRData.decodedRawData; Serial.print("Tus kodu: "); Serial.println(kod,HEX); IrReceiver.resume();
  if(kod==0xFFA25D) isik_ac(); if(kod==0xFF629D) isik_kapa();
 }
 if(Bluetooth.available()){
  String veri=Bluetooth.readStringUntil('\n'); veri.trim(); Serial.println(veri);
  if(veri=="ışığı aç"||veri=="aç"||veri=="ışığı yak"||veri=="yak"||veri=="aydınlan") isik_ac();
  if(veri=="ışığı kapat"||veri=="kapat"||veri=="söndür") isik_kapa();
  if(veri==KAPI_KOMUTU||veri==KAPI_KOMUTU_2){digitalWrite(2,HIGH);giris_buzzer();delay(1500);digitalWrite(2,LOW);Bluetooth.println("kapi acik");}
 }
}
int fonksiyon(int degisken){return 2*(degisken*degisken)+1;}
void giris(){lcd.clear();lcd.setCursor(0,0);lcd.print("Basarili...");lcd.setCursor(0,1);lcd.print("Giris yapabilirsiniz");}
void yanlis_giris(){lcd.clear();lcd.setCursor(0,0);lcd.print("Yanlis Sonuc");lcd.setCursor(0,1);lcd.print("Giris Basarisiz!!!");delay(2000);lcd.clear();lcd.setCursor(0,0);lcd.print("Kapiyi acmak icin");lcd.setCursor(0,1);lcd.print("Kareye basiniz(#)");}
void isik_ac(){digitalWrite(Role,HIGH);Serial.println("açıldı");}
void isik_kapa(){digitalWrite(Role,LOW);}
void buzzer(){tone(A0,500);delay(50);noTone(A0);}
void giris_buzzer(){tone(A0,600);delay(200);noTone(A0);delay(20);tone(A0,600);delay(200);noTone(A0);delay(250);tone(A0,600);delay(200);noTone(A0);delay(750);}