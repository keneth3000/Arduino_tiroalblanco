/*
  Sandoval López, Keneth Stiv 2019382
  López Xitumul, Dany Alexander
  Practica 3
*/

/***********************/
/*Ejercicio 1 Boton pullDown
  /***********************/

//pines botones
#define pullDown 7

//variables
byte data;
int estado = 0;

void setup() {
  pinMode(pullDown, INPUT);
  Serial.begin(9600);
}

void loop() {
  data = digitalRead(pullDown);

  if (data == 1) {
    delay(20);
    estado++;
    Serial.println(estado);
    delay(500);
  }
}
