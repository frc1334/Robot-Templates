#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* JOYSTICK_DRIVE;

public:
	OI();
	float GET_LEFT_XAXIS() { return AddDeadZone(JOYSTICK_DRIVE->GetRawAxis(0),0.15f);}
	float GET_LEFT_YAXIS() { return  AddDeadZone(JOYSTICK_DRIVE->GetRawAxis(1),0.15f);}
	float GET_LEFT_TRIGGER() {return  AddDeadZone(JOYSTICK_DRIVE->GetRawAxis(2),0.15f);}
	float GET_RIGHT_TRIGGER() {return  AddDeadZone(JOYSTICK_DRIVE->GetRawAxis(3),0.15f);}
	float GET_RIGHT_XAXIS() { return  AddDeadZone(JOYSTICK_DRIVE->GetRawAxis(4),0.15f);}
	float GET_RIGHT_YAXIS() { return  AddDeadZone(JOYSTICK_DRIVE->GetRawAxis(5),0.15f);}
	inline float AddDeadZone(float original, float deadzone)
	{
		//Joystick_Drive.get
		  return ((fabs(original) <= deadzone) ? 0 : original);
	}
};

#endif
