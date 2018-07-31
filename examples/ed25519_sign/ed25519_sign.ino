#include <Ed25519.h>

uint8_t signature[64];
uint8_t privateKey[32];
uint8_t publicKey[32];

void printSignature(uint8_t sig[64]) {
  Serial.print("0x");
  
  char tmp[10];
  for (int i = 0; i < sizeof(sig); ++i) {
     sprintf(tmp, "%X", sig[i]);
     Serial.print(tmp);
  }
  Serial.println("");
}

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  String msg = Serial.readString();
  
  Ed25519::sign(signature, privateKey, publicKey, msg.c_str(), msg.length());
  
  // print out the signature
  printSignature(signature);
}
