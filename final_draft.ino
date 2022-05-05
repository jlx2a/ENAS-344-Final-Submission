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
AudioSynthSimpleDrum     drum1;          //xy=79,476
AudioSynthKarplusStrong  string1;        //xy=121,581
AudioSynthKarplusStrong  string5;        //xy=124,729
AudioSynthKarplusStrong  string2;        //xy=126,615
AudioSynthKarplusStrong  string4;        //xy=127,687
AudioSynthKarplusStrong  string3;        //xy=135,652
AudioSynthWaveformSine   sine1;          //xy=139,283
AudioSynthWaveformModulated waveformMod2;   //xy=295,317
AudioSynthWaveformModulated waveformMod3;   //xy=295,353
AudioSynthWaveformModulated waveformMod5;   //xy=296,422
AudioSynthWaveformModulated waveformMod1;   //xy=299,282
AudioSynthWaveformModulated waveformMod4;   //xy=299,388
AudioSynthWaveformModulated waveformMod6;   //xy=304,457
AudioSynthWaveformModulated waveformMod7;   //xy=307,495
AudioSynthWaveformModulated waveformMod8;   //xy=307,533
AudioEffectEnvelope      envelope2;      //xy=486,339
AudioEffectEnvelope      envelope1;      //xy=487,301
AudioEffectEnvelope      envelope3;      //xy=492,372
AudioEffectEnvelope      envelope6;      //xy=496,492
AudioEffectEnvelope      envelope5;      //xy=500,449
AudioEffectEnvelope      envelope7;      //xy=500,538
AudioEffectEnvelope      envelope4;      //xy=512,410
AudioEffectEnvelope      envelope8;      //xy=515,578
AudioMixer4              mixer1;         //xy=695,339
AudioMixer4              mixer2;         //xy=709,439
AudioMixer4              mixer5;         //xy=720,600
AudioMixer4              mixer3;         //xy=721,525
AudioMixer4              mixer4;         //xy=866,516
AudioOutputI2S           i2s1;           //xy=901,439
AudioConnection          patchCord1(drum1, 0, mixer3, 0);
AudioConnection          patchCord2(string1, 0, mixer3, 1);
AudioConnection          patchCord3(string5, 0, mixer5, 3);
AudioConnection          patchCord4(string2, 0, mixer5, 0);
AudioConnection          patchCord5(string4, 0, mixer5, 2);
AudioConnection          patchCord6(string3, 0, mixer5, 1);
AudioConnection          patchCord7(sine1, 0, waveformMod1, 0);
AudioConnection          patchCord8(sine1, 0, waveformMod1, 1);
AudioConnection          patchCord9(sine1, 0, waveformMod2, 0);
AudioConnection          patchCord10(sine1, 0, waveformMod2, 1);
AudioConnection          patchCord11(sine1, 0, waveformMod3, 0);
AudioConnection          patchCord12(sine1, 0, waveformMod3, 1);
AudioConnection          patchCord13(sine1, 0, waveformMod4, 0);
AudioConnection          patchCord14(sine1, 0, waveformMod4, 1);
AudioConnection          patchCord15(sine1, 0, waveformMod5, 0);
AudioConnection          patchCord16(sine1, 0, waveformMod5, 1);
AudioConnection          patchCord17(sine1, 0, waveformMod6, 1);
AudioConnection          patchCord18(sine1, 0, waveformMod6, 0);
AudioConnection          patchCord19(sine1, 0, waveformMod7, 0);
AudioConnection          patchCord20(sine1, 0, waveformMod7, 1);
AudioConnection          patchCord21(sine1, 0, waveformMod8, 0);
AudioConnection          patchCord22(sine1, 0, waveformMod8, 1);
AudioConnection          patchCord23(waveformMod2, envelope2);
AudioConnection          patchCord24(waveformMod3, envelope3);
AudioConnection          patchCord25(waveformMod5, envelope5);
AudioConnection          patchCord26(waveformMod1, envelope1);
AudioConnection          patchCord27(waveformMod4, envelope4);
AudioConnection          patchCord28(waveformMod6, envelope6);
AudioConnection          patchCord29(waveformMod7, envelope7);
AudioConnection          patchCord30(waveformMod8, envelope8);
AudioConnection          patchCord31(envelope2, 0, mixer1, 1);
AudioConnection          patchCord32(envelope1, 0, mixer1, 0);
AudioConnection          patchCord33(envelope3, 0, mixer1, 2);
AudioConnection          patchCord34(envelope6, 0, mixer2, 2);
AudioConnection          patchCord35(envelope5, 0, mixer2, 0);
AudioConnection          patchCord36(envelope7, 0, mixer2, 1);
AudioConnection          patchCord37(envelope4, 0, mixer1, 3);
AudioConnection          patchCord38(envelope8, 0, mixer2, 3);
AudioConnection          patchCord39(mixer1, 0, mixer3, 3);
AudioConnection          patchCord40(mixer1, 0, mixer4, 1);
AudioConnection          patchCord41(mixer2, 0, mixer3, 2);
AudioConnection          patchCord42(mixer2, 0, mixer4, 2);
AudioConnection          patchCord43(mixer5, 0, mixer4, 0);
AudioConnection          patchCord44(mixer3, 0, mixer4, 3);
AudioConnection          patchCord45(mixer4, 0, i2s1, 0);
AudioConnection          patchCord46(mixer4, 0, i2s1, 1);
// GUItool: end automatically generated code

AudioControlSGTL5000     sgtl5000_1;     //xy=707,493
// GUItool: end automatically generated code

//float f_frequency = 261.23; // fundamental frequency of our synth
float m_frequency = 4.0;  // rate of the vibrato
float m_depth = .005; // depth of the vibrato
float env_attack = 20; // time, in milliseconds, of the attack stage of the envelope
float env_decay = 100; // time, in milliseconds, of the decay stage of the envelope
float env_sustain = .8; // level, from 0.0 to 1.0, of the sustain stage of the envelope
float env_release = 50; // time, in milliseconds, of the release stage of the envelope

const int pin_S0 = 0;
const int pin_S1 = 1;
const int pin_S2 = 2;
const int pin_S3 = 3;

int topReading;
int leftReading;
int backReading;
int frontReading;
int rightReading;
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
    delay(50);
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
  
  // music
  AudioMemory(12);
  sgtl5000_1.enable();
  sgtl5000_1.volume(1); // careful with your ears..! 

  // Configure the oscillator as a sine tone at middle C without modulation

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

  // loop for multiplexer 
  digitalWrite(pin_S0, LOW);
  digitalWrite(pin_S1, LOW);
  digitalWrite(pin_S2, LOW);
  digitalWrite(pin_S3, LOW);

  topReading = analogRead(pin_Signal);
  Serial.print("Top = ");
  Serial.println(topReading);

  delay(60);

  digitalWrite(pin_S0, HIGH);
  digitalWrite(pin_S1, LOW);
  digitalWrite(pin_S2, LOW);
  digitalWrite(pin_S3, LOW);

  leftReading = analogRead(pin_Signal);
  Serial.print("Left = ");
  Serial.println(leftReading);

  delay(60);

  digitalWrite(pin_S0, LOW);
  digitalWrite(pin_S1, HIGH);
  digitalWrite(pin_S2, LOW);
  digitalWrite(pin_S3, LOW);

  backReading = analogRead(pin_Signal);
  Serial.print("Back = ");
  Serial.println(backReading);

  delay(60);

  digitalWrite(pin_S0, HIGH);
  digitalWrite(pin_S1, HIGH);
  digitalWrite(pin_S2, LOW);
  digitalWrite(pin_S3, LOW);

  frontReading = analogRead(pin_Signal);
  Serial.print("Front = ");
  Serial.println(frontReading);

  delay(60);

  digitalWrite(pin_S0, LOW);
  digitalWrite(pin_S1, LOW);
  digitalWrite(pin_S2, HIGH);
  digitalWrite(pin_S3, LOW);

  rightReading = analogRead(pin_Signal);
  Serial.print("Right = ");
  Serial.println(rightReading);

  delay(30);

  digitalWrite(pin_S0, HIGH);
  digitalWrite(pin_S1, LOW);
  digitalWrite(pin_S2, HIGH);
  digitalWrite(pin_S3, LOW);

  bottomReading = analogRead(pin_Signal);
  Serial.print("Bottom = ");
  Serial.println(bottomReading);

  delay(60);

  Serial.println();

if(ay < 0) {
  // now top
  if(topReading > 20){
    string1.noteOn(554.37,0.005);
  } else if(topReading < 50){
    string1.noteOff(1);
  }
  
  if(frontReading > 20 && frontReading < 400){
    string2.noteOn(622.25, 0.005);
  } else if(frontReading < 50) {
    string2.noteOff(1);
  }

  if(backReading > 20 && backReading < 400){
    string3.noteOn(923.233, 0.005);
    } else if(backReading < 50){
      string3.noteOff(1);
    }
    
  if(bottomReading > 20 && bottomReading < 400) {
    string4.noteOn(739.99, 0.005);
  } else if(bottomReading < 50);
    string4.noteOff(1);

  if(rightReading > 20 && rightReading < 400){
    string5.noteOn(523.25, 0.005);
  } else if(rightReading < 50){
    string5.noteOff(1);
  }

  if(gy > 50){
    drum1.noteOn();
  }

 }if (az > 0){

  if(bottomReading > 50){
    drum1.frequency(3000);
    drum1.noteOn();
  }

  if(frontReading > 50){
    drum1.frequency(170);
    drum1.noteOn();
  }

  if(topReading > 50){
    drum1.frequency(80);
    drum1.noteOn();
  }

  if(backReading > 50){
    drum1.secondMix(1);
    drum1.noteOn();
  }

  if(leftReading > 50){
    drum1.frequency(60);
    drum1.noteOn();
  }
 }else if (ay >= 0 && ax >= 0){
  // mapping notes and volumes
  if(leftReading > 50) {
    waveformMod1.frequency(554.37); 
    waveformMod1.amplitude(1);
    waveformMod1.begin(WAVEFORM_SINE);
 //   waveformMod1.frequencyModulation(0); 

    envelope1.noteOn();
  } else if(leftReading < 20) {
    envelope1.noteOff();
  }
  
  if(frontReading > 20 && frontReading < 250) {
    waveformMod2.frequency(622.25);
    waveformMod2.amplitude(1);
    waveformMod2.begin(WAVEFORM_SINE);
 //   waveformMod2.frequencyModulation(10); 
    envelope2.noteOn();
  } if(frontReading > 250) {
    waveformMod2.frequency(698.46);
    waveformMod2.amplitude(1);
    waveformMod2.begin(WAVEFORM_SINE);
  //  waveformMod2.frequencyModulation(10); 
    envelope2.noteOn();
  } else if(frontReading < 50) {
    envelope2.noteOff();
  }


  if(backReading > 20 && backReading < 250) {
    waveformMod3.frequency(923.233);
    waveformMod3.amplitude(0.1);
    waveformMod3.begin(WAVEFORM_SINE);
   // waveformMod3.frequencyModulation(0); 
    envelope3.noteOn();
  } if(backReading > 250) {
    waveformMod3.frequency(987.77);
    waveformMod3.amplitude(0.01);
    waveformMod3.begin(WAVEFORM_SINE);
 //   waveformMod3.frequencyModulation(0); 
    envelope3.noteOn();
  } else if(backReading < 50) {   
    envelope3.noteOff();
  }
  
  if(rightReading > 20 && rightReading < 250) {
    waveformMod4.frequency(739.99);
    waveformMod4.amplitude(0.1);
    waveformMod4.begin(WAVEFORM_SINE);
//
    envelope4.noteOn();
  } if (rightReading > 250) {
    waveformMod4.frequency(830.61);
    waveformMod4.amplitude(0.1);
    waveformMod4.begin(WAVEFORM_SINE);
   // waveformMod4.frequencyModulation(0); 
    envelope4.noteOn();
  } else if(rightReading < 50) {
    envelope4.noteOff();
  }
  
  if(topReading > 20 && topReading < 250) {
    waveformMod5.frequency(523.25);
    waveformMod5.amplitude(1);
    waveformMod5.begin(WAVEFORM_SINE);
    envelope5.noteOn();
  } if(topReading > 250) {
    waveformMod5.frequency(1046.50);
    waveformMod5.amplitude(0.1);
    waveformMod5.begin(WAVEFORM_SINE);
    waveformMod5.frequencyModulation(0); 
    envelope5.noteOn();
  } else if(topReading < 50) {    
    envelope5.noteOff();
  }  

  if (bottomReading > 20 && rightReading > 250){
    envelope4.noteOff();
    for (int i = 0; i < 3; i++) {
      float freq = arpegF[i];
      waveformMod6.frequency(freq);
      waveformMod6.amplitude(0.1);
      waveformMod6.begin(WAVEFORM_SINE);
    //  waveformMod6.frequencyModulation(0); 
      envelope6.noteOn();
      delay(120);
      envelope6.noteOff();
      delay(120); //flag 
    }
  }

  if(bottomReading > 20 && frontReading > 250){
    envelope2.noteOff();
    for(int i = 0; i < 3; i++) {
      float freq = arpegD[i];
      waveformMod6.frequency(freq);
      waveformMod6.amplitude(1);
      waveformMod6.begin(WAVEFORM_SINE);
     // waveformMod6.frequencyModulation(0);
      envelope6.noteOn();
      delay(120);
      envelope6.noteOff();
      delay(120);
    }
  }

   
  if(bottomReading > 20 && backReading > 250){
    envelope2.noteOff();
    envelope3.noteOff();
    for(int i = 0; i < 5; i++) {
      float freq = arpegB[i];
      waveformMod6.frequency(freq);
      waveformMod6.amplitude(0.1);
      waveformMod6.begin(WAVEFORM_SINE);
    //  waveformMod6.frequencyModulation(0);
      envelope6.noteOn();
      delay(120);
      envelope6.noteOff();
      delay(120); //flag  
    }
  }

    if (gx > 20){
    drum1.noteOn();
    }
  }
}
