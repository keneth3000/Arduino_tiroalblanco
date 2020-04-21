int numeropines[7] = {2, 3, 4, 5, 6, 7, 8};

byte controlNumero[10] = {
  0b0111111,  //0
  0b0000110,  //1
  0b1011011,  //2
  0b1001111,  //3
  0b1100110,  //4
  0b1101101,  //5
  0b1111101,  //6
  0b0000111,  //7
  0b1111111,  //8
  0b1101111   //9

};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
    pinMode(numeropines[i], OUTPUT);
  }

  encenderSegmentos(0);
}

void loop() {
  mostrarMenu();
  for (int i = 0; i < 10; i++) {
    encenderSegmentos(i);
    delay(1000);
  }

}

void encenderSegmentos(int number) {
  byte numeroBit = controlNumero[number];

  for (int i = 0; i < 7; i++) {
    int bit = bitRead(numeroBit, i);
    digitalWrite(numeropines[i], bit);
  }
}

void mostrarMenu(){
  Serial.println("Nivel fácil: 2 a 3 minutos.");
  Serial.println("Nivel medio: 45 segundos a 1 minuto.");
  Serial.println("Nivel difícil: 20 a 30 segundos.");

}
