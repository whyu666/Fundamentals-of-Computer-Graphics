// experiment4_2Doc.cpp : implementation of the CExperiment4_2Doc class
//

#include "stdafx.h"
#include "experiment4_2.h"

#include "experiment4_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_2Doc

IMPLEMENT_DYNCREATE(CExperiment4_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment4_2Doc, CDocument)
	//{{AFX_MSG_MAP(CExperiment4_2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_2Doc construction/destruction

CExperiment4_2Doc::CExperiment4_2Doc()
{
	// TODO: add one-time construction code here

}

CExperiment4_2Doc::~CExperiment4_2Doc()
{
}

BOOL CExperiment4_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExperiment4_2Doc serialization

void CExperiment4_2Doc::Serialize(CArchive& ar)
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
// CExperiment4_2Doc diagnostics

#ifdef _DEBUG
void CExperiment4_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment4_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_2Doc commands
