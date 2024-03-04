#pragma once

#include "AITank.h"
#include "UserTank.h"
#include "StandardAI.h"

const int USER_TANK_TOP_HP = 10;
const int AI_TANK_TOP_HP = 3;

const float AITANK_SPEED = 0.03f;
const float USERTANK_SPEED = 0.06f;

class TankFactory
{
private:
	TankFactory(void);
	~TankFactory(void);

public:
	static Tank *GetTank(TANK_TYPE type,Vect2d *pos,DIRCTION dir,float r=1);

private:
	static UserTank *GetUserTank(Vect2d *pos,DIRCTION dir,float r=1);
	static AITank *GetStdAITank(Vect2d *pos,DIRCTION dir,float r=1);
};
