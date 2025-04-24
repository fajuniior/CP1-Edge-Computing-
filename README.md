# Projeto: Controle de Luminosidade com Arduino e LDR

# 🔗 Link para o tinkercad: https://www.tinkercad.com/things/lHQuTCim7kq-cp1-edge-computing?sharecode=vifiMo60PJ3a7jOzbjVW6DRar7TVdgpZxer1KirltKo

## 📌 Descrição

Este projeto utiliza um Arduino para monitorar a luminosidade de um ambiente através de um sensor LDR (fotoresistor). Dependendo da leitura do sensor, diferentes LEDs são acionados para indicar o estado do ambiente:

- **LED Verde**: Luminosidade baixa, ambiente em condições ideais.
- **LED Amarelo**: Luminosidade média, nível de alerta.
- **LED Vermelho**: Luminosidade alta, condições inadequadas.

Além disso, caso a luminosidade esteja muito alta (nível vermelho), um buzzer é acionado por 3 segundos, alertando sobre as condições impróprias.

## 🛠️ Componentes Necessários

- 1 Arduino Uno
- 1 Sensor LDR (fotoresistor)
- 1 Buzzer ativo
- 3 LEDs (verde, amarelo e vermelho)
- 3 resistores de 220Ω (para os LEDs)
- 1 resistor de 10kΩ (para o LDR)
- Protoboard e fios jumper

## 🔧 Conexões

| Componente      | Pino Arduino |
|-----------------|--------------|
| Buzzer          | 8            |
| LED Vermelho    | 9            |
| LED Amarelo     | 10           |
| LED Verde       | 11           |
| LDR (Fotoresistor)| A0         |

- O buzzer deve ser conectado diretamente ao pino digital 8.
- Cada LED precisa de um resistor de 220Ω para proteção.
- O sensor LDR deve formar um divisor de tensão com um resistor de 10kΩ conectado ao pino analógico A0.

## 📋 Como Reproduzir o Projeto

1. Monte o circuito conforme especificado no item Conexões acima.
2. Copie o código fornecido para a IDE do Arduino.
3. Conecte seu Arduino ao computador e faça upload do código.
4. Monitore o comportamento dos LEDs e buzzer conforme altera as condições de luminosidade do ambiente.

## 📌 Observações Importantes

- A faixa definida no código é:
  - **LED Verde:** leitura abaixo de 100
  - **LED Amarelo:** leitura entre 100 e 150
  - **LED Vermelho:** leitura acima de 150 (buzzer ativa por 3 segundos)

Esses valores podem precisar de ajustes dependendo do ambiente físico onde o sistema será instalado.

## 🚀 Autor

- Fabio Pereira Rogerio Junior RM: 564005
- Sebastian Iriarte Gonzales RM: 563619
- Matheus Tonsa Martini RM: 564454
- Kauã Veloso Lima RM: 561954
