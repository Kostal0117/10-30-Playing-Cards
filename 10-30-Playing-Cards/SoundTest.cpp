// SoundTest.cpp : 实现文件
//

#include "stdafx.h"
#include "10-30-Playing-Cards.h"
#include "SoundTest.h"
#include "afxdialogex.h"

// CSoundTest 对话框

IMPLEMENT_DYNAMIC(CSoundTest, CDialogEx)

CSoundTest::CSoundTest(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SOUNDTEST, pParent)
	, m_strCD(_T(""))
{

}

CSoundTest::~CSoundTest()
{
}

void CSoundTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSoundTest, CDialogEx)
	ON_BN_CLICKED(IDC_PLAY, &CSoundTest::OnBnClickedPlay)
	ON_BN_CLICKED(IDC_STOP, &CSoundTest::OnBnClickedStop)
	ON_BN_CLICKED(IDC_PAUSE, &CSoundTest::OnBnClickedPause)
	ON_BN_CLICKED(IDC_BUTTON1, &CSoundTest::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSoundTest 消息处理程序


BOOL CSoundTest::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	m_Player.IniWnd(this->m_hWnd);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CSoundTest::OnBnClickedPlay()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Player.Play();
}


void CSoundTest::OnBnClickedStop()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Player.Stop();
}


void CSoundTest::OnBnClickedPause()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Player.Pause();
}


void CSoundTest::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strFilter = _T("所有支持文件(*.mp3,*.wav,*.wma)|*.mp3;*.wav;*.wma||");
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, strFilter);

	//如果已正常打开
	if (IDOK == fileDlg.DoModal())
	{
		m_Player.SetCD(fileDlg.GetPathName());
	}
}
