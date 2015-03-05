//
// BITSHIFT
// Thibault Brevet, 2015
// release under the MIT license
//
// flash via Arduino IDE on ATTiny45/85 chips
//

int in = 3; // signal in
int shift = 1; // signal out
int heat = 2; // mosfet control

int heatTime = 15000; // how long we heat the panel

int wait = 5000;
int sigTime = 500; // how long we keep the OUT signal pulled high

void setup()
{
  pinMode(in, INPUT);
  pinMode(shift, OUTPUT);
  pinMode(heat, OUTPUT);
}

void loop()
{

  // if we detect the input pin HIGH, we start the sequence
  if (digitalRead(in)){

    // first turn on HEAT at maximum to reach temperature for specified time
    digitalWrite(heat, HIGH);
    delay(heatTime);
    digitalWrite(heat, LOW);
    
    // wait some time before shifting to next board
    delay(wait);

    // then forward SIGNAL for specififed time
    digitalWrite(shift, HIGH);
    delay(sigTime);
    digitalWrite(shift, LOW);
    delay(100);
  }

  // we wait for the IN signal
  delay(10);

}
