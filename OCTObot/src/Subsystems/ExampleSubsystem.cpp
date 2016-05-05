#include "ExampleSubsystem.h"
#include "../RobotMap.h"

ExampleSubsystem::ExampleSubsystem() :
		Subsystem("ExampleSubsystem"), MOTOR_1(1), MOTOR_2(2), MOTOR_3(3), MOTOR_4(4)
{

}

void ExampleSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void ExampleSubsystem::Drive(float speed_x, float turn, float speed_y)
{
	MOTOR_1.Set(turn + speed_x);
	MOTOR_2.Set(turn+speed_y);
	MOTOR_3.Set(turn + speed_x);
	MOTOR_4.Set(turn-speed_y);
}
