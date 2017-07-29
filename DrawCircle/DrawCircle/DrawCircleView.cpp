// DrawCircleView.cpp : CDrawCircleView ���ʵ��
//

#include "stdafx.h"
#include "DrawCircle.h"

#include "DrawCircleDoc.h"
#include "DrawCircleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawCircleView

IMPLEMENT_DYNCREATE(CDrawCircleView, CView)

BEGIN_MESSAGE_MAP(CDrawCircleView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CDrawCircleView ����/����

CDrawCircleView::CDrawCircleView()
{
	// TODO: �ڴ˴���ӹ������
	m_IsDraw=0;
	m_DrawNum=0;
	m_DrawCount=0;
}

CDrawCircleView::~CDrawCircleView()
{
}

BOOL CDrawCircleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDrawCircleView ����

void CDrawCircleView::OnDraw(CDC* pDC)
{
	
	CDrawCircleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	//if(m_IsDraw!=0)
	//{
	//	/*pDC->Ellipse(&m_rect[m_DrawCount]);*/
	//	/*pDC->SelectStockObject(GRAY_BRUSH);*/
	//	pDC=GetDC(); 
	//	CPen   pen; 
	//	pen.CreateStockObject(NULL_PEN); 
	//	CPen   *pOld=pDC->SelectObject(&pen); 
	//	pDC-> Ellipse(&m_rect[m_DrawCount]);//��Բ���� 

	//	pDC-> SelectObject(pOld); 
	//	pDC-> Ellipse(&m_rect[m_DrawCount]);//���»�Բ 

	//}

	
	if(m_IsDraw<=10 && m_IsDraw>0)
		pDC->Ellipse(m_rect[m_IsDraw-1]);
	else if(m_IsDraw>10)
	{
		pDC->Ellipse(m_rect[m_IsDraw-1]);
		CPen  pen; 
		pen.CreateStockObject(WHITE_PEN); 
		CPen  *pOld=pDC->SelectObject(&pen); 
		pDC->Ellipse(m_rect[m_IsDraw-11]);//��Բ���� 
	}







	
}


// CDrawCircleView ��ӡ

BOOL CDrawCircleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDrawCircleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDrawCircleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CDrawCircleView ���

#ifdef _DEBUG
void CDrawCircleView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawCircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawCircleDoc* CDrawCircleView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawCircleDoc)));
	return (CDrawCircleDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawCircleView ��Ϣ�������

void CDrawCircleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	
		m_rect[m_IsDraw].left=point.x-20;
		m_rect[m_IsDraw].right=point.x+20;
		m_rect[m_IsDraw].top=point.y-20;
		m_rect[m_IsDraw].bottom=point.y+20;
		m_IsDraw++;
		InvalidateRect(&m_rect[m_IsDraw-1],FALSE);
		if(m_IsDraw>10)
		{
			InvalidateRect(&m_rect[m_IsDraw-11],TRUE);

			for(int i=0;i<10;i++)
			{
				m_rect[i]=m_rect[i+1];
			}

			m_IsDraw-=1;
		}



	



	//if(m_DrawNum<10 && m_DrawCount==0)
	//{	//	m_rect[m_DrawNum].left=point.x-20;
	//	m_rect[m_DrawNum].right=point.x+20;
	//	m_rect[m_DrawNum].top=point.y-20;
	//	m_rect[m_DrawNum].bottom=point.y+20;	//	CClientDC  dc(this);	//	/**dc.SelectStockObject(LTGRAY_BRUSH);*/	//	dc.Ellipse(&m_rect[m_DrawNum]);
	//	m_DrawNum++;
	//}else
	//{	
	//	if(m_DrawCount<10)
	//	{	//		CClientDC  dc(this);	//		/**dc.SelectStockObject(WHITE_BRUSH);	//		dc.Ellipse(&m_rect[m_DrawCount]);*/
	//		
	//		CPen  pen; 
	//		pen.CreateStockObject(WHITE_PEN); 
	//		CPen  *pOld=dc.SelectObject(&pen); 
	//		dc.Ellipse(m_rect[m_DrawCount]);//��Բ���� 
	//		m_DrawCount++;
	//	}else
	//	{
	//		m_DrawCount=0;
	//		m_DrawNum=0;
	//	}
	//	
	//
	//
	//}
	
	
	

	CView::OnLButtonDown(nFlags, point);
}
