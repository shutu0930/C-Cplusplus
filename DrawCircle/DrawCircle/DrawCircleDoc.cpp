// DrawCircleDoc.cpp : CDrawCircleDoc ���ʵ��
//

#include "stdafx.h"
#include "DrawCircle.h"

#include "DrawCircleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawCircleDoc

IMPLEMENT_DYNCREATE(CDrawCircleDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawCircleDoc, CDocument)
END_MESSAGE_MAP()


// CDrawCircleDoc ����/����

CDrawCircleDoc::CDrawCircleDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CDrawCircleDoc::~CDrawCircleDoc()
{
}

BOOL CDrawCircleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CDrawCircleDoc ���л�

void CDrawCircleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CDrawCircleDoc ���

#ifdef _DEBUG
void CDrawCircleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawCircleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDrawCircleDoc ����
