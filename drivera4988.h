#pragma once
#include <Arduino.h>

Class Drivera{
public:
 Drivera(int numpinstep,int numpindir,int numpinm1,int numpinm2,int numpinm3, int step, int speed,int accel); // конструктор класса 
 void setspeed(int uspeed);
 void setcoors(bool mode);
 void setsplitt(int splitt);
 void setangle(int angle);
 void linmove(int angle);
 void moverot(int step);


private : 
	int _accel;
	int _step;
	int _numpinstep;	
	int _numpindir;
	int _numpinm1;
	int _numpinm2;
	int _numpinm3; 
	int curangle = 0;
	int _speed;
	bool curmode = 0;// 0 - относительная система координат , 1 - абсолютная система координат
	int cursplitt = 0;// 0 - 1 , 1 - 1/2 , 2 - 1/4 , 3 - 1/8 , 4 - 1/16 режимы микрошага
};
