// TankWarMFCDlg.h : ͷ�ļ�
//

#pragma once

#include "Controller.h"
#include "ModelB.h"
#include "afxwin.h"
#include "afxcmn.h"

// CTankWarMFCDlg �Ի���
class CTankWarMFCDlg : public CDialog,public IView
{
public:
	static const int TIMER_SPAN = 50;//ʱ����

// ����
public:
	CTankWarMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CTankWarMFCDlg();

// �Ի�������
	enum { IDD = IDD_TANKWARMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

private: 
	Controller *_gameController;
	USER_OPERATION _userOP;
	CBrush *_aiTank;
	CBrush *_userTank;
	CBrush *_bullet;
	Grid *_grid;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();

	afx_msg void OnBnClickedBtnHaltContinue();
	afx_msg void OnBnClickedBtnStartStop();
	afx_msg void OnBnClickedBtnExit();

	DECLARE_MESSAGE_MAP()

public:
	// ʵ��IView���麯��
	virtual void Clear();
	virtual void Initialization();
	virtual void DisplayGrid( Grid* grid );
	virtual void DisplayInformation( Information* information );
	virtual USER_OPERATION GetUserOperation();

private:
   void  SetUserOperation(USER_OPERATION op);
   void DrawUserTank(CDC *pDc,float hStep,float wStep,Tank* tank);
   void DrawAiTank(CDC *pDc,float hStep,float wStep,list<AITank*> *tankList);
   void DrawBullet(CDC *pDc,float hStep,float wStep,list<Bullet*> *bulletList);
   void OnKeyDown(UINT nChar);
   
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	 
	CStatic LabTime;
	CStatic LabScore;
	CProgressCtrl PrsHP;
	CProgressCtrl PrsEnimy;
};
