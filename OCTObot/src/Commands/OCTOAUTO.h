#ifndef OCTOAUTO_H
#define OCTOAUTO_H

#include "../CommandBase.h"
#include "WPILib.h"

class OCTOAUTO: public CommandBase
{
private:
	Timer delay;
	double seconds;
	float speedx,speedy, turn;
public:
	OCTOAUTO(float speedx, float speedy, float turn, double seconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
