// DrawCircleView.h : CDrawCircleView ��Ľӿ�
//


#pragma once


class CDrawCircleView : public CView
{
	CRect m_rect[11];
	int m_IsDraw;
	int m_DrawNum;
	int m_DrawCount;
protected: // �������л�����
	CDrawCircleView();
	DECLARE_DYNCREATE(CDrawCircleView)

// ����
public:
	CDrawCircleDoc* GetDocument() const;

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
	virtual ~CDrawCircleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // DrawCircleView.cpp �еĵ��԰汾
inline CDrawCircleDoc* CDrawCircleView::GetDocument() const
   { return reinterpret_cast<CDrawCircleDoc*>(m_pDocument); }
#endif

