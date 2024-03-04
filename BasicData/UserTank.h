#pragma once
#include "tank.h"

class UserTank :
	public Tank
{
public:
	UserTank(int hp,int topHP,BULLET_TYPE bulletType,Vect2d* pos,DIRCTION dir,float spd,float r);
	~UserTank(void);

  void LoadOperation(TANK_OPERATION op);
};
