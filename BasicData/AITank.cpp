#include "StdAfx.h"
#include "AITank.h"

AITank::AITank( AbstractAI* ai,int hp,int topHP,BULLET_TYPE bulletType,Vect2d* pos,DIRCTION dir,float spd,float r ):
Tank(topHP,hp,bulletType,pos,dir,spd,r)
{
    _ai = ai;
}

AITank::~AITank(void)
{
	delete _ai;
	_ai = NULL;
}

void AITank::GetAIOperation()
{
	_nextOp = _ai->GetOperation(_dirction);
}


