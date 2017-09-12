//pins
int ledVerde = 13;
int ledAmarillo = 12;
int ledRojo = 11;
int boton = 10;

int ledPeaton = 9;
boolean activado = false;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  
  pinMode(boton, INPUT);
  pinMode(ledPeaton, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(ledVerde, HIGH);
  
  for(int i = 0; i < 40; i++) {
    if(digitalRead(boton) == HIGH) {
      pasandoPeatones();
      activado = true;
      break;
    }
    delay(100);
  }

  if(activado == false) {
    pasandoPeatones();
  }

  activado == false;
}

void pasandoPeatones() {
  parpadear(ledVerde);
  encender(ledAmarillo);
  digitalWrite(ledRojo, HIGH);
  delay(100);
  Serial.println("PASANDO PEATONES");
  parpadear(ledPeaton);
  digitalWrite(ledRojo, LOW);
}

void encender(int led) {
  digitalWrite(led, HIGH);
  delay(2000);
  digitalWrite(led, LOW);
}

void parpadear(int led) {
  for(int i = 0; i < 5; i++) {
    digitalWrite(led, HIGH);
    delay(400);
    digitalWrite(led, LOW);
    delay(400);
  }   
}
