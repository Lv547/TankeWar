// TankWarMFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTankWarMFCApp:
// �йش����ʵ�֣������ TankWarMFC.cpp
//

class CTankWarMFCApp : public CWinApp
{
public:
	CTankWarMFCApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTankWarMFCApp theApp;