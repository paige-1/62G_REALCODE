/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       pageclancy                                                */
/*    Created:      Wed Jan 15 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// frontRight           motor         9               
// frontLeft            motor         10              `
// backRight            motor         4               
// backLeft             motor         8                
// arm                  motor         18              
// tray                 motor         5               
// rightIntake          motor         3               
// leftIntake           motor         19              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

competition Competition;

 void driveForwards (double distance) {

frontLeft.startSpinFor(directionType::fwd, distance, rotationUnits::raw, 30,velocityUnits::pct);
backLeft.startSpinFor(directionType::fwd, distance, rotationUnits::raw, 30,velocityUnits::pct);
frontRight.startSpinFor(directionType::fwd, distance, rotationUnits::raw, 30,velocityUnits::pct);
backRight.spinFor(directionType::fwd, distance, rotationUnits::raw, 30,velocityUnits::pct);

 }
void driveReverse (double distance) {
frontLeft.startSpinFor(directionType::rev, distance, rotationUnits::raw, 30,velocityUnits::pct);
backLeft.startSpinFor(directionType::rev, distance, rotationUnits::raw, 30,velocityUnits::pct);
frontRight.startSpinFor(directionType::rev, distance, rotationUnits::raw, 30,velocityUnits::pct);
backRight.spinFor(directionType::rev, distance, rotationUnits::raw, 30,velocityUnits::pct);

}

void turnRight (double left, double right) {
 frontLeft.startSpinFor(directionType::fwd, left, rotationUnits::raw, 30,velocityUnits::pct);
 backLeft.startSpinFor(directionType::fwd, left, rotationUnits::raw, 30,velocityUnits::pct);
 frontRight.startSpinFor(directionType::rev, right, rotationUnits::raw, 30,velocityUnits::pct);
 backRight.spinFor(directionType::rev, right, rotationUnits::raw, 30,velocityUnits::pct);


}

void turnLeft (double left, double right) {
 frontLeft.startSpinFor(directionType::rev, left, rotationUnits::raw, 30,velocityUnits::pct);
 backLeft.startSpinFor(directionType::rev, left, rotationUnits::raw, 30,velocityUnits::pct);
 frontRight.startSpinFor(directionType::fwd, right, rotationUnits::raw, 30,velocityUnits::pct);
 backRight.spinFor(directionType::fwd, right, rotationUnits::raw, 30,velocityUnits::pct);


}

void stack () {
  double trayheight;
  double speed;

}


void autonomus (void) 
{


  rightIntake.setBrake(brakeType::hold);
  leftIntake.setBrake(brakeType::hold);
  arm.setBrake(brakeType::hold);
  tray.setBrake(brakeType::hold);
  arm.resetRotation();
  tray.resetRotation();
  
    frontRight.spin(vex::directionType::rev,50, vex::percentUnits::pct);
    frontLeft.spin(vex::directionType::rev,50, vex::percentUnits::pct);
    backRight.spin(vex::directionType::rev,50, vex::percentUnits::pct);
    backLeft.spin(vex::directionType::rev,50, vex::percentUnits::pct);  

    task::sleep(3000);

    frontRight.spin(vex::directionType::fwd,50, vex::percentUnits::pct);
    frontLeft.spin(vex::directionType::fwd,50, vex::percentUnits::pct);
    backRight.spin(vex::directionType::fwd,50, vex::percentUnits::pct);
    backLeft.spin(vex::directionType::fwd,50, vex::percentUnits::pct);  

    task::sleep(3000);
    
    frontRight.stop();
    frontLeft.stop();
    backRight.stop();
    backLeft.stop();

/**
Brain.resetTimer();
while(Brain.timer(timeUnits::sec)<5)
{
  rightIntake.spin(vex::directionType::rev,100,percentUnits::pct);
  leftIntake.spin(vex::directionType::rev,100,percentUnits::pct);

}
 
 arm.spinTo(500, rotationUnits::raw, 100, velocityUnits::pct);
 
 task::sleep (300);

 arm.spinTo(0, rotationUnits::raw, 100, velocityUnits::pct);

 task::sleep(300);

  rightIntake.spin(vex::directionType::fwd,100,percentUnits::pct);
  leftIntake.spin(vex::directionType::fwd,100,percentUnits::pct);

 driveForwards (2500);

 task::sleep(300);

 turnRight(300,300);

task::sleep(300);

 driveForwards (2500);
  */
 }


/*int driveTask()
{
   while(true)
   {
     double lpower=Controller1.Axis3.value();
     double rpower=Controller1.Axis2.value();
     lpower=lpower * 12.0 / 127; 
     rpower=rpower * 12.0/127;

     frontRight.spin(vex::directionType::fwd,rpower,vex::voltageUnits::volt);
     backRight.spin(vex::directionType::fwd,rpower,vex::voltageUnits::volt);
     frontLeft.spin(vex::directionType::fwd,lpower,vex::voltageUnits::volt);
     backLeft.spin(vex::directionType::fwd,lpower,vex::voltageUnits::volt);
     
     vex::task::sleep(2);

      //printf("%6.6f\n",arm.rotation(rotationUnits::raw));

   }

   return 0 ; 
   
}*/
bool first=true;
/*int everythingElse()
{
  while (true)
  {
    if(Controller1.ButtonR1.pressing()) //intake
    {
      rightIntake.spin(directionType::fwd,100,percentUnits::pct);
      leftIntake.spin(directionType::fwd,100,percentUnits::pct);
    }

    else if (Controller1.ButtonR2.pressing()) //outtake
    {
      rightIntake.spin(directionType::rev,100,percentUnits::pct);
      leftIntake.spin(directionType::rev,100,percentUnits::pct);
    }

    else if (Controller1.ButtonLeft.pressing()) //arms up 
    {
      tray.startSpinTo(-2000,rotationUnits::raw,100,velocityUnits::pct);
      arm.spin(directionType::fwd,35,percentUnits::pct);
    }

    else if (Controller1.ButtonDown.pressing()) //arms down
    {
      tray.startSpinTo(0,rotationUnits::raw,100,velocityUnits::pct);
      arm.spin(directionType::rev,100,percentUnits::pct);
    }
    
    else if(Controller1.ButtonL1.pressing()) //lift tray
    {
      tray.spin(directionType::fwd, 100, percentUnits::pct);
      if(tray.rotation(rotationUnits::raw)>1000)
      {
        rightIntake.spin(directionType::fwd,30,percentUnits::pct);
        leftIntake.spin(directionType::fwd,30,percentUnits::pct);
      }
    }

    else if (Controller1.ButtonL2.pressing()) //lower tray
    {
        if (abs(arm.rotation(rotationUnits::raw))>3)
        {
          rightIntake.spin(directionType::rev,30,percentUnits::pct);
          leftIntake.spin(directionType::rev,30,percentUnits::pct);
          tray.spin(directionType::rev, 80, percentUnits::pct);
        }
        else tray.spin(directionType::rev, 100, percentUnits::pct);
    }
    else 
    {
      rightIntake.stop();
      leftIntake.stop();
      tray.stop();
      arm.stop();
    }
    task::sleep(20);
  }


}*/
   





void usercontrol (void)
{
  rightIntake.setBrake(brakeType::hold);
  leftIntake.setBrake(brakeType::hold);
  arm.setBrake(brakeType::hold);
  tray.setBrake(brakeType::hold);


  while(true)
  {
    //vex::task d(driveTask);
    //vex::task e(everythingElse);
    double lpower=Controller1.Axis3.value();
     double rpower=Controller1.Axis2.value();
     lpower=lpower * 12.0 / 127; 
     rpower=rpower * 12.0/127;

     frontRight.spin(vex::directionType::fwd,rpower,vex::voltageUnits::volt);
     backRight.spin(vex::directionType::fwd,rpower,vex::voltageUnits::volt);
     frontLeft.spin(vex::directionType::fwd,lpower,vex::voltageUnits::volt);
     backLeft.spin(vex::directionType::fwd,lpower,vex::voltageUnits::volt);
     
     vex::task::sleep(2);

     if(Controller1.ButtonR1.pressing()) //intake
    {
      rightIntake.spin(directionType::fwd,100,percentUnits::pct);
      leftIntake.spin(directionType::fwd,100,percentUnits::pct);
    }

    else if (Controller1.ButtonR2.pressing()) //outtake
    {
      rightIntake.spin(directionType::rev,100,percentUnits::pct);
      leftIntake.spin(directionType::rev,100,percentUnits::pct);
    }

    else if (Controller1.ButtonUp.pressing()) //arms up 
    {
      tray.startSpinTo(-1500,rotationUnits::raw,100,velocityUnits::pct);
      arm.spin(directionType::fwd,35,percentUnits::pct);
      
  
    }
    else if (Controller1.ButtonLeft.pressing())
    {
      tray.startSpinTo(-1500,rotationUnits::raw,100,velocityUnits::pct);
      arm.spin(directionType::fwd,50,percentUnits::pct);
    }

    else if (Controller1.ButtonDown.pressing()) //arms down
    {
      tray.startSpinTo(0,rotationUnits::raw,100,velocityUnits::pct);
      arm.spin(directionType::rev,100,percentUnits::pct);
    }
    
    else if(Controller1.ButtonL1.pressing()) //lift tray
    {
      tray.spin(directionType::fwd, 100, percentUnits::pct);
    
    }

    else if (Controller1.ButtonL2.pressing()) //lower tray
    {
      tray.spin(directionType::rev, 100, percentUnits::pct);
    }
    else
    {
      rightIntake.stop();
      leftIntake.stop();
      tray.stop();
      arm.stop();
    }
  }
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
Competition.drivercontrol(usercontrol);
Competition.autonomous(autonomus);

while(1) {
    vex::task::sleep(100);

}

}
