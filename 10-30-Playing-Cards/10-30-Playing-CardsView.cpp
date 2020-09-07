
// 10-30-Playing-CardsView.cpp : CMy1030PlayingCardsView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy1030PlayingCardsView 构造/析构

CMy1030PlayingCardsView::CMy1030PlayingCardsView()
{
	// TODO: 在此处添加构造代码

}

CMy1030PlayingCardsView::~CMy1030PlayingCardsView()
{
}

BOOL CMy1030PlayingCardsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy1030PlayingCardsView 绘制

void CMy1030PlayingCardsView::OnDraw(CDC* /*pDC*/)
{
	CMy1030PlayingCardsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy1030PlayingCardsView 打印

BOOL CMy1030PlayingCardsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy1030PlayingCardsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy1030PlayingCardsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy1030PlayingCardsView 诊断

#ifdef _DEBUG
void CMy1030PlayingCardsView::AssertValid() const
{
	CView::AssertValid();
}

void CMy1030PlayingCardsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1030PlayingCardsDoc* CMy1030PlayingCardsView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1030PlayingCardsDoc)));
	return (CMy1030PlayingCardsDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy1030PlayingCardsView 消息处理程序
