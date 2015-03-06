//
// BITSHIFT
// Thibault Brevet, 2015
// release under the MIT license
//
// flash via Arduino IDE on ATTiny45/85 chips
//

int shift = 1; // signal out
int heat = 2; // mosfet control

void setup()
{
  pinMode(shift, OUTPUT);
  pinMode(heat, OUTPUT);
}

void loop()
{

    // first turn on HEAT at maximum to reach temperature for specified time
    digitalWrite(heat, HIGH);
    delay(1000);
    digitalWrite(heat, LOW);

    // then forward SIGNAL for specififed time
    digitalWrite(shift, HIGH);
    delay(1000);
    digitalWrite(shift, LOW);
}
