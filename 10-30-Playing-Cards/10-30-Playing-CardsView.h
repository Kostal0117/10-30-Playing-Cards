
// 10-30-Playing-CardsView.h : CMy1030PlayingCardsView 类的接口
//

#pragma once


class CMy1030PlayingCardsView : public CView
{
protected: // 仅从序列化创建
	CMy1030PlayingCardsView();
	DECLARE_DYNCREATE(CMy1030PlayingCardsView)

// 特性
public:
	CMy1030PlayingCardsDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy1030PlayingCardsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 10-30-Playing-CardsView.cpp 中的调试版本
inline CMy1030PlayingCardsDoc* CMy1030PlayingCardsView::GetDocument() const
   { return reinterpret_cast<CMy1030PlayingCardsDoc*>(m_pDocument); }
#endif

