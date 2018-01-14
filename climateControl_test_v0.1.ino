
#include <EasyTransfer.h>
#define DIR 2            // переключатель прием\передача на Pin2
int ID;              // номер ардуины
EasyTransfer ETinOfBoiler, ETinOfCollector, ETinOfKitchen, ETout;  //create  objects

struct SEND_DATA_STRUCTURE {                  // структура, которую будем передавать
  int ID;
  char action;
  int targetPin;
  int levelPin;
};
char action = "get";    //  "get"/"set" - запрос выдачи данных / команда на исполнение
int levelPin = 0;   //  установка уровня на Pin (LOW/HIGH)
int targetPin = 10;         //  Pin=10 управления контактером

struct RECEIVE_DATA_2_OF_COLLECTOR {         // структура, которую будем принимать
  int ID;
  int sensorDsHallIn;    // адрес датчика DS18B20 на трубе №1 из летней кухни
  int sensorDsHallOut;    // адрес датчика DS18B20 на трубе №2 из летней кухни
  int sensorDsCollectorIn;   // адрес датчика DS18B20 на входе в коллектор
  int sensorDsCollectorOut;  // адрес датчика DS18B20 на выходе из коллектора
};

struct RECEIVE_DATA_21_OF_BOILER {         // структура, которую будем принимать
  int ID;
  int sensorPhotoBoiler;      // фоторезисторы у кнопок-сигнализатров тенов котла
  int sensorDsTankLow;       // температура от датчика DS18B20 на стенке бака внизу
  int sensorDsTankMiddle;    // температура от датчика DS18B20 на стенке бака посередине
  int sensorDsTankHigh;      // температура от датчика DS18B20 на стенке бака вверху
  int sensorDsTankInside;    // температура от датчика DS18B20 внутри бака
  int sensorDsBoiler;        // температура от датчика DS18B20 на выходном патрубке котла
  int sensorDhtTBoiler;      // температура в бойлерной
  int sensorDhtHBoiler;      // влажность в бойлерной
  int sensorDsTankIn;    // температура от датчика DS18B20 на трубе в бак
  int sensorDsTankOut;   // температура от датчика DS18B20 на трубе из бака
  int sensorPressTankFrom;    // температура от датчика давления в трубе от бака

};

struct RECEIVE_DATA_61_OF_KITCHEN {         // структура, которую будем принимать
  int ID;
  int sensorDhtTKitchen;      // температура в летней кухне
  int sensorDhtHKitchen;      // влажность в летней кухне
  int sensorAlarmKitchen;     //сигнал открытия двери и окон в летней кухне
};

//give a name to the group of data
RECEIVE_DATA_2_OF_COLLECTOR rxOf2;
RECEIVE_DATA_21_OF_BOILER rxOf21;
RECEIVE_DATA_61_OF_KITCHEN rxOf61;
SEND_DATA_STRUCTURE txdata;
//------------------------------------

int tempDsHallIn;   // температура датчика DS18B20 на трубе №1 из летней кухни
int tempDsHallOut;   // температура датчика DS18B20 на трубе №2 из летней кухни
int tempDsCollectorIn;   // температура датчика DS18B20 на входе в коллектор
int tempDsCollectorOut;  // температура датчика DS18B20 на выходе из коллектора

int sensorPhotoBoiler;         // фоторезисторы у кнопок-сигнализатров тенов котла
int tempDsTankLow;       // температура от датчика DS18B20 на стенке бака внизу
int tempDsTankMiddle;    // температура от датчика DS18B20 на стенке бака посередине
int tempDsTankHigh;      // температура от датчика DS18B20 на стенке бака вверху
int tempDsTankInside;    // температура от датчика DS18B20 внутри бака
int tempDsBoiler;        // температура от датчика DS18B20 на выходном патрубке котла
int tempDhtBoiler;       // температура в бойлерной
int humDhtBoiler;        // влажность в бойлерной

int tempDsTankIn;    // температура от датчика DS18B20 на трубе в бак
int tempDsTankOut;   // температура от датчика DS18B20 на трубе из бака
float sensorPressTankFrom;    // давление от датчика давления в трубе от бака

int tempDhtKitchen;      // температура в летней кухне
int humDhtKitchen;      // влажность в летней кухне
int sensorAlarmKitchen;     //сигнал открытия двери и окон в летней кухне


//-------------------

//-----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

void setup() {
  Serial.begin(9600);
  time.begin();
  //--------------



  Serial.print("FREE RAM: ");
  Serial.println(freeRam());

  delay(100);

  //  запyск RS-485
  Serial1.begin(9600); // start serial port
  ETinOfCollector.begin(details(rxOf2), &Serial1); //  //start the library, pass in the data details and the name of the serial port
  ETinOfBoiler.begin(details(rxOf21), &Serial1); //  //start the library, pass in the data details and the name of the serial port
  ETinOfKitchen.begin(details(rxOf61), &Serial1); //  //start the library, pass in the data details and the name of the serial port

  ETout.begin(details(txdata), &Serial1);

  pinMode(DIR, OUTPUT);
  delay(100);
  digitalWrite(DIR, LOW);                          // включаем прием

  delay(100);
  //----------
  
  //------------
}
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

void loop() {



  Serial.print("  switch txdata.ID = ");
  Serial.print(txdata.ID);                 // и отправляем в Serial

  Serial.println("  ");

  //    digitalWrite(DIR, LOW);                       // включаем прием
  //////
  switch (txdata.ID)  {

    case 2 : // Вывод на экран значений температуры и влажности на улице
      ETinOfCollector.receiveData();                           // если пришли данные
      receiveDataETinOfCollector();
      break;

    case 21 :
      ETinOfBoiler.receiveData();                           // если пришли данные
      receiveDataETinOfBoiler();
      break;

    case 61 :
      ETinOfKitchen.receiveData();
      receiveDataETinOfKitchen();
      break;

    default :
      // код выполняется если  не совпало ни одно предыдущее значение
      break;
  }

  //-----------
  if (millis() - lastDataTime > 5000) {     // Каждые 5 секунд меняются данные на дисплее
    // и отправляется запрос к ардуинам за данными.
    MyDispPrint();

    switchX++;
    if (switchX > 9) {
      switchX = 1;
    }
    lastDataTime = millis();
    delay(50);
    digitalWrite(DIR, HIGH);                      // включаем передачу
    delay(50);
    ETout.sendData();                              // отправляем в RS_485

    Serial.print(" lastDataTime = ");
    Serial.print(lastDataTime);                 // и отправляем в Serial port
    Serial.print("   txdata.ID = ");
    Serial.print(txdata.ID);                 // и отправляем в Serial port

    Serial.println("  ");
    delay(30);
    digitalWrite(DIR, LOW);                          // включаем прием
    delay(33);
    //----------

  }
 



  //------------------------
  //------------------------

 
  //---------------------------------------

  Serial.println("...");
  Serial.println("Конец цикла");
  Serial.println(" .......");
  //---------------------------------------

}
/////////////////////////////////////////////////////////////////////////////////////////////////
//			Дополнительные
//				функции
//////////////////////////////////////////////////////////////////////////////////////////////////////

//	Количество свободной памяти
int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

/////////    Прием данных  от ардуины №2 от коллектора

void receiveDataETinOfCollector() {

  //   byte id = rxdata.ID; // читаем байт, в нем для кого этот пакет
  //   if (id == 01){ // и если пакет пришел нам от ардуины №1

  tempDsHallIn = rxOf2.sensorDsHallIn;    // температура датчика DS18B20 на трубе №1 в прихожую
  tempDsHallOut = rxOf2.sensorDsHallOut;    // температура датчика DS18B20 на трубе №2 из прихожей
  tempDsCollectorIn = rxOf2.sensorDsCollectorIn;   // температура датчика DS18B20 на входе в коллектор
  tempDsCollectorOut = rxOf2.sensorDsCollectorOut;  // температура датчика DS18B20 на выходе из коллектора

  ////////////////

  Serial.print(" rxdata.ID = ");
  Serial.print(rxOf2.ID);                 // и отправляем в Serial
  Serial.print("  ");

  Serial.print(" tempDsCollectorIn = ");
  Serial.print(tempDsCollectorIn);
  Serial.print(" tempDsCollectorOut = ");
  Serial.print(tempDsCollectorOut);                 // и отправляем в Serial
  Serial.print(" tempDsHallIn = ");
  Serial.print(tempDsHallIn);                 // и отправляем в Serial
  Serial.print(" tempDsHallOut = ");
  Serial.print(tempDsHallOut);                 // и отправляем в Serial


  Serial.println();
  //   delay(100);                                     // небольшая задержка, иначе неуспевает

}


/////////    Прием данных от ардуины №21 из бойлерной

void receiveDataETinOfBoiler() {

  //   byte id = rxOf21.ID; // читаем байт, в нем для кого этот пакет
  //   if (id == 01){ // и если пакет пришел нам от ардуины №1

  sensorPhotoBoiler = rxOf21.sensorPhotoBoiler;
  tempDsTankLow = rxOf21.sensorDsTankLow;       // температура от датчика DS18B20 на стенке бака внизу
  tempDsTankMiddle = rxOf21.sensorDsTankMiddle;    // температура от датчика DS18B20 на стенке бака посередине
  tempDsTankHigh = rxOf21.sensorDsTankHigh;      // температура от датчика DS18B20 на стенке бака вверху
  tempDsTankInside = rxOf21.sensorDsTankInside;    // температура от датчика DS18B20 внутри бака
  tempDsBoiler = rxOf21.sensorDsBoiler;        // температура от датчика DS18B20 на выходном патрубке котла
  tempDhtBoiler = rxOf21.sensorDhtTBoiler;      // температура в бойлерной
  humDhtBoiler = rxOf21.sensorDhtHBoiler;        // влажность в бойлерной

  tempDsTankIn = rxOf21.sensorDsTankOut;    // температура от датчика DS18B20 на трубе в бак
  tempDsTankOut = rxOf21.sensorDsTankIn;   // температура от датчика DS18B20 на трубе из бака
  sensorPressTankFrom = rxOf21.sensorPressTankFrom;    // давление от датчика давления в трубе от бака
  sensorPressTankFrom = ((sensorPressTankFrom - 102.3) / 167); // перевод в атм [(sensorPressTankFrom - 0,1*1023) / (1,6*1023/9,8)]
  ////////////////

  Serial.print(" ID = ");
  Serial.print(rxOf21.ID);                 // и отправляем в Serial
  Serial.print("  ");

  Serial.print(" sensorPhotoBoiler = ");
  Serial.print(sensorPhotoBoiler);
  Serial.print(" sensorPressTankFrom = ");
  Serial.print(sensorPressTankFrom);

  Serial.print(" tempDsTankLow = ");
  Serial.print(tempDsTankLow);                 // и отправляем в Serial
  Serial.print(" tempDsTankMiddle = ");
  Serial.print(tempDsTankMiddle);                 // и отправляем в Serial
  Serial.print(" tempDsTankHigh = ");
  Serial.print(tempDsTankHigh);
  Serial.print(" tempDsTankInside = ");
  Serial.print(tempDsTankInside);
  Serial.print(" rxOf21.sensorDsBoiler = ");
  Serial.print(tempDsBoiler);                 // и отправляем в Serial
  Serial.print(" tempDsTankIn = ");
  Serial.print(tempDsTankIn);
  Serial.print(" rxOf21.tempDsTankOut = ");
  Serial.print(tempDsTankOut);                 // и отправляем в Serial

  Serial.print(" tempDhtBoiler = ");
  Serial.print(tempDhtBoiler);                 // и отправляем в Serial
  Serial.print(" humDhtBoiler = ");
  Serial.print(humDhtBoiler);                 // и отправляем в Serial

  Serial.println();
  //   delay(100);                                     // небольшая задержка, иначе неуспевает

}

////////////////////////////////////////////////////////////////////////////////////////////////////


/////////    Прием данных  от ардуины №61 из новой кyхни

void receiveDataETinOfKitchen() {

  //   byte id = rxOf61.ID; // читаем байт, в нем для кого этот пакет
  //   if (id == 01){ // и если пакет пришел нам от ардуины №1

  tempDhtKitchen = rxOf61.sensorDhtTKitchen;      // температура в летней кухне
  humDhtKitchen = rxOf61.sensorDhtHKitchen;      // влажность в летней кухне

  sensorAlarmKitchen = rxOf61.sensorAlarmKitchen;     //сигнал открытия двери и окон в летней кухне

  ////////////////

  Serial.print(" rxOf61.ID = ");
  Serial.print(rxOf61.ID);                 // и отправляем в Serial
  Serial.print("  ");

  Serial.print(" tempDhtKitchen = ");
  Serial.print(tempDhtKitchen);
  Serial.print(" humDhtKitchen = ");
  Serial.print(humDhtKitchen);                 // и отправляем в Serial
  Serial.print(" sensorAlarmKitchen = ");
  Serial.print(sensorAlarmKitchen);                 // и отправляем в Serial

  Serial.println();
  //   delay(100);                                     // небольшая задержка, иначе неуспевает

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// Вывод информации на дисплей и влючение передачи данных по RS-485 каждой ардyине в сети по ее ID

int MyDispPrint() {
  switch (switchX)  {

    case 1 : // Вывод на экран значений температуры и влажности на улице


      txdata.ID = 2;
      delay(50);
      digitalWrite(DIR, HIGH);                      // включаем передачу
      delay(50);
      ETout.sendData();                              // отправляем
      Serial.print(" switchX = ");
      Serial.print(switchX);
      Serial.print(" txdata.ID = ");
      Serial.println(txdata.ID);

      break;

    case 2 : // Вывод на экран значений температуры и влажности в комнате

  

      txdata.ID = 21;
      delay(50);
      digitalWrite(DIR, HIGH);                      // включаем передачу
      delay(50);
      ETout.sendData();                              // отправляем
      Serial.print(" switchX = ");
      Serial.print(switchX);
      Serial.print(" txdata.ID = ");
      Serial.println(txdata.ID);

      break;

    case 3 : // Вывод на экран значений температуры и влажности в комнате

  
      txdata.ID = 61;
      delay(50);
      digitalWrite(DIR, HIGH);                      // включаем передачу
      delay(50);
      ETout.sendData();                              // отправляем
      Serial.print(" switchX = ");
      Serial.print(switchX);
      Serial.print(" txdata.ID = ");
      Serial.println(txdata.ID);

      break;


    case 4 : // Вывод на экран значений температуры и влажности в бойлерной

  
      txdata.ID = 2;
      delay(50);
      digitalWrite(DIR, HIGH);                      // включаем передачу
      delay(50);
      ETout.sendData();                              // отправляем

      Serial.print(" switchX = ");
      Serial.print(switchX);
      Serial.print(" txdata.ID = ");
      Serial.println(txdata.ID);

      break;


    case 5 :  // Вывод на экран значений температуры воды на выходе из котла

  

      txdata.ID = 21;
      delay(50);
      digitalWrite(DIR, HIGH);                      // включаем передачу
      delay(50);
      ETout.sendData();                              // отправляем

      Serial.print(" switchX = ");
      Serial.print(switchX);
      Serial.print(" txdata.ID = ");
      Serial.println(txdata.ID);

      break;

    case 6 :  // Вывод на экран значений температуры воды в баке

  

      txdata.ID = 61;
      delay(50);
      digitalWrite(DIR, HIGH);                      // включаем передачу
      delay(50);
      ETout.sendData();                              // отправляем

      Serial.print(" switchX = ");
      Serial.print(switchX);
      Serial.print(" txdata.ID = ");
      Serial.println(txdata.ID);

      break;

    case 7 :  // Вывод на экран значений температуры воды в баке

 
      txdata.ID = 2;
      delay(50);
      digitalWrite(DIR, HIGH);                      // включаем передачу
      delay(50);
      ETout.sendData();                              // отправляем

      Serial.print(" switchX = ");
      Serial.print(switchX);
      Serial.print(" txdata.ID = ");
      Serial.println(txdata.ID);

      break;

    case 8 :  // Вывод на экран значений температуры воды в коллекторе

 
      txdata.ID = 21;
      delay(50);
      digitalWrite(DIR, HIGH);                      // включаем передачу
      delay(50);
      ETout.sendData();                              // отправляем

      Serial.print(" switchX = ");
      Serial.print(switchX);
      Serial.print(" txdata.ID = ");
      Serial.println(txdata.ID);

      break;

    case 9 :  // Вывод на экран значений температуры воды в коллекторе

 
      txdata.ID = 61;
      delay(50);
      digitalWrite(DIR, HIGH);                      // включаем передачу
      delay(50);
      ETout.sendData();                              // отправляем

      Serial.print(" switchX = ");
      Serial.print(switchX);
      Serial.print(" txdata.ID = ");
      Serial.println(txdata.ID);

      break;

    default :
      // код выполняется если  не совпало ни одно предыдущее значение
      txdata.ID = 21;
      delay(50);
      digitalWrite(DIR, HIGH);                      // включаем передачу
      delay(50);
      ETout.sendData();                              // отправляем

      Serial.print(" switchX = ");
      Serial.print(switchX);
      Serial.print(" txdata.ID = ");
      Serial.println(txdata.ID);

      break;
  }
}


////////////////////////////////////////////////////////////////////////////////
///////////////////////////////*******//////////////////////////////////////////
//  E N D

