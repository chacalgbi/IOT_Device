void ler_EEPROM(){
  String aviso = "";
  int rele = 0;
  for (int i = 0; i < QTD_RELES; i++){
      hora_lig   [i] = EEPROM.read(indice_eeprom); indice_eeprom++;
      minuto_lig [i] = EEPROM.read(indice_eeprom); indice_eeprom++;
      hora_desl  [i] = EEPROM.read(indice_eeprom); indice_eeprom++;
      minuto_desl[i] = EEPROM.read(indice_eeprom); indice_eeprom++;

      rele = i + 1;
      aviso = "Rele"+String(rele)+" = "+String(hora_lig[i])+":"+String(minuto_lig[i])+" - "+String(hora_desl[i])+":"+String(minuto_desl[i]);
      Serial.println(aviso);
      aviso = "";
  }
  indice_eeprom = 0;
}

void zerar_EEPROM(int endereco){
  for (int i = 0 ; i < endereco; i++){
    Serial.print(String(i));
    Serial.print(" Antes:");  Serial.print(String(EEPROM.read(i)));
    EEPROM.write(i, 0);
    EEPROM.commit();
    delay(20);
    Serial.print(" Depois:"); Serial.println(String(EEPROM.read(i)));
  }
  debug("","EEPROM","","LIMPA",true,16,2);
}

boolean configSave() {
  // Grava configuração
  StaticJsonDocument<JSON_SIZE> jsonConfig;
  File file = SPIFFS.open(F("/Config.json"), "w+");
  if (file) {
    jsonConfig["device"] = device;
    jsonConfig["ssid"]   = ssid;
    jsonConfig["pw"]     = pw;

    serializeJsonPretty(jsonConfig, file);
    file.close();
    serializeJsonPretty(jsonConfig, Serial);
    debug("Gravado","SPIFFS","","",true,16,2);
    return true;
  }
  return false;
}

boolean configRead() {
  // Lê configuração
  StaticJsonDocument<JSON_SIZE> jsonConfig;

  File file = SPIFFS.open(F("/Config.json"), "r");
  if (deserializeJson(jsonConfig, file)) {
    // Falha na leitura, assume valores padrão
    debug("Falha ao","ler o","SPIFFS",":(",true,16,2);
    return false;
  } else {
    // Sucesso na leitura
    strlcpy(device,  jsonConfig["device"] | "", sizeof(device)); 
    strlcpy(ssid,    jsonConfig["ssid"]   | "", sizeof(ssid));
    strlcpy(pw,      jsonConfig["pw"]     | "", sizeof(pw));
    device_str = device;
    pw_str = pw;
    ssid_str = ssid;
    
    file.close();
    //debug("SPIFFS OK",ssid,pw,device_str,true,16,2);
    serializeJsonPretty(jsonConfig, Serial);
    Serial.println("");
    return true;
  }
}

void iniciar_SPIFFS(){
  if(!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)){
    debug("Falha SPIFFS","","Contacte o","Suporte",true,16,1); 
    while(true){}
    }
  else{
    debug("Sucesso ao","iniciar o","SPIFFS",":)",true,16,1);
    configRead();  // Ler conteudo da SPIFFS
    }
}
