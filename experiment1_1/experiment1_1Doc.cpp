// experiment1_1Doc.cpp : implementation of the CExperiment1_1Doc class
//

#include "stdafx.h"
#include "experiment1_1.h"

#include "experiment1_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_1Doc

IMPLEMENT_DYNCREATE(CExperiment1_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment1_1Doc, CDocument)
	//{{AFX_MSG_MAP(CExperiment1_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_1Doc construction/destruction

CExperiment1_1Doc::CExperiment1_1Doc()
{
	// TODO: add one-time construction code here

}

CExperiment1_1Doc::~CExperiment1_1Doc()
{
}

BOOL CExperiment1_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExperiment1_1Doc serialization

void CExperiment1_1Doc::Serialize(CArchive& ar)
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
// CExperiment1_1Doc diagnostics

#ifdef _DEBUG
void CExperiment1_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment1_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_1Doc commands
