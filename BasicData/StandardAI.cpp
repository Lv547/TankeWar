#include "StdAfx.h"
#include "StandardAI.h"

StandardAI::StandardAI(void)
{
}

StandardAI::~StandardAI(void)
{
}

TANK_OPERATION StandardAI::GetOperation(DIRCTION dir)
{
	// 有一半的概率直行
	int isGo = rand()%2;
	if (isGo)
	{
		switch(dir)
		{
		case DIR_UP:return TANK_UP;
		case DIR_DOWN:return TANK_DOWN;
		case DIR_LEFT:return TANK_LEFT;
		case DIR_RIGHT:return TANK_RIGHT;
		}
	}

	int op = rand()%(TANK_OPERATION_COUNT);
	return TANK_OPERATION(op);
}
