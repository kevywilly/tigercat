/*
 * HindLeg.h
 *
 *  Created on: Dec 19, 2016
 *      Author: kevywilly
 */

#ifndef HINDLEG_H_
#define HINDLEG_H_

#include "Joint.h"

class HindLeg {
public:
	HindLeg(Joint* _hip, Joint* _knee, Joint* _ankle);

	Joint* hip;
	Joint* knee;
	Joint* ankle;

	bool is_moving();
	bool goal_is_reached();
	void init();
	void jumpToZero();
	void jumpToNeutral();
	void jumpTo(uint8_t hip_angle, uint8_t knee_angle, uint8_t ankle_angle);
};

#endif /* HINDLEG_H_ */
