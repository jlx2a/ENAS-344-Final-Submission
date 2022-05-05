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
AudioControlSGTL5000     sgtl5000_1;     //xy=655.5555419921875,297.77777099609375
// GUItool: end automatically generated code

float base_freq = 261.63;
float amp_scale = 0.5;

void setup() {
  // put your setup code here, to run once:
  AudioMemory(20);
  sgtl5000_1.enable(0.5);
  sgtl5000_1.volume(0.5);
  sine1.frequency(base_freq);
  sine1.amplitude(amp_scale);

}

void loop() {
  // put your main code here, to run repeatedly:

}
