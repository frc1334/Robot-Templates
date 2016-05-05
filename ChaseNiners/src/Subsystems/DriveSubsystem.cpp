#include "DriveSubsystem.h"
#include "../RobotMap.h"

DriveSubsystem::DriveSubsystem() :
		Subsystem("DriveSubsystem"), DriveRight1(RIGHT1), DriveRight2(RIGHT2), DriveLeft1(LEFT1), DriveLeft2(LEFT2), Shift1(SHIFT1), Shift2(SHIFT2)

{

}

void DriveSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void DriveSubsystem::Drive(float speedLeft, float speedRight, float turn)
{
	DriveLeft1.SetSafetyEnabled(true);
	DriveLeft1.SetExpiration(1.0f);
	DriveLeft2.SetSafetyEnabled(true);
	DriveLeft2.SetExpiration(1.0f);
	DriveRight1.SetSafetyEnabled(true);
	DriveRight1.SetExpiration(1.0f);
	DriveRight2.SetSafetyEnabled(true);
	DriveRight2.SetExpiration(1.0f);
	float speed = (speedLeft *-1) + speedRight;
	DriveLeft1.Set(turn + speed);
	DriveLeft2.Set(turn + speed);
	DriveRight1.Set(turn - speed);
	DriveRight2.Set(turn - speed);

}

void DriveSubsystem::SetShiftState(bool state)
{
	if (state == true){
		Shift1.Set(true);
		Shift2.Set(true);
	}else if(state == false){
		Shift1.Set(false);
		Shift2.Set(false);
	}
}





// Put methods for controlling this subsystem
// here. Call these from Commands.

