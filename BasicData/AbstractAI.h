#pragma once
#include "Tank.h"

class AbstractAI
{
public:
	AbstractAI(void);
	~AbstractAI(void);

	virtual TANK_OPERATION GetOperation(DIRCTION dir)=0;
};
