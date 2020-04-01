/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup SoftEasyTransfer
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void SoftEasyTransfer() {
//  запyск RS-485
  mySerial.begin(9600); // start serial port
  
  ETin1.begin(details(rxdata1), &mySerial); //  //start the library, pass in the data details and the name of the serial port
  
  ETout1.begin(details(txdata), &mySerial);

}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 
