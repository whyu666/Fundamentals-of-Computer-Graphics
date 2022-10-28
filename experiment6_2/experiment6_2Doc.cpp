// experiment6_2Doc.cpp : implementation of the CExperiment6_2Doc class
//

#include "stdafx.h"
#include "experiment6_2.h"

#include "experiment6_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_2Doc

IMPLEMENT_DYNCREATE(CExperiment6_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment6_2Doc, CDocument)
	//{{AFX_MSG_MAP(CExperiment6_2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_2Doc construction/destruction

CExperiment6_2Doc::CExperiment6_2Doc()
{
	// TODO: add one-time construction code here

}

CExperiment6_2Doc::~CExperiment6_2Doc()
{
}

BOOL CExperiment6_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExperiment6_2Doc serialization

void CExperiment6_2Doc::Serialize(CArchive& ar)
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
// CExperiment6_2Doc diagnostics

#ifdef _DEBUG
void CExperiment6_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment6_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment6_2Doc commands
