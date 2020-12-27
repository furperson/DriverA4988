#include "drivera4988.h"

Drivera::Drivera(int numpinstep, int numpindir, int numpinm1, int numpinm2, int numpinm3, int step, int speed, int accel) {
	_numpinstep = numpinstep;
	_numpindir = numpindir;
	_numpinm1 = numpinm1;
	_numpinm2 = numpinm2;
	_numpinm3 = numpinm3;
	_speed = speed;
	_step = step;
	_accel = accel;
	pinMode(numpinstep, OUTPUT);
	pinMode(numpindir, OUTPUT);
	pinMode(numpinm1, OUTPUT);
	pinMode(numpinm2, OUTPUT);
	pinMode(numpinm3, OUTPUT);
}
void setspeed(int uspeed) {
	_speed = uspeed;
}
void setcoors(bool mode) {
	curmode = mode;
}
void setsplitt(int splitt){
	
};
void setangle(int angle);
void linmove(int angle);
void moverot(int step);