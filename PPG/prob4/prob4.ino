#include "arduinoFFT.h" 

arduinoFFT FFT = arduinoFFT(); 

double vReal[128]; 
double vImag[128]; 
int flag = 0;
char receivedChar = 's';
int i = 0;

void setup() {
  pinMode(A0,INPUT);
  pinMode(3,OUTPUT);//led output
  pinMode(5,OUTPUT);//led output
  pinMode(6,OUTPUT);//led output
  Serial.begin(9600);
}
void loop() {   
  while(1) {
    if(Serial.available()>0){
      receivedChar = Serial.read();
      if(receivedChar=='g'){
        flag =1;
      }
      else if(receivedChar=='s'){
        flag = 0;
      }
    }
    if(flag ==1){
      if(i<128){
        vReal[i] = analogRead(A0);
        Serial.println(vReal[i]);
        vImag[i] =0;
        i++;
        delay(100);
      }
      else{
        flag=0;
        break;
      }
    }
  }
  FFT.Compute(vReal, vImag, 128, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, 128);
  double peak = FFT.MajorPeak(vReal, 128, 10);
  Serial.println("심박수 출력");
  double heart_rate = peak*60;
  Serial.println(heart_rate);
  //int heart_rate = 150;
  if (10 <= heart_rate && heart_rate<80){
    digitalWrite(6,HIGH); //BLUE
  }
  else if(80<= heart_rate && heart_rate<130){
    digitalWrite(5,HIGH); //ORANGE
  }
  else if(130<= heart_rate && heart_rate<200){
    digitalWrite(3,HIGH); //RED
  }
  return 0;
}
