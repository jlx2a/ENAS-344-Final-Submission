//
//#include "GY521.h"
//
//GY521 sensor(0x68);
//
//uint32_t counter = 0;

int front = A1;     // the FSR and 10K pulldown are connected to a0
int back = A2;
int right = A3;
//int left = ;
//int top = ;
//int bottom = ;

int frontReading;     // the analog reading from the FSR resistor divider
int backReading;
int rightReading;
//int leftReading;
//int topReading;
//int bottomReading;
 
void setup(void) {
  Serial.begin(9600);   
  Serial.println(__FILE__);
 // Wire.begin();
//
//  delay(100);
//  while (sensor.wakeup() == false)
//  {
//    Serial.print(millis());
//    Serial.println("\tCould not connect to GY521");
//    delay(1000);
//  }
//  sensor.setAccelSensitivity(0);  // 2g
//  sensor.setGyroSensitivity(0);   // 250 degrees/s
//
//  sensor.setThrottle();
//  Serial.println("start...");
//  
//  // set calibration values from calibration sketch.
//  sensor.axe = 0;
//  sensor.aye = 0;
//  sensor.aze = 0;
//  sensor.gxe = 0;
//  sensor.gye = 0;
//  sensor.gze = 0;
}
 
void loop(void) {

//  sensor.read();
//  int ax = sensor.getAccelX();
//  int ay = sensor.getAccelY();
//  int az = sensor.getAccelZ();
//  int gx = sensor.getGyroX();
//  int gy = sensor.getGyroY();
//  int gz = sensor.getGyroZ();
//  int t = sensor.getTemperature();
//  
//  Serial.println("\n\tACCELEROMETER\t\tGYROSCOPE");
//  Serial.println("\tax\tay\taz\tgx\tgy\tgz");
//  
//
//  
//  Serial.print('\t');
//  Serial.print(ax);
//  Serial.print('\t');
//  Serial.print(ay);
//  Serial.print('\t');
//  Serial.print(az);
//  Serial.print('\t');
//  Serial.print(gx);
//  Serial.print('\t');
//  Serial.print(gy);
//  Serial.print('\t');
//  Serial.print(gz);
//
//  Serial.println();
//
//  counter++;
//









  ///////////////////////////////////
  frontReading = analogRead(front); 
  backReading = analogRead(back);
  rightReading = analogRead(right);
//  leftReading = analogRead(left);
//  topReading = analogRead(top);
//  bottomReading = analogRead(bottom);
 
  Serial.print("Front = ");
  Serial.print(frontReading); 
  Serial.print("   Back = ");
  Serial.print(backReading); 
  Serial.print("   Right = ");
  Serial.print(rightReading); 
//  Serial.print("   Left = ");
//  Serial.print(leftReading); 
//  Serial.print("   Top = ");
//  Serial.print(topReading); 
//  Serial.print("   Bot = ");
//  Serial.println(bottomReading); 
//  
  // print the raw analog reading
  //Serial.println(frontReading);
  delay(300);

//  if (frontReading < 10) {
//    Serial.println(" - No pressure");
//  } else if (frontReading < 200) {
//    Serial.println(" - Light touch");
//  } else if (frontReading < 500) {
//    Serial.println(" - Light squeeze");
//  } else if (frontReading < 800) {
//    Serial.println(" - Medium squeeze");
//  } else {
//    Serial.println(" - Big squeeze");
//  }
//  delay(1000);
//
//  Serial.print("Back = ");
//  Serial.print(backReading);
//
//    if (backReading < 10) {
//    Serial.println(" - No pressure");
//  } else if (backReading < 200) {
//    Serial.println(" - Light touch");
//  } else if (backReading < 500) {
//    Serial.println(" - Light squeeze");
//  } else if (backReading < 800) {
//    Serial.println(" - Medium squeeze");
//  } else {
//    Serial.println(" - Big squeeze");
//  }
//  delay(1000);

  
//  Serial.print("Right = ");
//  Serial.print(rightReading);     // print the raw analog reading
//
//    if (rightReading < 10) {
//    Serial.println(" - No pressure");
//  } else if (rightReading < 200) {
//    Serial.println(" - Light touch");
//  } else if (rightReading < 500) {
//    Serial.println(" - Light squeeze");
//  } else if (rightReading < 800) {
//    Serial.println(" - Medium squeeze");
//  } else {
//    Serial.println(" - Big squeeze");
//  }
//  delay(1000);
//
//  Serial.print("Left = ");
//  Serial.print(leftReading);
//
//    if (leftReading < 10) {
//    Serial.println(" - No pressure");
//  } else if (leftReading < 200) {
//    Serial.println(" - Light touch");
//  } else if (leftReading < 500) {
//    Serial.println(" - Light squeeze");
//  } else if (leftReading < 800) {
//    Serial.println(" - Medium squeeze");
//  } else {
//    Serial.println(" - Big squeeze");
//  }
//  delay(1000);
//
//  Serial.print("Top = ");
//  Serial.print(topReading);     // print the raw analog reading
//
//    if (topReading < 10) {
//    Serial.println(" - No pressure");
//  } else if (topReading < 200) {
//    Serial.println(" - Light touch");
//  } else if (topReading < 500) {
//    Serial.println(" - Light squeeze");
//  } else if (topReading < 800) {
//    Serial.println(" - Medium squeeze");
//  } else {
//    Serial.println(" - Big squeeze");
//  }
//  delay(1000);
//
//  Serial.print("Bottom = ");
//  Serial.print(bottomReading);
//
//
//    if (bottomReading < 10) {
//    Serial.println(" - No pressure");
//  } else if (bottomReading < 200) {
//    Serial.println(" - Light touch");
//  } else if (bottomReading < 500) {
//    Serial.println(" - Light squeeze");
//  } else if (bottomReading < 800) {
//    Serial.println(" - Medium squeeze");
//  } else {
//    Serial.println(" - Big squeeze");
//  }
//  delay(1000);
}
