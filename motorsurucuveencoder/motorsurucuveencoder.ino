#define MOTO1 11
#define MOTO2 10
#define KONTROL 9
#define ASIGNAL 4
#define BSIGNAL 5

int State;
int lastState;
int encoder_value = 0;
int encoder_negatif=0;
void setup() {
  Serial.begin(9600);
  lastState = digitalRead(ASIGNAL);

  pinMode(MOTO1, OUTPUT);
  pinMode(MOTO2, OUTPUT);
  pinMode(KONTROL, OUTPUT);

  pinMode(ASIGNAL, INPUT);
  pinMode(BSIGNAL, INPUT);
}

void loop() {
  State = digitalRead(ASIGNAL);
  
  if (lastState != State) {
    if (digitalRead(BSIGNAL) != lastState) {//encoder değerini arttır
      encoder_value++;
      if (encoder_value>255){
        encoder_value = 255; 
      }
    }
    else { //encoder değerini azalt
      encoder_value--;
      if (encoder_value<-255){
        encoder_value=-255;
      }
    }
    motor(encoder_value);
    Serial.println(encoder_value);
  }
  lastState = State;
}

void motor(int hiz){
  if(hiz<0){
    digitalWrite(MOTO1,1);
    digitalWrite(MOTO2,0);
  }
  else{
    digitalWrite(MOTO1,0);
    digitalWrite(MOTO2,1);   
  }
  analogWrite(KONTROL,abs(hiz));
}
