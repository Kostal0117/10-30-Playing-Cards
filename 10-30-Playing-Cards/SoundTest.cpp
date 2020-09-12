// SoundTest.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "10-30-Playing-Cards.h"
#include "SoundTest.h"
#include "afxdialogex.h"

// CSoundTest �Ի���

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


// CSoundTest ��Ϣ�������


BOOL CSoundTest::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	m_Player.IniWnd(this->m_hWnd);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CSoundTest::OnBnClickedPlay()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Player.Play();
}


void CSoundTest::OnBnClickedStop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Player.Stop();
}


void CSoundTest::OnBnClickedPause()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Player.Pause();
}


void CSoundTest::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strFilter = _T("����֧���ļ�(*.mp3,*.wav,*.wma)|*.mp3;*.wav;*.wma||");
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, strFilter);

	//�����������
	if (IDOK == fileDlg.DoModal())
	{
		m_Player.SetCD(fileDlg.GetPathName());
	}
}
