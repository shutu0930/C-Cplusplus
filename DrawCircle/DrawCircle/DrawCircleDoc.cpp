// DrawCircleDoc.cpp : CDrawCircleDoc 类的实现
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


// CDrawCircleDoc 构造/析构

CDrawCircleDoc::CDrawCircleDoc()
{
	// TODO: 在此添加一次性构造代码

}

CDrawCircleDoc::~CDrawCircleDoc()
{
}

BOOL CDrawCircleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CDrawCircleDoc 序列化

void CDrawCircleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CDrawCircleDoc 诊断

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


// CDrawCircleDoc 命令
