#include "AUTOGROUP.h"
#include "OCTOAUTO.h"
#include "VisionAuto.h"

AUTOGROUP::AUTOGROUP()
{

	AddSequential(new OCTOAUTO(0,0,1,1));
    /*auto grip = NetworkTable::GetTable("grip");

    	    // Get published values from GRIP using NetworkTables
    auto centers = grip->GetNumberArray("targets/centerX", llvm::ArrayRef<double>());


    for (auto center : centers) {
        if(center < 130){

        } else if (center > 150){

        } else if(center > 130 and center < 150){

        } else{

        }
    }*/

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
