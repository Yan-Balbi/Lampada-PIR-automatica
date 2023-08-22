#define PIR 2 
#define rele 16

int existe_movimento = 1;
int estado_do_rele = LOW;
unsigned long hora_que_acendeu_lampada = 0;
const long periodo_aceso = 5000; 

void setup(){
  pinMode(rele, OUTPUT);
  pinMode(PIR, INPUT);
}

void loop() {
  existe_movimento = digitalRead(PIR);

  if( existe_movimento == 1 ){
    digitalWrite(rele, LOW);
    estado_do_rele = HIGH;
    hora_que_acendeu_lampada = millis();
  }

  if( estado_do_rele == HIGH &&    (millis() - hora_que_acendeu_lampada >= periodo_aceso) ){
    digitalWrite(rele, HIGH);
    estado_do_rele = LOW;
  }   
}
