#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX

struct VR {
  int xval;
  int yval;
};

VR vr;

void setup() {
  Serial.begin(9600);
  mySerial.begin(38400);
}

void loop() {
  if (mySerial.available()) {
    mySerial.readBytes((char*)&vr, sizeof(vr));
    Serial.print("xval: ");
    Serial.print(vr.xval);
    Serial.print(" yval: ");
    Serial.println(vr.yval);
  }
}
