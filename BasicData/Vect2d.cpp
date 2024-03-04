#include "StdAfx.h"
#include "Vect2d.h"
#include <math.h>

Vect2d::Vect2d(void)
{
	_x = _y = 0;
}

Vect2d::Vect2d( float x,float y )
{
    _x = x;
	_y = y;
}

Vect2d::Vect2d( Vect2d *val )
{
	_x = val->X();
	_y = val->Y();
}

Vect2d::~Vect2d(void)
{
}

void Vect2d::operator+( Vect2d val )
{
       _x += val.X();
	   _y += val.Y();
}

void Vect2d::operator+( Vect2d *val )
{
	_x += val->X();
	_y += val->Y();
}

bool Vect2d::operator==( Vect2d *val )
{
       return (_x==val->X() )&& (_y ==val->Y());
}

bool Vect2d::operator==( Vect2d val )
{
	   return (_x==val.X() )&& (_y ==val.Y());
}

void Vect2d::AddX( float dx )
{
    _x+=dx;
}

void Vect2d::AddY( float dy )
{
    _y+=dy;
}

float Vect2d::R()
{
     return sqrt(_x*_x + _y*_y);
}

float Vect2d::Distance( Vect2d *other )
{
	return Distance(this,other);
}

float Vect2d::Distance( Vect2d *val1,Vect2d *val2 )
{
	float dx = (val1->X()) - (val2->X());
	float dy = (val1->Y()) - (val2->Y());
	return sqrt(dx*dx + dy*dy);
}

Vect2d * Vect2d::Clone()
{
     return new Vect2d(this);
}
