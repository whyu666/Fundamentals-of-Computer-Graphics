// experiment4_3Doc.cpp : implementation of the CExperiment4_3Doc class
//

#include "stdafx.h"
#include "experiment4_3.h"

#include "experiment4_3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_3Doc

IMPLEMENT_DYNCREATE(CExperiment4_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment4_3Doc, CDocument)
	//{{AFX_MSG_MAP(CExperiment4_3Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_3Doc construction/destruction

CExperiment4_3Doc::CExperiment4_3Doc()
{
	// TODO: add one-time construction code here

}

CExperiment4_3Doc::~CExperiment4_3Doc()
{
}

BOOL CExperiment4_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExperiment4_3Doc serialization

void CExperiment4_3Doc::Serialize(CArchive& ar)
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
// CExperiment4_3Doc diagnostics

#ifdef _DEBUG
void CExperiment4_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment4_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment4_3Doc commands
