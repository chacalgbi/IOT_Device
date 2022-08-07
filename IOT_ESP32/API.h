void API_Login(char* servidor, String token){
  
  HTTPClient http;
  http.begin(client, servidor);
  
  //Prepara o cabeçalho da requisição
  http.addHeader("Content-Type", "application/json");

  //Monta o corpo da requisição: "token":"*****"
  String login = "{\"token\":\"" + token + "\"}";

  //Faz a solicitação e aguarda o status da resposta
  int httpResponseCode = http.POST(login);
  
  //Converte a string de resposta em um objeto JSON
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, http.getString());

  const char * msg = doc["msg"];
  const char * description = doc["dados"][0]["description"];
  const char * obs = doc["dados"][0]["obs"];
  const char * erroGeral = doc["erroGeral"];

  if(httpResponseCode == 200){
    debug("Login OK", msg, description, obs, true, 16, 2);
  }else{
    debug("Login Error", "Code:", String(httpResponseCode), "", true, 16, 2);
  }
  
  http.end();

}
