void deletaTodosNamespaces() {
    //Após executar este código no ESP32, deve-se carregar outro sketch para não desgastar a vida útil da memória do ESP32.
    //Execute esta função somente quando necessário.
    
    Serial.println("Partição NVS sendo limpa...");
    nvs_flash_erase(); // apague a partição NVS
    nvs_flash_init(); // inicializa a partição NVS
    Serial.println("Partição zerada com sucesso.");
    while (1);
}

void StorageSave(String ssid, String pass, String device, String server){
  preferences.begin("configs", false);

  preferences.putString("ssid", ssid);
  preferences.putString("pass", pass);
  preferences.putString("device", device);
  preferences.putString("server", server);

  preferences.end();

  debug("Salvo na Storage","","","",true,16,2);
}

void StorageRead(){
  preferences.begin("configs", true);

  ssid_str   = preferences.getString("ssid", "NULL");
  pw_str     = preferences.getString("pass", "NULL");
  device_str = preferences.getString("device", "NULL");
  server_str = preferences.getString("server", "http://www.google.com.br");

  preferences.end();

  device_str.trim(); strlcpy(device,    device_str.c_str(), sizeof(device));
  ssid_str.trim();   strlcpy(ssid,      ssid_str.c_str(),   sizeof(ssid));
  pw_str.trim();     strlcpy(pw,        pw_str.c_str(),     sizeof(pw));
  server_str.trim(); strlcpy(servidor,  server_str.c_str(), sizeof(servidor));

  debug("Read Storage:","","","",true,16,2);
  debug(ssid_str, pw_str, device_str, server_str, true,16,2);
}

/*

  Abra Preferências com o nome de namespace informado.
    name:      indica o nome do namespace
    readOnly:  true= leitura, false= leitura/gravação
      
      preferences.begin("config_aleats", false);
  
  
 
  Coloque valores-chave (salve um valor)
      key:    indica o nome da chave
      value:  valor para setar
    
  preferences.putChar("key_carac", 'e');
  preferences.putInt("key_nInt", 23);
  preferences.putUInt("key_nIntPosi", 8764);
  preferences.putFloat("key_nDec", 3.1415);
  preferences.putBool("key_boolean", true);
  preferences.putString("key_palavra", "Eletrogate - eletrogate.com");

----------------------------------------------------------------------------
  
  Obtenha os valores-chave (valor de leitura)
      key:           indica o nome da chave
      defaultValue:  opcional, valor para retornar caso não seja encontrado valor
  
  caractere = preferences.getChar("key_carac", '-');
  numeroInteiro = preferences.getInt("key_nInt", 0);
  numeroInteiroPositivo = preferences.getUInt("key_nIntPosi", 0);
  numeroDecimal = preferences.getFloat("key_nDec", 0);
  booleano = preferences.getBool("key_boolean", false);
  palavra = preferences.getString("key_palavra", "NULL");

------------------------------------------------------------------------------
  Fecha as preferências no namespace aberto.
    preferences.end();
-------------------------------------------------------------------------------

  Limpa todas as preferências no namespace aberto (não exclui o namespace)
    preferences.clear();

-------------------------------------------------------------------------------

  Remova as chaves dos namespace's
    preferences.remove("key_carac");
    preferences.remove("key_nInt");
    preferences.remove("key_nIntPosi");
    preferences.remove("key_nDec");
    preferences.remove("key_boolean");
    preferences.remove("key_palavra");


  


*/
