//global functions
//turning right (+) or left (-)
int turn (double degrees) {
set_create_angle(0);
double createAngle = get_create_angle(0);
if (degrees > 0) {
	while (createAngle < degrees) {
		create_drive_direct(50, -50);
msleep(100); //might need to adjust interval depending on accuracy
create_stop();
createAngle = get_create_distance(0);
}
} 
else if (degrees  == 0) {
printf("did you mean to turn 0 degrees?");
}
else {
	double negativeDeg = -1*degrees
while (createAngle < negativeDeg) {
create_drive_direct(-50, 50); //vs might need to change to go straight
msleep(100);
create_stop();
createAngle = get_create_distance(0);
}
}

return 0; }
//moving straight forward (+) or backward (-)
int straight (double millimeters) {
set _create_distance(0);
double createDistancemm = get_create_distance(0);
if (millimeters > 0) {
while (createDistancemm < millimeters) {
create_drive_direct(50, 50); //vs might need to change to go straight
msleep(100);
create_stop();
createDistancemm = get_create_distance(0);
}
}
else if (millimeters == 0) {
printf("did you mean to move 0 mm?");
}
else {
	double negativeMm = -1*millimeters
while (createDistancemm < negativeMm) {
create_drive_direct(-50, -50); //vs might need to change to go straight
msleep(100);
create_stop();
createDistancemm = get_create_distance([arg necessary?, if so use 0 to start]);
}
}
return 0;
}

//main script does the stuff
int main () {
//light sensor stuff to be added later
create_connect();
straight([# mm (+)]);
turn(-90);
straight([# mm (+)]);
turn(-90);
straight([# mm (+)]);
turn(90);
straight([# mm (+)]);
turn(90);
straight([# mm (+)]);
turn([# degrees (+)]); //angle unknown
//Drop poms in coupler
create_disconnect();
return 0; }
