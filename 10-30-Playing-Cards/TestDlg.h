#pragma once
#include "afxwin.h"
#include "Pokers.h"


// CTestDlg �Ի���

class CTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTestDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnSelchangeFeaturecombo();
//	afx_msg void OnSelchangeSuitcombo();
	virtual BOOL OnInitDialog();
	CComboBox m_Fcomb;
	CComboBox m_Scomb;
	CStatic m_Pokerpic;
	CString m_Suit;
	CString m_Feature;
	Pokers m_Poker;
	afx_msg void OnClickedButton1();
	CStatic m_PIC;
};
