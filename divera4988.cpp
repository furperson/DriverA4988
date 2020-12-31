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

void Drivera::move(int step, bool direct)
{
	digitalWrite(_numpindir, direct);
	for (int i = 0; i < step; i++)
	{
		digitalWrite(_numpinstep, HIGH);
		delay(_speed);
		digitalWrite(_numpinstep, LOW);
		delay(_speed);
	}
}

void Drivera::sethome(float angle){
abszero = angle;
}

void Drivera::setspeed(int uspeed)
{
	_speed = uspeed;
}

void Drivera::setmode(bool mode)
{
	curmode = mode;
}

void Drivera::setcoors(float angle)
{
	if (angle == 360)
		angle = 0;
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

void Drivera::setangle(int angle)
{
	float angleperstep = 360 / _step;
	int nstep = (angle - curangle) / angleperstep;
	if (nstep < 0)
		nstep = 360 + nstep;

	nstep /= angleperstep;
	move(nstep, 1);
	curangle = nstep * angleperstep + curangle;
	if (curangle > 359)
		curangle = 360 - curangle;
}

void Drivera::setherezero()
{
	abszero = curangle;
}

void Drivera::linmove(float angle)
{

	float angleperstep = (float)360 / _step;
	if (!curmode)
	{ //линейное движение в относительной  системе координат
		if (angle == 360)
			angle = 0;
		int abscurangle = curangle + abszero;
		
		if (abscurangle > 359)
			abscurangle =  abscurangle - 360;
		float nstep = angle;
		if (nstep > 359)
			nstep = nstep - 360;
		if (nstep > abscurangle)
		{
			nstep = (nstep - abscurangle);
			nstep /= angleperstep;
			move((int)nstep, 1);
			curangle = curangle + (nstep * angleperstep);
			if (curangle > 359)
				curangle = curangle - 360;
		}
		else
		{
			nstep = (abscurangle - nstep);
			nstep /= angleperstep;
			move((int)nstep, 0);
			curangle = curangle - (nstep * angleperstep);
			if (curangle < 0)
				curangle = 360 + curangle;
		}
	}
	else
	{ //линейное движение в абсолютной системе координат
		moverot(angle);
	}

	
}

int Drivera::getangle()
{
	return (int)curangle;
}

void Drivera::moverot(float sangle)
{
	float angleperstep = (float)360 / _step;
	int nstep = sangle / angleperstep;
	move(nstep, 1);
	curangle = (curangle + nstep * angleperstep);
	int cofs = curangle / 360;
	curangle -= cofs * 360;
}

void Drivera::moverot(float sangle, bool direct)
{
	float angleperstep = (float)360 / _step;
	int nstep = sangle / angleperstep;
	move(nstep, direct);
	if (direct)
	{
		curangle = (curangle + nstep * angleperstep);
		int cofs = curangle / 360;
		curangle -= cofs * 360;
	}
	else
	{

		curangle = (curangle - nstep * angleperstep);
		int cofs = curangle / 360;
		curangle -= cofs * 360;
		if (curangle < 0)
			curangle = 360 + curangle;
	}
}