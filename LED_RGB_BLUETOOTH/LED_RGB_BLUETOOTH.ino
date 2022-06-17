int red=11, green=10, blue=9;

char btRecebido; //RECEBE DADOS DO BLUETOOTH

String rgb, r, g, b;

int rInt; //RECEBE O VALOR INTEIRO QUE REPRESENTA A COR VERMELHA
int gInt; //RECEBE O VALOR INTEIRO QUE REPRESENTA A COR VERDE
int bInt; //RECEBE O VALOR INTEIRO QUE REPRESENTA A COR AZUL

int controle = 0; //CONTROLA OS CARACTERES RECEBIDOS

void setup(){
  Serial.begin(9600);    
}

void loop(){
  if(Serial.available()){
    btRecebido = Serial.read();
    rgb.concat(btRecebido);
    controle++;
  }
  
  if(controle == 9){
    //QUEBRA A STRING COM O CÓDIGO DA COR PARA CADA UMA DAS TRÊS CORES.
    r = rgb.substring(0,3);
    g = rgb.substring(3,6);
    b = rgb.substring(6,9);
    
    rInt = atoi(r.c_str());
    gInt = atoi(g.c_str());
    bInt = atoi(b.c_str());
    
    analogWrite(red, rInt);
    analogWrite(green, gInt);
    analogWrite(blue, bInt);
    rgb = "";
    controle = 0;
  }
}
