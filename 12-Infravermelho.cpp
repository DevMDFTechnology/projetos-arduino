/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#define emissorIR 3

IRsend irsend;

void setup() {
  Serial.begin(9600);
  pinMode(emissorIR, OUTPUT);  // Configura o pino como saída
}

void loop() {
  if (Serial.available() > 0) {  // Verifica se há dados disponíveis na serial
    char command = Serial.read();  // Lê o comando

    switch (command) {
      case 'a':
        digitalWrite(emissorIR, HIGH);  // Liga o pino do emissor IR
        delay(500);
        digitalWrite(emissorIR, LOW);   // Desliga o pino do emissor IR
        irsend.sendPanasonic(0x100BCBD, 48);  // Envia o código IR
        Serial.println("Codigo Enviado");
        delay(40);
        break;
    }

    delay(5000);  // 5 segundos de atraso entre cada sinal
  }
}
