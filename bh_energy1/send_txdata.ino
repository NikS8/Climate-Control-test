/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            sendTxData
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void sendTxData() {

    digitalWrite(DIR, HIGH);                      // включаем передачу

    for ( int i = 13 ; i < 16 ; i++) {
        current[i] = emonMultiple(i);
    }

    txdata.ID = ID;
    txdata.current01 = current[13];
    txdata.current02 = current[14];
    txdata.current03 = current[15];

    ETout.sendData();
    delay(30);   
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 
