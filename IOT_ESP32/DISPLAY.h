void barra_progresso(int p1, int p2, int p3, int p4, int p5, int tempo){
  for (int x=0; x<p5; x++){ // p5 é o valor total da barra
    display1.drawProgressBar(p1, p2, p3, p4, x); // Onde começa a barra a esquerda
                                                 // Linha onde a barra vai ficar
                                                 // Onde finaliza a barra a Direita
                                                 // Largura da Barra
                                                 // Valor a ser mostrado na progressao da barra
    display1.display();
    delay(tempo);
  }
}

void iniciar_display(){
  display1.init();
  display1.flipScreenVertically();
  display1.setTextAlignment(TEXT_ALIGN_LEFT);
  display1.setFont(ArialMT_Plain_16);
  display1.drawString(0, 0, "Iniciando...");
  display1.display();
  barra_progresso(0, 30, 127, 10, 100, 20);
  display1.clear();
  display1.display();
}

void mostrar_display(String t1, String t2, String t3, String t4, byte fonte, float segundos){
  int tempo = segundos * 1000;
  display1.clear();
  display1.setTextAlignment(TEXT_ALIGN_CENTER);
  if(fonte == 10){display1.setFont(ArialMT_Plain_10);}
  if(fonte == 16){display1.setFont(ArialMT_Plain_16);}
  display1.drawString(64,  0, t1);
  display1.drawString(64, 16, t2);
  display1.drawString(64, 32, t3);
  display1.drawString(64, 48, t4);
  display1.display();
  delay(tempo);
}
