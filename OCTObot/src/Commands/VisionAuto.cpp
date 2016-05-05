#include "VisionAuto.h"
bool aligned = false;
VisionAuto::VisionAuto()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(examplesubsystem);
}

// Called just before this Command runs the first time
void VisionAuto::Initialize()
{
	aligned = false;
    auto grip = NetworkTable::GetTable("grip");

    	    // Get published values from GRIP using NetworkTables
    auto centers = grip->GetNumberArray("targets/centerX", llvm::ArrayRef<double>());
    for (auto center : centers) {
        if(center < 130){
        	examplesubsystem->Drive(0,0.4f,0);
        } else if (center > 150){
        	examplesubsystem->Drive(0,-0.4f,0);
        } else if(center > 130 and center < 150){
        	aligned = true;
        	examplesubsystem->Drive(0,0,0);
        } else{
        	examplesubsystem->Drive(0,1,0);
        }
    }
}

// Called repeatedly when this Command is scheduled to run
void VisionAuto::Execute()
{
    auto grip = NetworkTable::GetTable("grip");
    std::cout<<aligned<<std::endl;
    	    // Get published values from GRIP using NetworkTables
    auto centers = grip->GetNumberArray("targets/centerX", llvm::ArrayRef<double>());
    for (auto center : centers) {
        if(center < 130){
        	examplesubsystem->Drive(0,0.4f,0);
        } else if (center > 150){
        	examplesubsystem->Drive(0,-0.4f,0);
        } else if(center > 130 and center < 150){
        	aligned = true;
        	examplesubsystem->Drive(0,0,0);
        } else{
        	examplesubsystem->Drive(0,1,0);
        }
    }
}

// Make this return true when this Command no longer needs to run execute()
bool VisionAuto::IsFinished()
{
	return aligned;
}

// Called once after isFinished returns true
void VisionAuto::End()
{
	examplesubsystem->Drive(0,0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void VisionAuto::Interrupted()
{
	examplesubsystem->Drive(0,0,0);
}
