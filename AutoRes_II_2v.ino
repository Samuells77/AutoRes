// Inclui a biblioteca DHT que possui as funções dos sensores do tipo DHT
#include "DHT.h"

#include <SoftwareSerial.h> // Comandos Seriais

SoftwareSerial HC05(2, 3); // TX-RX

// Declaração dos pinos
const int pinoLEDR1 = 13;
const int pinoLEDG1 = 12;
const int pinoLEDB1 = 11;
const int pinoLEDR2 = 10;
const int pinoLEDG2 = 9;
const int pinoLEDB2 = 8;
const int pinoLEDR3 = 7;
const int pinoLEDG3 = 6;
const int pinoLEDB3 = 5;
const int pinoLEDR4 = A0;
const int pinoLEDG4 = A1;
const int pinoLEDB4 = A2;
const int pino_dht = A5;
const int pinoBuzzer = A4;

//variaveis
String dados;
String enviar;
String estado;
int n = 0;
bool stateA = false;

// Variável para armazenar o valor de temperatura e umidade
float temperatura; 
float umidade;

DHT dht(pino_dht, DHT11); // define o pino e o tipo de DHT

// Definir pinos de conexão:
#define pirPin 4
// Crie variáveis:
int val = 0;
bool motionState = false; // Começamos sem nenhum movimento detectado.
bool buzState = false;

void setup()
{
  // Inicia e configura a Serial
  Serial.begin(9600); // 9600bps
  
  HC05.begin(9600); // Taxa de transmissão do Módulo
  
  dht.begin(); // inicializa o sensor DHT
  
  //Configura os pinos
  pinMode(pinoLEDR1, OUTPUT);
  pinMode(pinoLEDG1, OUTPUT);
  pinMode(pinoLEDB1, OUTPUT);
  pinMode(pinoLEDR2, OUTPUT);
  pinMode(pinoLEDG2, OUTPUT);
  pinMode(pinoLEDB2, OUTPUT);
  pinMode(pinoLEDR3, OUTPUT);
  pinMode(pinoLEDG3, OUTPUT);
  pinMode(pinoLEDB3, OUTPUT);
  pinMode(pinoLEDR4, OUTPUT);
  pinMode(pinoLEDG4, OUTPUT);
  pinMode(pinoLEDB4, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pirPin, INPUT);
}

void loop()
{
  if(HC05.available()>0){
    dados = HC05.readString();
    Serial.println(dados);
    delay(15);

    // ************** ALARME ***************
    if(dados == "ALARMEON"){
      buzState = false;
      stateA = true;
    }
    if(dados == "ALARMEOFF"){
      stateA = false;
      buzState = false;
    }
    
    // *************** LED's ***************
    // LIGAR/DESLIGAR LED's
    if (dados == "LED1ON"){
        digitalWrite(pinoLEDR1, HIGH);
        digitalWrite(pinoLEDG1, HIGH);
        digitalWrite(pinoLEDB1, HIGH);
    }
    if (dados == "LED1OFF"){
        digitalWrite(pinoLEDR1, LOW);
        digitalWrite(pinoLEDG1, LOW);
        digitalWrite(pinoLEDB1, LOW);
    }
    if (dados == "LED2ON"){
        digitalWrite(pinoLEDR2, HIGH);
        digitalWrite(pinoLEDG2, HIGH);
        digitalWrite(pinoLEDB2, HIGH);
    }
    if (dados == "LED2OFF"){
        digitalWrite(pinoLEDR2, LOW);
        digitalWrite(pinoLEDG2, LOW);
        digitalWrite(pinoLEDB2, LOW);
    }
    if (dados == "LED3ON"){
        digitalWrite(pinoLEDR3, HIGH);
        digitalWrite(pinoLEDG3, HIGH);
        digitalWrite(pinoLEDB3, HIGH);
    }
    if (dados == "LED3OFF"){
        digitalWrite(pinoLEDR3, LOW);
        digitalWrite(pinoLEDG3, LOW);
        digitalWrite(pinoLEDB3, LOW);
    }
    if (dados == "LED4ON"){
        digitalWrite(pinoLEDR4, HIGH);
        digitalWrite(pinoLEDG4, HIGH);
        digitalWrite(pinoLEDB4, HIGH);
    }
    if (dados == "LED4OFF"){
        digitalWrite(pinoLEDR4, LOW);
        digitalWrite(pinoLEDG4, LOW);
        digitalWrite(pinoLEDB4, LOW);
    }

    // CORES LED's
    
      // ########### LED1 ###########
    if (dados == "LED1B"){
        digitalWrite(pinoLEDR1, LOW);
        digitalWrite(pinoLEDG1, LOW);
        digitalWrite(pinoLEDB1, HIGH);
    }
    if (dados == "LED1P"){
        digitalWrite(pinoLEDR1, HIGH);
        digitalWrite(pinoLEDG1, LOW);
        digitalWrite(pinoLEDB1, HIGH);
    }
    if (dados == "LED1W"){
        digitalWrite(pinoLEDR1, HIGH);
        digitalWrite(pinoLEDG1, HIGH);
        digitalWrite(pinoLEDB1, HIGH);
    }
    if (dados == "LED1R"){
        digitalWrite(pinoLEDR1, HIGH);
        digitalWrite(pinoLEDG1, LOW);
        digitalWrite(pinoLEDB1, LOW);
    }
    if (dados == "LED1G"){
        digitalWrite(pinoLEDR1, LOW);
        digitalWrite(pinoLEDG1, HIGH);
        digitalWrite(pinoLEDB1, LOW);
    }
    if (dados == "LED1Y"){
        digitalWrite(pinoLEDR1, HIGH);
        digitalWrite(pinoLEDG1, HIGH);
        digitalWrite(pinoLEDB1, LOW);
    }
    
      // ########### LED2 ###########
    if (dados == "LED2B"){
        digitalWrite(pinoLEDR2, LOW);
        digitalWrite(pinoLEDG2, LOW);
        digitalWrite(pinoLEDB2, HIGH);
    }
    if (dados == "LED2P"){
        digitalWrite(pinoLEDR2, HIGH);
        digitalWrite(pinoLEDG2, LOW);
        digitalWrite(pinoLEDB2, HIGH);
    }
    if (dados == "LED2W"){
        digitalWrite(pinoLEDR2, HIGH);
        digitalWrite(pinoLEDG2, HIGH);
        digitalWrite(pinoLEDB2, HIGH);
    }
    if (dados == "LED2R"){
        digitalWrite(pinoLEDR2, HIGH);
        digitalWrite(pinoLEDG2, LOW);
        digitalWrite(pinoLEDB2, LOW);
    }
    if (dados == "LED2G"){
        digitalWrite(pinoLEDR2, LOW);
        digitalWrite(pinoLEDG2, HIGH);
        digitalWrite(pinoLEDB2, LOW);
    }
    if (dados == "LED2Y"){
        digitalWrite(pinoLEDR2, HIGH);
        digitalWrite(pinoLEDG2, HIGH);
        digitalWrite(pinoLEDB2, LOW);
    }
    
      // ########### LED3 ###########
    if (dados == "LED3B"){
        digitalWrite(pinoLEDR3, LOW);
        digitalWrite(pinoLEDG3, LOW);
        digitalWrite(pinoLEDB3, HIGH);
    }
    if (dados == "LED3P"){
        digitalWrite(pinoLEDR3, HIGH);
        digitalWrite(pinoLEDG3, LOW);
        digitalWrite(pinoLEDB3, HIGH);
    }
    if (dados == "LED3W"){
        digitalWrite(pinoLEDR3, HIGH);
        digitalWrite(pinoLEDG3, HIGH);
        digitalWrite(pinoLEDB3, HIGH);
    }
    if (dados == "LED3R"){
        digitalWrite(pinoLEDR3, HIGH);
        digitalWrite(pinoLEDG3, LOW);
        digitalWrite(pinoLEDB3, LOW);
    }
    if (dados == "LED3G"){
        digitalWrite(pinoLEDR3, LOW);
        digitalWrite(pinoLEDG3, HIGH);
        digitalWrite(pinoLEDB3, LOW);
    }
    if (dados == "LED3Y"){
        digitalWrite(pinoLEDR3, HIGH);
        digitalWrite(pinoLEDG3, HIGH);
        digitalWrite(pinoLEDB3, LOW);
    }

      // ########### LED4 ###########
    if (dados == "LED4B"){
        digitalWrite(pinoLEDR4, LOW);
        digitalWrite(pinoLEDG4, LOW);
        digitalWrite(pinoLEDB4, HIGH);
    }
    if (dados == "LED4P"){
        digitalWrite(pinoLEDR4, HIGH);
        digitalWrite(pinoLEDG4, LOW);
        digitalWrite(pinoLEDB4, HIGH);
    }
    if (dados == "LED4W"){
        digitalWrite(pinoLEDR4, HIGH);
        digitalWrite(pinoLEDG4, HIGH);
        digitalWrite(pinoLEDB4, HIGH);
    }
    if (dados == "LED4R"){
        digitalWrite(pinoLEDR4, HIGH);
        digitalWrite(pinoLEDG4, LOW);
        digitalWrite(pinoLEDB4, LOW);
    }
    if (dados == "LED4G"){
        digitalWrite(pinoLEDR4, LOW);
        digitalWrite(pinoLEDG4, HIGH);
        digitalWrite(pinoLEDB4, LOW);
    }
    if (dados == "LED4Y"){
        digitalWrite(pinoLEDR4, HIGH);
        digitalWrite(pinoLEDG4, HIGH);
        digitalWrite(pinoLEDB4, LOW);
    }
  }
  // Aguarda alguns segundos entre uma leitura e outra
  delay(2000); // 2 segundos (Datasheet)

  if (buzState == false){
        sensor();
  }
  
  if (stateA == true){
     // Leia o pirPin e armazene como val:
     val = digitalRead(pirPin);
     // Se o movimento for detectado (pirPin = HIGH), faça o seguinte:
     if (val == HIGH) {
        buzState = true;
        // Altere o estado de movimento para verdadeiro (movimento detectado):
        if (motionState == false) {
          Serial.println("Movimento detectado!");
          motionState = true;
        }
     } else {  // Se nenhum movimento for detectado (pirPin = LOW), faça o seguinte:
        // Altere o estado de movimento para falso (sem movimento):
        if (motionState == true) {
          Serial.println("Movimento finalizado!");
          motionState = false;
        }
      }
     if (buzState == true){
        alarm(500, 1000);
        delay(150);
     }
   }
  
}
void alarm(long duration, int freq) {
  tone(pinoBuzzer, 1000);
  estado = "MOVIMENTO SUSPEITO";
  enviar = (String)temperatura + "," + (String)umidade + "," + estado;
  HC05.println(enviar);
  digitalWrite(pinoLEDR1, HIGH);
  digitalWrite(pinoLEDG1, LOW);
  digitalWrite(pinoLEDB1, LOW);
  digitalWrite(pinoLEDR2, HIGH);
  digitalWrite(pinoLEDG2, LOW);
  digitalWrite(pinoLEDB2, LOW);
  digitalWrite(pinoLEDR3, HIGH);
  digitalWrite(pinoLEDG3, LOW);
  digitalWrite(pinoLEDB3, LOW);
  digitalWrite(pinoLEDR4, HIGH);
  digitalWrite(pinoLEDG4, LOW);
  digitalWrite(pinoLEDB4, LOW);
  delay(500);
  noTone(pinoBuzzer);
  digitalWrite(pinoLEDR1, LOW);
  digitalWrite(pinoLEDG1, LOW);
  digitalWrite(pinoLEDB1, LOW);
  digitalWrite(pinoLEDR2, LOW);
  digitalWrite(pinoLEDG2, LOW);
  digitalWrite(pinoLEDB2, LOW);
  digitalWrite(pinoLEDR3, LOW);
  digitalWrite(pinoLEDG3, LOW);
  digitalWrite(pinoLEDB3, LOW);
  digitalWrite(pinoLEDR4, LOW);
  digitalWrite(pinoLEDG4, LOW);
  digitalWrite(pinoLEDB4, LOW);
}

void sensor(){
   // A leitura da temperatura ou umidade pode levar 250ms
  // O atraso do sensor pode chegar a 2 segundos
  temperatura = dht.readTemperature(); // lê a temperatura em Celsius
  umidade = dht.readHumidity(); // lê a umidade
  
  // Se ocorreu alguma falha durante a leitura
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha na leitura do Sensor DHT!");
  }
  else { // Se não
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" *C ");

    Serial.print("\t"); // tabulação
  
    // Imprime o valor de umidade
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.print(" %\t");
    
    Serial.println(); // nova linha
    if (temperatura > 40 || umidade < 40) {
      // Acende vermelho e aciona buzzer a 1000Hz
      alarm(500, 1000);
      delay(150);
      Serial.print("ALERTA RISCO A SAÚDE! E RISCO DE INCÊNDIO!");
      Serial.println();
      estado = "ALERTA RISCO A SAÚDE! E RISCO DE INCÊNDIO!";
      enviar = (String)temperatura + "," + (String)umidade + "," + estado;
      HC05.println(enviar);
    }
    else if (temperatura < 0) {
      // Acende azul
      digitalWrite(pinoLEDR1, LOW);
      digitalWrite(pinoLEDG1, LOW);
      digitalWrite(pinoLEDB1, HIGH);
      digitalWrite(pinoLEDR2, LOW);
      digitalWrite(pinoLEDG2, LOW);
      digitalWrite(pinoLEDB2, HIGH);
      digitalWrite(pinoLEDR3, LOW);
      digitalWrite(pinoLEDG3, LOW);
      digitalWrite(pinoLEDB3, HIGH);
      Serial.print("Temperatura ambiente muito baixa!");
      Serial.println();
      estado = "Temperatura ambiente muito baixa!";
      enviar = (String)temperatura + "," + (String)umidade + "," + estado;
      HC05.println(enviar);
    }
    else {
      Serial.print("Ambiente agradável!");
      Serial.println();
      estado = "Ambiente agradável!";
      enviar = (String)temperatura + "," + (String)umidade + "," + estado;
      HC05.println(enviar);
    }
  }
}
