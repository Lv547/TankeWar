// TankWarMFC.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "TankWarMFC.h"
#include "TankWarMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTankWarMFCApp

BEGIN_MESSAGE_MAP(CTankWarMFCApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTankWarMFCApp 构造

CTankWarMFCApp::CTankWarMFCApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CTankWarMFCApp 对象

CTankWarMFCApp theApp;


// CTankWarMFCApp 初始化

BOOL CTankWarMFCApp::InitInstance()
{
	CWinApp::InitInstance();

	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CTankWarMFCDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}
