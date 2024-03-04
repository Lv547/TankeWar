#pragma once
#include "IModel.h"
#include <time.h>

class ModelB:
	public IModel
{
public:
	const static int GIRD_HEIGHT = 250;
	const static int GIRD_WIDTH = 250;
	const static int TANK_RADIUS = 5;
	const static int WAVE_COUNT = 3;

private:
	Grid *_grid;
	string *_msg;

	int _wave;
	int _score;
	long _totalTime;

public:
	ModelB(void);
	~ModelB(void);

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
