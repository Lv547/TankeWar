#include "StdAfx.h"
#include "Controller.h"



Controller::Controller( IView *view, IModel *model )
{
	_view = view;
	_model = model;
	_state = STATE_STOP;
}

Controller::~Controller(void)
{
	delete _view;
	delete _model;
}

void Controller::Go()
{
	// Initialization
    time_t last_time = clock();

	// run
	while(_state!=STATE_ESC)
	{
		// time
		time_t this_time = clock();
		int derta_time = this_time - last_time;
	  	last_time = this_time;

		//user operation
		USER_OPERATION op = _view->GetUserOperation();
		LoopOperation(op, derta_time);
	}
}

bool Controller::TimerTick( int dertaTime )
{
	USER_OPERATION op = _view->GetUserOperation();
	LoopOperation(op, dertaTime);

	if(_state!=STATE_ESC) return true;
	else return false;//用户选择退出
}


void Controller::HandleSysOperation( USER_OPERATION op )
{
    if (!IsSystemOperation(op))  return;

	switch(op)
	{
	case USER_START_STOP:StartOrStop();break;
	case USER_HALT_CONTINUE:HaltOrContinue();break;
	case USER_EXIT:Exit();break;
	}
}


void Controller::HaltOrContinue()
{
	if (_state==STATE_GO)// halt
	{
		_state = STATE_HALT;
	} 
	else if(_state==STATE_HALT) // continue
	{
		_state = STATE_GO;
	}
}

void Controller::StartOrStop()
{
	if (_state==STATE_STOP) // start
	{
		_state = STATE_GO;
		_model->Initialization();
		_view->Initialization();
	} 
	else // stop
	{
		_state = STATE_STOP;
		_model->Clear();
		_view->Clear();
	}
}

void Controller::Exit()
{
	_state = STATE_ESC;
}

TANK_OPERATION Controller::UserOpToTankOp(USER_OPERATION op)
{
	switch(op)
	{
	case USER_NONE: return TANK_NONE;
	case USER_UP: return TANK_UP;
	case USER_LEFT:return TANK_LEFT;
	case USER_RIGHT:return TANK_RIGHT;
	case USER_DOWN:return TANK_DOWN;
	case USER_FIRE:return TANK_FIRE;
	default: return TANK_NONE;
	}
}

bool Controller::IsSystemOperation(USER_OPERATION op)
{
	return( op==USER_START_STOP)||(op==USER_EXIT)||(op==USER_HALT_CONTINUE);
}

void Controller::LoopOperation( USER_OPERATION op, int derta_time )
{
	HandleSysOperation(op);//handle sys op

	string *alert = NULL;
	if(_state==STATE_GO)
	{
		_model->FrameStart(derta_time,UserOpToTankOp(op));// frame go
		if (_model->IsLose()) alert = new string("GAME OVER!");
		if (_model->IsWin()) alert = new string("YOU WIN!");
		if (_model->IsLose()||_model->IsWin())	StartOrStop();
	}
	Information *information = _model->GetInformation();
	information->AlertMsg(alert);

	_view->DisplayInformation(information); // information
	_view->DisplayGrid(_model->GetGird()); // draw grid

	delete information;
}

