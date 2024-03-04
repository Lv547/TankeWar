#pragma once
#include "StandardBullet.h"

class BulletFactory
{
private:
	BulletFactory(void);
	~BulletFactory(void);

public:
	static Bullet* GetBullet( BULLET_TYPE type ,Vect2d *pos,DIRCTION dir);
};
