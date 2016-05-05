#ifndef SRC_COMMANDS_AUTONOMOUSDRIVECOMMAND_H_
#define SRC_COMMANDS_AUTONOMOUSDRIVECOMMAND_H_
#include "../CommandBase.h"

class AutonomousDriveCommand: public CommandBase
{
private:
	Timer* timer;
	float throttle, turn;
	double time;
public:
	AutonomousDriveCommand(float throttle, float turn, double time);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
