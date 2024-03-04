#pragma once
#include "circle.h"

#ifndef ENUM_DRECTION
#define  ENUM_DRECTION
enum DIRCTION
{
    DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
};

#endif

class MoveCircle :
	public Circle
{
protected:
	float _speed;
	DIRCTION _dirction;

public:
	MoveCircle(Vect2d *pos,DIRCTION dir,float spd=0,float r=0);
	MoveCircle(float x,float y,DIRCTION dir,float spd=0,float r=0);
	~MoveCircle(void);

	DIRCTION Dirction() const { return _dirction; }
	void Dirction(DIRCTION val) { _dirction = val; }

	float Speed() const { return _speed; }
	void Speed(float val) { _speed = val; }

	// just move ahead
	virtual Vect2d* NextPosition(int dertaTime);
	// just move ahead
	virtual Circle* GetNextPosition(int dertaTime);
	virtual void Operation(int dertaTime);
};
