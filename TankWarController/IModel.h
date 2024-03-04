#pragma once

#include "Grid.h"
#include "Information.h"
#include "Enum.h"

static const int TOP_ENIMY_COUNT = 20;

class IModel
{

public:
	IModel(void);
	~IModel(void);

	virtual Grid* GetGird() = 0;
	virtual Information* GetInformation()= 0;

	virtual void Initialization()= 0;
	virtual void Clear()= 0;

	virtual  bool IsWin()= 0;
	virtual  bool IsLose()= 0;

	virtual void FrameStart(int dertaTime, TANK_OPERATION op)= 0;
};
