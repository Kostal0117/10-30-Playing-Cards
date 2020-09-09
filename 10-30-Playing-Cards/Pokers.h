#pragma once

#ifndef _TH_POKERS
#define _TH_POKERS

#include "stdafx.h"

/*-------------------------------------------------
   四种花色的组别已标记
   每张扑克有一个ID用于取得对应的bmp
   查找对应牌ID可用以下宏定义
   POKERS_花色(对应数值)(J,Q,K分别记为11,12,13)
   当然如果想着直接用AJQK方便些我也帮你们定义好了
--------------------------------------------------*/

//取用ID
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

//图像大小
#define POKERS_WIDTH 105
#define POKERS_HEIGHT 150
//源图像文件宽度
#define POKERS_ORIGINWIDTH 5565

enum Poker_Suit {Spade,Heart,Diamond,Club};

/*------------------------------------------
	已大致封装好扑克类，目前可以实现的功能：
	获取\设置点数与花色，取得当前扑克
	对应的bmp（返回值是个CBitmap指针）
	使用时一定要在窗口类的初始化函数
	里调用IniHwnd函数，参数为当前窗口
	的句柄，否则会出现扑克牌变黑的错误
	\或者当掉
-------------------------------------------*/
class Pokers {
private:
	int ID;
	int Feature;
	Poker_Suit Suit;
	CBitmap cbmp;
	const HWND* pwnd;
	//位图拷贝
	bool BitmapCopy(CBitmap *bitmap);
	//位图截取
	bool CutBitmap();
	//位图初始化
	bool IniBitmap();
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
	//保存位图(调试用)
	void SaveBitmap(CString strFilePath);
	//保存当前窗口句柄
	void IniHwnd(const HWND* hwnd);
};

#endif //_TH_POKERS