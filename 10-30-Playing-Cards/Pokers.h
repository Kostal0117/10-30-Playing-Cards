#pragma once

#include "stdafx.h"
#include "resource.h"

/*-------------------------------------------------
   四种花色的组别已标记
   每张扑克有一个ID用于取得对应的bmp
   查找对应牌ID可用以下宏定义
   POKERS_花色(对应数值)(J,Q,K分别记为11,12,13)
   当然如果想着直接用AJQK方便些我也帮你们定义好了
--------------------------------------------------*/

//取用ID
#define POKERS_SPADE(feature) (0+(feature))
#define POKERS_HEART(feature) (13+(feature))
#define POKERS_DIAMOND(feature) (26+(feature))
#define POKERS_CLUB(feature) (39+feature)
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

//取用对应位图资源ID
#define POKERS_SPADE_H(feature) (IDB_BITMAP1-1+(feature))
#define POKERS_HEART_H(feature) (IDB_BITMAP13+(feature))
#define POKERS_DIAMOND_H(feature) (IDB_BITMAP26+(feature))
#define POKERS_CLUB_H(feature) (IDB_BITMAP39+(feature))
#define POKERS_SPADE_AH POKERS_SPADE_H(1)
#define POKERS_HEART_AH POKERS_HEART_H(1)
#define POKERS_DIAMOND_AH POKERS_DIAMOND_H(1)
#define POKERS_CLUB_AH POKERS_CLUB_H(1)
#define POKERS_SPADE_JH POKERS_SPADE_H(11)
#define POKERS_HEART_JH POKERS_HEART_H(11)
#define POKERS_DIAMOND_JH POKERS_DIAMOND_H(11)
#define POKERS_CLUB_JH POKERS_CLUB_H(11)
#define POKERS_SPADE_QH POKERS_SPADE_H(12)
#define POKERS_HEART_QH POKERS_HEART_H(12)
#define POKERS_DIAMOND_QH POKERS_DIAMOND_H(12)
#define POKERS_CLUB_QH POKERS_CLUB_H(12)
#define POKERS_SPADE_KH POKERS_SPADE_H(13)
#define POKERS_HEART_KH POKERS_HEART_H(13)
#define POKERS_DIAMOND_KH POKERS_DIAMOND_H(13)
#define POKERS_CLUB_KH POKERS_CLUB_H(13)
#define POKERS_IDH(ID) (ID+IDB_BITMAP1-1)

//图像大小
#define POKERS_WIDTH 105
#define POKERS_HEIGHT 150

/*
//源图像文件宽度
#define POKERS_ORIGINWIDTH 5565
*/
enum Poker_Suit {Spade,Heart,Diamond,Club};

/*------------------------------------------
	已封装好扑克类，目前可以实现的功能：
	获取\设置点数与花色，取得当前扑克
	对应的bmp（返回值是个CBitmap指针）
-------------------------------------------*/
class Pokers {
private:
	int ID;
	int Feature;
	Poker_Suit Suit;
	CBitmap cbmp;
	
	/*
	const HWND* pwnd;
	//位图拷贝
	bool BitmapCopy(CBitmap *bitmap);
	//位图截取
	bool CutBitmap();
	//位图初始化
	bool IniBitmap();
	*/

public:
	//点数+花色构造
	Pokers(int Feature,Poker_Suit Suit);    
	//扑克ID构造
	Pokers(int ID=1);
	//复制构造
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

	
	//位图获取
	CBitmap* Getbitmap();
	/*
	//保存位图(调试用)
	void SaveBitmap(CString strFilePath);
	//保存当前窗口句柄
	void IniHwnd(const HWND* hwnd);
	*/
};
