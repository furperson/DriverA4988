#pragma once
#include <Arduino.h>

class Drivera
{
public:
	Drivera(int numpinsteps, int numpindirs, int numpinm1s, int numpinm2s, int numpinm3s, int steps, int speeds, int accel,int minspeed); // конструктор класса
	void setspeed(int uspeed);//установить скорость
	void setmode(bool mode);// установить систему координат( 0 - относительная система координат , 1 - абсолютная система координат)
	void setsplitt(int splitt);// установить микрошаг
	void setangle(int angle);// поворот до опр. угла (от 0 до 360)
	void moverot(float sangle);// поворот на определеный угол(от 0 до int) в сторону 1
	void moverot(float sangle, bool direct);// поворот на определеный угол(от 0 до int) в опр. сторону (0,1)
	void linmove(float angle);// линейное движение
	void setcoors(float angle);// утсановить текущие координаты
	void move(int step, bool direct);// движение на опр. кол-во шагов
	void setherezero(); //установка текущей координаты как дом
	int getangle();// получить текущий реальный угол
	void sethome(float angle);
	void setaccel(int naccel);
private:
int minspeed;
int accel;
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
