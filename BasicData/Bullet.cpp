#include "StdAfx.h"
#include "Bullet.h"


Bullet::Bullet( bool isUser,int damage,Vect2d *pos,DIRCTION dir,float spd,float r ):MoveCircle(pos,dir,spd,r)
{
    _isFromUser = isUser;
	_damage = damage;
}

Bullet::~Bullet(void)
{
}
