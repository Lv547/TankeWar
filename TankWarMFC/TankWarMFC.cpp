// TankWarMFC.cpp : ����Ӧ�ó��������Ϊ��
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


// CTankWarMFCApp ����

CTankWarMFCApp::CTankWarMFCApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CTankWarMFCApp ����

CTankWarMFCApp theApp;


// CTankWarMFCApp ��ʼ��

BOOL CTankWarMFCApp::InitInstance()
{
	CWinApp::InitInstance();

	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CTankWarMFCDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}
