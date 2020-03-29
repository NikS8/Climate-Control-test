/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            emonMultiple
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
float emonMultiple(int i) {

    digitalWrite(S0, (i >> 0) & 0x01);
    digitalWrite(S1, (i >> 1) & 0x01);
    digitalWrite(S2, (i >> 2) & 0x01);
    digitalWrite(S3, (i >> 3) & 0x01);

  return emon0.calcIrms(1480);
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 
