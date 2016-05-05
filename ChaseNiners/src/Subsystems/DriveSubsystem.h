#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSubsystem: public Subsystem
{
private:


	Solenoid Shift1;
	Solenoid Shift2;


public:
	Talon DriveRight1;
	Talon DriveRight2;

	Talon DriveLeft1;
	Talon DriveLeft2;

	DriveSubsystem();
	void InitDefaultCommand();
	void Drive(float speedLeft, float speedRight, float turn);
	void SetShiftState(bool state);
	void Stop();

};

#endif
