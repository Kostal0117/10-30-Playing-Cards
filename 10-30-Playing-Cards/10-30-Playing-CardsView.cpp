
// 10-30-Playing-CardsView.cpp : CMy1030PlayingCardsView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "10-30-Playing-Cards.h"
#endif

#include "10-30-Playing-CardsDoc.h"
#include "10-30-Playing-CardsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1030PlayingCardsView

IMPLEMENT_DYNCREATE(CMy1030PlayingCardsView, CView)

BEGIN_MESSAGE_MAP(CMy1030PlayingCardsView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy1030PlayingCardsView ����/����

CMy1030PlayingCardsView::CMy1030PlayingCardsView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy1030PlayingCardsView::~CMy1030PlayingCardsView()
{
}

BOOL CMy1030PlayingCardsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy1030PlayingCardsView ����

void CMy1030PlayingCardsView::OnDraw(CDC* /*pDC*/)
{
	CMy1030PlayingCardsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy1030PlayingCardsView ��ӡ

BOOL CMy1030PlayingCardsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy1030PlayingCardsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy1030PlayingCardsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy1030PlayingCardsView ���

#ifdef _DEBUG
void CMy1030PlayingCardsView::AssertValid() const
{
	CView::AssertValid();
}

void CMy1030PlayingCardsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1030PlayingCardsDoc* CMy1030PlayingCardsView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1030PlayingCardsDoc)));
	return (CMy1030PlayingCardsDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy1030PlayingCardsView ��Ϣ�������
