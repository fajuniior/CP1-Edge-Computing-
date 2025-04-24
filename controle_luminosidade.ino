
// PROGRAMA CONTROLE LUMINOSIDADE COM LDR
int buzzer = 8;         // Atribui a porta 8 à variável buzzer
int ledVermelho = 9;    // Atribui a porta 9 à variável ledVermelho
int ledAmarelo = 10;    // Atribui a porta 10 à variável ledAmarelo
int ledVerde = 11;      // Atribui a porta 11 à variável ledVerde
int ldr = A0;           // Atribui A0 à variável ldr
int valorLdr = 0;       // Leitura inicial do LDR
 
void setup() {
  Serial.begin(9600);                 // Inicialização da comunicação serial
  pinMode(ldr, INPUT);                // Define ldr (pino analógico A0) como entrada
  pinMode(buzzer, OUTPUT);            // Define buzzer (pino digital 8) como saída
  pinMode(ledVermelho, OUTPUT);       // Define ledVermelho (pino digital 9) como saída
  pinMode(ledAmarelo, OUTPUT);        // Define ledAmarelo (pino digital 10) como saída
  pinMode(ledVerde, OUTPUT);          // Define ledVerde (pino digital 11) como saída
}
 
void loop() {
  valorLdr = analogRead(ldr);         // Lê o valor do sensor LDR e armazena
 
  if (valorLdr < 150) {               // Luminosidade baixa (OK < 150 lux)
    apagarLeds();                     // Executa a função apagarLeds
    digitalWrite(ledVerde, HIGH);     // Acende o LED verde
  }
  else if (valorLdr > 150 && valorLdr < 250) {  // Luminosidade média (alerta 150 a 250 lux)
    apagarLeds();                               // Executa a função apagarLeds
    digitalWrite(ledAmarelo, HIGH);             // Acende o LED amarelo
  }
  else {                              // Luminosidade alta (problema acima de 250 lux)
    apagarLeds();                     // Executa a função apagarLeds
    digitalWrite(ledVermelho, HIGH);  // Acende o LED vermelho
    tone(buzzer, 1000);               // Toca o buzzer na frequência de 1000 Hz
    delay(3000);                      // Define o tempo de duração do som do buzzer (3 segundos)
    noTone(buzzer);                   // Desliga o som do buzzer
    delay(2000);                      // Define o silêncio entre um toque e outro
  }
 
  Serial.print("Valor do LDR: ");     // Imprime uma mensagem
  Serial.println(valorLdr);           // Imprime a variável valorLdr
}
 
void apagarLeds() {                   // Função para apagar todos os LEDs
  digitalWrite(ledVermelho, LOW);     // Desliga o LED vermelho
  digitalWrite(ledAmarelo, LOW);      // Desliga o LED amarelo
  digitalWrite(ledVerde, LOW);        // Desliga o LED verde
}
