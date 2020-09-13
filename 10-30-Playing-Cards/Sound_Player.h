#pragma once

#include <mmsystem.h>
#include <Vfw.h>
#include <Digitalv.h>

#pragma comment(lib,"winmm.lib")

//调试用
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
	
	//以下函数返回DWORD:返回0为正常否则返回的为错误信息
	//(从Pos位置)播放
	DWORD Play(DWORD PlayPos=0);
	//继续播放
	DWORD Resume();
	//停止播放
	DWORD Stop();
	//暂停播放
	DWORD Pause();
	//设置播放速度
#ifdef SP_USE_SENDCOMMAND
	DWORD SetSpeed(DWORD Speed);
#endif
	//设置音量(0-1000)
	DWORD SetVolume(DWORD volume);
	//设置播放的音乐
#ifdef SP_USE_SENDCOMMAND
	DWORD SetCD(LPWSTR Filepath);
#else
	DWORD SetCD(LPWSTR Filepath, LPWSTR alia);
#endif
	//获取音乐长度
	DWORD Length();
	//设置窗口句柄
	void IniWnd(HWND hwnd);
	//显示错误
	void ShowError(DWORD error);
	//循环播放
	DWORD RepeatPlay();
	//获取当前播放位置
	DWORD GetCurrentPos();
};
