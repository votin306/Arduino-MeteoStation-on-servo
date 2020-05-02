#include <Servo.h>
#include <SFE_BMP180.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32 
#define OLED_RESET 4
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
SFE_BMP180 pressure; 

Servo myservo;
int pos = 0;


void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  if(pressure.begin())                         // Инициализация датчика
     Serial.println("BMP180 init success");   // Печать текста "BMP180 подключен"
   else{                                      // В противном случаи, датчик не подключен
     Serial.println("BMP180 init fail\n\n");  // Печать текста "BMP180 не подключен"
     while(1);                                // Пауза.
       }
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  display.clearDisplay();
  display.setTextSize(3); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  char status;
  double T,P,p0,a;
  status = pressure.startTemperature();       // Считывание показания
  if(status!=0){                              // Если значение status не 0, выполняем следующию команду.
     delay(status);                           // Ждем     
     status = pressure.getTemperature(T);     // Полученые показания, сохраняем в переменную T
      if(status!=0){                          // Если все хорошо, функция вернет 1, иначе вернет 0
         Serial.print("Temperature: ");       // Печать текста "Температура"
         Serial.print(T,2);                   // Печать показания переменной "Т"
         Serial.println(" C, ");              // Печать текста "С"
  status = pressure.startPressure(3);         // Считывание показания
  if(status!=0){                              // Если значение status не 0, выполняем следующию команду.
     delay(status);                           // Ждем
     status = pressure.getPressure(P,T);      // Полученные показания, сохраняем в переменную P
      if(status!=0){                          // Если все хорошо, функция вернет 1, иначе вернет 0 
         Serial.print("Absolute pressure: "); // Печать текста "Атмосферное давление"
          Serial.print(P,2);                  // Печать показания переменной mBar
          Serial.print(" mbar, ");            // Печать текста "mBar"
          Serial.print(P*0.7500637554192,2);  // Печать показания в mmHg
          Serial.println(" mmHg");}

    pos = P * 0.7500637554192 - 700;  //map(P,700,800,0,180);
    Serial.println(pos);
    myservo.write(pos);
    delay(4);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(T);
    display.setCursor(89, 0);
    display.println(F(".C"));
    display.display();
    
    }
   }
  }
 }
