// experiment8_1Doc.cpp : implementation of the CExperiment8_1Doc class
//

#include "stdafx.h"
#include "experiment8_1.h"

#include "experiment8_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_1Doc

IMPLEMENT_DYNCREATE(CExperiment8_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment8_1Doc, CDocument)
	//{{AFX_MSG_MAP(CExperiment8_1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_1Doc construction/destruction

CExperiment8_1Doc::CExperiment8_1Doc()
{
	// TODO: add one-time construction code here

}

CExperiment8_1Doc::~CExperiment8_1Doc()
{
}

BOOL CExperiment8_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CExperiment8_1Doc serialization

void CExperiment8_1Doc::Serialize(CArchive& ar)
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
// CExperiment8_1Doc diagnostics

#ifdef _DEBUG
void CExperiment8_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment8_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CExperiment8_1Doc commands
