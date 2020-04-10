/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            sendTxData
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void sendTxData() {
delay(55); 
    digitalWrite(DIR, HIGH);                      // включаем передачу
delay(55); 
    for ( int i = 13 ; i < 16 ; i++) {
        current[i] = emonMultiple(i);
    }

    txdata.ID = ID;
    txdata.current01 = 100 * current[13];
    txdata.current02 = 100 * current[14];
    txdata.current03 = 100 * current[15];

    Serial.println("     sendTxData");
  Serial.print("  txdata.current01 = "); 
  Serial.print(txdata.current01);
  Serial.print("  current[13] = "); 
  Serial.println(current[13]);
  Serial.println(" End sendTxData"); 

    ETout.sendData();
    delay(30);   
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 
