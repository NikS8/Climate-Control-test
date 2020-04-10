/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup SoftEasyTransfer
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void SoftEasyTransferSetup() {
//  запyск RS-485
  mySerial.begin(9600); // start serial port
  
  ETin1.begin(details(rxdata1), &mySerial); //  //start the library, pass in the data details and the name of the serial port
  
  ETout.begin(details(txdata), &mySerial);

  pinMode(DIR, OUTPUT);

}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 
