#include "OI.h"
#include "RobotMap.h"

OI::OI()

{

	driveStick = new Joystick(JOYSTICK_DRIVE);
	ButtonAShiftUp = new JoystickButton(driveStick, 1);
	ButtonBShiftDown = new JoystickButton(driveStick, 2);

}
