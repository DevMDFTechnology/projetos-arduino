#include <IRremote.h>

#define PanasonicAddress      0x4004     // Endereço Panasonic (dados anteriores) 
#define PanasonicPower        0x100BCBD  // Botão de energia Panasonic
#define PanasonicVolumeUp     0x1000405  // Código para aumentar o volume
#define PanasonicVolumeDown   0x1008485  // Código para diminuir o volume
#define PanasonicChannelUp    0x1002C2D
#define PanasonicChannelDown  0x100ACAD
#define PanasonicMute         0x1004C4D
#define PanasonicNum0         0x1009899
#define PanasonicNum1         0x1000809
#define PanasonicNum2         0x1008889
#define PanasonicNum3         0x1004849
#define PanasonicNum4         0x100C8C9
#define PanasonicNum5         0x1002829
#define PanasonicNum6         0x100A8A9
#define PanasonicNum7         0x1006869
#define PanasonicNum8         0x100E8E9
#define PanasonicNum9         0x1001819

IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char tecla = Serial.read();
    switch (tecla) {
      case 'P':
        irsend.sendPanasonic(PanasonicAddress, PanasonicPower);
        break;
      case '0':
        irsend.sendPanasonic(PanasonicAddress, PanasonicNum0);
        break;
      case '1':
        irsend.sendPanasonic(PanasonicAddress, PanasonicNum1);
        break;
      case '2':
        irsend.sendPanasonic(PanasonicAddress, PanasonicNum2);
        break;
      case '3':
        irsend.sendPanasonic(PanasonicAddress, PanasonicNum3);
        break;
      case '4':
        irsend.sendPanasonic(PanasonicAddress, PanasonicNum4);
        break;
      case '5':
        irsend.sendPanasonic(PanasonicAddress, PanasonicNum5);
        break;
      case '6':
        irsend.sendPanasonic(PanasonicAddress, PanasonicNum6);
        break;
      case '7':
        irsend.sendPanasonic(PanasonicAddress, PanasonicNum7);
        break;
      case '8':
        irsend.sendPanasonic(PanasonicAddress, PanasonicNum8);
        break;
      case '9':
        irsend.sendPanasonic(PanasonicAddress, PanasonicNum9);
        break;
      case '+':
        irsend.sendPanasonic(PanasonicAddress, PanasonicVolumeUp);
        break;
      case '-':
        irsend.sendPanasonic(PanasonicAddress, PanasonicVolumeDown);
        break;
      case 'W':
        irsend.sendPanasonic(PanasonicAddress, PanasonicChannelUp);
        break;
      case 'S':
        irsend.sendPanasonic(PanasonicAddress, PanasonicChannelDown);
        break;
      case 'M':
        irsend.sendPanasonic(PanasonicAddress, PanasonicMute);
        break;
      default:
        // Nenhuma ação para outros caracteres
        break;
    }
    delay(1000); // Adiciona um delay para evitar múltiplos envios acidentais
  }
}
