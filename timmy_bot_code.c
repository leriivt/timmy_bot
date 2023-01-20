#pragma config(Sensor, dgtl11,  jumper,         sensorDigitalIn)
#pragma config(Motor,  port1,           frontleftMotor, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           backleftMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           backrightMotor, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           intakeMotor,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           liftMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          frontrightMotor, tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	//autonstart
	//wait(10);
	
	//move forwards
	startMotor(frontleftMotor,-127);
	startMotor(backleftMotor,-127);
	startMotor(frontrightMotor,-127);
	startMotor(backrightMotor,-127);
	wait(1.3);
	stopMotor(frontleftMotor);
	stopMotor(backleftMotor);
	stopMotor(frontrightMotor);
	stopMotor(backrightMotor);
	wait(0.5);
	
	
	if(SensorValue[jumper] == 0){  //blue (jumper in)
		//turn right
		startMotor(frontleftMotor,127);
		startMotor(backleftMotor,127);
		startMotor(frontrightMotor,-127);
		startMotor(backrightMotor,-127);
		wait(0.65);
		
		//move forward
		startMotor(frontleftMotor,-127);
		startMotor(backleftMotor,-127);
		startMotor(frontrightMotor,-127);
		startMotor(backrightMotor,-127);
		wait(0.5);
		stopMotor(frontleftMotor);
		stopMotor(backleftMotor);
		stopMotor(frontrightMotor);
		stopMotor(backrightMotor);
		
		//score ball
		motor[liftMotor] = 80;
		wait(1.6);
		motor[liftMotor] = 0;

		wait(1);

		motor[liftMotor] = -80;
		wait(1.6);
		motor(liftMotor) = 0;

	}
	else{ //red (jumper out)
		//turn left
		startMotor(frontleftMotor,-127);
		startMotor(backleftMotor,-127);
		startMotor(frontrightMotor,127);
		startMotor(backrightMotor,127);
		wait(0.65);
		
		//move forward
		startMotor(frontleftMotor,-127);
		startMotor(backleftMotor,-127);
		startMotor(frontrightMotor,-127);
		startMotor(backrightMotor,-127);
		wait(0.5);
		stopMotor(frontleftMotor);
		stopMotor(backleftMotor);
		stopMotor(frontrightMotor);
		stopMotor(backrightMotor);
		
		//score ball
		motor[liftMotor] = 80;
		wait(1.6);
		motor[liftMotor] = 0;

		wait(1);

		motor[liftMotor] = -80;
		wait(1.6);
		motor(liftMotor) = 0;
		
		
		//start intake
		startMotor(intakeMotor, 127);
		
		//drive to get second ball	
		startMotor(frontleftMotor,120); //left motors are slower to try to make bot turn slightly left
		startMotor(backleftMotor,120);
		startMotor(frontrightMotor,127);
		startMotor(backrightMotor,127);
		wait(0.45);
		stopMotor(frontleftMotor);
		stopMotor(backleftMotor);
		stopMotor(frontrightMotor);
		stopMotor(backrightMotor);
		
		wait(4); //wait a few while ball intakes
		
		//drive back to scoring area
		startMotor(frontleftMotor,-120); //left motors still slower
		startMotor(backleftMotor,-120);
		startMotor(frontrightMotor,-127);
		startMotor(backrightMotor,-127);
		
		//score second ball
		motor[liftMotor] = 80;
		wait(1.6);
		motor[liftMotor] = 0;

		wait(1);

		motor[liftMotor] = -80;
		wait(1.6);
		motor(liftMotor) = 0;
		
		
	}

	//autonend
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	int intakeSpeed = 0;
	// User control code here, inside the loop

	while (true)
	{
		//remotecontrolstart

		//Right Wheels
		motor[frontrightMotor] = vexRT[Ch2];
		motor[backrightMotor]  = vexRT[Ch2];
		//Left Wheels
		motor[frontleftMotor] = vexRT[Ch3];
		motor[backleftMotor]  = vexRT[Ch3];


		//motor[frontleftMotor] = vexRT[Ch3];
		//motor[backleftMotor] = vexRT[Ch3];
		//motor[frontrightMotor] = vexRT[Ch3];
		//motor[backrightMotor] = vexRT[Ch3];

		//motor[frontleftMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
		//motor[frontrightMotor]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
		//   motor[backrightMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2
		//motor[backleftMotor] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2
		//intake
		if(vexRT[Btn5U] == 1){
			intakeSpeed = 127;
		}
		else if (vexRT[Btn5D] == 1){
			intakeSpeed = -127;
		}
		else if (vexRT[Btn7U] == 1){
			intakeSpeed = 0;
		}

		motor[intakeMotor] = intakeSpeed;

		//if(vexRT[Btn5U] == 1)
		//{
		//	motor[intakeMotor] = 127;
		//}
		//else if(vexRT[Btn5D] == 1)q
		//{
		//	motor[intakeMotor] = -127;
		//}
		//else
		//{
		//	motor[intakeMotor] = 0;
		//}

		//lift
		if(vexRT[Btn6U] == 1)
		{
			motor[liftMotor] = 127;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[liftMotor] = -127;
		}
		else
		{
			motor[liftMotor] = 0;
		}

		//Special Buttons
		if(vexRT[Btn7L] == 1)
		{
			motor[liftMotor] = 80;
			wait(1.6);
			motor[liftMotor] = 0;

			wait(1);

			motor[liftMotor] = -80;
			wait(1.6);
			motor(liftMotor) = 0;
		}
		//Special Buttons End
		//remotecontrolend
	}
}
