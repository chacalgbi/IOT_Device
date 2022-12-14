// Definir para Minimal SPIFFS (1.9MB APP with OTA / 190 KB SPIFFS)
// A ordem das importações importa! Não alterar

#include "BIBLIOTECAS.h"
#include "INSTANCIAS.h"
#include "VARIAVEIS.h"
#include "DISPLAY.h"
#include "UTILS.h"
//#include "EEPROM.h"
#include "STORAGE.h"
#include "WIFI.h"
#include "WEBSERVER.h"
#include "UPDATEWEB.h"
#include "NTP.h"
#include "OTA.h"
//#include "I2C_Scan.h"
#include "API.h"
#include "COMPONENTES.h"


void normalSetup() {
  TemRede = ConectaWifi(ssid, pw, 10);
  if (TemRede) {
    iniciar_OTA();
    TemInternet = PingServer(3);
    configTime(-10800, 0, ntpServer); //-10800 segundos de (UTC -3 horas)
    API_Login(servidor, device_str);
  } else {
    ReinicaESP32("Sem Wifi");
  }
}

void normalLoop() {
  if (millis() - segundos_1 > 1016) {
    segundos_1 = millis();
    indicador_conexao();

  }

  if (millis() - segundos_5 > 5450) {
    segundos_5 = millis();
    //debug(hour(), date(), IP(), IntensidadeSinalWifi(), true, 16, 1);

  }

  if (millis() - segundos_10 > 10700) {
    segundos_10 = millis();

  }

  if (millis() - segundos_60 > 60227) {
    segundos_60 = millis();

  }

  if (millis() - segundos_180 > 180457) { // 3 minutos
    segundos_180 = millis();
    TemRede = ConectaWifi(ssid, pw, 15);
    TemInternet = PingServer(5);
    //tempe_proc(); // Temperatura do processador do ESP32

  }

  button_pres(); // Se pressionar o botão 1seg mostra as informações de memória, se pressionar 5seg reinicia o ESP32
  ArduinoOTA.handle();

}

void setup() {
  //deletaTodosNamespaces(); // Fazer só uma vez
  iniciar_PINs();
  indicador_inicilizacao();
  Serial.begin(9600);
  Wire.begin();
  delay(50);
  iniciar_display();
  Serial.println("\n\n");
  debug("ESP32", "", "Iniciado", "", true, 16, 0.5);
  StorageRead();

  if (modo_config == true) {
    config_rede();
  } else {
    normalSetup();
  }

  setTimeRele("15_12:10_15:30");
  //StringDivider();
  //debug("Atualizando via WEB","","","",true,16,1);
  //updateWeb();
  //I2C_Scanner();

}

void loop() {
  if (modo_config) {
    server.handleClient();
    delay(50);
  }
  else {
    normalLoop();
  }
}
