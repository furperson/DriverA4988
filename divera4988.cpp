#include "drivera4988.h"

Drivera::Drivera(int numpinsteps, int numpindirs, int numpinm1s, int numpinm2s, int numpinm3s, int steps, int speeds, int accels, int minspeeds) : numpinstep{numpinsteps},
																																				   numpindir{numpindirs}, numpinm1{numpinm1s}, numpinm2{numpinm2s}, numpinm3{numpinm3s}, speed{speeds}, step{steps}, accel{accels}, minspeed{minspeeds}
{

	pinMode(numpinstep, OUTPUT);
	pinMode(numpindir, OUTPUT);
	pinMode(numpinm1, OUTPUT);
	pinMode(numpinm2, OUTPUT);
	pinMode(numpinm3, OUTPUT);
	digitalWrite(numpinm1, LOW);
	digitalWrite(numpinm2, LOW);
	digitalWrite(numpinm3, LOW);
}

void Drivera::move(int steps, bool direct)
{
	digitalWrite(numpindir, direct);
	int nowstep = steps * mnsplitt;
	int nowspeed = minspeed;
	int nst = (minspeed - speed) / accel;
	if (nst > nowstep / 2)
		nst = steps / 2;
	int connst = nowstep - nst;
	for (int i = 0; i < nowstep; i++)
	{
		if (i < nst)
			nowspeed -= accel;
		if (i >= connst)
			nowspeed += accel;
		digitalWrite(numpinstep, HIGH);
		delay(nowspeed);
		digitalWrite(numpinstep, LOW);
		delay(nowspeed);
	}
}

void Drivera::sethome(float angle)
{
	abszero = angle;
}

void Drivera::setspeed(int uspeed)
{
	speed = uspeed;
}

void Drivera::setaccel(int accelsd)
{
	accel = accelsd;
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
			step / 2;
		}
	}
	else
	{
		for (int i = 0; i <= splitt - cursplitt; i++)
		{
			step * 2;
		}
	}
	cursplitt = splitt;
	switch (cursplitt)
	{
	case 0:
		mnsplitt = 1;
		digitalWrite(numpinm1, LOW);
		digitalWrite(numpinm2, LOW);
		digitalWrite(numpinm3, LOW);
		break;

	case 1:
		mnsplitt = 2;
		digitalWrite(numpinm1, HIGH);
		digitalWrite(numpinm2, LOW);
		digitalWrite(numpinm3, LOW);
		break;

	case 2:
		mnsplitt = 4;
		digitalWrite(numpinm1, LOW);
		digitalWrite(numpinm2, HIGH);
		digitalWrite(numpinm3, LOW);
		break;

	case 3:
		mnsplitt = 8;
		digitalWrite(numpinm1, HIGH);
		digitalWrite(numpinm2, HIGH);
		digitalWrite(numpinm3, LOW);
		break;

	case 4:
		mnsplitt = 16;
		digitalWrite(numpinm1, HIGH);
		digitalWrite(numpinm2, HIGH);
		digitalWrite(numpinm3, HIGH);
		break;
	}
};

void Drivera::setangle(int angle)
{
	float angleperstep = (float)360 / step;
	if (angle == 360)
		angle = 0;
	float nstep = angle;
	if (nstep > 359)
		nstep = nstep - 360;
	if (nstep > curangle)
	{
		nstep = (nstep - curangle);
		nstep /= angleperstep;
		move((int)nstep, 1);
		curangle = curangle + (nstep * angleperstep);
		if (curangle > 359)
			curangle = curangle - 360;
	}
	else
	{
		nstep = (curangle - nstep);
		nstep /= angleperstep;
		move((int)nstep, 0);
		curangle = curangle - (nstep * angleperstep);
		if (curangle < 0)
			curangle = 360 + curangle;
	}
}

void Drivera::setherezero()
{
	abszero = curangle;
}

void Drivera::linmove(float angle)
{

	float angleperstep = (float)360 / step;
	if (!curmode)
	{ //линейное движение в относительной  системе координат
		if (angle == 360)
			angle = 0;
		int abscurangle = curangle + abszero;

		if (abscurangle > 359)
			abscurangle = abscurangle - 360;
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
	float angleperstep = (float)360 / step;
	int nstep = sangle / angleperstep;
	move(nstep, 1);
	curangle = (curangle + nstep * angleperstep);
	int cofs = curangle / 360;
	curangle -= cofs * 360;
}

void Drivera::moverot(float sangle, bool direct)
{
	float angleperstep = (float)360 / step;
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