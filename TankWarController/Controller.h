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
// ���ǵ����ֲ�ͬ��ϵͳ��go����Ϊ����û�м�ʱ���ĳ����������У���ֻ������go���Զ�����ѭ��
// �����Դ�ѭ�����Ƶ�ϵͳ����MFC��ͨ���ⲿ����TimerTick����ʵ��֡ѭ��
//////////////////////////////////////////////////////////////////////////
	//************************************
	// Method:    Go
	// FullName:  Controller::Go
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// go����Ϊ����û�м�ʱ���ĳ����������У���ֻ������go���Զ�����ѭ��
	//************************************
	void Go();
	//************************************
	// Method:    TimerTick
	// FullName:  Controller::TimerTick
	// Access:    public 
	// Returns:   bool ��Ϸ�Ƿ���Լ���ִ��
	// Qualifier:
	// Parameter: int dertaTime ʱ���
	// �����Դ�ѭ�����Ƶ�ϵͳ����MFC��ͨ���ⲿ����TimerTick����ʵ��֡ѭ��
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
