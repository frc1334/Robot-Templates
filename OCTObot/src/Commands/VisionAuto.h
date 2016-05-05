#ifndef VisionAuto_H
#define VisionAuto_H

#include "../CommandBase.h"
#include "WPILib.h"

class VisionAuto: public CommandBase
{
public:
	VisionAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
