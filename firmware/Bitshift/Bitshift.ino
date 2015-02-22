//
// BITSHIFT
// Thibault Brevet, 2015
// release under the MIT license
//
// flash via Arduino IDE on ATTiny45/85 chips
//

int in = 1; // signal in
int out = 2; // signal out
int led = 0; // mosfet control

int heatTime = 2000; // how long we heat the panel
int sigTime = 500; // how long we keep the OUT signal pulled high

void setup()
{
  pinMode(in, INPUT);
  pinMode(out, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop()
{

  // if we detect the input pin HIGH, we start the sequence
  if (digitalRead(in)){

    // first turn on HEAT for specified time
    digitalWrite(led, HIGH);
    delay(heatTime);
    digitalWrite(led, LOW);
    delay(100);

    // then forward SIGNAL for specififed time
    digitalWrite(out, HIGH);
    delay(sigTime);
    digitalWrite(out, LOW);
    delay(100);
  }

  // we wait for the IN signal
  delay(10);

}
