#include "drivera4988.h"

Drivera::Drivera(int numpinstep, int numpindir, int numpinm1, int numpinm2, int numpinm3, int step, int speed)
{
	_numpinstep = numpinstep;
	_numpindir = numpindir;
	_numpinm1 = numpinm1;
	_numpinm2 = numpinm2;
	_numpinm3 = numpinm3;
	_speed = speed;
	_step = step;
	pinMode(numpinstep, OUTPUT);
	pinMode(numpindir, OUTPUT);
	pinMode(numpinm1, OUTPUT);
	pinMode(numpinm2, OUTPUT);
	pinMode(numpinm3, OUTPUT);
}
void Drivera::move(int step, bool direct){
	digitalWrite(_numpindir, direct);
	for(int i = 0; i < step; i++) {
	digitalWrite(_numpinstep, HIGH);
	delay(_speed);
	digitalWrite(_numpinstep, LOW);
	delay(_speed);
	}
}
void Drivera::setspeed(int uspeed)
{
	_speed = uspeed;
}
void Drivera::setmode(bool mode)
{
	curmode = mode;
}
void Drivera::setcoors(int angle){
	curangle = angle;
}
void Drivera::setsplitt(int splitt)
{
	if (cursplitt > splitt)
	{
		for (int i = 0; i <= cursplitt - splitt; i++)
		{
			_step / 2;
		}
	}
	else
	{
		for (int i = 0; i <= splitt - cursplitt; i++)
		{
			_step * 2;
		}
	}
	cursplitt = splitt;
	switch (cursplitt)
	{
	case 0:
		digitalWrite(_numpinm1, LOW);
		digitalWrite(_numpinm2, LOW);
		digitalWrite(_numpinm3, LOW);
		break;

	case 1:
		digitalWrite(_numpinm1, HIGH);
		digitalWrite(_numpinm2, LOW);
		digitalWrite(_numpinm3, LOW);
		break;

	case 2:
		digitalWrite(_numpinm1, LOW);
		digitalWrite(_numpinm2, HIGH);
		digitalWrite(_numpinm3, LOW);
		break;

	case 3:
		digitalWrite(_numpinm1, HIGH);
		digitalWrite(_numpinm2, HIGH);
		digitalWrite(_numpinm3, LOW);
		break;

	case 4:
		digitalWrite(_numpinm1, HIGH);
		digitalWrite(_numpinm2, HIGH);
		digitalWrite(_numpinm3, HIGH);
		break;
	}
};
void Drivera::setangle(int angle){

}
void Drivera::linmove(float angle){
float angleperstep =360/_step;
if(!curmode){//линейное движение в относительной  системе координат
int abscurangle = curangle-abszero;
if(abscurangle <0 ) abscurangle = 360 + abscurangle;

		int nstep = (angle - curangle) ;
		if(nstep <0 ) nstep = 360 + nstep;
		nstep /= angleperstep;
		move(nstep,1);
}
else {//линейное движение в абсолютной системе координат
		int nstep = (angle - curangle) / angleperstep ;
		if(nstep <0 ) nstep = 360 + nstep;
		nstep /= angleperstep;
		move(nstep,1);
}
}

void Drivera::moverot(int step){}
