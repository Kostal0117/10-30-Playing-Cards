#pragma once

#include <mmsystem.h>
#include <Vfw.h>
#include <Digitalv.h>

#pragma comment(lib,"winmm.lib")

//�豸���� ��SP_+�ļ���׺������
#define SP_WAV (LPCTSTR)MCI_DEVTYPE_WAVEFORM_AUDIO


class Sound_Player {
private:
	HWND hWnd;
	UINT DeviceID;
public:
	Sound_Player();
	~Sound_Player();
	
	//���º�������DWORD:����0Ϊ�������򷵻ص�Ϊ������Ϣ
	//(��Posλ��)����
	DWORD Play(DWORD PlayPos=0);
	//��������
	DWORD Resume();
	//ֹͣ����
	DWORD Stop();
	//��ͣ����
	DWORD Pause();
	//���ò����ٶ�
	DWORD SetSpeed(DWORD Speed);
	//��������(0-1000)
	DWORD SetVolume(DWORD volume);
	//���ò��ŵ�����
	DWORD SetCD(const CString &Filepath);
	//��ȡ���ֳ���
	DWORD Length();
	//���ô��ھ��
	void IniWnd(HWND hwnd);
	//��ʾ����
	void ShowError(DWORD error);
	//ѭ������
	DWORD RepeatPlay();
	//��ȡ��ǰ����λ��
	DWORD GetCurrentPos();
};
