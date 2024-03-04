#pragma once

#include "Grid.h"
#include "Information.h"
#include "Enum.h"

class IView
{
public:
	IView(void);
	~IView(void);

	virtual void DisplayGrid(Grid* grid) = 0;
	virtual void DisplayInformation(Information* information) = 0;

	virtual USER_OPERATION GetUserOperation() = 0;

	virtual void Initialization() = 0;
	virtual void Clear() = 0;
};
