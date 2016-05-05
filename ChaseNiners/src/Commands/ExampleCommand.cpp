#include "ExampleCommand.h"

ExampleCommand::ExampleCommand()
{
	Requires(driveSubsystem);
}

// Called just before this Command runs the first time
void ExampleCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ExampleCommand::Execute()
{

	driveSubsystem->Drive(oi->GetDriveLeftTrigger(), oi->GetDriveRightTrigger(),oi->GetSteering());


	if(oi->GetShiftUp())
	{
	driveSubsystem->SetShiftState(true);
	}else if(oi->GetShiftDown())
	{
	driveSubsystem->SetShiftState(false);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool ExampleCommand::IsFinished()
{
	return false;//default; doesn't end
}

// Called once after isFinished returns true
void ExampleCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExampleCommand::Interrupted()
{
	//no interruptions, no reason to use this command
}
