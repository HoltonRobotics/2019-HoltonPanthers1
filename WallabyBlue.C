#include <kipr/botball.h>

// Created on Sat Mar 2 2019
void forward(double inches) {
	double centimeters = inches * 2.54 * 1.73;
	double diameter = 6.94; //cm
	int ticks = centimeters/(3.14*diameter) * 1100;
	mrp(0, 500, ticks);
	mrp(1, 500, ticks*100/103); //IF NOT GOING STRAIGHT CHANGE TICKS NOT VELOCITY
	bmd(0); //right
	bmd(1); //left
    ao();
}
void turnLeft(double degrees) {
    printf("start turning\n");
	double seconds = degrees/360*6.3;
	mav(0, 507);
	mav(1, -500);
    msleep(seconds*1000);
	ao();
    printf("done turning\n");
} 
void turnRight(double degrees) {
	printf("start turning\n");
	double seconds = degrees/360*6.3;
	mav(0, -500);
	mav(1, 507);
    msleep(seconds*1000);
	ao();
    printf("done turning\n");
}
void slow_close_servo(int servo, int position) {
    while (get_servo_position(servo) <= position) {
		msleep(5);
        int newPos = get_servo_position(servo)+5;
        set_servo_position(servo, newPos);     
    }
}
void align() {
    printf("align \n");
    while (analog(0)<3600) { //top hat
        motor(0, 30);
    }
    ao();
    msleep(100);
    forward(-1);
    //set_servo_position(2, LOWER_CLAW);
}
int main() 
{
    wait_for_light(2);
    printf("I see the light! \n");
    shut_down_in(118);
    
    
	const int RAISE_FULL = 450;
    const int RAISE_WITH_BLOCKS = 1200;
    const int LOWER_CLAW = 1480;
    const int LOWER_CLAW_TO_STACK = 1280;
    const int OPEN_CLAW = 1500;
    const int CLOSE_CLAW = 1936;
    
    //Start facing right w/ claw open and up
    enable_servos();
    
	printf("close Claw \n");
    	msleep(500);
		set_servo_position(1, CLOSE_CLAW);
    
	printf("Raise claw\n");
    	msleep(500);
		set_servo_position(2, RAISE_FULL);
    
	printf("Forward 22 in\n");
    	msleep(500);
		forward(22);
    
    printf("Raise claw\n");
    	msleep(500);
		set_servo_position(2, RAISE_FULL);
    
	printf("Turn right\n");
    	msleep(500);
		turnRight(90); //TAPE AFFECTS TURN
    
	printf("Forward until reaches tape\n");
    	msleep(500);
    	while (analog(0)<3000) {
            printf("%d", analog(0));
            printf("\n");
			mav(0, 507);
            mav(1, 500);
        }
    	ao();
    	forward(2);
    
    printf("Turn right\n");
    	msleep(500);
		turnRight(100); //TAPE AFFECTS TURN
    
    printf("Backward 1 in\n");
    	msleep(500);
		forward(-1); 
    
    //repeat to pick up stacks
	printf("pick up poms\n");
    int i=0;
	while (i<4) {
        if (i!=0) { //goes forward each time except for when picking up first stack
        	printf("go forward 13.125 in\n");
        		msleep(500);
				forward(13.125);
            
        }
        align();
        /*//knocks off pom
        printf("turn right 25\n");
        	msleep(200);
        	turnRight(25);
        printf("raise claw\n");
       		msleep(200);
			set_servo_position(2, RAISE_WITH_BLOCKS); //raise claw
        printf("turn left 50");
        	msleep(500);
        	turnLeft(50);
        printf("turn right 25");
        	msleep(200);
       		turnRight(25);
        */
        //stack blocks
        printf("lower claw to stack\n");
        	msleep(500);
        	set_servo_position(2, LOWER_CLAW_TO_STACK);//lower claw
		printf("open claw\n");
        	msleep(500);
        	set_servo_position(1, OPEN_CLAW); //open claw
        printf("lower claw\n");
        	msleep(500);
			set_servo_position(2, LOWER_CLAW);//lower claw
        printf("close claw\n");
        	msleep(500);
			slow_close_servo(1, CLOSE_CLAW); //close claw
        printf("raise claw\n");
        	msleep(500);
			set_servo_position(2, RAISE_WITH_BLOCKS-20); //raise claw
        i++;
	}
	
	printf("Turn left 90\n");
    	msleep(500);
		turnLeft(90);
	
	printf("Forward 9in\n");
    	msleep(1000);
		forward(9);
	
	printf("Turn left 90\n");
    	msleep(1000);
		turnLeft(90);
	
	printf("Forward 6in");
    	msleep(1000);
		forward(6);
	
	msleep(1000);
    set_servo_position(2, LOWER_CLAW); //lower claw
    msleep(1000);
	set_servo_position(1, OPEN_CLAW); //open claw
    
    
    ao();
	
	return 0;
}
