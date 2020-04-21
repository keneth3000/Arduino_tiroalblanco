int ldr = 0;
int dato;

void setup() {
  Serial.begin(9600);

}

void loop() {
  dato = analogRead(ldr);

  Serial.println(dato);
}
