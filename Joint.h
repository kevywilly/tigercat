/*
 * Joint.h
 *
 *  Created on: Dec 19, 2016
 *      Author: kevywilly
 */

#ifndef JOINT_H_
#define JOINT_H_

#include "Arduino.h"
#include <Servo.h>

class Joint {

public:

	Joint(uint8_t _pin, uint8_t _zero, uint8_t _neutral);
	~Joint();

	uint8_t pin;
	uint8_t zero;
	uint8_t neutral;
	uint8_t current_angle;
	uint8_t goal_angle;

	bool goal_is_reached = true;
	bool is_moving = false;

	void init();
	void reset();
	void rest();
	void jumpTo(uint8_t angle);
	void jumpToNeutral();
	void jumpToZero();

	int8_t direction();


	Servo *servo;



};

#endif /* JOINT_H_ */
