#pragma once
#include <Arduino.h>

class Drivera{
public:
 Drivera(int numpinstep,int numpindir,int numpinm1,int numpinm2,int numpinm3, int step, int speed); // конструктор класса 
 void setspeed(int uspeed);
 void setmode(bool mode);
 void setsplitt(int splitt);
 void setangle(int angle);
 void moverot(int sangle);
 void moverot(int sangle, bool direct);
 void linmove(float angle, bool direct);
 void linmove(float angle);
 void setcoors(int angle);
 void move(int step, bool direct); 
 void setherezero(); //установка текущей координаты как дом

private : 
	int abszero = 0; // координата дома относительной системы координат 
	int _step; // шагов на один оборот
	int _numpinstep; //пин для связи с драйвером
	int _numpindir; //пин направления
	int _numpinm1; //пин м1 драйвера
	int _numpinm2; //пин м2 драйвера
	int _numpinm3; //пин м3 драйвера
	float curangle = 0;//угол поворота на данный момент
	int _speed; //скорость вращения
	bool curmode = 0;// 0 - относительная система координат , 1 - абсолютная система координат
	int cursplitt = 0;// 0 - 1 , 1 - 1/2 , 2 - 1/4 , 3 - 1/8 , 4 - 1/16 режимы микрошага
};
