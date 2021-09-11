int flag = 0;
double vReal[128];
int i =0;

void setup() {
  pinMode(A0,INPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(2)==HIGH){
    if(flag==1){
      flag =0;
    }
    else{
      flag = 1;
    }
    delay(1000);
  }
  if(flag ==1){
    if(i<128){
      vReal[i] = analogRead(A0);
      Serial.println(vReal[i]);
      i++;
      delay(100);
    }
    else{
      return 0;
    }
  }
}
