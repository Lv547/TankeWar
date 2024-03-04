#pragma once

#include "IView.h"
#include <stdio.h>


class ConsoleView :
	public IView
{
public:
	ConsoleView(void);
	~ConsoleView(void);

	virtual void DisplayGrid( Grid* grid );

	virtual void DisplayInformation( Information* information );

	virtual USER_OPERATION GetUserOperation();

	virtual void Initialization();

	virtual void Clear();

};
