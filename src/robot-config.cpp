#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor frontRight = motor(PORT9, ratio18_1, true);
motor frontLeft = motor(PORT10, ratio18_1, false);
motor backRight = motor(PORT4, ratio18_1, true);
motor backLeft = motor(PORT8, ratio18_1, false);
motor arm = motor(PORT18, ratio18_1, true);
motor tray = motor(PORT5, ratio18_1, false);
motor rightIntake = motor(PORT3, ratio18_1, false);
motor leftIntake = motor(PORT19, ratio18_1, true);
controller Controller1 = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}