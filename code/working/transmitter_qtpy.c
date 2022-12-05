#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(A3,A2);
struct vals{
  int xval;
  int yval;
};

vals VR;


int VRx = A0;
int VRy = A1;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

// BLUETOOTH RATE IS 38400

// VRx and VRy are the analog pins connected to the joystick
// xPosition and yPosition are the values read from the joystick

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(38400);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  mapX = map(xPosition, 0, 1023, 0, 255);
  mapY = map(yPosition, 0, 1023, 0, 255);
  VR.xval = mapX;
  VR.yval = mapY;
      // STORE mapX and mapY in a struct and send it to the bluetooth module
    Bluetooth.write((byte*)&VR, sizeof(VR));
    // print the values to the serial monitor
    Serial.print("\n X: ");
    Serial.print(mapX);
    Serial.print(" Y: ");
    Serial.println(mapY);
  // Bluetooth.write(VR.xval);
  // Serial.println(VR.xval);
  delay(100);
}
