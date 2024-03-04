// TankWarMFCDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TankWarMFC.h"
#include "TankWarMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



CTankWarMFCDlg::CTankWarMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTankWarMFCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	_userTank = new CBrush(RGB(0,200,0));
	_aiTank = new CBrush(RGB(0,0,200));
	_bullet = new CBrush(RGB(200,0,0));

	// new game
	_gameController = new Controller(this,new ModelB());
	_userOP = USER_NONE;
	_grid = NULL;
}

CTankWarMFCDlg::~CTankWarMFCDlg()
{
	CDialog::~CDialog();
}



void CTankWarMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LAB_TIME, LabTime);
	DDX_Control(pDX, IDC_LAB_SCORE, LabScore);
	DDX_Control(pDX, IDC_PRS_HP, PrsHP);
	DDX_Control(pDX, IDC_PRS_ENIMY, PrsEnimy);

	PrsHP.SetRange(0,USER_TANK_TOP_HP);
	PrsEnimy.SetRange(0,TOP_ENIMY_COUNT);
}

BEGIN_MESSAGE_MAP(CTankWarMFCDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BTN_HALT_CONTINUE, &CTankWarMFCDlg::OnBnClickedBtnHaltContinue)
	ON_BN_CLICKED(IDC_BTN_START_STOP, &CTankWarMFCDlg::OnBnClickedBtnStartStop)
	ON_BN_CLICKED(IDC_BTN_EXIT, &CTankWarMFCDlg::OnBnClickedBtnExit)
END_MESSAGE_MAP()


//////////////////////////////////////////////////////////////////////////
//  事件
//////////////////////////////////////////////////////////////////////////

void CTankWarMFCDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(!_gameController->TimerTick(TIMER_SPAN))
		this->OnCancel();

	__super::OnTimer(nIDEvent);
	
	_userOP = USER_NONE;

}
void CTankWarMFCDlg::OnClose()
{
	KillTimer(1);
	delete _gameController;
	__super::OnClose();
}


BOOL CTankWarMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	SetTimer(1,TIMER_SPAN,NULL);// 启动计时器

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTankWarMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();

		if(_grid!=NULL) 
		{
			CWnd *wnd = GetDlgItem(IDC_PIC_MAIN);
			CPaintDC dc(wnd);

			CRect rect;
			wnd->GetClientRect(&rect);

			float hStep = rect.Height()/(float)_grid->Height();
			float wStep = rect.Width()/(float)_grid->Width();

			DrawAiTank(&dc,hStep,wStep,_grid->AiTankList());
			DrawUserTank(&dc,hStep,wStep,_grid->User());
			DrawBullet(&dc,hStep,wStep,_grid->BulletList());

			wnd->RedrawWindow();
		}
		
	}
}

// 按钮

void CTankWarMFCDlg::OnBnClickedBtnHaltContinue()
{
	 SetUserOperation(USER_HALT_CONTINUE);
}

void CTankWarMFCDlg::OnBnClickedBtnStartStop()
{
	 SetUserOperation(USER_START_STOP);
}

void CTankWarMFCDlg::OnBnClickedBtnExit()
{
	SetUserOperation(USER_EXIT);
}


//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTankWarMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//////////////////////////////////////////////////////////////////////////
//实现 IView 的虚函数
//////////////////////////////////////////////////////////////////////////

void CTankWarMFCDlg::DisplayGrid( Grid* grid )
{
	if (!_grid)
		_grid = grid;

	CRect rect;
	CWnd *wnd = GetDlgItem(IDC_PIC_MAIN);
	wnd->GetClientRect(&rect);
	InvalidateRect(rect);
}

void CTankWarMFCDlg::DisplayInformation( Information* information )
{
	 if (information->AlertMsg())
	 {  
		 CString alertMsg(information->AlertMsg()->c_str()) ;
		 AfxMessageBox(alertMsg);
	 }
     else
	 {
	    
		 // information->Msg();
		 PrsHP.SetPos(information->UserHp());
		 PrsEnimy.SetPos(information->EnemyCount());
         
		 CString time;
		 time.Format(L"%d",information->PlayTime());
		 LabTime.SetWindowText(time);

		 CString score;
		 time.Format(L"%d",information->Score());
		 LabScore.SetWindowText(time);
		 
	 }
}

USER_OPERATION CTankWarMFCDlg::GetUserOperation()
{
	return _userOP;
}

void CTankWarMFCDlg::Initialization()
{
	_grid = NULL;
	CRect rect;
	CWnd *wnd = GetDlgItem(IDC_PIC_MAIN);
	wnd->GetClientRect(&rect);
	InvalidateRect(rect);
}

void CTankWarMFCDlg::Clear()
{
	_grid = NULL;
	CRect rect;
	CWnd *wnd = GetDlgItem(IDC_PIC_MAIN);
	wnd->GetClientRect(&rect);
	InvalidateRect(rect);
}


//////////////////////////////////////////////////////////////////////////
// 工具函数
//////////////////////////////////////////////////////////////////////////

void CTankWarMFCDlg::SetUserOperation( USER_OPERATION op )
{
	  // 用户已经退出，不响应
      if (_userOP==USER_EXIT) return;
      
	  //如果当前是系统操作，只接受系统操作
	  if (Controller::IsSystemOperation(_userOP)&&!Controller::IsSystemOperation(op)) return;

	   _userOP = op;

}

void CTankWarMFCDlg::DrawAiTank( CDC *pDc,float hStep,float wStep,list<AITank*> *tankList )
{
    pDc->SelectObject(_aiTank);

	for(list<AITank*>::iterator iter = tankList->begin();iter!=tankList->end();iter++)
	{
        AITank *t = (*iter);

		Vect2d *pos = t->Position();
		 float r = t->Radius();

		 float x = pos->X();
		 float y = pos->Y();

		 int x1 = (x-r)*wStep;
		 int x2 = (x+r)*wStep;
		 int y1 = (y-r)*hStep;
		 int y2 = (y+r)*hStep;

		 pDc->Ellipse(x1,y1,x2,y2);
	}
}

void CTankWarMFCDlg::DrawBullet( CDC *pDc,float hStep,float wStep,list<Bullet*> *bulletList )
{
	pDc->SelectObject(_bullet);

	for(list<Bullet*>::iterator iter = bulletList->begin();iter!=bulletList->end();iter++)
	{
		Bullet *t = (*iter);

		Vect2d *pos = t->Position();
		float r = 1;

		float x = pos->X();
		float y = pos->Y();

		int x1 = (x-r)*wStep;
		int x2 = (x+r)*wStep;
		int y1 = (y-r)*hStep;
		int y2 = (y+r)*hStep;

		pDc->Ellipse(x1,y1,x2,y2);
	}
}

void CTankWarMFCDlg::DrawUserTank( CDC *pDc,float hStep,float wStep,Tank* tank )
{
    pDc->SelectObject(_userTank);

	Vect2d *pos = tank->Position();
	float r = tank->Radius();

	float x = pos->X();
	float y = pos->Y();

	int x1 = (x-r)*wStep;
	int x2 = (x+r)*wStep;
	int y1 = (y-r)*hStep;
	int y2 = (y+r)*hStep;

	pDc->Ellipse(x1,y1,x2,y2);
}

BOOL CTankWarMFCDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message==WM_KEYDOWN)
		OnKeyDown((UINT)pMsg->wParam);
	
    return FALSE;
}

void CTankWarMFCDlg::OnKeyDown(UINT nChar)
{
	switch(nChar)
	{
	case 'w':case'W':SetUserOperation(USER_UP) ;break;	
	case 's' :case'S':SetUserOperation(USER_DOWN)  ;break;
	case 'a' :case'A':SetUserOperation(USER_LEFT) ;break;
	case 'd' :case'D':SetUserOperation(USER_RIGHT) ;break;
	case 'l'  :case'L':SetUserOperation(USER_FIRE) ;break;
	}
}
