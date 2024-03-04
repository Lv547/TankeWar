#pragma once
#include "IModel.h"
#include <time.h>

class ModelA :
	public IModel
{
public:
	const static int GIRD_HEIGHT = 30;
	const static int GIRD_WIDTH = 50;
	const static int TANK_RADIUS = 1;
	const static int WAVE_COUNT = 3;

private:
	Grid *_grid;
	string *_msg;
	
	int _wave;
	int _score;
	long _totalTime;

public:
	ModelA(void);
	~ModelA(void);

	Grid* GetGird();

	Information* GetInformation();

	void Initialization();

	void Clear();

	bool IsWin();

	bool IsLose();

	void FrameStart( int dertaTime, TANK_OPERATION op );

	void UserOperation( int dertaTime,TANK_OPERATION op);

	void BulletsOperation(int dertaTime);

	void TanksOperation(int dertaTime);

	void NewWave();

	bool NeedNewWave();
};
