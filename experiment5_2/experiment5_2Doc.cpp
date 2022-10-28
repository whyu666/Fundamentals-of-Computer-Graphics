// experiment5_2Doc.cpp : implementation of the CExperiment5_2Doc class
//

#include "stdafx.h"
#include "experiment5_2.h"

#include "experiment5_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_2Doc

IMPLEMENT_DYNCREATE(CExperiment5_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment5_2Doc, CDocument)
	//{{AFX_MSG_MAP(CExperiment5_2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_2Doc construction/destruction

CExperiment5_2Doc::CExperiment5_2Doc()
{
	// TODO: add one-time construction code here

}

CExperiment5_2Doc::~CExperiment5_2Doc()
{
}

BOOL CExperiment5_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExperiment5_2Doc serialization

void CExperiment5_2Doc::Serialize(CArchive& ar)
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
// CExperiment5_2Doc diagnostics

#ifdef _DEBUG
void CExperiment5_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment5_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment5_2Doc commands
