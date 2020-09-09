#pragma once
#include "afxwin.h"
#include "Pokers.h"


// CTestDlg 对话框

class CTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
