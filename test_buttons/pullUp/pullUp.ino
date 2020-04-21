/*
  Sandoval López, Keneth Stiv 2019382
  López Xitumul, Dany Alexander
  Practica 3
*/

  /***********************/
  /*Ejercicio 2 Boton pullUp
  /***********************/

//pines botones
#define pullUp 8

//variables
byte data;
int estado = 0;

void setup() {
  pinMode(pullUp, INPUT);
  Serial.begin(9600);
}

void loop() {
  data = digitalRead(pullUp);

  if (data == 0) {
    delay(20);
    estado++;
    Serial.println(estado);
    delay(500);
  }
}
