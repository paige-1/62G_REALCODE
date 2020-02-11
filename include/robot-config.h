using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor frontRight;
extern motor frontLeft;
extern motor backRight;
extern motor backLeft;
extern motor arm;
extern motor tray;
extern motor rightIntake;
extern motor leftIntake;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );