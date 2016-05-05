#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"
#include <math.h>

class OI
{
private:
	Joystick *driveStick;

	JoystickButton *ButtonAShiftUp;
	JoystickButton *ButtonBShiftDown;

public:
	OI();
	inline float GetSteering() { return -AddDeadZone(driveStick->GetX(), 0.15f); }
	inline float GetDriveLeftTrigger() { return driveStick->GetRawAxis(2); }
	inline float GetDriveRightTrigger() { return driveStick->GetRawAxis(3); }

	bool GetShiftUp(){ return ButtonAShiftUp->Get();}
	bool GetShiftDown(){ return ButtonBShiftDown->Get();}


	inline float AddDeadZone(float original, float deadzone)
	{
		//Joystick_Drive.get
		  return ((fabs(original) <= deadzone) ? 0 : original);
	}
};

#endif
