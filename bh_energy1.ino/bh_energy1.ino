/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
                                                                bh_energy01.ino 
                                            Copyright © 2020, Zigfred & Nik.S
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\                            
  Arduino Pro Mini:
Скетч использует 14302 байт (5%) памяти устройства. Всего доступно 253952 байт.
Глобальные переменные используют 635 байт (7%) динамической памяти,
оставляя 7557 байт для локальных переменных. Максимум: 8192 байт.
/*****************************************************************************\
  Arduino Pro Mini boiler_house_energy1 выдает данные:
    аналоговые: 
величины электрического тока 
    цифровые:
/*****************************************************************************/

//  Блок DEVICE  --------------------------------------------------------------
//  Arduino Pro Mini
#define DEVICE_ID "boiler_house_energy1"
#define VERSION 1

//  Блок libraries  -----------------------------------------------------------
#include <EasyTransfer.h>            //   pins D13, D12, D11 

//  Блок settings  ------------------------------------------------------------
#include "bh_energy1_init.h"

unsigned long currentTime;

//	end init  -----------------------------------------------------------------

 
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void setup() {
  Serial.begin(9600);
  Serial.println("Serial.begin(9600)"); 

  EasyTransferSetup();

}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            loop
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void loop() {
  
  delay(30);
    digitalWrite(DIR, LOW);  // включаем прием
    delay(33);

    ETin0.receiveData(); // если пришли данные
    receiveDataETin0();

//  resetWhen30Days();

}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            info
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
25.03.2020 v1  
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            end
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
