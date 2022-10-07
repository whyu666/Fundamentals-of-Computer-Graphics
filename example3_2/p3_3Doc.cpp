// p3_3Doc.cpp : implementation of the CP3_3Doc class
//

#include "stdafx.h"
#include "p3_3.h"

#include "p3_3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CP3_3Doc

IMPLEMENT_DYNCREATE(CP3_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CP3_3Doc, CDocument)
	//{{AFX_MSG_MAP(CP3_3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CP3_3Doc construction/destruction

CP3_3Doc::CP3_3Doc()
{
	// TODO: add one-time construction code here

}

CP3_3Doc::~CP3_3Doc()
{
}

BOOL CP3_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CP3_3Doc serialization

void CP3_3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CP3_3Doc diagnostics

#ifdef _DEBUG
void CP3_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CP3_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CP3_3Doc commands
