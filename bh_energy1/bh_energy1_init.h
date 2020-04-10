/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            settings bh_energy1
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//	#include "bh_energy1_init.h"

//  Блок EmonLib  -------------------------------------------------------------
EnergyMonitor emon0;

#define EN 6
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define SIG A0

double current[17];

//  Блок SoftEasyTransfer  ------------------------------------------------------
#define DIR 13            // переключатель прием\передача на Pin13
int ID = 11;              // номер этой ардуины
SoftwareSerial mySerial(12, 11);     // Serial для RS485
SoftEasyTransfer ETin1, ETout;  //create  objects

struct RECEIVE_DATA_1_STRUCTURE {  // структура, которую будем принимать
  int ID;
  char action;
};

struct SEND_DATA_STRUCTURE {   // структура, которую будем передавать
  int ID;
  int current01;   // трансформатор тока на общей фазе №1 
  int current02;   // трансформатор тока на общей фазе №2 
  int current03;   // трансформатор тока на общей фазе №3
};

//give a name to the group of data
SEND_DATA_STRUCTURE txdata;
RECEIVE_DATA_1_STRUCTURE rxdata1;



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 
