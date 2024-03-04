#include "StdAfx.h"
#include "Information.h"

Information::Information(void)
{
	_msg = NULL;
	_alertMsg = NULL;
	_score =0;
	_userHp = 0;
	_playTime = 0;
	_enemyCount = 0;
}

Information::~Information(void)
{
	delete _msg;
	delete _alertMsg;
}
