#include <kipr/botball.h>

// Created on Sat Mar 2 2019
void turnRight(int x) {
	set_create_total_angle(0);
	while (get_create_total_angle() > -x*1.15) {
		create_drive_direct(50, -50);
    }
	create_stop();
}

void goBackward(double inches) {
    double millimeters = inches*25.4;
	set_create_distance(0);
	int distance = 0;
	while (distance > -millimeters) {
		create_drive_direct(-50, -50);
		distance = get_create_distance();
	}
	create_stop();
}
int main() 
{
	create_connect();
		//*Start left (point away from fire zone)
    
	printf("Claw open\n");
		//open claw
	
	printf("Leave start box 22.75 in = 578 mm \n");
		goBackward(22.75);
	
	printf("Turn right 90 \n");
		turnRight(90);
    
    printf("Go backwards to poms 19in = 482mm\n");
		goBackward(19);
		
	printf("Turn right 90 \n");
		turnRight(90);
			
	printf("Go backwards and collect poms 64.125in=1629mm \n");
		goBackward(64.125);
		
	printf("Close claw\n");
		//close claw
	
	printf("Turn right 90");
		turnRight(90);
    
    printf("Go backwards for 30 in = 762 mm \n");
		goBackward(30);
		
	printf("Raise claw \n");
		//raise claw
	
	printf("Open claw");
		//open claw
	
    create_disconnect();
	return 0;
}

April 1 code 
#include <kipr/botball.h>

// Created on Sat Mar 2 2019
void turnLeft(int x) {
	set_create_total_angle(0);
	while (get_create_total_angle() > -x*1.15) {
		create_drive_direct(-50, 50);
    }
	create_stop();
}

void goForward(double inches) {
    double millimeters = inches*25.4;
	set_create_distance(0);
	int distance = 0;
	while (distance > -millimeters) {
		create_drive_direct(50, 50);
		distance = get_create_distance();
	}
	create_stop();
}
int main() 
{
    wait_for_light(2);
    printf("I see the light!\n");
    
	create_connect();
		//*Start right (point towards utility zone)
	printf("Claw open\n");
		//open claw
	motor(2,0);
	printf("Leave start box 22.75 in = 578 mm \n");
		goForward(1.00);
    	msleep(1000);
	
	printf("Turn left 90 \n");
		turnLeft(90);
    
    printf("Go forwards to poms 19in = 482mm\n");
		goForward(19);
		
	printf("Turn left 90 \n");
		turnLeft(90);
			
	printf("Go forwards and collect poms 64.125in=1629mm \n");
		goForward(64.125);
		
	printf("Close claw\n");
		//close claw
	motor(2,-1000);
	printf("Turn left 90");
		turnLeft(90);
    
    printf("Go forwards for 30 in = 762 mm \n");
		goForward(-30);
		
	printf("Raise claw \n");
		//raise claw
	set_servo_position(3,1500);
	printf("Open claw");
		//open claw
	motor(2,1000);
    create_disconnect();
	return 0;
}
