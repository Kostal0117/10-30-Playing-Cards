
#include "stdafx.h"
#include "Pokers.h"
#include "resource.h"

/*
#include "TestDlg.h"


这种实现方式太复杂了，我们已经不需要了
void Pokers::SaveBitmap(CString strFilePath)
{
	IniBitmap();
	CutBitmap();
	if (cbmp.m_hObject)
	{
		CImage imgTemp;      
		imgTemp.Attach(cbmp.operator HBITMAP());
		imgTemp.Save(strFilePath);
	}
}

void Pokers::IniHwnd(const HWND * hwnd)
{
	pwnd = hwnd;
}

bool Pokers::BitmapCopy(CBitmap * bitmap)
{
	cbmp.DeleteObject();
	BITMAP tempbm;
	bitmap->GetBitmap(&tempbm);
	PBYTE pBits = new BYTE[tempbm.bmWidth*tempbm.bmHeight];
	bitmap->GetBitmapBits(tempbm.bmWidth*tempbm.bmHeight,pBits);
	cbmp.CreateBitmap(tempbm.bmWidth,tempbm.bmHeight,tempbm.bmPlanes,tempbm.bmBitsPixel,pBits);
	delete[] pBits;
	return false;
}

bool Pokers::CutBitmap()
{
	if (pwnd == NULL) { return false; }
	HDC hDc = CreateCompatibleDC(NULL);
	SelectObject(hDc, cbmp);
	HDC pDC = GetDC(*pwnd);
	HDC hdcDest = CreateCompatibleDC(hDc);

	HBITMAP ret = CreateCompatibleBitmap(pDC,POKERS_WIDTH,POKERS_HEIGHT);
	SelectObject(hdcDest, ret);
	BitBlt(hdcDest, 0, 0, POKERS_WIDTH, POKERS_HEIGHT, hDc, (ID - 1)*POKERS_WIDTH, 0, SRCCOPY);
	ReleaseDC(*pwnd, pDC);
	DeleteDC(hDc);
	cbmp.DeleteObject();
	cbmp.Attach(ret);
	return true;
}

bool Pokers::IniBitmap()
{
	cbmp.DeleteObject();
	return cbmp.LoadBitmap(IDB_BITMAPPOK256);
}
*/
Pokers::Pokers(int Feature, Poker_Suit Suit)
{
	this->Feature = Feature;
	SetSuit(Suit);
}

Pokers::Pokers(int ID)
{
	SetID(ID);
}

Pokers::Pokers(Pokers & p)
{
	ID = p.ID;
	Feature = p.Feature;
	Suit = p.Suit;
	//BitmapCopy(&p.cbmp);
}

int Pokers::GetID()
{
	return ID;
}

int Pokers::GetFeature()
{
	return Feature;
}

Poker_Suit Pokers::GetSuit()
{
	return Suit;
}

void Pokers::SetID(int ID)
{
	this->ID = ID;
	Feature = (ID - 1) % 13 + 1;
	switch ((ID - 1) / 13) {
	case 0: {
		Suit = Spade;
		break;
	}
	case 1:{
		Suit = Heart;
		break;
	}
	case 2: {
		Suit = Diamond;
		break;
	}
	case 3: {
		Suit = Club;
		break;
	}
	}
}

void Pokers::SetFeature(int Feature)
{
	ID += this->Feature-Feature;
	this->Feature = Feature;
}

void Pokers::SetSuit(Poker_Suit Suit)
{
	switch (Suit) {
	case Spade: {
		ID = POKERS_SPADE(Feature);
		break;
	}
	case Heart:{
		ID = POKERS_HEART(Feature);
		break;
	}
	case Diamond:{
		ID = POKERS_DIAMOND(Feature);
		break;
	}
	case Club:{
		ID = POKERS_CLUB(Feature);
		break;
	}
	}
}

void Pokers::SetPoker(int Feature, Poker_Suit Suit)
{
	this->Feature=Feature;
	switch (Suit) {
	case Spade: {
		ID = POKERS_SPADE(Feature);
		break;
	}
	case Heart: {
		ID = POKERS_HEART(Feature);
		break;
	}
	case Diamond: {
		ID = POKERS_DIAMOND(Feature);
		break;
	}
	case Club: {
		ID = POKERS_CLUB(Feature);
		break;
	}
	}
}

CBitmap * Pokers::Getbitmap()
{
	//IniBitmap();
	//CutBitmap();
	cbmp.DeleteObject();
	cbmp.LoadBitmapW(POKERS_IDH(ID));
	return &cbmp;
}
