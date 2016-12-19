/*
 * Joint.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: kevywilly
 */

#include "Joint.h"

//	Constructor
Joint::Joint(uint8_t _pin, uint8_t _zero, uint8_t _neutral) {

		servo = new Servo;
		pin = _pin;
		zero = _zero;
		neutral = _neutral;
		current_angle = zero;
		goal_angle = zero;
		goal_is_reached = true;
		reset();
}

Joint::~Joint() {
	rest();
}
void Joint::init() {
	jumpToZero();
}

void Joint::reset() {

}

void Joint::rest() {
	jumpToZero();
	servo->detach();
}
// Show Direction
int8_t Joint::direction() {
	if(current_angle == goal_angle)
		return 0;

	return (current_angle < goal_angle) ? 1 : -1;
}

void Joint::jumpToNeutral() {
	servo->attach(pin);
	jumpTo(neutral);
}

void Joint::jumpToZero() {
	servo->attach(pin);
	jumpTo(zero);
}

void Joint::jumpTo(uint8_t angle) {

	goal_angle = angle;
	goal_is_reached = false;
	is_moving = true;

	servo->write(angle);

	current_angle = angle;
	goal_is_reached = true;
	is_moving = false;
}

