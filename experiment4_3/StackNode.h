// StackNode.h: interface for the CStackNode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STACKNODE_H__49D4B45C_6631_42AD_A771_8794ED01E7A1__INCLUDED_)
#define AFX_STACKNODE_H__49D4B45C_6631_42AD_A771_8794ED01E7A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "P2.h"

class CStackNode {  //Õ»½áµã  
public:
	CStackNode();
	virtual ~CStackNode();
public:
    CP2 PixelPoint;
	CStackNode *pNext;
};

#endif // !defined(AFX_STACKNODE_H__49D4B45C_6631_42AD_A771_8794ED01E7A1__INCLUDED_)
