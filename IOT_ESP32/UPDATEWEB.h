void updateWeb(){
  httpUpdate.setLedPin(led, LOW);
  
  t_httpUpdate_return ret = httpUpdate.update(client, "http://devrails.com.br/img/teste.bin");

  switch (ret) {
    case HTTP_UPDATE_FAILED:
      //Serial.printf("HTTP_UPDATE_FAILED Error (%d): %s\n", httpUpdate.getLastError(), httpUpdate.getLastErrorString().c_str());
      debug("", "HTTP_UPDATE", "", "FAILED Error", true, 16, 2);
      break;

    case HTTP_UPDATE_NO_UPDATES:
      debug("", "HTTP_UPDATE", "", "NO_UPDATES", true, 16, 2);
      break;

    case HTTP_UPDATE_OK:
      debug("", "HTTP_UPDATE", "", "OK", true, 16, 2);
      break;
  }
}
