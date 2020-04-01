/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            settings bh_energy
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//	#include "bh_energy_init.h"

//	Блок httpServer	-----------------------------------------------------------
byte mac[] = {0xCA, 0x74, 0xC0, 0xFF, 0xBE, 0x01};
IPAddress ip(192, 168, 1, 115);
EthernetServer httpServer(40115);

//  Блок EasyTransfer  ------------------------------------------------------
#define DIR 7            // переключатель прием\передача на Pin13
int ID = 11;              // номер этой ардуины
SoftwareSerial mySerial(5, 6);     // Serial для RS485
SoftEasyTransfer ETin1, ETout1;  //create  objects

//EasyTransfer ETin0, ETout0;  //create  objects

struct SEND_DATA_STRUCTURE {   // структура, которую будем передавать
  int ID;
  char action;
};
//int ID = 11;              // номер ардуины
char action = "get";    //  "get"/"set" - запрос выдачи данных / команда на исполнение

struct RECEIVE_DATA_1_STRUCTURE {  // структура, которую будем принимать
  int ID;
  int current01;    // трансформатор тока на общей фазе №1 
  int current02;    // трансформатор тока на общей фазе №2 
  int current03;    // трансформатор тока на общей фазе №3
};

//give a name to the group of data
SEND_DATA_STRUCTURE txdata;
RECEIVE_DATA_1_STRUCTURE rxdata1;

float current_01;
float current_02;
float current_03;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 
