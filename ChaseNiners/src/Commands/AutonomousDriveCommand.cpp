#include "AutonomousDriveCommand.h"


AutonomousDriveCommand::AutonomousDriveCommand(float drive, float turn, double time)
{
	Requires(driveSubsystem);
	timer = new Timer();
	this->throttle = drive;
	this->turn = turn;
	this->time = time;
}
void AutonomousDriveCommand::Initialize()
{
	timer->Reset();
	timer->Start();
}
void AutonomousDriveCommand::Execute()
{

}

bool AutonomousDriveCommand::IsFinished()
{
	return timer->HasPeriodPassed(time);
}

void AutonomousDriveCommand::End()
{

	timer->Stop();
	timer->Reset();
}

void AutonomousDriveCommand::Interrupted()
{
	timer->Stop();
	timer->Reset();
}
