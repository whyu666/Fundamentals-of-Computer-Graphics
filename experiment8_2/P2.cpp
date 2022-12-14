// P2.cpp: implementation of the CP2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "experiment8_2.h"
#include "P2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CP2::CP2() {
	this->x = 0.0;
	this->y = 0.0;
	this->c = CRGB(1.0, 1.0, 1.0);
}

CP2::~CP2() {

}

CP2::CP2(double x0, double y0) {
	this->x = x0;
	this->y = y0;
}
