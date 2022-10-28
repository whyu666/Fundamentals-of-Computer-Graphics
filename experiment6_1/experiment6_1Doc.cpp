// experiment6_1Doc.cpp : implementation of the CExperiment6_1Doc class
//

#include "stdafx.h"
#include "experiment6_1.h"

#include "experiment6_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_1Doc

IMPLEMENT_DYNCREATE(CExperiment6_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment6_1Doc, CDocument)
	//{{AFX_MSG_MAP(CExperiment6_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_1Doc construction/destruction

CExperiment6_1Doc::CExperiment6_1Doc()
{
	// TODO: add one-time construction code here

}

CExperiment6_1Doc::~CExperiment6_1Doc()
{
}

BOOL CExperiment6_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExperiment6_1Doc serialization

void CExperiment6_1Doc::Serialize(CArchive& ar)
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
// CExperiment6_1Doc diagnostics

#ifdef _DEBUG
void CExperiment6_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment6_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_1Doc commands
