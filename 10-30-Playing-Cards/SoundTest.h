#pragma once
#include "afxwin.h"
#include "Sound_Player.h"

// CSoundTest �Ի���

class CSoundTest : public CDialogEx
{
	DECLARE_DYNAMIC(CSoundTest)

public:
	CSoundTest(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSoundTest();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SOUNDTEST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	CComboBox m_CDlist;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedPlay();
	CString m_strCD;
	afx_msg void OnBnClickedStop();
	afx_msg void OnBnClickedPause();
	Sound_Player m_Player;
	afx_msg void OnBnClickedButton1();
};
