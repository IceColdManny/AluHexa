int EstadoW = 0;
int EstadoX = 0;
int EstadoY = 0;
int EstadoZ = 0;

void setup() {
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);

  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  // Leer los estados de los botones y construir el número binario (de 0 a 15)
  EstadoW = digitalRead(10);
  EstadoX = digitalRead(11);
  EstadoY = digitalRead(12);
  EstadoZ = digitalRead(13);
  int number;

  // Convertir los botones a un número de 4 bits
  if 
  (EstadoW == 0 && EstadoX == 0 && EstadoY == 0 && EstadoZ == 0) //0 
    {number = 0;}
  else if 
  (EstadoW == 0 && EstadoX == 0 && EstadoY == 0 && EstadoZ == 1) //1
    {number = 1;}
  else if
  (EstadoW == 0 && EstadoX == 0 && EstadoY == 1 && EstadoZ == 0) //2
    {number = 2;}
  else if 
  (EstadoW ==  0 && EstadoX == 0 && EstadoY == 1 && EstadoZ == 1) //3
    {number = 3;}
  else if 
  (EstadoW == 0 && EstadoX == 1 && EstadoY == 0 && EstadoZ == 0) //4
    {number = 4;}
  else if 
  (EstadoW == 0 && EstadoX == 1 && EstadoY == 0 && EstadoZ == 1) //5
    {number = 5;}
  else if 
  (EstadoW == 0 && EstadoX == 1 && EstadoY == 1 && EstadoZ == 0) //6
    {number = 6;}
  else if 
  (EstadoW == 0 && EstadoX == 1 && EstadoY == 1 && EstadoZ == 1) //7
    {number = 7;}
  else if 
  (EstadoW == 1 && EstadoX == 0 && EstadoY == 0 && EstadoZ == 0) //8
    {number = 8;}
  else if 
  (EstadoW == 1 && EstadoX == 0 && EstadoY == 0 && EstadoZ == 1) //9
    {number = 9;}
  else if 
  (EstadoW == 1 && EstadoX == 0 && EstadoY == 1 && EstadoZ == 0) //A
    {number = 10;}
  else if 
  (EstadoW == 1 && EstadoX == 0 && EstadoY == 1 && EstadoZ == 1) //B
    {number = 11;}
  else if 
  (EstadoW == 1 && EstadoX == 1 && EstadoY == 0 && EstadoZ == 0) //C
    {number = 12;}
  else if 
  (EstadoW == 1 && EstadoX == 1 && EstadoY == 0 && EstadoZ == 1) //D
    {number = 13;}
  else if 
  (EstadoW == 1 && EstadoX == 1 && EstadoY == 1 && EstadoZ == 0) //E
    {number = 14;}
  else if (EstadoW == 1 && EstadoX == 1 && EstadoY == 1 && EstadoZ == 1) //F
    {number = 15;}

  clearDisplay1();

  // Mostrar el número en el display
  display7Segment1(number);

  // Imprimir el número en monitor serial
  Serial.print("Valor: ");
  Serial.println(number);

  delay(200);
}

void display7Segment1(int number) {
  int segments[] = {
    0b0111111, // 0
    0b0000110, // 1
    0b1011011, // 2
    0b1001111, // 3
    0b1100110, // 4
    0b1101101, // 5
    0b1111101, // 6
    0b0000111, // 7
    0b1111111, // 8
    0b1101111, // 9
    0b1110111, // A
    0b1111100, // B
    0b0111001, // C
    0b1011110, // D
    0b1111001, // E
    0b1110001, // F
  };
  
  if (number >= 0 && number <= 15) {
    int segmento = segments[number];
    for (int i = 2; i <= 8; i++) {
      digitalWrite(i, segmento & 1);
      segmento >>= 1;
    }
  }
}

void clearDisplay1() {
  for (int i = 2; i <= 8; i++) {
    digitalWrite(i, LOW);
  }     
}

