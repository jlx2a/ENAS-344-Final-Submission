#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=331.1111111111111,220
AudioOutputI2S           i2s1;           //xy=654.4444444444445,222.22222222222223
AudioConnection          patchCord1(sine1, 0, i2s1, 0);
AudioConnection          patchCord2(sine1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     
//xy=655.5555419921875,297.77777099609375
// GUItool: end automatically generated code

float arpegF[] = {739.99, 830.61, 932.33};
float amp_scale = 0.5;


void setup() {
  Serial.begin(9600);  
  
  AudioMemory(20);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5); // careful with your ears..! 
}
void loop() {
  for (int i = 0; i < 3; i++){
      float freq = arpegF[i];
      sine1.frequency(freq);
      delay(100);
      sine1.amplitude(amp_scale);
      delay(100);
    }
}
