// TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "10-30-Playing-Cards.h"
#include "TestDlg.h"
#include "afxdialogex.h"


// CTestDlg 对话框

IMPLEMENT_DYNAMIC(CTestDlg, CDialogEx)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST, pParent)
	, m_Suit(_T(""))
	, m_Feature(_T(""))
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FEATURECOMBO, m_Fcomb);
	DDX_Control(pDX, IDC_SUITCOMBO, m_Scomb);
	DDX_Control(pDX, ID_POKERPIC, m_Pokerpic);
	DDX_CBString(pDX, IDC_SUITCOMBO, m_Suit);
	DDX_CBString(pDX, IDC_FEATURECOMBO, m_Feature);
	DDX_Control(pDX, IDC_PIC, m_PIC);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
//	ON_CBN_SELCHANGE(IDC_FEATURECOMBO, &CTestDlg::OnSelchangeFeaturecombo)
//	ON_CBN_SELCHANGE(IDC_SUITCOMBO, &CTestDlg::OnSelchangeSuitcombo)
ON_BN_CLICKED(IDC_BUTTON1, &CTestDlg::OnClickedButton1)
END_MESSAGE_MAP()


// CTestDlg 消息处理程序


//void CTestDlg::OnSelchangeFeaturecombo()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//	int F;
//	if (m_Feature == _T("A")) { F = 1; }
//	else if (m_Feature == _T("J")) { F = 11; }
//	else if (m_Feature == _T("Q")) { F = 12; }
//	else if (m_Feature == _T("K")) { F = 13; }
//	else { F = _ttoi(m_Feature); }
//	m_Poker.SetFeature(F);
//	m_Pokerpic.SetBitmap((HBITMAP)(m_Poker.Getbitmap()));
//	m_Poker.SaveBitmap(_T("Test5.bmp"));
//}


//void CTestDlg::OnSelchangeSuitcombo()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
//	Poker_Suit s;
//	if (m_Suit == _T("黑桃")) { s = Spade; }
//	else if (m_Suit == _T("红心")) { s = Heart; }
//	else if (m_Suit == _T("方块")) { s = Diamond; }
//	else { s = Club; }
//	m_Poker.SetSuit(s);
//	m_Pokerpic.SetBitmap((HBITMAP)(m_Poker.Getbitmap()));
//	m_Poker.SaveBitmap(_T("Test5.bmp"));
//}


BOOL CTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_Scomb.InsertString(0,_T("黑桃"));
	m_Scomb.InsertString(1,_T("红心"));
	m_Scomb.InsertString(2,_T("方块"));
	m_Scomb.InsertString(3,_T("梅花"));
	m_Scomb.SetCurSel(0);

	CString temp;
	m_Fcomb.InsertString(0, _T("A"));
	for (int i = 2; i <= 10; i++) {
		temp.Format(_T("%d"), i);
		m_Fcomb.InsertString(i-1,temp);
	}
	m_Fcomb.InsertString(10, _T("J"));
	m_Fcomb.InsertString(11, _T("Q"));
	m_Fcomb.InsertString(12, _T("K"));
	m_Fcomb.SetCurSel(0);

	m_Suit = _T("黑桃");
	m_Feature = _T("A");

	m_PIC.ModifyStyle(SS_ENHMETAFILE, SS_BITMAP | SS_CENTERIMAGE);
	
	m_PIC.SetBitmap((HBITMAP)(*m_Poker.Getbitmap()));
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CTestDlg::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	
	Poker_Suit s;
	if (m_Suit == _T("黑桃")) { s = Spade; }
	else if (m_Suit == _T("红心")) { s = Heart; }
	else if (m_Suit == _T("方块")) { s = Diamond; }
	else { s = Club; }
	
	int F;
	if (m_Feature == _T("A")) { F = 1; }
	else if (m_Feature == _T("J")) { F = 11; }
	else if (m_Feature == _T("Q")) { F = 12; }
	else if (m_Feature == _T("K")) { F = 13; }
	else { F = _ttoi(m_Feature); }
	m_Poker.SetPoker(F,s);

	m_PIC.SetBitmap((HBITMAP)(*m_Poker.Getbitmap()));
	UpdateData(FALSE);
}
