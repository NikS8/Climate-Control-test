/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
                                                                bh_energy.ino 
                                            Copyright © 2020, Zigfred & Nik.S
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\                            
  Arduino Mega2560:
Скетч использует 14302 байт (5%) памяти устройства. Всего доступно 253952 байт.
Глобальные переменные используют 635 байт (7%) динамической памяти,
оставляя 7557 байт для локальных переменных. Максимум: 8192 байт.
/*****************************************************************************\
  Сервер boiler_house_energy выдает данные:
    аналоговые: 
величины электрического тока 
    
/*****************************************************************************/

//  Блок DEVICE  --------------------------------------------------------------
//  Arduino Mega2560
#define DEVICE_ID "boiler_house_energy"
#define VERSION 1

//  Блок libraries  -----------------------------------------------------------
#include <Ethernet2.h>          //  httpServer (40115) pins D10,D11,D12,D13
#include <EasyTransfer.h>            //   pins D2, D18, D19 

//  Блок settings  ------------------------------------------------------------
#include "bh_energy_init.h"

unsigned long currentTime;

//	end init  -----------------------------------------------------------------

 
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void setup() {
  Serial.begin(9600);
  Serial.println("Serial.begin(9600)"); 

  httpServerSetup();
  EasyTransferSetup();

}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            loop
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void loop() {
  
  realTimeService();
////
unsigned long deltaTime = millis() - currentTime;
  
  if (deltaTime > 15000)
  {
    sendTxData();
    
    currentTime = millis();

    delay(30);
    digitalWrite(DIR, LOW);  // включаем прием
    delay(33);
  }

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
