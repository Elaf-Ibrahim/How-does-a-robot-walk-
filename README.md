# حركة مشي الروبوت
لتشكيل حركة المشي لروبوت نحتاج لكتابة خوارزمية المشي ثم تطبيقها على الروبوت,
قبل كتابة الخوارزمية يجب تحديد اذا كنت سوف اقوم ببناء روبوت ذو عجلات ام روبوت ذو ارجل واذا وقع الاختيار على الروبوت ذو الارجل يجب تحديد عدد الارجل اذا كانت ثنائية مثل الانسان ام رباعية مثل الحيوانات ام متعددة الارجل اي اكثر من ستة ارجل وغالبا تكون في الروبوتات التي تحتاج الى استقرار و اتزان كبير. 
بالنسبة لحركة الروبوتات الثنائية تكون كالتالي رفع احدى الاقدام وتحريكها الى الامام ثم انزال القدم و استقرارها على الارض وعند استقرارها تتحرك القدم الاخرى بالمثل.
قمت بكتابة FUNCTION بسيط يوضح حركة ارجل الروبوت عن طريق برنامج البايثون وهو كالتالي:

    def walk(robot):
       while True:
        # رفع القدم اليسرى
        robot.lift_leg('left')
        # نقل القدم اليسرى للأمام
        robot.move_leg_forward('left')
        # إنزال القدم اليسرى
        robot.lower_leg('left')
        # ضبط توازن الروبوت
        robot.adjust_balance()

        # رفع القدم اليمنى
        robot.lift_leg('right')
        # نقل القدم اليمنى للأمام
        robot.move_leg_forward('right')
        # إنزال القدم اليمنى
        robot.lower_leg('right')
        # ضبط توازن الروبوت
        robot.adjust_balance()
قمت بتوصيل دائرة كهربائية مكونة من   servo (6), Arduino Uno and wires

![لقطة شاشة 2024-08-01 085544](https://github.com/user-attachments/assets/8f2ac9c4-bbdc-406e-871b-8ab595e745b2)
https://www.tinkercad.com/things/gEjjPSUNMse-terrific-snicket-blorr/editel?returnTo=%2Fthings%2FgEjjPSUNMse-terrific-snicket-blorr&sharecode=wS_NalaHdrVFLllDNyTiufbA0vmEVW2CQyEv3lOKRcA
و قمت ببرمجة الدائرة عن طريق برنامج Arduino IDE 
        
        
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
