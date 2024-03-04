#include "StdAfx.h"
#include "TankFactory.h"

TankFactory::TankFactory(void)
{
}

TankFactory::~TankFactory(void)
{
}

Tank * TankFactory::GetTank( TANK_TYPE type,Vect2d *pos,DIRCTION dir,float r)
{
	switch(type)
	{
	case TANK_USER: return GetUserTank(pos,dir,r);break;
	case TANK_AI_STD:return GetStdAITank(pos,dir,r);break;
	default:return NULL;
	}
}

UserTank * TankFactory::GetUserTank( Vect2d *pos,DIRCTION dir,float r)
{
     return new UserTank(USER_TANK_TOP_HP,USER_TANK_TOP_HP,BULLET_STD_USER,pos,dir,USERTANK_SPEED,r);
}

AITank * TankFactory::GetStdAITank( Vect2d *pos,DIRCTION dir,float r)
{
  return new AITank(new StandardAI(),AI_TANK_TOP_HP,AI_TANK_TOP_HP,BULLET_STD,pos,dir,AITANK_SPEED,r);
}

