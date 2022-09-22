// experiment2Doc.cpp : implementation of the CExperiment2Doc class
//

#include "stdafx.h"
#include "experiment2.h"

#include "experiment2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment2Doc

IMPLEMENT_DYNCREATE(CExperiment2Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment2Doc, CDocument)
	//{{AFX_MSG_MAP(CExperiment2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment2Doc construction/destruction

CExperiment2Doc::CExperiment2Doc()
{
	// TODO: add one-time construction code here

}

CExperiment2Doc::~CExperiment2Doc()
{
}

BOOL CExperiment2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExperiment2Doc serialization

void CExperiment2Doc::Serialize(CArchive& ar)
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
// CExperiment2Doc diagnostics

#ifdef _DEBUG
void CExperiment2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment2Doc commands
