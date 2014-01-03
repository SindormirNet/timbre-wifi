#include <Process.h>

#define MICRO_GND 2
#define MICRO_SIG 3
#define MICRO_VCC 4

void setup(){
  //Configuracion de pines para el microfono
  pinMode(MICRO_GND, OUTPUT);
  pinMode(MICRO_SIG, INPUT);
  pinMode(MICRO_VCC, OUTPUT);

  //Tierra y VCC para los pines de alimentacion
  digitalWrite(MICRO_GND, LOW);
  digitalWrite(MICRO_VCC, HIGH);

  Bridge.begin();
}

void genera_alarma(){
  Process alarma; 
  alarma.begin("curl");
  alarma.addParameter("http://192.168.1.199:10000");
  alarma.run();
  alarma.close();
}

void loop(){
  if (!digitalRead(MICRO_SIG)) genera_alarma();
}



