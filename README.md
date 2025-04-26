# Projeto: Controle de Luminosidade com Arduino e LDR

## 🔗 Link para o Tinkercad
https://www.tinkercad.com/things/jhaIl5Rz3s7-shiny-luulia?sharecode=Xredn416oP8xJeytFs4EbDNO2roJ2R-1oLOY5byUzoE

---

## 📌 Descrição

Este projeto utiliza um Arduino Uno para monitorar a luminosidade de um ambiente através de um sensor LDR. Conforme o nível de luz, o sistema sinaliza:

- **LED Verde**: Ambiente escuro (baixo nível de luz).
- **LED Amarelo**: Luminosidade média.
- **LED Vermelho**: Ambiente muito claro (alto nível de luz), com buzzer acionado por 3 segundos.

O valor de luminosidade também é exibido em um display LCD 16×2, que apresenta na inicialização o nome do grupo **TALK TIE** e, em seguida, a porcentagem de luz.

---

## 🛠️ Componentes Necessários

- **1×** Arduino Uno
- **1×** Sensor LDR (fotoresistor)
- **1×** Buzzer ativo
- **3×** LEDs (verde, amarelo, vermelho)
- **3×** Resistores de 220 Ω (para os LEDs)
- **1×** Resistor de 10 kΩ (para divisor de tensão do LDR)
- **1×** Potenciômetro de 10 kΩ (ajuste de contraste do LCD)
- **1×** Display LCD 16×2 (modo 4 bits)
- Protoboard e fios jumper

---

## 🔧 Conexões

### Sensor LDR (Divisor de Tensão)
- **LDR** → 5 V
- **LDR** → A0 (pino analógico)
- **Resistor 10 kΩ** → A0 → GND

### LEDs e Buzzer
| Componente    | Pino Arduino | Resistor  |
|---------------|--------------|-----------|
| LED Vermelho  | D8           | 220 Ω → GND |
| LED Amarelo   | D9           | 220 Ω → GND |
| LED Verde     | D10          | 220 Ω → GND |
| Buzzer        | D11          | (direto)  |

### Display LCD 16×2 (4-bit)
| LCD Pino | Função            | Arduino Uno |
|----------|-------------------|-------------|
| 1 (GND)  | Terra             | GND         |
| 2 (VCC)  | 5 V               | 5 V         |
| 3 (VO)   | Contraste         | Pot (10 kΩ) |
| 4 (RS)   | Register Select   | D13         |
| 5 (RW)   | Read/Write        | GND         |
| 6 (E)    | Enable            | D12         |
| 11 (D4)  | Data Bit 4        | D5          |
| 12 (D5)  | Data Bit 5        | D4          |
| 13 (D6)  | Data Bit 6        | D3          |
| 14 (D7)  | Data Bit 7        | D2          |
| 15 (LED+) | Backlight (+)    | 5 V → 220 Ω |
| 16 (LED-) | Backlight (−)    | GND         |

---

## 📋 Como Reproduzir

1. Monte o circuito conforme as conexões acima.
2. Ajuste o potenciômetro até que o contraste do LCD permita leitura clara.
3. Copie o código-fonte para a IDE Arduino ou para o editor do Tinkercad.
4. Faça o upload no Arduino Uno virtual ou real.
5. Observe no LCD a tela inicial “TALK TIE” e, depois, a porcentagem de luminosidade. Confira os LEDs e buzzer conforme a intensidade de luz.

---

## 📌 Parâmetros no Código

- **Faixas de luminosidade (mapeadas em %):**
  - **< 150:** LED Verde (escuro)
  - **150 – 300:** LED Amarelo (médio)
  - **> 300:** LED Vermelho + Buzzer por 3 s (claro)

- **delay** no loop: 500 ms

Esses valores podem ser ajustados conforme o ambiente.

---

## 🚀 Autores

- Fabio Pereira Rogerio Junior – RM 564005
- Sebastian Iriarte Gonzales – RM 563619
- Matheus Tonsa Martini – RM 564454
- Kauã Veloso Lima – RM 561954

