double vReal[128];
int Swit =0;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
  
}

//왜 안끝나냐...
void loop() {
  // put your main code here, to run repeatedly:
  while(1){
    Swit = digitalRead(2);
    if(Swit == HIGH){
      for(int i=0;i<128; i++){
        vReal[i] = analogRead(A0);
        Serial.println(vReal[i]);
        delay(100);
      }
    }
    else{
      break;    
    }
  }
}
