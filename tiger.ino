#include "Arduino.h"
#include <Servo.h>
#include "HindLeg.h"

#define STOPPED true

#define BR_HIP_PIN 10
#define BR_KNEE_PIN 9
#define BR_ANKLE_PIN 8

#define HIP_ZERO 160
#define HIND_KNEE_ZERO 20
#define HIND_ANKLE_ZERO 150

#define HIP_NEUTRAL 64
#define HIND_KNEE_NEUTRAL 120
#define HIND_ANKLE_NEUTRAL 70

int8_t steps = 2;
int8_t step_delay = 15;

Joint br_hip(BR_HIP_PIN, HIP_ZERO, HIP_NEUTRAL);
Joint br_knee(BR_KNEE_PIN, HIND_KNEE_ZERO, HIND_KNEE_NEUTRAL);
Joint br_ankle(BR_ANKLE_PIN, HIND_ANKLE_ZERO, HIND_ANKLE_NEUTRAL);

HindLeg br_leg(&br_hip, &br_knee, &br_ankle);


void setup() {
  // put your setup code here, to run once:

Serial.begin(57600);

br_leg.init();


}

void loop() {

	if(!STOPPED) {
	br_leg.jumpToZero();
	delay(1000);
	br_leg.jumpToNeutral();
	delay(1000);
	}

}

