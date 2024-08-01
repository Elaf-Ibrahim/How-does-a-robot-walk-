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
![لقطة شاشة 2024-08-01 051534](https://github.com/user-attachments/assets/d067b2fe-2a20-466a-aed9-e82a8cca29af)
https://www.tinkercad.com/things/gEjjPSUNMse-terrific-snicket-blorr/editel?returnTo=%2Fthings%2FgEjjPSUNMse-terrific-snicket-blorr&sharecode=wS_NalaHdrVFLllDNyTiufbA0vmEVW2CQyEv3lOKRcA
و قمت ببرمجة الدائرة عن طريق برنامج Arduino IDE 
        
![لقطة شاشة 2024-08-01 045209](https://github.com/user-attachments/assets/9197c61a-e754-44c4-a378-1b83cbba7711)
![لقطة شاشة 2024-08-01 045238](https://github.com/user-attachments/assets/35cfc1b5-7725-4f1f-b0cb-d89cf1501781)
