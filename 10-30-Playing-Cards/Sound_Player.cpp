
#include "stdafx.h"
#include "Sound_Player.h"

#ifdef SP_USE_SENDCOMMAND
Sound_Player::Sound_Player()
{
	DeviceID = NULL;
}

Sound_Player::~Sound_Player()
{
	mciSendCommand(DeviceID, MCI_CLOSE, MCI_WAIT, NULL);
}

DWORD Sound_Player::Play(DWORD PlayPos)
{
	MCI_PLAY_PARMS mciPlay;
	mciPlay.dwFrom = PlayPos;
	mciPlay.dwCallback = (DWORD) hWnd;
	DWORD mcireturn = mciSendCommand(DeviceID,MCI_PLAY,MCI_FROM|MCI_NOTIFY,(DWORD)LPVOID(&mciPlay));
	if (mcireturn) { ShowError(mcireturn);}
	return mcireturn;
}

DWORD Sound_Player::Resume()
{

	DWORD mcireturn = mciSendCommand(DeviceID, MCI_RESUME, NULL, NULL);
	if (mcireturn) { ShowError(mcireturn); }
	return mcireturn;
}

DWORD Sound_Player::SetCD(LPWSTR Filepath)
{
	MCI_OPEN_PARMS mciOpen;
	if (DeviceID!=NULL) { mciSendCommand(DeviceID, MCI_CLOSE, NULL, NULL);}
	mciOpen.dwCallback = NULL;
	mciOpen.lpstrAlias = NULL;
	mciOpen.lpstrDeviceType = NULL;
	mciOpen.lpstrElementName = Filepath;
	DWORD mcireturn = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);
	if (mcireturn) {
		ShowError(mcireturn);
		DeviceID = NULL;
	}
	else {
		DeviceID = mciOpen.wDeviceID;
	}
	return mcireturn;
}

DWORD Sound_Player::Length()
{
	MCI_STATUS_PARMS mciStatus;
	mciStatus.dwItem = MCI_STATUS_LENGTH;
	DWORD mcireturn = mciSendCommand(DeviceID, MCI_STATUS, MCI_WAIT | MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatus);
	if (mcireturn) { ShowError(mcireturn); }
	return mciStatus.dwReturn;
}

void Sound_Player::IniWnd(HWND hwnd)
{
	if (hWnd == NULL) { hWnd = hwnd; }
}

void Sound_Player::ShowError(DWORD error)
{
	TCHAR Errorbuf[MAXERRORLENGTH];
	MessageBeep(MB_ICONEXCLAMATION);
	if (mciGetErrorString(error, (LPWSTR)Errorbuf, MAXERRORLENGTH)) {
		MessageBox(hWnd, Errorbuf, _T("MCI Error"), MB_ICONEXCLAMATION);
	}else {
		MessageBox(hWnd, _T("Unknown Error"),_T("MCI Error"),MB_ICONEXCLAMATION);
	}
}

DWORD Sound_Player::RepeatPlay()
{
	MCI_PLAY_PARMS mciPlay;
	mciPlay.dwCallback = (DWORD)hWnd;
	DWORD mcireturn = mciSendCommand(DeviceID, MCI_DGV_PLAY_REPEAT, MCI_FROM | MCI_NOTIFY, (DWORD)LPVOID(&mciPlay));
	if (mcireturn) { ShowError(mcireturn); }
	return mcireturn;
}

DWORD Sound_Player::Stop()
{
	MCI_PLAY_PARMS mciPlay;
	return mciSendCommand(DeviceID,MCI_CLOSE,NULL,(DWORD)LPVOID(&mciPlay));
}

DWORD Sound_Player::Pause()
{
	DWORD mcireturn = mciSendCommand(DeviceID, MCI_PAUSE, NULL, NULL);
	if (mcireturn) { ShowError(mcireturn); }
	return mcireturn;
}

DWORD Sound_Player::SetSpeed(DWORD Speed)
{
	MCI_SET_PARMS mciSet;
	mciSet.dwTimeFormat = Speed;
	DWORD mcireturn=mciSendCommand(DeviceID,MCI_SET,MCI_SET_TIME_FORMAT,(DWORD)&mciSet);
	if (mcireturn) { ShowError(mcireturn); }
	return mcireturn;
}

DWORD Sound_Player::SetVolume(DWORD volume)
{
	MCI_DGV_SETAUDIO_PARMS mciDSet;
	if (volume > 1000) { volume = 1000; }
	else if (volume < 0) { volume = 0; }
	mciDSet.dwCallback = NULL;
	mciDSet.dwItem = MCI_DGV_SETAUDIO_VOLUME;
	mciDSet.dwValue = volume;
	DWORD mcireturn = mciSendCommand(DeviceID, MCI_SETAUDIO, MCI_DGV_SETAUDIO_ITEM | MCI_DGV_SETAUDIO_VALUE, (DWORD)(LPVOID)&mciDSet);
	if (mcireturn) { ShowError(mcireturn); }
	return mcireturn;
}
#else

Sound_Player::~Sound_Player()
{
	CString command;
	command.Format(_T("close %s"),Alias);
	mciSendString(command.GetBuffer(),NULL,NULL,NULL);
}

DWORD Sound_Player::Play(DWORD PlayPos)
{
	CString command;
	command.Format(_T("play %s from %u"),Alias,PlayPos);
	DWORD mcireturn = mciSendString(command.GetBuffer(),NULL, NULL,NULL);
	if (mcireturn) { ShowError(mcireturn); }
	return mcireturn;
}

DWORD Sound_Player::Resume()
{
	CString command;
	command.Format(_T("resume %s"), Alias);
	DWORD mcireturn = mciSendString(command.GetBuffer(), NULL, NULL, NULL);
	if (mcireturn) { ShowError(mcireturn); }
	return mcireturn;
}

DWORD Sound_Player::SetCD(LPWSTR Filepath,LPWSTR alia)
{
	TCHAR errBuff[MAXERRORLENGTH];
	CString text;
	text.Format(_T("open %s alias %s"), Filepath,alia);
	DWORD mcireturn = mciSendString(text, errBuff, MAXERRORLENGTH, NULL);
	if (mcireturn) { ShowError(mcireturn); }
	return mcireturn;
}

DWORD Sound_Player::Length()
{
	TCHAR mcilen[MAXERRORLENGTH];
	CString command;
	command.Format(_T("Status %s length"),Alias);
	DWORD len;
	DWORD mcireturn = mciSendString(command,mcilen,MAXERRORLENGTH,NULL);
	if (mcireturn) { ShowError(mcireturn); }
	return len=_ttol(mcilen);
}

void Sound_Player::IniWnd(HWND hwnd)
{
	if (hWnd == NULL) { hWnd = hwnd; }
}

void Sound_Player::ShowError(DWORD error)
{
	TCHAR Errorbuf[MAXERRORLENGTH];
	MessageBeep(MB_ICONEXCLAMATION);
	if (mciGetErrorString(error, (LPWSTR)Errorbuf, MAXERRORLENGTH)) {
		MessageBox(hWnd, Errorbuf, _T("MCI Error"), MB_ICONEXCLAMATION);
	}
	else {
		MessageBox(hWnd, _T("Unknown Error"), _T("MCI Error"), MB_ICONEXCLAMATION);
	}
}

DWORD Sound_Player::RepeatPlay()
{
	CString command;
	command.Format(_T("play %s repeat"), Alias);
	DWORD mcireturn = mciSendString(command.GetBuffer(),NULL,NULL,NULL);
	if (mcireturn) { ShowError(mcireturn); }
	return mcireturn;
}

DWORD Sound_Player::Stop()
{
	CString command;
	command.Format(_T("stop %s"), Alias);
	return mciSendString(command.GetBuffer(),NULL, NULL,NULL);
}

DWORD Sound_Player::Pause()
{
	CString command;
	command.Format(_T("pause %s"), Alias);
	DWORD mcireturn = mciSendString(command.GetBuffer(), NULL, NULL, NULL);
	if (mcireturn) { ShowError(mcireturn); }
	return mcireturn;
}

DWORD Sound_Player::SetVolume(DWORD volume)
{
	MCI_DGV_SETAUDIO_PARMS mciDSet;
	if (volume > 1000) { volume = 1000; }
	else if (volume < 0) { volume = 0; }
	CString command;
	command.Format(_T("Status %s volume to %u"), Alias,volume);
	DWORD mcireturn = mciSendString(command.GetBuffer(),NULL,NULL,NULL);
	if (mcireturn) { ShowError(mcireturn); }
	return mcireturn;
}

#endif