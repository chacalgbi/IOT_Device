const char* RetornaStatusWifi(wl_status_t Status){
  switch (Status){
  case WL_NO_SHIELD: return "NO_SHIELD";
  case WL_IDLE_STATUS: return "IDLE_STATUS";
  case WL_NO_SSID_AVAIL: return "SEM SSID DISP";
  case WL_SCAN_COMPLETED: return "SCAN CONCLUIDO";
  case WL_CONNECTED: return "CONECTADO";
  case WL_CONNECT_FAILED: return "CONEXAO FALHOU";
  case WL_CONNECTION_LOST: return "CONEXAO PERDIDA";
  case WL_DISCONNECTED: return "DESCONECTADO";
  default: return "Unknown";
  }
}

String IntensidadeSinalWifi(){
  int sinal = WiFi.RSSI();
  String sinal_str = "";

  if (sinal >= -65) {
    sinal_str = "Excelente";
  } else if (sinal >= -67) {
    sinal_str = "Muito Bom";
  } else if (sinal >= -70) {
    sinal_str = "Aceitavel";
  } else if (sinal >= -80) {
    sinal_str = "Ruim";
  } else if (sinal >= -99) {
    sinal_str = "Muito ruim";
  } else {
    sinal_str = "Extr. ruim";
  }

  return String(sinal) + "dBm " + sinal_str; 
}

String IP(){
  String ip = WiFi.localIP().toString().c_str();
  return ip; 
}

bool ConectaWifi(char* rede, char* senha, int tentativas){
  if (WiFi.status() != WL_CONNECTED){
    const int DELAY_CONFIG = 400;
    WiFi.disconnect(); 
    delay(DELAY_CONFIG);
    WiFi.mode(WIFI_STA);
    //WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
    //WiFi.setHostname("Lucas".c_str()); //define hostname
    //wifi_station_set_hostname( NomeRede.c_str() );
    delay(DELAY_CONFIG);
    WiFi.begin(rede, senha);
    delay(DELAY_CONFIG);
    while ( tentativas > 0) {
      if (WiFi.status() == WL_CONNECTED){
        break;
      }
      delay(1000);
      tentativas--;
      debug("Conectando","no WIFi","",String(tentativas),true,16,1);
    }
    debug(RetornaStatusWifi(WiFi.status())," ",IP(),"",true,16,1);
    if (WiFi.status() == WL_CONNECTED){
      return true;
    }else{
      return false;
    }
  }
  else{
    return true;
  }
}

bool PingServer(int num_pings){
  bool pingInfo = Ping.ping("www.google.com", num_pings);
  float ping_ms = Ping.averageTime();
  if(pingInfo){
    debug("Ping OK","google.com","",String(ping_ms)+"ms",true,16,3);
  }else{
    debug("Ping Falhou","","google.com",":(",true,16,1);
  }
  return pingInfo;
}
