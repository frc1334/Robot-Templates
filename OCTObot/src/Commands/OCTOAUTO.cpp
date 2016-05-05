#include "OCTOAUTO.h"

OCTOAUTO::OCTOAUTO(float speedx, float speedy, float turn, double seconds):
speedx(speedx),turn(turn),seconds(seconds),delay(),speedy(speedy)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void OCTOAUTO::Initialize()
{
	delay.Reset();
		delay.Start();
		examplesubsystem->Drive(speedx,turn, speedy);
}

// Called repeatedly when this Command is scheduled to run
void OCTOAUTO::Execute()
{
	examplesubsystem->Drive(speedx,turn, speedy);
}

// Make this return true when this Command no longer needs to run execute()
bool OCTOAUTO::IsFinished()
{
	return delay.HasPeriodPassed(seconds);
}

// Called once after isFinished returns true
void OCTOAUTO::End()
{
	examplesubsystem->Drive(0,0,0);
	delay.Stop();
	delay.Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OCTOAUTO::Interrupted()
{
	examplesubsystem->Drive(0,0,0);
	delay.Stop();
	delay.Reset();
}
