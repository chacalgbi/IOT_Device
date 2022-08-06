void iniciar_OTA(){
  if(TemRede){
    debug("Iniciando","OTA","","",true,16,1);
    ArduinoOTA.setHostname("IOT Device");
    ArduinoOTA.begin();
    ArduinoOTA.onStart([]() { debug("Atualizando...","","","",true,16,0); });
    ArduinoOTA.onEnd([]()   { debug("Fim da","Atualizacao","","",true,16,1); });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total){
        unsigned int porcentagem = progress / (total / 100);
        debug("Atualizando",String(porcentagem),"%","",true,16,0);
        });
    ArduinoOTA.onError([](ota_error_t error) { debug("Erro ao","Atualizar","","",true,16,1); });
  }
  else{
    debug("Erro","OTA","","",true,16,1);
  }
}
