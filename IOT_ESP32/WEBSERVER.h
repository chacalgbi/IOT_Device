void PaginaInicial() {
  //Go to http://192.168.4.1 in a web browser
String html  = "<!DOCTYPE html><head><html lang='pt-br'><meta charset='UTF-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Configurar WIFI</title>";
       html += "</head><body onload=\"myFunction()\" align='center'>";
       html += "<h3>CONFIGURAÇÃO<br> WIFI</h3>";
       html += "<form method='POST' action='/form'>";
       
       if(ssid_str == ""){
          html += "<input type=text placeholder='DIGITE O NOME DA REDE'  name=txt_ssid /><br><br>";
       }else{
          html += "<input type=text value=";
          html += ssid_str;
          html += " name=txt_ssid /><br><br>";
       }

       if(pw_str == ""){
          html += "<input type=text placeholder='DIGITE A SENHA DA REDE' name=txt_pw   /><br><br>";
       }else{
          html += "<input type=text value=";
          html += pw_str;
          html += " name=txt_pw   /><br><br>";
       }
       
       if(device_str == ""){
          html += "<input type=text placeholder='TOKEN DO DISPOSITIVO'          name=txt_nome /><br><br>";
       }else{
          html += "<input type=text value=";
          html += device_str;
          html += " name=txt_nome /><br><br>";
       }

       if(server_str == ""){
          html += "<input type=text placeholder='URL DO SERVIDOR'          name=txt_server /><br><br>";
       }else{
          html += "<input type=text value=";
          html += server_str;
          html += " name=txt_server /><br><br>";
       }

       
       html += "<input type=submit name=botao value=Enviar />";
       html += "</form>";
       html += "</body></html>";
server.send(200, "text/html", html);
}

void formularioEnviado() {
String html =  "<!DOCTYPE html><head><html lang='pt-br'><meta charset='UTF-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>WIFI Configurado</title></head><body align='center'><h3>Seu dispositivo foi<br> configurado</h3>";
       html += "<h1><font color='red'>SSID: ";
       html += server.arg("txt_ssid");
       html += "</h1></font><br><h1><font color='green'>SENHA: ";
       html += server.arg("txt_pw");
       html += "</font></h1></body></html>";
       server.send(200, "text/html", html);

  device_str   = server.arg("txt_nome");
  ssid_str     = server.arg("txt_ssid");
  pw_str       = server.arg("txt_pw");
  server_str   = server.arg("txt_server");

  StorageSave(ssid_str, pw_str, device_str, server_str);

//  device_str.trim(); strlcpy(device,  device_str.c_str(), sizeof(device));
//  ssid_str.trim();   strlcpy(ssid,    ssid_str.c_str(),   sizeof(ssid));
//  pw_str.trim();     strlcpy(pw,      pw_str.c_str(),     sizeof(pw));

/*  if(configSave()){ // salva na SPIFFS
    debug("Dados:","Gravados","","...",true,16,1);
  }else{
    debug("Erro ao","Gravar","Dados","",true,16,1);
  }
*/  
  ReinicaESP32("Resetando");
}

void config_rede(){
  WiFi.softAP("IOT Device");
  server.on("/", PaginaInicial);
  server.on("/form", HTTP_POST, formularioEnviado);
  server.begin();
  debug("Modo","Config","Ativado","",true,16,1);
}
