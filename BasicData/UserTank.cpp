#include "StdAfx.h"
#include "UserTank.h"

UserTank::UserTank( int hp,int topHP,BULLET_TYPE bulletType,Vect2d* pos,DIRCTION dir,float spd,float r ):
Tank(topHP,hp,bulletType,pos,dir,spd,r)
{
       _nextOp = TANK_NONE;
}

UserTank::~UserTank(void)
{
}

void UserTank::LoadOperation( TANK_OPERATION op )
{
     _nextOp = op;
}
