#include "arduinoFFT.h" // To include the installed library. Must include this.

arduinoFFT FFT = arduinoFFT(); // To use functions in the arduinoFFT library

double vReal[128]; // To store the obtained data and real parts of FFT results later
double vImag[128]; // To store imaginary parts of FFT results
int flag = 0;
int i =0;

void setup() {
  pinMode(A0,INPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
}

void loop() {
   /* have to include something to implement what is described below */
   // The code to store the obtained data in the array, vReal, which was probably done in problem #1.
   // While the data is stored in the array as changing the index, the array of vImag is also initialized to have zero values for each element.
  while(1) {
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
   // Using FFT, compute the Fourier Transform of the obtaine data (vReal).
   // The result of FFT will be saved in vReal (real parts) and vImag (imaginary parts).
   // SAMPLES means the size of the array. So, input 128.
   // After computation, vReal does not have the obatined data any more.
  FFT.ComplexToMagnitude(vReal, vImag, 128);
   // Using vReal and vImag, to calculate the magnitude for each index
   // It performs vReal = √(vReal)2+(vImag)2 for each index, and store the results into vReal // After computation, vReal does not have the real parts of the Fourier Transform.
  double peak = FFT.MajorPeak(vReal, 128, 10);
   // FFT.MajorPeak function finds the maximum value in the array (vReal) and returns its corresponding frequency 
   // At this moment, the magnitudes calculated by FFT.ComplexToMagnitude are stored in the array (vRael).
   // SAMPLES is the size of the array (128), and SAMPLING_FREQUENCY is sampling frequency (10). 
   /* have to include something to implement what is described below */
   // A code to estimate the heart rate based on the frequency obtained with FFT.
   // A code to send the heart rate via serial communication.
   Serial.println("심박수 출력");
   double heart_rate = peak*60;
   Serial.println(heart_rate);
   delay(1000);
}
