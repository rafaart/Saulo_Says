//array que definem as portas para os leds
int ledPins[] = {
  0,1,2,3,4,5,6,7
};
// array que define a sequencia de leds do jogador 1 que vão piscar
int sequenc1[] = {
  0,0,0,0,0,0,0,0
};

// array que define a sequencia de leds do jogador 2 que vão piscar
int sequenc2[] = {
  0,0,0,0,0,0,0,0
};

//array que guarda os valores dos ldrs para calibragem
int LDRsVal[] = {
  0,0,0,0,0,0,0,0
};

// tempo ja dercorrido para o jogador 1
unsigned long tempo1 = 0;

// tempo ja dercorrido para o jogador 2
unsigned long tempo2 = 0;

int randNumber;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);

  pinMode (0,OUTPUT);
  pinMode (1,OUTPUT);
  pinMode (2,OUTPUT);
  pinMode (3,OUTPUT);
  pinMode (4,OUTPUT);
  pinMode (5,OUTPUT);
  pinMode (6,OUTPUT);
  pinMode (7,OUTPUT);
  

  pinMode (8,OUTPUT);

  randomSeed(analogRead(0));
  //faz uma leitura previa dos valores lidos nos LDRs para calibração.
  for (int d=0;d<=3;d++){
    digitalWrite(ledPins[d],HIGH);
    delay(100);
    LDRsVal[d]=analogRead(d);
  }

  for (int d=0;d<=3;d++){
    digitalWrite(ledPins[d],LOW);
  }

    for (int d=4;d<=7;d++){
    digitalWrite(ledPins[d],HIGH);
    delay(100);
    LDRsVal[d]=analogRead(d);
  }

  for (int d=4;d<=7;d++){
    digitalWrite(ledPins[d],LOW);
  }
  
}

void loop() {

    for(int z=0; z<=3; z++){
      digitalWrite(z,HIGH);
    }
while(foiPressionadoP1()>=0){
  
}

    for(int z=4; z<=7; z++){
      digitalWrite(z,HIGH);
    }
while(foiPressionadoP1()>=0){
  
}
  
  //declaração da variavel que armazena os pontos do jogador 1
  int pontos1=3;

  //declaração da variavel que armazena os pontos do jogador 2
  int pontos2=3;

  //loop para preencher o array do jogador 1
  for(int i=0;i<6;i++){
    randNumber = random(0,4);
    sequenc1[i] = randNumber;
  }

//loop para preencher o array do jogador 2
   for(int i=0;i<6;i++){
    randNumber = random(4,8);
    sequenc2[i] = randNumber;
  }

  // tempo de espera pela resposta dos LDRs
  long intervalo = 4500;


  //espera um tempo para começar
  delay (1000);



  //percorre o array da sequencia
  for (int a=0; a<6; a++){
    if (a>2){
      a=7;
    }

    //aumenta mais dois segundos para resposta do jogador a cada jogada.
    intervalo =((a+1)*2000)+ 4000;

/* -----------------------
* atuação do jogador 1 
------------------------*/
    for(int z=0; z<=3; z++){
      digitalWrite(z,HIGH);
    }
    delay(1000);

    //pisca a sequencia do jogador 1
    for (int i=0; i<=a; i++){
      digitalWrite(sequenc1[i],LOW);
      tone(8,(sequenc1[i]+4)*120,500);
      delay (500);
      digitalWrite(sequenc1[i],HIGH);
      delay (500);
    }

    //guarda o tempo atual antes de ler a resposta dos LDRs
    tempo1 = millis();

    //flag para que a leitura dos LDRs acompanhe a sequencia
    int ordem1 = 0;

    //tomar resposta dos LDRs do grupo 1
    while((tempo1+intervalo) > millis() && ordem1 <= a){
      int pressionado = foiPressionadoP1();
      if (pressionado!=-1){
        if (sequenc1[ordem1] == pressionado){
          //pisca indicando que acertou
          digitalWrite(sequenc1[ordem1],LOW);
          delay (100);
          digitalWrite(sequenc1[ordem1],HIGH); 
          delay (100);
          digitalWrite(sequenc1[ordem1],LOW);
          delay (100);
          digitalWrite(sequenc1[ordem1],HIGH);
          delay (100);
          digitalWrite(sequenc1[ordem1],LOW);
          delay (100);
          digitalWrite(sequenc1[ordem1],HIGH);
                    delay (100);
          digitalWrite(sequenc1[ordem1],LOW);
          delay (100);
          digitalWrite(sequenc1[ordem1],HIGH);
                    delay (100);
          digitalWrite(sequenc1[ordem1],LOW);
          delay (100);
          digitalWrite(sequenc1[ordem1],HIGH);
            delay (100);
          digitalWrite(sequenc1[ordem1],LOW);
          delay (100);
          digitalWrite(sequenc1[ordem1],HIGH);
          delay (100);

                 
          ordem1++;
        }else{
          errrou(0);
          ordem1 = a+1;
          pontos1--;
        }

      }
    }

    //se o tempo acabou e não foi digitado toda ordem decrementa a pontuação
    if (ordem1 <= a){
      errrou(0);
      pontos1--;
    }

    for(int z=0; z<=3; z++){
      digitalWrite(z,LOW);
    }

    delay(2000); 



/* --------------------------
* atuação do jogador 2 
----------------------------*/
    for(int z=4; z<=7; z++){
      digitalWrite(z,HIGH);
    }

    delay(1000);

    //pisca a sequencia do jogador 2
    for(int z=0; z<=a; z++){
      digitalWrite(sequenc2[z],LOW);
      tone(8,sequenc2[z]*120,500);
      delay (500);
      digitalWrite(sequenc2[z],HIGH);
      delay (500);
    } 

    //guarda o tempo atual antes de ler a resposta dos LDRs
    tempo2 = millis();

    //flag para que a leitura dos LDRs acompanhe a sequencia
    int ordem2 = 0;

    //tomar resposta dos LDRs do grupo 1
    while(tempo2+intervalo > millis() && ordem2 <= a){
      int pressionado = foiPressionadoP2();
      if (pressionado!=-1){
        if (sequenc2[ordem2] == pressionado){
          //pisca indicando que acertou
          digitalWrite(sequenc2[ordem2],LOW); 
          delay (100);
          digitalWrite(sequenc2[ordem2],HIGH);
          delay (100);
          digitalWrite(sequenc2[ordem2],LOW);
          delay (100);
          digitalWrite(sequenc2[ordem2],HIGH);
          delay (100);
          digitalWrite(sequenc2[ordem2],LOW);
          delay (100);
          digitalWrite(sequenc2[ordem2],HIGH);
          delay (100);
          digitalWrite(sequenc2[ordem2],LOW);
          delay (100);
          digitalWrite(sequenc2[ordem2],HIGH);
          delay (100);
          digitalWrite(sequenc2[ordem2],LOW);
          delay (100);
          digitalWrite(sequenc2[ordem2],HIGH);
          delay (100);
          digitalWrite(sequenc2[ordem2],LOW);
          delay (100);
          digitalWrite(sequenc2[ordem2],HIGH);
          delay (100);

          
          ordem2++;
        }else{
          errrou(4);
          ordem2 = a+1;
          pontos2--;
        }

      }
    }

    //se o tempo acabou e não foi digitado toda ordem decrementa a pontuação
    if (ordem2 <= a){
      errrou(4);
      pontos2--;
    }
    
      for(int z=4; z<=7; z++){
      digitalWrite(z,LOW);
    }
    
    delay(2000);
   

  } 

  // final do jogo imprime a quantidade de acertos do jogador 1
  pontuacao(pontos1, 0);

  // final do jogo imprime a quantidade de acertos do jogador 2
  pontuacao(pontos2, 4);

  for (int a=0; a<=7; a++){
    digitalWrite(ledPins[a],HIGH);
  }

        for(int z=4; z<=7; z++){
      digitalWrite(z,LOW);
    }

}


//função que mostra que acabou a rodada
void pontuacao(int pontos, int jogador){
  int inicio = jogador;
  int fim = jogador + pontos;

  //ascende todos os leds para sinalizar fim da partida  
  for (int a=inicio; a<=fim; a++){
    digitalWrite(ledPins[a],LOW);
  }
  delay (1000);
  for (int a=inicio; a<=fim; a++){
    digitalWrite(ledPins[a],HIGH);
  }
  delay (1000);
  
}

//função que mostra que errou a ordem
void errrou(int inicio){
  for (int a=inicio; a<=inicio+3; a++){
    digitalWrite(ledPins[a],LOW);
    delay (100);
    tone (8, 100, 500);
  }
  delay (500);
  for (int a=inicio; a<=inicio+3; a++){
    digitalWrite(ledPins[a],HIGH);
  }
  delay (500);
}

int foiPressionadoP1(){
  for (int c=0;c<=3;c++){
    int Resp=analogRead(c);
    if(Resp<LDRsVal[c]-300){
      return(c);
    }
  }
  return(-1);
}

int foiPressionadoP2(){
  for (int c=4;c<=7;c++){
    int Resp=analogRead(c);
    if(Resp<LDRsVal[c]-120){
      return(c);
    }
  }
  return(-1);
}
