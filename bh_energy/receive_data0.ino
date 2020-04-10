/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            Прием данных  от ардуины 
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void receiveDataETin1() {
  //ETin1.receiveData();
  byte id = rxdata1.ID; // читаем байт, в нем для кого этот пакет
  //   if (id == 01){ // и если пакет пришел нам от ардуины №1

  current_01 = rxdata1.current01;    //  №1 
  current_02 = rxdata1.current02;    //  №2 
  current_03 = rxdata1.current03;    //  №3
Serial.print("     receiveDataETin1");
    Serial.print("   rxdata1.ID = ");
  Serial.println(rxdata1.ID); 
/*
  Serial.print("  rxdata1.current01 = "); 
  Serial.print(rxdata1.current01);
  Serial.print("  current_01 = "); 
  Serial.println(current_01);
  Serial.println(" End receiveDataETin1"); 
  */
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 
