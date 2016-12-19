/*
 * HindLeg.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: kevywilly
 */

#include "HindLeg.h"

HindLeg::HindLeg(Joint* _hip, Joint* _knee, Joint* _ankle) {
	hip = _hip;
	knee = _knee;
	ankle = _ankle;
}

void HindLeg::init() {
	hip->init();
	knee->init();
	ankle->init();
}

void HindLeg::jumpToZero() {
	hip->jumpToZero();
	knee->jumpToZero();
	ankle->jumpToZero();
}

void HindLeg::jumpToNeutral() {
	hip->jumpToNeutral();
	knee->jumpToNeutral();
	ankle->jumpToNeutral();
}

void HindLeg::jumpTo(uint8_t hip_angle, uint8_t knee_angle, uint8_t ankle_angle) {
	hip->jumpTo(hip_angle);
	knee->jumpTo(knee_angle);
	ankle->jumpTo(ankle_angle);

}

bool HindLeg::is_moving() {
	return (hip->is_moving || knee->is_moving || ankle->is_moving);
}

bool HindLeg::goal_is_reached() {
	return (hip->goal_is_reached && knee->goal_is_reached && ankle->goal_is_reached);
}
