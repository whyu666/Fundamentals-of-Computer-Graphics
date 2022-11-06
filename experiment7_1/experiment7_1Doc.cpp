// experiment7_1Doc.cpp : implementation of the CExperiment7_1Doc class
//

#include "stdafx.h"
#include "experiment7_1.h"

#include "experiment7_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_1Doc

IMPLEMENT_DYNCREATE(CExperiment7_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment7_1Doc, CDocument)
	//{{AFX_MSG_MAP(CExperiment7_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_1Doc construction/destruction

CExperiment7_1Doc::CExperiment7_1Doc()
{
	// TODO: add one-time construction code here

}

CExperiment7_1Doc::~CExperiment7_1Doc()
{
}

BOOL CExperiment7_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExperiment7_1Doc serialization

void CExperiment7_1Doc::Serialize(CArchive& ar)
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
// CExperiment7_1Doc diagnostics

#ifdef _DEBUG
void CExperiment7_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment7_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment7_1Doc commands
