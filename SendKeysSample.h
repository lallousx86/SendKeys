// SendKeysSample.h : main header file for the SENDKEYSSAMPLE application
//

#if !defined(AFX_SENDKEYSSAMPLE_H__0CA01026_D42B_4CD9_AD0C_DE18E2410D45__INCLUDED_)
#define AFX_SENDKEYSSAMPLE_H__0CA01026_D42B_4CD9_AD0C_DE18E2410D45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSendKeysSampleApp:
// See SendKeysSample.cpp for the implementation of this class
//

class CSendKeysSampleApp : public CWinApp
{
public:
	CSendKeysSampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendKeysSampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSendKeysSampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDKEYSSAMPLE_H__0CA01026_D42B_4CD9_AD0C_DE18E2410D45__INCLUDED_)
