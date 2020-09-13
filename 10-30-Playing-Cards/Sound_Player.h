#pragma once

#include <mmsystem.h>
#include <Vfw.h>
#include <Digitalv.h>

#pragma comment(lib,"winmm.lib")

//������
//#define SP_USE_SENDCOMMAND 1


class Sound_Player {
private:
	HWND hWnd;
#ifdef SP_USE_SENDCOMMAND
	MCIDEVICEID DeviceID;
#else
	LPCTSTR Alias;
#endif
public:
#ifdef SP_USE_SENDCOMMAND
	Sound_Player();
#endif
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
#ifdef SP_USE_SENDCOMMAND
	DWORD SetSpeed(DWORD Speed);
#endif
	//��������(0-1000)
	DWORD SetVolume(DWORD volume);
	//���ò��ŵ�����
#ifdef SP_USE_SENDCOMMAND
	DWORD SetCD(LPWSTR Filepath);
#else
	DWORD SetCD(LPWSTR Filepath, LPWSTR alia);
#endif
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
