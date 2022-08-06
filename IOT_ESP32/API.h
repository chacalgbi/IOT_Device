void API_Login(){
  
  const char* serverName = "http://192.168.100.6:8087/device_login";
  String token = "qmdcgq889b";
  
  HTTPClient http;
  http.begin(client, serverName);
  
  http.addHeader("Content-Type", "application/json");
  String login = "{\"token\":\"" + token + "\"}";

  int httpResponseCode = http.POST(login);
  

  DynamicJsonDocument doc(1024);
  deserializeJson(doc, http.getString());

  const char * msg = doc["msg"];
  const char * description = doc["dados"][0]["description"];
  const char * obs = doc["dados"][0]["obs"];
  const char * erroGeral = doc["erroGeral"];

  Serial.println("---------------");
  Serial.println("HTTP Response code: " + String(httpResponseCode));
  Serial.println(msg);
  Serial.println(description);
  Serial.println(obs);
  Serial.println(erroGeral);

  
  http.end();

}
