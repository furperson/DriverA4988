#include "drivera4988.h"

Drivera::Drivera(int numpinstep, int numpindir, int numpinm1, int numpinm2, int numpinm3, int step, int speed, int accel)
{
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
void Drivera::setspeed(int uspeed)
{
	_speed = uspeed;
}
void Drivera::setcoors(bool mode)
{
	curmode = mode;
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
void Drivera::setangle(int angle){};
void Drivera::linmove(int angle){};
void Drivera::moverot(int step){};