#include "StdAfx.h"
#include "BulletFactory.h"

BulletFactory::BulletFactory(void)
{
}

BulletFactory::~BulletFactory(void)
{
}

Bullet* BulletFactory::GetBullet( BULLET_TYPE type ,Vect2d *pos,DIRCTION dir)
{
	   Vect2d *posTmp = pos->Clone();
       switch(type)
	   {
	   case BULLET_STD:return new StandardBullet(false,posTmp,dir);break;
	   case BULLET_STD_USER:return new StandardBullet(true,posTmp,dir);break;
	   default:return NULL;
	   }
}
