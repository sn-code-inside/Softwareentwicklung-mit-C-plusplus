
// P002KD_FileViewDlg.cpp: Implementierungsdatei
//

#include "pch.h"
#include "framework.h"
#include "P002KD_FileView.h"
#include "P002KD_FileViewDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CP002KDFileViewDlg-Dialogfeld



CP002KDFileViewDlg::CP002KDFileViewDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_P002KD_FILEVIEW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CP002KDFileViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CP002KDFileViewDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPENFILE, &CP002KDFileViewDlg::OnBnClickedButtonOpenfile)
	ON_BN_CLICKED(IDC_BUTTON_SAVEFILE, &CP002KDFileViewDlg::OnBnClickedButtonSavefile)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CP002KDFileViewDlg::OnBnClickedButtonExit)
END_MESSAGE_MAP()


// CP002KDFileViewDlg-Meldungshandler

BOOL CP002KDFileViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	//SetWindowText(_T("P002KBD_FileView"));

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

void CP002KDFileViewDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CP002KDFileViewDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CP002KDFileViewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CP002KDFileViewDlg::OnBnClickedButtonOpenfile()
{
    CFileDialog dlg(TRUE);                  //TRUE bedeutet, dass wir ein File öffnen wollen.
                                            //FALSE: Wir wollen ein File speichern.
    dlg.DoModal();                          //Dialog selektiert beliebiges File.
    strFNameAndPath_ = dlg.GetPathName();   //GetPathName liefert Name & Pfad des sel. Files.
    cFileUtil myFile(strFNameAndPath_);
    char* strFileData = myFile.getFileData();

    CWnd* p2EditControl = GetDlgItem(IDC_EDIT_TEXT);        //1
    CString strWinText(strFileData);                        //2
    p2EditControl->SetWindowTextW(strWinText);              //3
}

void CP002KDFileViewDlg::OnBnClickedButtonSavefile()
{
	CWnd* p2EditControl = GetDlgItem(IDC_EDIT_TEXT);        //1
	CString strWinText;                                     //2
	p2EditControl->GetWindowTextW(strWinText);              //3
	cFileUtil myFile(strFNameAndPath_);                     //4
	myFile.saveFile(strWinText);                            //5
}

void CP002KDFileViewDlg::OnBnClickedButtonExit()
{
	OnOK();                                                 //6
}

//=== Klasse cFileUtil ===========================================
cFileUtil::cFileUtil(void)
{
}

cFileUtil::cFileUtil(CString fileName) 
{
	strFNameAndPath_ = fileName;                                        //1
	BOOL bOK = file_.Open(strFNameAndPath_, CFile::modeRead);           //2
	strFileData_ = NULL;                                                //3
	if (bOK) {
		ullFLen_ = file_.GetLength();                                   //4
		strFileData_ = new char[(int)ullFLen_ + 1];                     //5
		memset(strFileData_, 0, (int)ullFLen_ + 1);                     //6
		UINT uiErr = file_.Read(strFileData_, (unsigned int)ullFLen_);  //7
		file_.Close();                                                  //8
	}
}

cFileUtil::~cFileUtil(void) 
{
	if (strFileData_)                                                   //9
		delete[]strFileData_;
}
void cFileUtil::readFile(void)
{
	BOOL bOK = file_.Open(strFNameAndPath_, CFile::modeRead);
	strFileData_ = NULL;
	if (bOK) {
		ullFLen_ = file_.GetLength();
		strFileData_ = new char[(int)ullFLen_ + 1];
		memset(strFileData_, 0, (int)ullFLen_ + 1);
		UINT uiErr = file_.Read(strFileData_, (unsigned int)ullFLen_);
		file_.Close();
	}
}
void cFileUtil::saveFile(CString strWinText) 
{
	BOOL bOK = file_.Open(strFNameAndPath_, CFile::modeWrite | CFile::modeCreate);//10
	if (bOK) {
		int iNewLen = strWinText.GetLength();                           //11
		char* str = new char[iNewLen + 1];                              //12
		memset(str, 0, iNewLen + 1);
		LPTSTR strFileData = strWinText.GetBuffer(iNewLen);             //13
		size_t uiConv = 0;                                              //14
		wcstombs_s(&uiConv, str, iNewLen + 1, strFileData, iNewLen + 1);//15
		file_.Write(str, iNewLen);                                      //16
		file_.Close();
		delete[] str;
	}
}

//=== Klasse cFileUtil ========================================end

