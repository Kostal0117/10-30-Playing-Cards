
// 10-30-Playing-Cards.h : 10-30-Playing-Cards Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy1030PlayingCardsApp:
// �йش����ʵ�֣������ 10-30-Playing-Cards.cpp
//

class CMy1030PlayingCardsApp : public CWinAppEx
{
public:
	CMy1030PlayingCardsApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy1030PlayingCardsApp theApp;
