void setTimeRele(String releAndTime){
  //EX: Se tiver 3 relés na placa.
  // releAndTime deve vir nos formatos: 1_08:05_09:10 , 12_10:00_11:00 , 7_05:10_06:00
  // O primeiro número é o relé e depois a hora de ligar e depois a hora de desligar.

  //Pega o relé
  int index1 = releAndTime.indexOf('_', 0);
  String rele = releAndTime.substring(0, index1);

  //Pega a hora de ligar
  int index2 = releAndTime.indexOf('_', index1+1);
  String ligar = releAndTime.substring(index1+1, index2);

  //pega a hora de desligar
  int index3 = releAndTime.indexOf('_', index2+1);
  String desligar = releAndTime.substring(index2+1, index3);
  
  //debug("Rele: "+rele,"Liga: "+ligar,"","Desl: "+desligar,true,16,2);

  preferences.begin("times", false);

  if(rele == "1"){
    preferences.putString("liga1", ligar);
    preferences.putString("desl1", desligar);
    if(ligar == "00:00"){
      debug("Time Rele1","DESABILITADO","","",true,16,2);
    }else{
      debug("Rele: "+rele,"Liga: "+ligar,"","Desl: "+desligar,true,16,2);
    }
  }else if(rele == "2"){
    preferences.putString("liga2", ligar);
    preferences.putString("desl2", desligar);
    if(ligar == "00:00"){
      debug("Time Rele2","DESABILITADO","","",true,16,2);
    }else{
      debug("Rele: "+rele,"Liga: "+ligar,"","Desl: "+desligar,true,16,2);
    }
  }else if(rele == "3"){
    preferences.putString("liga3", ligar);
    preferences.putString("desl3", desligar);
    if(ligar == "00:00"){
      debug("Time Rele3","DESABILITADO","","",true,16,2);
    }else{
      debug("Rele: "+rele,"Liga: "+ligar,"","Desl: "+desligar,true,16,2);
    }
  }else{
    debug("Rele nao","encontrado","","",true,16,2);
  }

  preferences.end();

}

void readTimeReles(){
  preferences.begin("times", true);

  time_liga_rele1 = preferences.getString("liga1", "NULL");
  time_liga_rele2 = preferences.getString("liga2", "NULL");
  time_liga_rele3 = preferences.getString("liga3", "NULL");

  time_desl_rele1 = preferences.getString("desl1", "NULL");
  time_desl_rele2 = preferences.getString("desl2", "NULL");
  time_desl_rele3 = preferences.getString("desl3", "NULL");

  preferences.end();
}
