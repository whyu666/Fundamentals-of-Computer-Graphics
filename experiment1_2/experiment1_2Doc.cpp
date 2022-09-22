// experiment1_2Doc.cpp : implementation of the CExperiment1_2Doc class
//

#include "stdafx.h"
#include "experiment1_2.h"

#include "experiment1_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_2Doc

IMPLEMENT_DYNCREATE(CExperiment1_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment1_2Doc, CDocument)
	//{{AFX_MSG_MAP(CExperiment1_2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_2Doc construction/destruction

CExperiment1_2Doc::CExperiment1_2Doc()
{
	// TODO: add one-time construction code here

}

CExperiment1_2Doc::~CExperiment1_2Doc()
{
}

BOOL CExperiment1_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExperiment1_2Doc serialization

void CExperiment1_2Doc::Serialize(CArchive& ar)
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
// CExperiment1_2Doc diagnostics

#ifdef _DEBUG
void CExperiment1_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment1_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment1_2Doc commands
