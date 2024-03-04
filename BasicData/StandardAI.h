#pragma once
#include "abstractai.h"
#include "Tank.h"

class StandardAI :
	public AbstractAI
{
public:
	StandardAI(void);
	~StandardAI(void);

	virtual TANK_OPERATION GetOperation(DIRCTION dir);
};
