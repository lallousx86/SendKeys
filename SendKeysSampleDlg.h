// SendKeysSampleDlg.h : header file
//

#if !defined(AFX_SENDKEYSSAMPLEDLG_H__7BCAE5A7_75C4_4831_82FD_5A13F846FE61__INCLUDED_)
#define AFX_SENDKEYSSAMPLEDLG_H__7BCAE5A7_75C4_4831_82FD_5A13F846FE61__INCLUDED_

#include "SendKeys.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSendKeysSampleDlg dialog

class CSendKeysSampleDlg : public CDialog
{
// Construction
public:
	CSendKeysSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSendKeysSampleDlg)
	enum { IDD = IDD_SENDKEYSSAMPLE_DIALOG };
	BOOL	m_chkOnlyToApp;
	CString	m_edtAppTitle;
	CString	m_edtKeyStrokes;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendKeysSampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSendKeysSampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CSendKeys m_sk;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDKEYSSAMPLEDLG_H__7BCAE5A7_75C4_4831_82FD_5A13F846FE61__INCLUDED_)
