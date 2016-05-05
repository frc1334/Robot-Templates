#include "AutonomousMode.h"
#include "AutonomousDriveCommand.h"
#include "Commands/WaitCommand.h"

AutonomousMode::AutonomousMode()
{
	AddSequential(new AutonomousDriveCommand(1.0f,0,1));
}
