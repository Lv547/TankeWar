#pragma once
#include "bullet.h"

const int STD_BULLET_DAMAGE = 1;
const float STD_BULLET_SPEED = 0.1f;

class StandardBullet :
	public Bullet
{
public:
	StandardBullet(bool isUser,Vect2d *pos,DIRCTION dir);
	~StandardBullet(void);
};
