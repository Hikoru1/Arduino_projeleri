/*
 * Servo motorun çalışması sırasında hangi açıda olduğunu lcd ekran ile görmeye yarayan kod.
 * Bağlantılar:
 * 1. Anahtar PIN 8
 * 2. Anahtar PIN 9
 * Anahtarları pulldown direnci ile stabil çalışması sağlandı.
 * LCD ekran:
 * VSS/GND          -GND
 * VCC              -5V
 * VD               -POTANSIYOMETRE
 * RS               -PIN 12
 * R/W              -GND
 * E                -PIN 11
 * DBO,DB1,DB2,DB3  - BOŞ
 * DB4              -PIN5
 * DB5              -PIN4
 * DB6              -PIN3
 * DB7              -PIN2
 * LED+             -5V(220ohm dirençle)
 * LED-             -GND
 * POTANSIYOMETRE   -GND,5V
 */
#include <LiquidCrystal.h> //LCD ekran kütüphanesi.
#include<Servo.h> //Servo motor kütüphanesi.

#define B1 8
#define B2 9
#define SERVO 6

int pos = 100;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Arduino'ya bağlı dijital pinler.
Servo servo;

void setup() {
  lcd.begin(16, 2); //LCD nin boyutları
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
  lcd.setCursor(0, 0); //İmleç, ekranın 1. satırın 1. sütununa yerleşti.
  lcd.print("Position: "); //LCD ekrana yazıldı
  servo.attach(SERVO);
}
void loop() {
  lcd.setCursor(9, 0); //İmleç, ekranın 10. satırın 1. sütununa yerleşti.
  lcd.print(pos, DEC); //pos değişkeni DEC sayı tipine çevrildi.
  if (digitalRead(B1) == true) {  //Birinci buton aktif olduğu sürece...
    pos++;
    delay(25);
    if (pos > 180) pos = 180; //pos değeri 180 üzeri olduğu sürece...
  }
  else if (digitalRead(B2) == true) { //İkinci buton aktif olduğu sürece...
    pos--;
    delay(25);
    
    /*Aşağıdaki "if" fonksiyonu pos ifadesinin 100 den küçük bir değer aldığı sürece (örneğin 90); sayının yazılacağı yere gelir ve 900 şeklinde sayıyı üretir.
     * Bu durum sayının 900 olduğu anlamına gelmez. Sadece 90 sayısının sonundaki 0 silinmez ve öyle kalır. Bu yüzden ekranda 900 sayısını görürüz.
     * Bunun önüne geçmek için 3 haneli sayı 2 haneliye düşerken sondan bir sıfır silinir ve 90 sayısını ekranda görürüz.
     */
    if (pos < 100) { // pos değeri 100'den küçük bir değer olduğu sürece... 
      lcd.setCursor(11, 0); // 11. sütunun 1.satırına yerleşti.
      lcd.print(" "); // Boşluk yazdır.
    }
    if (pos < 0) pos = 0;  //pos ifadesi 0'dan küçük olduğu sürece pos 0 a eşitlenir.
    /*
     *Aşağıdaki if fonksiyonu; 2 haneli sayı tek haneye düşünce, sonda kalan 0 değerinin silinmesi için.
     */
    if (pos < 10) { // pos sıfırdan büyük olduğu sürece...
      lcd.setCursor(10, 0); //11 sütünun 1 satırına imleç yerleşir.
      lcd.print(" "); //Boşluk yazdır.
    }
  }
  servo.write(pos); //Servo motoru çalıştır.
}
