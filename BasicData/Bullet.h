#pragma once
#include "movecircle.h"


#ifndef ENUM_BULLET_TYPE
#define  ENUM_BULLET_TYPE
enum BULLET_TYPE
{
	BULLET_STD,
	BULLET_STD_USER
};

#endif

class Bullet :
	public MoveCircle
{
protected:
	int _damage;
	bool _isFromUser;

public:
	Bullet(bool isUser,int damage,Vect2d *pos,DIRCTION dir,float spd,float r);
	~Bullet(void);

	int Damage() const { return _damage; }
	bool IsFromUser() const { return _isFromUser; }

};
