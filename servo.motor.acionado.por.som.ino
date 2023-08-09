#include <Servo.h>

Servo servoMotor;
const int soundSensorPin = A0;
int soundThreshold = 400;  // Ajuste esse valor de acordo com seu sensor e ambiente
int claps = 0;

void setup() {
  servoMotor.attach(9);
  Serial.begin(9600);
}

void loop() {
  int soundValue = analogRead(soundSensorPin);

  if (soundValue > soundThreshold) {
    delay(50);  // Pequeno atraso para evitar detecção falsa
    int newSoundValue = analogRead(soundSensorPin);
    
    if (newSoundValue > soundThreshold) {
      claps++;
      delay(500);  // Atraso para evitar múltiplas detecções rápidas
    }
  }

  if (claps == 1) {
    // Gire o servo para a esquerda
    servoMotor.write(0);  // Angulo para a esquerda (ajuste conforme necessário)
    delay(3000);         // Mantenha a posição por 3 segundo
    servoMotor.write(90); // Volte à posição neutra
    claps = 0;
  } else if (claps == 2) {
    // Gire o servo para a direita
    servoMotor.write(180);  // Angulo para a direita (ajuste conforme necessário)
    delay(3000);           // Mantenha a posição por 3 segundo
    servoMotor.write(90);   // Volte à posição neutra
    claps = 0;
  }
}
