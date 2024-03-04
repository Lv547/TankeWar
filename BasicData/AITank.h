#pragma once
#include "tank.h"
#include "AbstractAI.h"

class AITank :
	public Tank
{
protected:
	AbstractAI *_ai;
public:
	AITank(AbstractAI* ai,int hp,int topHP,BULLET_TYPE bulletType,Vect2d* pos,DIRCTION dir,float spd,float r);
	~AITank(void);

	void GetAIOperation();
};
