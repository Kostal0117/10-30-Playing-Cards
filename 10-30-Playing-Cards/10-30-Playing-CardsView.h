
// 10-30-Playing-CardsView.h : CMy1030PlayingCardsView ��Ľӿ�
//

#pragma once


class CMy1030PlayingCardsView : public CView
{
protected: // �������л�����
	CMy1030PlayingCardsView();
	DECLARE_DYNCREATE(CMy1030PlayingCardsView)

// ����
public:
	CMy1030PlayingCardsDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy1030PlayingCardsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 10-30-Playing-CardsView.cpp �еĵ��԰汾
inline CMy1030PlayingCardsDoc* CMy1030PlayingCardsView::GetDocument() const
   { return reinterpret_cast<CMy1030PlayingCardsDoc*>(m_pDocument); }
#endif

