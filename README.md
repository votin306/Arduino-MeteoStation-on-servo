# Метеостанция на Arduino
Метеостанция на электронном барометре BMP180 (I2C) на базе arduino

![screenshot of sample](https://github.com/votin306/Arduino-MeteoStation-on-servo/blob/master/Preview.jpg?raw=true)

# Цели моего проекта
Я попробовал сделать метеостанцию с целью какая будет погода на улице
# Что умеет электронный барометр BMP180
Для чего нужен барометр ? Он нужен для измерения атмосферного давления. Простыми словами он может показать какая будет погода(Дождливая,ясная или облачная)
Также он может определить температуру!
# Состав электроники 
  
  Я использовал Arduino nano

  Cервопривод

  OLED дисплей

  Ну и как же без барометра

## ПИНЫ
1. oled дисплей

   GND => GND
   
   VCC => 5V
   
   SDA => A4
   
   SCL => A5
   
2. Сервопривод

   Коричневый провод  => GND
   
   Красный провод => 5V
   
   Оранжевый провод => D9
   
3. Барометр

   GND => GND
   
   VCC(VIN) => 5V
   
   SDA => A4
   
   SCL => A5
   
## Для чего нужен в моем проекте OLED дисплей
   
   Я его изпользовал для того чтобы узнавать какая будет температура и какое будет давление  
   
## КАК Скачать архив с GitHub

   Нажать Clone or download
   
   и download ZIP
   
   и у вас скачивается архив
##  Как распаковать библиотеку в Arduino IDE 
    Скетч > Подключить библиотеку > Добавить .ZIP библиотеку 
    и выберите папку с этим архивом (библиотеку)  
