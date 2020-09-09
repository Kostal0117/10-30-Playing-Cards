#pragma once

#ifndef _TH_POKERS
#define _TH_POKERS

#include "stdafx.h"

/*-------------------------------------------------
   ���ֻ�ɫ������ѱ��
   ÿ���˿���һ��ID����ȡ�ö�Ӧ��bmp
   ���Ҷ�Ӧ��ID�������º궨��
   POKERS_��ɫ(��Ӧ��ֵ)(J,Q,K�ֱ��Ϊ11,12,13)
   ��Ȼ�������ֱ����AJQK����Щ��Ҳ�����Ƕ������
--------------------------------------------------*/

//ȡ��ID
#define POKERS_SPADE(feature) (0+(feature))
#define POKERS_HEART(feature) (14+(feature))
#define POKERS_DIAMOND(feature) (27+(feature))
#define POKERS_CLUB(feature) (40+feature)
#define POKERS_SPADE_A POKERS_SPADE(1)
#define POKERS_HEART_A POKERS_HEART(1)
#define POKERS_DIAMOND_A POKERS_DIAMOND(1)
#define POKERS_CLUB_A POKERS_CLUB(1)
#define POKERS_SPADE_J POKERS_SPADE(11)
#define POKERS_HEART_J POKERS_HEART(11)
#define POKERS_DIAMOND_J POKERS_DIAMOND(11)
#define POKERS_CLUB_J POKERS_CLUB(11)
#define POKERS_SPADE_Q POKERS_SPADE(12)
#define POKERS_HEART_Q POKERS_HEART(12)
#define POKERS_DIAMOND_Q POKERS_DIAMOND(12)
#define POKERS_CLUB_Q POKERS_CLUB(12)
#define POKERS_SPADE_K POKERS_SPADE(13)
#define POKERS_HEART_K POKERS_HEART(13)
#define POKERS_DIAMOND_K POKERS_DIAMOND(13)
#define POKERS_CLUB_K POKERS_CLUB(13)

//ͼ���С
#define POKERS_WIDTH 105
#define POKERS_HEIGHT 150
//Դͼ���ļ����
#define POKERS_ORIGINWIDTH 5565

enum Poker_Suit {Spade,Heart,Diamond,Club};

/*------------------------------------------
	�Ѵ��·�װ���˿��࣬Ŀǰ����ʵ�ֵĹ��ܣ�
	��ȡ\���õ����뻨ɫ��ȡ�õ�ǰ�˿�
	��Ӧ��bmp������ֵ�Ǹ�CBitmapָ�룩
	ʹ��ʱһ��Ҫ�ڴ�����ĳ�ʼ������
	�����IniHwnd����������Ϊ��ǰ����
	�ľ�������������˿��Ʊ�ڵĴ���
	\���ߵ���
-------------------------------------------*/
class Pokers {
private:
	int ID;
	int Feature;
	Poker_Suit Suit;
	CBitmap cbmp;
	const HWND* pwnd;
	//λͼ����
	bool BitmapCopy(CBitmap *bitmap);
	//λͼ��ȡ
	bool CutBitmap();
	//λͼ��ʼ��
	bool IniBitmap();
public:
	//����+��ɫ����
	Pokers(int Feature,Poker_Suit Suit);    
	//�˿�ID����
	Pokers(int ID=1);
	//���ƹ���
	Pokers(Pokers &p);

	//Getter
	int GetID();
	int GetFeature();
	Poker_Suit GetSuit();
	
	//Setter
	void SetID(int ID);
	void SetFeature(int Feature);
	void SetSuit(Poker_Suit Suit);
	void SetPoker(int Feature, Poker_Suit Suit);

	//λͼ��ȡ
	CBitmap* Getbitmap();
	//����λͼ(������)
	void SaveBitmap(CString strFilePath);
	//���浱ǰ���ھ��
	void IniHwnd(const HWND* hwnd);
};

#endif //_TH_POKERS