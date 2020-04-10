/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            Передача данных к ардуине 
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void sendTxData() {

//    digitalWrite(DIR, HIGH);                      // включаем передачу

ID = 11;              // номер ардуины
action = 'a';    //  "get"/"set" - запрос выдачи данных / команда на исполнение

    txdata.ID = ID;
    txdata.action = action;
    
  Serial.println("     sendTxData");
  Serial.print("  txdata.ID = "); 
  Serial.print(ID);
  Serial.print("  txdata.action = "); 
  Serial.println(txdata.action);
  Serial.println(" ETout1.sendData()"); 

    delay(30);   
    ETout1.sendData();
    delay(30);   
    
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 
