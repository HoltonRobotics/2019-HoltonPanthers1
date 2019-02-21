//global variables:
const int motorPortLeft = 1;
const int motorPortRight = 3;

//global functions
//turning Right
int turnRight (int degrees) {
	int turnTicks = degrees * [number to test]; 
mav(motorPortLeft, 50);
mav(motorPortRight, -50);
msleep(turnTicks); 
return 0;
}

//turning Left
int turnLeft (int degrees) {
	int turnTicks = degrees * [number to test]; 
mav(motorPortLeft, -50);
mav(motorPortRight, 50);
msleep(turnTicks); 
return 0;
}

//moving in a straight line
int driveStraight (int centimeters) {
if (centimeters > 0) {
int forwardTicks = centimeters * [number to test]; 
mav(motorPortLeft, 50); //velocities might have to change to adjust driving straight
mav(motorPortRight, 50); //velocities might have to change to adjust driving straight
msleep(forwardTicks); 
}
else if (centimeters == 0) {
printf("did you mean to move 0 cm?");
}
else {
	int backwardTicks = -1 * centimeters * [number to test]; 
mav(motorPortLeft, -50); //velocities might have to change to adjust driving straight
mav(motorPortRight, -50); //velocities might have to change to adjust driving straight
msleep(backwardTicks); 
}
return 0; }


//main script with placeholders for cube grabber
int main (){
	//light sensor to be included later
	turnLeft(90);
	driveStraight([# centimeters to be measured. (+)]);
	turnRight(90);
	driveStraight([# centimeters to be measured. (+)]);
	turnRight(90);
	driveStraight([# centimeters to be measured. (+)]);
	//Pick up cubes
//Lift cubes
driveStraight([# centimeters to be measured. (+)]);
//Place on new stack
//Lift cubes
driveStraight([# centimeters to be measured. (+)]);
//Place on New Stack
//Lift cubes
driveStraight([# centimeters to be measured. (+)]);
//Place on new stack
//Pick up stack
turnRight(90);
driveStraight([# centimeters to be measured. (+)]);
turnRight(90);
driveStraight([# centimeters to be measured. (+)]);
//Put Stack Down
//Move somewhere to get out of the way
return 0;
}
