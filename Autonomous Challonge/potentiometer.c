#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    lineFollower,   sensorLineFollower)
#pragma config(Sensor, in2,    potentionmeter, sensorPotentiometer)
#pragma config(Sensor, dgtl1,  button,         sensorTouch)
#pragma config(Sensor, I2C_1,  leftEncoder,    sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  rightEncoder,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port2,           clawMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           armMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop, reversed, encoderPort, I2C_2)

#include <GLOBAL2.h>
#define dia 10.6
#define trc 35.5
//up:1130
//down:350
int armpos = 1000;

task arm(){
	while(1){
		motor[armMotor] = armpos-SensorValue(potentionmeter)+5;
	}
}

task main(){
	startTask(arm);
}
