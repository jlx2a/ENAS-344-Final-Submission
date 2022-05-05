// include libraries
#include "GY521.h"
GY521 sensor(0x68);
uint32_t counter = 0;

// music preparation
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine5;          //xy=67,230
AudioSynthWaveformSine   sine4;          //xy=68,190
AudioSynthSimpleDrum     drum1;          //xy=75,274
AudioSynthWaveformSine   sine3;          //xy=76,149
AudioSynthWaveformSine   sine2;          //xy=79,107
AudioSynthWaveformSine   sine1;          //xy=81,69
AudioSynthKarplusStrong  string5;        //xy=80,488
AudioSynthKarplusStrong  string1;        //xy=81,328
AudioSynthKarplusStrong  string3;        //xy=82,407
AudioSynthKarplusStrong  string4;        //xy=82,447
AudioSynthKarplusStrong  string2;        //xy=84,368
AudioSynthWaveformModulated waveformMod2;   //xy=237,103
AudioSynthWaveformModulated waveformMod3;   //xy=237,139
AudioSynthWaveformModulated waveformMod5;   //xy=238,208
AudioSynthWaveformModulated waveformMod1;   //xy=241,68
AudioSynthWaveformModulated waveformMod4;   //xy=241,174
AudioSynthWaveformModulated waveformMod6;   //xy=251,295
AudioSynthWaveformModulated waveformMod7;   //xy=254,331
AudioSynthWaveformModulated waveformMod8;   //xy=256,369
AudioSynthWaveformModulated waveformMod9;   //xy=258,405
AudioSynthWaveformModulated waveformMod10;  //xy=267,442
AudioEffectEnvelope      envelope2;      //xy=428,125
AudioEffectEnvelope      envelope1;      //xy=429,87
AudioEffectEnvelope      envelope3;      //xy=434,158
AudioEffectEnvelope      envelope6;      //xy=438,278
AudioEffectEnvelope      envelope5;      //xy=442,235
AudioEffectEnvelope      envelope7;      //xy=442,324
AudioEffectEnvelope      envelope4;      //xy=454,196
AudioEffectEnvelope      envelope8;      //xy=457,364
AudioEffectEnvelope      envelope9;      //xy=460,409
AudioEffectEnvelope      envelope10;     //xy=471,451
AudioMixer4              mixer1;         //xy=637,125
AudioMixer4              mixer2;         //xy=651,225
AudioMixer4              mixer3;         //xy=663,311
AudioMixer4              mixer4;         //xy=808,302
AudioOutputI2S           i2s1;           //xy=843,225
AudioConnection          patchCord1(sine5, 0, waveformMod5, 0);
AudioConnection          patchCord2(sine4, 0, waveformMod4, 0);
AudioConnection          patchCord3(drum1, 0, mixer4, 0);
AudioConnection          patchCord4(sine3, 0, waveformMod3, 0);
AudioConnection          patchCord5(sine2, 0, waveformMod2, 0);
AudioConnection          patchCord6(sine1, 0, waveformMod1, 0);
AudioConnection          patchCord7(string5, 0, waveformMod10, 0);
AudioConnection          patchCord8(string1, 0, waveformMod6, 0);
AudioConnection          patchCord9(string3, 0, waveformMod8, 0);
AudioConnection          patchCord10(string4, 0, waveformMod9, 0);
AudioConnection          patchCord11(string2, 0, waveformMod7, 0);
AudioConnection          patchCord12(waveformMod2, envelope2);
AudioConnection          patchCord13(waveformMod3, envelope3);
AudioConnection          patchCord14(waveformMod5, envelope5);
AudioConnection          patchCord15(waveformMod1, envelope1);
AudioConnection          patchCord16(waveformMod4, envelope4);
AudioConnection          patchCord17(waveformMod6, envelope6);
AudioConnection          patchCord18(waveformMod7, envelope7);
AudioConnection          patchCord19(waveformMod8, envelope8);
AudioConnection          patchCord20(waveformMod9, envelope9);
AudioConnection          patchCord21(waveformMod10, envelope10);
AudioConnection          patchCord22(envelope2, 0, mixer1, 1);
AudioConnection          patchCord23(envelope1, 0, mixer1, 0);
AudioConnection          patchCord24(envelope3, 0, mixer1, 2);
AudioConnection          patchCord25(envelope6, 0, mixer2, 2);
AudioConnection          patchCord26(envelope5, 0, mixer2, 0);
AudioConnection          patchCord27(envelope7, 0, mixer2, 1);
AudioConnection          patchCord28(envelope4, 0, mixer1, 3);
AudioConnection          patchCord29(envelope8, 0, mixer2, 3);
AudioConnection          patchCord30(envelope9, 0, mixer3, 0);
AudioConnection          patchCord31(envelope10, 0, mixer3, 1);
AudioConnection          patchCord32(mixer1, 0, mixer3, 3);
AudioConnection          patchCord33(mixer1, 0, mixer4, 1);
AudioConnection          patchCord34(mixer2, 0, mixer3, 2);
AudioConnection          patchCord35(mixer2, 0, mixer4, 2);
AudioConnection          patchCord36(mixer3, 0, mixer4, 3);
AudioConnection          patchCord37(mixer4, 0, i2s1, 0);
AudioConnection          patchCord38(mixer4, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=707,493
// GUItool: end automatically generated code

//float f_frequency = 261.23; // fundamental frequency of our synth
float m_frequency = 4.0;  // rate of the vibrato
float m_depth = .005; // depth of the vibrato
float env_attack = 20; // time, in milliseconds, of the attack stage of the envelope
float env_decay = 100; // time, in milliseconds, of the decay stage of the envelope
float env_sustain = .8; // level, from 0.0 to 1.0, of the sustain stage of the envelope
float env_release = 50; // time, in milliseconds, of the release stage of the envelope

// set up variables
const int front = A1;
const int back = A2;
const int right = A3;

int frontReading;
int backReading;
int rightReading;

const int pin_S0 = 0;
const int pin_S1 = 1;
const int pin_S2 = 2;
const int pin_S3 = 3;

int leftReading;
int topReading;
int bottomReading;

const int pin_Signal = A0;

// arpeggiator arrays
float arpegF[] = {739.99, 830.61, 932.33};
float arpegD[] = {1244.51, 1108.73, 932.33};
float arpegB[] = {932.33, 739.99, 554.37, 523.25, 554.37};


void setup() {
  
  // setup for accelerometer 
  Serial.begin(9600);   
  Serial.println(__FILE__);
  Wire.begin();

  delay(100);
  pinMode(pin_S1, OUTPUT);
  pinMode(pin_S2, OUTPUT);
  pinMode(pin_S3, OUTPUT);
  while (sensor.wakeup() == false)
  {
    Serial.print(millis());
    Serial.println("\tCould not connect to GY521");
    delay(300);
  }
  sensor.setAccelSensitivity(0);  // 2g
  sensor.setGyroSensitivity(0);   // 250 degrees/s

  sensor.setThrottle();
  Serial.println("start...");
  
  // set calibration values from calibration sketch.
  sensor.axe = 0;
  sensor.aye = 0;
  sensor.aze = 0;
  sensor.gxe = 0;
  sensor.gye = 0;
  sensor.gze = 0;

  // set up for multiplexer
  pinMode(pin_S0, OUTPUT);
  pinMode(pin_Signal, INPUT);

  // set the stages of the envelope with the assigned variables
  envelope1.attack(env_attack);
  envelope1.hold(0.0);  
  envelope1.decay(env_decay);
  envelope1.sustain(env_sustain);
  envelope1.release(env_release);  

  envelope2.attack(env_attack);
  envelope2.hold(0.0);  
  envelope2.decay(env_decay);
  envelope2.sustain(env_sustain);
  envelope2.release(env_release);  

  envelope3.attack(env_attack);
  envelope3.hold(0.0);  
  envelope3.decay(env_decay);
  envelope3.sustain(env_sustain);
  envelope3.release(env_release); 

  envelope4.attack(env_attack);
  envelope4.hold(0.0);  
  envelope4.decay(env_decay);
  envelope4.sustain(env_sustain);
  envelope4.release(env_release); 

  envelope5.attack(env_attack);
  envelope5.hold(0.0);  
  envelope5.decay(env_decay);
  envelope5.sustain(env_sustain);
  envelope5.release(env_release); 

  envelope6.attack(env_attack);
  envelope6.hold(0.0);  
  envelope6.decay(env_decay);
  envelope6.sustain(env_sustain);
  envelope6.release(env_release); 

  envelope7.attack(env_attack);
  envelope7.hold(0.0);  
  envelope7.decay(env_decay);
  envelope7.sustain(env_sustain);
  envelope7.release(env_release); 

  envelope8.attack(env_attack);
  envelope8.hold(0.0);  
  envelope8.decay(env_decay);
  envelope8.sustain(env_sustain);
  envelope8.release(env_release); 
  
  // music
  AudioMemory(12);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5); // careful with your ears..! 

  // Configure the oscillator as a sine tone at middle C without modulation
  waveformMod1.frequency(277.18); 
  waveformMod1.amplitude(0.1);
  waveformMod1.begin(WAVEFORM_SINE);
  waveformMod1.frequencyModulation(0); 

  waveformMod2.frequency(311.13);
  waveformMod2.amplitude(0.1);
  waveformMod2.begin(WAVEFORM_SINE);
  waveformMod2.frequencyModulation(0); 

  waveformMod3.frequency(369.99);
  waveformMod3.amplitude(0.1);
  waveformMod3.begin(WAVEFORM_SINE);
  waveformMod3.frequencyModulation(0); 

  waveformMod4.frequency(261.63);
  waveformMod4.amplitude(0.1);
  waveformMod4.begin(WAVEFORM_SINE);
  waveformMod4.frequencyModulation(0); 

  waveformMod5.frequency(233.08);
  waveformMod5.amplitude(0.1);
  waveformMod5.begin(WAVEFORM_SINE);
  waveformMod5.frequencyModulation(0); 

}

void loop() {
  
  // loop for accelerometer
  sensor.read();
  int ax = sensor.getAccelX();
  int ay = sensor.getAccelY();
  int az = sensor.getAccelZ();
  int gx = sensor.getGyroX();
  int gy = sensor.getGyroY();
  int gz = sensor.getGyroZ();
  int t = sensor.getTemperature();
  
  Serial.println("\n\tACCELEROMETER\t\tGYROSCOPE");
  Serial.println("\tax\tay\taz\tgx\tgy\tgz");
  
  Serial.print('\t');
  Serial.print(ax);
  Serial.print('\t');
  Serial.print(ay);
  Serial.print('\t');
  Serial.print(az);
  Serial.print('\t');
  Serial.print(gx);
  Serial.print('\t');
  Serial.print(gy);
  Serial.print('\t');
  Serial.print(gz);

  Serial.println();

  counter++;

  // loop for Teensy analog pins
  frontReading = analogRead(front); 
  backReading = analogRead(back);
  rightReading = analogRead(right);

  Serial.print("Front = ");
  Serial.print(frontReading); 
  Serial.print("   Back = ");
  Serial.print(backReading); 
  Serial.print("   Right = ");
  Serial.print(rightReading); 
  delay(50);

  // loop for multiplexer 
  digitalWrite(pin_S0, LOW);
  digitalWrite(pin_S1, LOW);
  digitalWrite(pin_S2, LOW);
  digitalWrite(pin_S3, LOW);

  bottomReading = analogRead(pin_Signal);
  Serial.print("Bottom = ");
  Serial.println(bottomReading);

  delay(50);

  digitalWrite(pin_S0, HIGH);
  digitalWrite(pin_S1, LOW);
  digitalWrite(pin_S2, LOW);
  digitalWrite(pin_S3, LOW);

  leftReading = analogRead(pin_Signal);
  Serial.print("Left = ");
  Serial.println(leftReading);

  delay(50);

  digitalWrite(pin_S0, LOW);
  digitalWrite(pin_S1, HIGH);
  digitalWrite(pin_S2, LOW);
  digitalWrite(pin_S3, LOW);

  topReading = analogRead(pin_Signal);
  Serial.print("Top = ");
  Serial.println(topReading);

  delay(50);

  Serial.println();

  // mapping notes and volumes
  if(leftReading > 200) {
    envelope1.noteOn();
  }


  if(leftReading < 50) {
    envelope1.noteOff();
  }
    
  if(frontReading > 200) {
    envelope2.noteOn();
  }

  if(frontReading < 50) {
    envelope2.noteOff();
  }

  
  if(rightReading > 200) {
    envelope3.noteOn();
  }


  if(rightReading < 50) {
    envelope3.noteOff();
  }


  if(topReading > 200) {
    envelope4.noteOn();
  }


  if(topReading < 50) {
    envelope4.noteOff();
  }  

  if(backReading > 200) {
    envelope5.noteOn();
  }

  if(backReading < 50) {
    envelope5.noteOff();
  }

  if (bottomReading > 250 && rightReading > 250){
    envelope3.noteOff();
    for (int i = 0; i < 3; i++) {
      float freq = arpegF[i];
      waveformMod6.frequency(freq);
      waveformMod6.amplitude(0.1);
      waveformMod6.begin(WAVEFORM_SINE);
      waveformMod6.frequencyModulation(0); 
      envelope6.noteOn();
      delay(167);
      envelope6.noteOff();
      delay(167); //flag 
    }
  } else {
      envelope6.noteOff();
    }

  if(bottomReading > 250 && frontReading > 250){
    envelope2.noteOff();
    for(int i = 0; i < 3; i++) {
      float freq = arpegD[i];
      waveformMod7.frequency(freq);
      waveformMod7.amplitude(0.1);
      waveformMod7.begin(WAVEFORM_SINE);
      waveformMod7.frequencyModulation(0);
      envelope7.noteOn();
      delay(167);
      envelope7.noteOff();
      delay(167); //flag  
    }
  } else {
      envelope7.noteOff();
    }

  if(bottomReading > 250 && backReading > 250){
    envelope2.noteOff();
    for(int i = 0; i < 5; i++) {
      float freq = arpegB[i];
      waveformMod8.frequency(freq);
      waveformMod8.amplitude(0.1);
      waveformMod8.begin(WAVEFORM_SINE);
      waveformMod8.frequencyModulation(0);
      envelope8.noteOn();
      delay(167);
      envelope8.noteOff();
      delay(167); //flag  
    }
  } else {
      envelope8.noteOff();
    }

    if (gy > 30){
    drum1.noteOn();
    }
 }

//
//  if (gx > 0) {
//    
//  }
//  

//  
//  if (gz > 0){
//    
