// SendKeysSampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SendKeysSample.h"
#include "SendKeysSampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendKeysSampleDlg dialog

CSendKeysSampleDlg::CSendKeysSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendKeysSampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendKeysSampleDlg)
	m_chkOnlyToApp = TRUE;
	m_edtAppTitle = _T("Notepad");
	m_edtKeyStrokes = _T("{DELAY=200}Hello we{BS}orld!");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSendKeysSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendKeysSampleDlg)
	DDX_Check(pDX, IDC_CHK_TOAPP, m_chkOnlyToApp);
	DDX_Text(pDX, IDC_EDIT_APP, m_edtAppTitle);
	DDX_Text(pDX, IDC_EDIT_KEYSTROKES, m_edtKeyStrokes);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSendKeysSampleDlg, CDialog)
	//{{AFX_MSG_MAP(CSendKeysSampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendKeysSampleDlg message handlers

BOOL CSendKeysSampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSendKeysSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSendKeysSampleDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSendKeysSampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSendKeysSampleDlg::OnOK() 
{
  UpdateData(TRUE);
  
  if (m_chkOnlyToApp && !m_sk.AppActivate((LPCTSTR)m_edtAppTitle))
  {
    MessageBox(_T("Could not send to this application!"));
    return;
  }

  m_sk.SendKeys((LPCTSTR)m_edtKeyStrokes);
}

void CSendKeysSampleDlg::OnButton2() 
{
  m_sk.SendKeys(_T("{DELAY=200}@rnotepad~{appactivate Notepad}{DELAY 100}Hello!!!!%ha{BEEP 1999 1000}{ESC}% {DOWN 5}"));
}

void CSendKeysSampleDlg::OnButton1() 
{
  m_sk.SendKeys(_T("{DELAY=200}@rcalc~{DELAY 100}{appactivate Calculator}1500{PLUS}1*600~"));
}

void CSendKeysSampleDlg::OnButton3() 
{
  m_sk.SendKeys(_T("{DELAY=200}@rcmd~{DELAY 500}dir/w~cd ..~dir/w~title I love Cmd line!~cd\\~exit"));
}

void CSendKeysSampleDlg::OnButton4() 
{
  MessageBox(_T("turn off all LEDs and watch!"));
  m_sk.SetDelay(200);
  for (int i=0;i<5;i++)
  {
    m_sk.SendKeys(_T("{NUMLOCK}{CAPSLOCK}{SCROLL}{SCROLL}{CAPSLOCK}{NUMLOCK}"));
  }
}
