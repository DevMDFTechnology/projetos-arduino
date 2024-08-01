#include <IRremote.h>

#define EMISSOR 2
IRsend irsend;

void setup() {
  Serial.begin(9600);
  pinMode(EMISSOR, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char valorLido = Serial.read();

    switch (valorLido) {
      case 'a':
        digitalWrite(EMISSOR, HIGH);
        delay(100);
        digitalWrite(EMISSOR, LOW);
        // Envia o código NEC para ligar a TV (exemplo fictício)
        irsend.sendNEC(0xE0C84C4A, 32);
        delay(500);  // Intervalo entre envios
        Serial.println("Código para ligar enviado!");
        break;

      case 'b':
        digitalWrite(EMISSOR, HIGH);
        delay(100);
        digitalWrite(EMISSOR, LOW);
        // Envia o código Panasonic para desligar a TV (exemplo fictício)
        irsend.sendPanasonic(0x100BCBD, 48);  // Exemplo fictício de código de desligar
        delay(500);                           // Intervalo entre envios
        Serial.println("Código para desligar enviado!");
        break;
    }
  }
}
