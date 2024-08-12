#include <Servo.h>

// تعريف محركات السيرفو لكل رجل
Servo servoLF1, servoLF2; // Left Front leg
Servo servoLR1, servoLR2; // Left Rear leg
Servo servoRF1, servoRF2; // Right Front leg

// زوايا الحركة
int legUp = 60;
int legDown = 180;
int legForward = 90;
int legBackward = 180;

void setup() {
  // توصيل محركات السيرفو بأطراف الأردوينو
  servoLF1.attach(3);
  servoLF2.attach(9);
  
  servoLR1.attach(10);
  servoLR2.attach(5);
  
  servoRF1.attach(6);
  servoRF2.attach(11);
}

void loop() {
  // رفع وتحريك الرجل الأمامية اليسرى للأمام
  servoLF1.write(legUp);
  servoLF2.write(legForward);
  
  // رفع وتحريك الرجل الخلفية اليسرى للأمام
  servoLR1.write(legUp);
  servoLR2.write(legForward);
  
  delay(500); // انتظار لتحرك الأرجل

  // إنزال الأرجل اليسرى الأمامية والخلفية
  servoLF1.write(legDown);
  servoLR1.write(legDown);
  
  delay(500);

  // رفع وتحريك الرجل الأمامية اليمنى للأمام
  servoRF1.write(legUp);
  servoRF2.write(legForward);
  
  // رفع وتحريك الرجل الخلفية اليسرى إلى الخلف لاستعادة الوضعية الأصلية
  servoLR2.write(legBackward);
  
  delay(500);

  // إنزال الرجل الأمامية اليمنى والخلفية اليسرى
  servoRF1.write(legDown);
  servoLR1.write(legDown);
  
  delay(500);

  // تحريك الرجل الأمامية اليسرى والخلفية اليمنى إلى الوراء لإعادة الوضعية الأصلية
  servoLF2.write(legBackward);
  servoRF2.write(legBackward);
  
  delay(500);
}
