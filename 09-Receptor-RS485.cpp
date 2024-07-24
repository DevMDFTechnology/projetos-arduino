#include <SoftwareSerial.h>

unsigned long tempoAnterior = 0;
#define Pino_RS485_RX 10 // DO (Direct Output)
#define Pino_RS485_TX 11 // DI (Direct Input)
#define SSerialTxControl 3
#define RS485Transmit HIGH
#define RS485Receive LOW

SoftwareSerial RS485Serial(Pino_RS485_RX, Pino_RS485_TX);

String inputString = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Módulo Receptor");
  Serial.println("Aguardando dados...");
  pinMode(SSerialTxControl, OUTPUT);
  digitalWrite(SSerialTxControl, RS485Receive);
  RS485Serial.begin(4800);
}

void loop() {
  if (RS485Serial.available()) {
    while (RS485Serial.available()) {
      char inChar = (char)RS485Serial.read();
      inputString += inChar;
      if (inChar == '\n') {
        processInput(inputString);
        inputString = "";
      }
    }
  }
}

void processInput(String input) {
  // Remove espaços em branco extras
  input.trim();
  
  // Verifica se a entrada não está vazia e termina com ','
  if (input.length() > 0 && input.endsWith(",")) {
    // Remove a vírgula final
    input = input.substring(0, input.length() - 1);
    
    // Verifica se a entrada começa com '/' e termina com ','
    if (input.startsWith("/") && input.endsWith(",")) {
      // Remove '/' do início
      input = input.substring(1);
      
      // Divide a entrada em tokens separados por ','
      int startPos = 0;
      int commaPos = input.indexOf(',', startPos);
      while (commaPos != -1) {
        String codigo = input.substring(startPos, commaPos);
        bufferPrint(codigo, tempoAnterior);
        startPos = commaPos + 1;
        commaPos = input.indexOf(',', startPos);
      }
      
      // Processa o último código depois da última vírgula
      if (startPos < input.length()) {
        String codigo = input.substring(startPos);
        bufferPrint(codigo, tempoAnterior);
      }
    } 
    Serial.println("Buffer: " + input);
  } 
}

void bufferPrint(String codigo, unsigned long leituraAnterior){
  // Verifica se passaram 500 ms desde a última impressão
  if (millis() - tempoAnterior >= leituraAnterior && codigo.length() > 0) {
    // Verifica se a string tem o formato esperado
    if (codigo.endsWith("X")) {
      // Extrai o código entre '/' e 'X' e adiciona 'R '
      String codigoLimpo = codigo.substring(0, codigo.length() - 1) + "R ";
      // Imprime o código limpo
      Serial.print(codigoLimpo);
    } else {
      Serial.println("Código inválido: " + codigo);
    }
    
    tempoAnterior = millis(); // Atualiza o tempo anterior para o atual
  }
}
