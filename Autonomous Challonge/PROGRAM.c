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

task main(){
	MoveDist(105,80,dia);
	motor[clawMotor] = -100;
	wait1Msec(300);
	motor[clawMotor] = -10;
	motor[armMotor] = 100;
  wait1Msec(1000);
	motor[armMotor] = 10;
	MoveDist(-20,80,dia);
  TurnRobot(90,100,dia,trc,leftMotor,rightMotor);
  MoveDist(68,50,dia);
  TurnRobot(85,130,dia,trc,leftMotor,rightMotor);
  MoveDist(100,50,dia);
  motor[armMotor] = -50;
  wait1Msec(700);
  motor[armMotor] = 10;
  motor[clawMotor] = 100;
  wait1Msec(500);
  MoveDist(-75,80,dia);
  TurnRobot(-108,90,dia,trc,leftMotor,rightMotor);
  MoveDist(45,80,dia);
  motor[clawMotor] = -100;
  wait1Msec(500);
  motor[clawMotor] = -20;
  motor[armMotor] = 100;
  wait1Msec(700);
  motor[armMotor] = 10;
  MoveDist(-50,80,dia);
  TurnRobot(90,100,dia,trc,leftMotor,rightMotor);
  MoveDist(74,100,dia);
  motor[armMotor] = -50;
  wait1Msec(700);
  motor[armMotor] = 10;
  motor[clawMotor] = 100;
  wait1Msec(500);
  motor[clawMotor] = 0;
  MoveDist(-20,100,dia);
}
