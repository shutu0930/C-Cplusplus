// DrawCircleDoc.h : CDrawCircleDoc ��Ľӿ�
//


#pragma once


class CDrawCircleDoc : public CDocument
{
protected: // �������л�����
	CDrawCircleDoc();
	DECLARE_DYNCREATE(CDrawCircleDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CDrawCircleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


