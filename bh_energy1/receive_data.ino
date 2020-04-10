/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            receiveData()
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void receiveRxData() {
if (ETin1.receiveData()) {                         // если пришли данные
    
    byte id = rxdata1.ID; // читаем байт, в нем для кого этот пакет

Serial.println("     receiveData");
  Serial.print("  byte id = rxdata1.ID = "); 
  Serial.print(rxdata1.ID);
  Serial.print("   rxdata1.action = "); 
  Serial.print(rxdata1.action);
 
  Serial.println("");
    Serial.println(millis()); 
    if (id == ID) { // и если пакет пришел нам
          
          sendTxData();
          }
        
      }
  }
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 
