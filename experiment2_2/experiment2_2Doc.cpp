// experiment2_2Doc.cpp : implementation of the CExperiment2_2Doc class
//

#include "stdafx.h"
#include "experiment2_2.h"

#include "experiment2_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_2Doc

IMPLEMENT_DYNCREATE(CExperiment2_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment2_2Doc, CDocument)
	//{{AFX_MSG_MAP(CExperiment2_2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_2Doc construction/destruction

CExperiment2_2Doc::CExperiment2_2Doc()
{
	// TODO: add one-time construction code here

}

CExperiment2_2Doc::~CExperiment2_2Doc()
{
}

BOOL CExperiment2_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExperiment2_2Doc serialization

void CExperiment2_2Doc::Serialize(CArchive& ar)
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
// CExperiment2_2Doc diagnostics

#ifdef _DEBUG
void CExperiment2_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment2_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment2_2Doc commands
