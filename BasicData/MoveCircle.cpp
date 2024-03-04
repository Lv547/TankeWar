#include "StdAfx.h"
#include "MoveCircle.h"

MoveCircle::MoveCircle( Vect2d *pos,DIRCTION dir,float spd/*=0*/,float r/*=0*/ ):Circle(pos,r)
{
      _dirction = dir;
      _speed = spd;
}

MoveCircle::MoveCircle( float x,float y,DIRCTION dir,float spd/*=0*/,float r/*=0*/ ):Circle(x,y,r)
{
	_dirction = dir;
	_speed = spd;
}

MoveCircle::~MoveCircle(void)
{
	
}

Vect2d* MoveCircle::NextPosition( int dertaTime )
{
	Vect2d *pos=_position->Clone();
	float d = _speed*dertaTime; // user this for MFC view
	//float d = 1 ;//test for console view 
    
     switch(_dirction)
	 {
	 case DIR_LEFT     :pos->AddX(-d);break;
	 case DIR_RIGHT  :pos->AddX( d) ;break;
	 case DIR_UP       :pos->AddY(-d) ;break;
	 case DIR_DOWN :pos->AddY( d) ;break;
	 }

	return pos;
}


Circle* MoveCircle::GetNextPosition(int dertaTime)
{
    Vect2d *pos = NextPosition(dertaTime);
	 return new Circle(pos,_radius);
}

void MoveCircle::Operation( int dertaTime )
{
      Vect2d *tmp = _position;// remeber old pointer
      _position = NextPosition(dertaTime);// give pointer new value;
	  delete tmp;// delete old pointer
}

