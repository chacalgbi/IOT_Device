String date(){
  if (!getLocalTime(&timeinfo)) {
    return String ("Falha ao obter a data");
  }else{
    String date = "0" + String(timeinfo.tm_mday) + "\\0" + String(timeinfo.tm_mon + 1) + "\\" + String(1900 + timeinfo.tm_year);
    return date;
  } 
}

String hour(){
  if (!getLocalTime(&timeinfo)) {
    return String ("Falha ao obter a hora");
  }else{
    String hour = String(timeinfo.tm_hour) + ":" + String(timeinfo.tm_min) + ":" + String(timeinfo.tm_sec);
    return hour;
  } 
}
