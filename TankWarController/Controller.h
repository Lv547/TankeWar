#pragma once

#include "IModel.h"
#include "IView.h"
#include "Enum.h"
#include <time.h>

class Controller
{
private:
	IView *_view;
	IModel *_model;
	GAME_STATE _state; 

public:
	Controller(IView *view, IModel *model);
	~Controller(void);

//////////////////////////////////////////////////////////////////////////
// 考虑到两种不同的系统，go函数为那种没有计时器的程序（如命令行），只需启动go就自动进入循环
// 对于自带循环机制的系统，如MFC，通过外部调用TimerTick函数实现帧循环
//////////////////////////////////////////////////////////////////////////
	//************************************
	// Method:    Go
	// FullName:  Controller::Go
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// go函数为那种没有计时器的程序（如命令行），只需启动go就自动进入循环
	//************************************
	void Go();
	//************************************
	// Method:    TimerTick
	// FullName:  Controller::TimerTick
	// Access:    public 
	// Returns:   bool 游戏是否可以继续执行
	// Qualifier:
	// Parameter: int dertaTime 时间差
	// 对于自带循环机制的系统，如MFC，通过外部调用TimerTick函数实现帧循环
	//************************************
	bool TimerTick(int dertaTime);
//////////////////////////////////////////////////////////////////////////

	static TANK_OPERATION UserOpToTankOp(USER_OPERATION op);
	static bool IsSystemOperation(USER_OPERATION op);

private:
	void LoopOperation( USER_OPERATION op, int derta_time );
	void HandleSysOperation(USER_OPERATION op);

	void HaltOrContinue();
	void StartOrStop();
	void Exit();
};
