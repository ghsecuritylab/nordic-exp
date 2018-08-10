#ifndef DEFINES_H
#define DEFINES_H

#define PWM_PIN_1			11
#define MOTOR_PIN_0		12
#define MOTOR_PIN_1		13

enum class Direction {
	FORWARD,
	BACKWARDS,
	LEFT,
	RIGHT,
	NEUTRAL
};

enum class Location {
	FRONT,
	REAR,
	LEFT,
	RIGHT,
	MIDDLE,
	TOP,
	BELOW,
	UNKNOWN
};


#endif // DEFINES_H