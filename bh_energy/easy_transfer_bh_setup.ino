/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup EasyTransfer
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void EasyTransferSetup() {
//  запyск RS-485
  Serial1.begin(9600); // start serial port
  
  ETin0.begin(details(rxdata0), &Serial1); //  //start the library, pass in the data details and the name of the serial port
  
  ETout0.begin(details(txdata), &Serial1);

}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
