#pragma once
#include <Arduino.h>

class Drivera
{
public:
	Drivera(int numpinsteps, int numpindirs, int numpinm1s, int numpinm2s, int numpinm3s, int steps, int speeds); // конструктор класса
	void setspeed(int uspeed);
	void setmode(bool mode);
	void setsplitt(int splitt);
	void setangle(int angle);
	void moverot(float sangle);
	void moverot(float sangle, bool direct);
	void linmove(float angle);
	void setcoors(float angle);
	void move(int step, bool direct);
	void setherezero(); //установка текущей координаты как дом
	int getangle();
	void sethome(float angle);

private:
	int abszero = 0;	// координата дома относительной системы координат
	int step;			// шагов на один оборот
	int numpinstep;	//пин для связи с драйвером
	int numpindir;		//пин направления
	int numpinm1;		//пин м1 драйвера
	int numpinm2;		//пин м2 драйвера
	int numpinm3;		//пин м3 драйвера
	float curangle = 0; //угол поворота на данный момент
	int speed;			//скорость вращения
	bool curmode = 0;	// 0 - относительная система координат , 1 - абсолютная система координат
	int cursplitt = 0;	// 0 - 1 , 1 - 1/2 , 2 - 1/4 , 3 - 1/8 , 4 - 1/16 режимы микрошага
	int mnsplitt = 1;
};
