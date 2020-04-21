//===========================================================
//Variable
//Array de los pines del display
int numeropines[7] = {2, 3, 4, 5, 6, 7, 8};
//bytes para encender leds del display (de derecha a izquierda)
byte controlNumero[4] = {
  0b0111111,  //0
  0b0000110,  //1
  0b1011011,  //2
  0b1001111  //3
};
float x, y;
int d;
int buzzer = 12;
int push = 9; //boton
int contador;
int dataBoton;
int laser = 13;
int LDR1 = A0;
int LDR2 = A1;
int dato1;
int dato2;
int pulsos;
int FACIL = 10;
int MEDIUM = 11;
int DIFICIL = A2;

//===========================================================
//funcion de display
void display(int number) {
  byte numeroBit = controlNumero[number];

  for (int i = 0; i < 7; i++) {
    int bit = bitRead(numeroBit, i);
    digitalWrite(numeropines[i], bit);
    delay(5);
  }

}
//===========================================================
//Funcion de menu

void mostrarMenu() {
  Serial.println("BIENVENIDO!");
  Serial.println("AL JUEGO TIRO AL BLANCO");
  Serial.println("Facil: un tiempo entre 2 a 3 minutos");
  Serial.println("Medio: un tiempo entre 45 segundos a 1 minuto.");
  Serial.println("Dificil: un tiempo entre 20 y 30 segundos." );
}
//===========================================================
//Funcion de disparo

void disparo() {
  dato1 = analogRead(LDR1);
  dato2 = analogRead(LDR2);

  if (dato1 < 400 || dato2 < 400) {
    contador++;
    if (contador == 1) {
      display(1);
      delay(500);
    }
    if (contador == 2) {
      display(2);
      delay(500);
    }
    if (contador == 3) {
      display(3);
      delay(500);
    }
  }
}

void tiroLaser() {
  dataBoton = digitalRead(push);
  if (dataBoton == 1) {
    pulsos++;
    Serial.println(pulsos);
    digitalWrite(laser, HIGH);
    delay(20);
    digitalWrite(laser, LOW);
  }
}

//===========================================================
void setup() {
  Serial.begin(9600);
  pinMode(push, INPUT);
  pinMode(FACIL, INPUT);
  pinMode(MEDIUM, INPUT);
  pinMode(DIFICIL, OUTPUT);
  pinMode(laser, OUTPUT);
  pinMode(buzzer, OUTPUT);

  //===========================================================
  //pines del display
  for (int i = 0; i < 7; i++) {
    pinMode(numeropines[i], OUTPUT);
  }
  //===========================================================
  display(0);
  mostrarMenu();
}

void loop() {
  //===========================================================
regreso:    //etiqueta para cuando termine el modo de juego, funciona con el goto
  d = 0;

  if (digitalRead(FACIL) == 1) { //mode de juego facil
    millis(); //tiempo de juego
    x = millis();
    while (d == 0) {
      y = millis() - x;
      Serial.println("Empezo");
      //===========================================================
      disparo();
      //==========================================================
      //Tiro del laser
      tiroLaser();
      //==========================================================
      if (y > 5200) {
        Serial.println("Fin del juego");
        tone(12, 261.63, 250);
        goto regreso; //manda donde esta la etiqueta
      } //if y>52000
    }//while
  }// if del nivel

  //-------------------------------------------------------------
  d = 0;
  if (digitalRead(MEDIUM) == 1) { //mode de juego medio
    millis(); //tiempo de juego
    x = millis();
    while (d == 0) {
      y = millis() - x;
      Serial.println("Empezo");
      //===========================================================
      disparo();
      //==========================================================
      //Tiro del laser
      tiroLaser();
      //==========================================================
      if (y > 2600) {
        Serial.println("Fin del juego");
        tone(12, 261.63, 250);
        goto regreso; //manda donde esta la etiqueta
      } //if y>2600
    }//while
  }// if del nivel
  //-------------------------------------------------------------
  d = 0;
  if (digitalRead(DIFICIL) == 1) { //mode de juego dificil
    millis(); //tiempo de juego
    x = millis();
    while (d == 0) {
      y = millis() - x;
      Serial.println("Empezo");
      //===========================================================
      disparo();
      //==========================================================
      //Tiro del laser
      tiroLaser();
      //==========================================================
      if (y > 1500) {
        Serial.println("Fin del juego");
        tone(12, 261.63, 250);
        goto regreso; //manda donde esta la etiqueta
      } //if y>1300
    }//while
  }// if del nivel

}//loop
