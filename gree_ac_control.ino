#include <Tadiran.h> // Gree remote control codes from https://github.com/dpressle
#include <IRremote.h>

// the IR emitter object
IRsend irsend;
int incomingByte = 0;
// A/C Settings
int temperature = 24;
int mode = 1; // 0-Auto | 1-Cold | 2-Dry | 3-Fan | 4-Heat
int fanspeed = FAN_auto; //0-Auto | 1-Low | 2-Medium | 3-High

// the Tairan code generator object
Tadiran tadiran(mode, fanspeed, temperature, STATE_on);

void setup()i
{
  Serial.begin(9600);
  Serial.println("Commands: +/- Temperature | m - Mode | f - fanspeed | p - Power");
}

void loop() {

   if(Serial.available() > 0){
      incomingByte = Serial.parseInt();

      if(incomingByte == 1){
        tadiran.setState(1);
        irsend.sendRaw(tadiran.codes, TADIRAN_BUFFER_SIZE, 38);
      } else if(incomingByte == 2){
        tadiran.setState(0);
        irsend.sendRaw(tadiran.codes, TADIRAN_BUFFER_SIZE, 38);
      }
   }

}
