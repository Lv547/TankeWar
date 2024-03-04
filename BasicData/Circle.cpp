#include "StdAfx.h"
#include "Circle.h"

Circle::Circle(Vect2d *position,float radius)
{
	_position = position;
	_radius =radius;
}

Circle::Circle( float x,float y,float r/*=0*/ )
{
      _position = new Vect2d(x,y);
	  _radius = r;
}

Circle::~Circle(void)
{
	delete _position;
	_position = NULL;
}

bool Circle::IsImpact( Circle *other ) const
{
      return IsImpact(this,other);
}

bool Circle::IsImpact(const Circle *c1 ,const Circle *c2 )
{
	 float sumR = c1->Radius()+c2->Radius();
	 float distence =c1->Position()->Distance(c2->Position());
     return sumR>=distence;
}
