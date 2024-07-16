const int sensorPin = A0;
const int motorPin = 3;
const int greenLedPin = 4;
const int redLedPin = 5;
const int buzzerPin = 6;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Inicia comunicação serial para debug (opcional)
}

void loop() {
  // Faz a leitura da temperatura
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0 / 1023.0); // Converte a leitura para tensão
  float temperatureC = (voltage - 0.5) * 100.0; // Converte a tensão para temperatura em Celsius
  
  // Condições para acionamento baseado na temperatura
  if (temperatureC >= 30.0) {
    digitalWrite(motorPin, HIGH); // Liga o motor do ventilador
    digitalWrite(greenLedPin, HIGH); // Liga o LED verde (normal)
    digitalWrite(redLedPin, LOW); // Desliga o LED vermelho (emergência)
    noTone(buzzerPin); // Desliga a buzina
  } 
  
  if (temperatureC > 50.0) {
    digitalWrite(redLedPin, HIGH); // Liga o LED vermelho (emergência)
    tone(buzzerPin, 1000); // Liga a buzina com frequência de 1000 Hz
  }

  // Exibe a temperatura no monitor serial (opcional)
  Serial.print("Temperatura: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(1000); // Aguarda 1 segundo antes da próxima leitura
}