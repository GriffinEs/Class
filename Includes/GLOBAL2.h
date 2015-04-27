

void TurnRobot(float deg, int power, float dia, float trc, tMotor leftMotor, tMotor rightMotor){
	float wc = PI*dia;
	float rc = PI*trc;
	float turnleft = sgn(deg);
	deg = abs(deg);
	float wheeldist = abs((rc*deg)/360.0);
	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;

	bool left = false;
	bool right = false;

	while(left == false && right == false){
		float distL = abs(nMotorEncoder[leftMotor]/627.2)*wc;
		float distR = abs(nMotorEncoder[rightMotor]/627.2)*wc;

		if(distL >= wheeldist){
			left = true;
			motor[leftMotor] = 0;
		} else {
			motor[leftMotor] = abs(power)*turnleft;
		}

		if(distR >= wheeldist){
			 right = true;
			 motor[rightMotor] = 0;
		} else {
			motor[rightMotor] = -abs(power)*turnleft;
		}

	}

	motor[rightMotor] = 20*turnleft;
	motor[leftMotor] = -20*turnleft;
	wait1Msec(100);
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}

void MoveDist(float cm, int power, int dia){
	float wc = PI*dia;
	int back = sgn(cm);
	cm = abs(cm)*0.9; //obligatory code to make Jacqueline stop whining, remove when it's all over
	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;

	bool left = false;
	bool right = false;

	while(left == false && right == false){
		float distL = abs(nMotorEncoder[leftMotor]/627.2)*wc;
		float distR = abs(nMotorEncoder[rightMotor]/627.2)*wc;

		if(distL >= cm){
			left = true;
			motor[leftMotor] = 0;
		} else {
			motor[leftMotor] = abs(power)*back;
		}

		if(distR >= cm){
			right = true;
			motor[rightMotor] = 0;
		} else {
			motor[rightMotor] = abs(power)*back;
		}
	}

	motor[leftMotor] = -10*back;
	motor[rightMotor] = -10*back;
	wait1Msec(100);
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}



/*
task killswitch(){ 						// The task to listen for the killswitch to be pressed and stop the program if it is.
	while(1){ 									// do this forever, unless it's stopped by itself
		if(SensorValue[dgtl1]){		// If the killswitch (port 1) is pressed, then
			stopAllTasks();					// stop all tasks (this one and task main).
		}
	}
}*/
