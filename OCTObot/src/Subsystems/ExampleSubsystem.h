#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ExampleSubsystem: public Subsystem
{
private:

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Talon MOTOR_1;
	Talon MOTOR_2;
	Talon MOTOR_3;
	Talon MOTOR_4;
	ExampleSubsystem();
	void InitDefaultCommand();
	void Drive(float speed_x, float turn, float speed_y);
};

#endif
