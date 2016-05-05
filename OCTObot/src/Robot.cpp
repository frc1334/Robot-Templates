#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/AUTOGROUP.h"
#include <unistd.h>

class Robot: public IterativeRobot
{
private:
	Command* examplecommand;
	CommandGroup* AUTO;
	IMAQdxSession session;
	Image *frame;
	IMAQdxError imaqError;

	void RobotInit()
	{
		CommandBase::init();
		examplecommand = new ExampleCommand();
		frame = imaqCreateImage(IMAQ_IMAGE_HSL, 0);


						imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);

						if(imaqError != IMAQdxErrorSuccess) {
									DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
								}
								imaqError = IMAQdxConfigureGrab(session);
								if(imaqError != IMAQdxErrorSuccess) {
									DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
								}
								AUTO = new AUTOGROUP();
							    if (fork() == 0) {
							            system("/home/lvuser/grip &");
							    }
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
		/* std::string autoSelected = SmartDashboard::GetString("Auto Selector", "Default");
		if(autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		} else {
			autonomousCommand.reset(new ExampleCommand());
		} */
		AUTO->Start();
	}

	void AutonomousPeriodic()
	{

	        auto grip = NetworkTable::GetTable("grip");

	        /* Get published values from GRIP using NetworkTables */
	        auto areas = grip->GetNumberArray("targets/area", llvm::ArrayRef<double>());

	        for (auto area : areas) {
	            std::cout << "Got contour with area=" << area << std::endl;
	        }
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (AUTO!=NULL){
			AUTO->Cancel();
		}
		examplecommand->Start();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		IMAQdxGrab(session, frame, true, NULL);

		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
		} else {
			//imaqDrawShapeOnImage(frame, frame, { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_RECT, 1.0f);
			//imaqDrawShapeOnImage(frame, frame, { 300, 220, 340, 260 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_RECT, 1.0f);

			CameraServer::GetInstance()->SetImage(frame);
		}
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

