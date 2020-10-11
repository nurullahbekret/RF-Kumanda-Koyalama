#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

char auth[] = "YourAuthToken";
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

int on,off;

void setup()
{
  
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  mySwitch.enableTransmit(D2);

}

BLYNK_WRITE(V1) {
  int deger = param.asInt();
  on = deger;
}
BLYNK_WRITE(V2) {
  int deger = param.asInt();
  off = deger;
}

void loop()
{ 
  if(on){
    delay(50);
    mySwitch.send(kumandaKodu, 24);
  }
  if(off){
    delay(50);
    mySwitch.send(kumandaKodu, 24);
  }
  Blynk.run();
}
