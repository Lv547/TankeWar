#include "StdAfx.h"
#include "StandardBullet.h"

StandardBullet::StandardBullet( bool isUser,Vect2d *pos,DIRCTION dir ):Bullet(isUser,STD_BULLET_DAMAGE,pos,dir,STD_BULLET_SPEED,0)
{
    
}

StandardBullet::~StandardBullet(void)
{
}

