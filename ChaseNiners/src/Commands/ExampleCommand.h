#ifndef EXAMPLE_COMMAND_H
#define EXAMPLE_COMMAND_H

#include "../CommandBase.h"
#include "WPILib.h"

class ExampleCommand: public CommandBase
{
private:

public:
	ExampleCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
