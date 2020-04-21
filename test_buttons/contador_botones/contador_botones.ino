/*
  Sandoval López, Keneth Stiv 2019382
  López Xitumul, Dany Alexander
  Practica 3
*/

  /***********************/
  /*Ejercicio 3 Boton Contador
  /***********************/

//pines botones
#define pullDown 7
#define pullUp 8

//variables
byte data;
byte data1;
int estado = 0;

void setup() {
  pinMode(pullDown, INPUT);
  pinMode(pullUp, INPUT);
  Serial.begin(9600);
}

void loop() {
  data = digitalRead(pullDown);
  data1 = digitalRead(pullUp);

  if (data == 1) {
    delay(20);
    estado++;
    Serial.println(estado);
    delay(500);
  } else if (data1 == 0) {
    delay(20);
    estado--;
    Serial.println(estado);
    delay(500);
  }
}
