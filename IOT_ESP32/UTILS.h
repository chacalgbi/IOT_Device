void debug(String linha1, String linha2, String linha3, String linha4, bool Display, byte Tamanho, float Tempo){
  Serial.print(linha1);
  Serial.print(" ");
  Serial.print(linha2);
  Serial.print(" ");
  Serial.print(linha3);
  Serial.print(" ");
  Serial.println(linha4);

  if(Display){
    mostrar_display(linha1, linha2, linha3, linha4, Tamanho, Tempo);
  }
}

void ReinicaESP32(String Aviso){
  debug("Reiniciando","...",Aviso,"",true,16,1);
  esp_task_wdt_init(1,true); // define o whachDog pra 1 segundo
  esp_task_wdt_add(NULL);    // adiciona o processo atual
  while(true); // loop infinito pra resetar o ESP32
}

void iniciar_PINs(){
  pinMode(config_wifi, INPUT);
//pinMode(Reset_Sinal, OUTPUT); digitalWrite(Reset_Sinal, LOW);
  pinMode(led,         OUTPUT); digitalWrite(led,         LOW);
  pinMode(rele1,       OUTPUT); digitalWrite(rele1,       LOW);
//pinMode(rele2,       OUTPUT); digitalWrite(rele2,       LOW);
//pinMode(rele3,       OUTPUT); digitalWrite(rele3,       LOW);
//pinMode(rele4,       OUTPUT); digitalWrite(rele4,       LOW);
//pinMode(rele5,       OUTPUT); digitalWrite(rele5,       LOW);

  if(!digitalRead(config_wifi)){modo_config = true;} // SE O PINO ESTIVER NO GND INICIA EM MODO CONFIGURAÇÃO
}

void indicador_inicilizacao(){
  for( int i=0; i<50; i++){
    digitalWrite(led, !digitalRead(led));
    delay(50);
  }
  digitalWrite(led, LOW);
}

void indicador_conexao(){ // Pisca o LED de maneiras diferentes para indicar conexão
  
  if(TemInternet){ // Tem Internet e WIFI
    digitalWrite(led, !digitalRead(led));
  }else if(TemRede){ // NÃO tem internet mas o WIFI está conectado
    for( int i=0; i<10; i++){
      digitalWrite(led, !digitalRead(led));
      delay(25);
    }
    digitalWrite(led, LOW);
  }else{ // Sem WIFI e Internet
    digitalWrite(led, HIGH);
  }

}

void info(){
    //RAM
  uint32_t RAM_total = ESP.getHeapSize();        RAM_total = RAM_total / 1024;
  uint32_t RAM_livre = ESP.getFreeHeap();        RAM_livre = RAM_livre / 1024;
  uint32_t RAM_usada = RAM_total - RAM_livre;
  int RAM_porcentagem_usada =  (RAM_usada * 100) / RAM_total;
  
  //ROM (Espaço programa + OTA)  
  uint32_t ROM_usado = ESP.getSketchSize();      ROM_usado   = ROM_usado / 1024;
  uint32_t ROM_total = ESP.getFreeSketchSpace(); ROM_total   = ROM_total / 1024;
  uint32_t ROM_livre = ROM_total - ROM_usado;
  int ROM_porcentagem_usada = (ROM_usado * 100) / ROM_total;

  // Tamanho total da FLASH (ROM/SPI/OTA)
  uint32_t SIZE_chip = ESP.getFlashChipSize();   SIZE_chip   = SIZE_chip / 1024;
  int  FREQ = ESP.getCpuFreqMHz();

  String RAM = "ram" + String(RAM_porcentagem_usada) + "%";
  String ROM = "rom" + String(ROM_porcentagem_usada) + "%";
  String usado = RAM + " " + ROM;
  String RAM_descr = "RAM: " + String(RAM_usada) + "KB de " + String(RAM_total)+ "KB";
  String ROM_descr = "ROM: " + String(ROM_usado) + "KB de " + String(ROM_total)+ "KB";

  Serial.println( String(FREQ) + " MHz" );
  debug("Espaco Usado: ", usado, RAM_descr, ROM_descr ,true,16,1);
}

void button_pres(){
  if(!digitalRead(config_wifi)){
    info();
    delay(4000);
    if(!digitalRead(config_wifi)){
      ReinicaESP32("Reset press");
    }
  } 
}

void tempe_proc(){
  temp_int = ((temprature_sens_read() - 32 ) / 1.8);
  debug("Tempe Proc: ", "", String(temp_int)+"C", "" ,true,16,1);
}

void StringDivider(){
  // Aqui vamos considerar que a String inicial tem 4 pedaços que quero separar
  String Teste = "Thome_Lucas_Araujo_Oliveira";
  
  int index1 = Teste.indexOf('_', 0);
  String a1 = Teste.substring(0, index1);

  int index2 = Teste.indexOf('_', index1+1);
  String a2 = Teste.substring(index1+1, index2);

  int index3 = Teste.indexOf('_', index2+1);
  String a3 = Teste.substring(index2+1, index3);

  int index4 = Teste.indexOf('_', index3+1);
  String a4 = Teste.substring(index3+1, index4);

  Serial.println("\n\n\n");
  Serial.print(index1); Serial.print(" - "); Serial.println(a1);
  Serial.print(index2); Serial.print(" - "); Serial.println(a2);
  Serial.print(index3); Serial.print(" - "); Serial.println(a3);
  Serial.print(index4); Serial.print(" - "); Serial.println(a4);
}
