/*
Autor : Mateus 
Nome: CarretaFuracao
Versão : 1
Descrição:.....
*/
//definição de angulo max e min
#define AnguloMin 0
#define AnguloMax 180
#define AnguloMinB 0
#define AnguloMaxB 180

//inclusão da bibblioteca servo
#include<Servo.h>
//criando objetos x e y
Servo x;
Servo y;
// criando uma variavel "estado" para controlar 
// a máquina de estados ela é do tipo charatere
char estado;

//função setup predefine as entradas e saidas da lógica
void setup()
{
  // definimos que as portas 9 e 10 do arduino serão 
  // usadas para servos
  x.attach(9);
  y.attach(10);
  //iniciamos a comunicação serial
  Serial.begin(9600);
}
//cria função que ficará em loop
void loop()
{
  //se o serial estiver disponivel e for maior que zero 
  //executa o que está dentro das chaves
  if (Serial.available() > 0) {
    //a variavel estado vai fazer leitura da comunicação serial
    estado  = Serial.read();
    // a comunicação serial manda de volta como confirmação
    //do que foi recebido
    Serial.write(estado);
  }
  //se a leitura da varial estado for igual a 'W' ele ira enviar um comando para o servo 
  //se movimentar
  if (estado == 'W') {
    x.write(AnguloMin );
  }
  else if (estado == 'S') {  // Se o estado recebido for igual a 'I', o carro se movimenta para Frente Esquerda.
    x.write(AnguloMax);

  } else if (estado == 'A') {  // Se o estado recebido for igual a 'I', o carro se movimenta para Frente Esquerda.
    y.write(AnguloMax);

  }else if (estado == 'D') {  // Se o estado recebido for igual a 'I', o carro se movimenta para Frente Esquerda.  
    y.write(AnguloMin );

  }


}
