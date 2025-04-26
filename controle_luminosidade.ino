// PROGRAMA CONTROLE LUMINOSIDADE COM LDR

#include <LiquidCrystal.h>
#define C4 262 // nota Dó

// pinos do LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

const int pinLDR    = A0;
const int LED_verde = 10;  // sem luz
const int LED_amarelo = 9; // luz média
const int LED_vermelho = 8; // muita luz
const int buzzer     = 11;

void setup() {
  // configurações de pino
  pinMode(pinLDR, INPUT);
  pinMode(LED_verde, OUTPUT);
  pinMode(LED_amarelo, OUTPUT);
  pinMode(LED_vermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // inicializa LCD
  lcd.begin(16, 2);
  // splash de boas-vindas
  lcd.setCursor(4, 0);
  lcd.print("TALK TIE");
  lcd.setCursor(2, 1);
  lcd.print("Lum Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {
  int valor = analogRead(pinLDR);
  int pct   = map(valor, 0, 1023, 0, 100);

  // mostra a % no LCD
  lcd.setCursor(0, 0);
  lcd.print("Lum: ");
  lcd.print(pct);
  lcd.print("%   "); // espaços apagam resíduos

  // decide LEDs e buzzer
  if (valor < 50) {
    // ESCURO → verde
    digitalWrite(LED_verde, HIGH);
    digitalWrite(LED_amarelo, LOW);
    digitalWrite(LED_vermelho, LOW);
    noTone(buzzer);
  }
  else if (valor < 600) {
    // MÉDIO → amarelo
    digitalWrite(LED_verde, LOW);
    digitalWrite(LED_amarelo, HIGH);
    digitalWrite(LED_vermelho, LOW);
    noTone(buzzer);
  }
  else {
    // CLARO → vermelho + buzzer 3s
    digitalWrite(LED_verde, LOW);
    digitalWrite(LED_amarelo, LOW);
    digitalWrite(LED_vermelho, HIGH);

    tone(buzzer, C4);     // toca a nota
    delay(3000);          // por 3 segundos
    noTone(buzzer);
  }

  delay(500); // pausa curta antes de atualizar
}
